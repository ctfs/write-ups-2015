#!/usr/bin/env python3

from random import SystemRandom
import binascii
import inspect
import struct
import os
import sys
import re
import traceback
import cmd

# the flag is: "uiuctf_" + FLAG 
FLAG = open('flag.txt', 'r').read() # file contains hex data

# drop in /dev/urandom for randomness
csrandom = SystemRandom()

RANDOMIZE = True

# for testing
if len(sys.argv) >= 2:
    if sys.argv[1] == 'norandom':
        print('No instruction randomization testing mode.')
        RANDOMIZE = False

class RISE:

    PRG_MAX_SIZE = 0x400
    PRG_LOC = 0x10000
    MEM_SIZE = 0x4000
    
    INST_SIZE = 4
    FLAG_SIZE = 28
    ADDR_MAX = 0xffffff
    KEY_R_BEGIN = 0x800000
    OBS_INFO_LOC = 0x2000
    VAL_SPACE = 0x100000000
    INVALID_MEM_READ_VAL = 0xffffffff
    
    def __init__(self, flag=bytearray(range(65,85)), 
                 out_handler=lambda x: None, randomize=RANDOMIZE):
        self.out_handler = out_handler
        self.load_program(b'')
        self.flag = flag[:self.FLAG_SIZE] + b'\x00' * (self.FLAG_SIZE - len(flag))
        self.flag = bytearray(self.flag) #[e for e in self.flag]
        
        # !!! Generate randomized instruction set !!!
        fg = inspect.getmembers(self, inspect.ismethod)
        fg = [e for e in fg if '__inst' in e[0]]
        if randomize:
            csrandom.shuffle(fg)
        fns = [fn for name, fn in fg]
        self.iset = [self.__z_inst_halt]
        self.iset.extend(fns)
    
    def load_program(self, program):
        # pad with 0 bytes
        prgpad = program[:self.PRG_MAX_SIZE] + b'\x00' * (self.PRG_MAX_SIZE - len(program))
        self.program = bytearray(prgpad) #[e for e in prgpad] # convert to byte array
        self.reset()
        
    def reset(self):
        self.halted = False
        self.crashed = False
        self.pc = self.PRG_LOC
        self.sp = self.MEM_SIZE
        self.reg_a = 0
        self.reg_c = 0
        self.reg_x = 0
        self.mem = [0] * self.MEM_SIZE
        self.trace = []
        self.__hideflag()
    
    def __hideflag(self):
        self.flaglocked = True
        self.flagindex = 0
        
        self.flagkey, loc, pad = (csrandom.randrange(2**32) for _ in range(3))
        # Secret flag register somewhere between 0x800000 to 0xfffffc
        self.flagloc = ((loc & 0x1fffff) << 2) + self.KEY_R_BEGIN
        # Write the random key to that register then read from it a few times to get the whole flag
        
        # Obfuscate
        enckey = self.flagkey ^ pad
        obsenckey = ((enckey ^ 0x25f9c651) - 0xa74b5c0a) % self.VAL_SPACE
        obspad = (pad + 0xc3c7f05c) % self.VAL_SPACE
        obsloc1 = self.flagloc & 0xea5bbddd
        obsloc2 = self.flagloc & 0x77b7473b
        self.__mem_write(self.OBS_INFO_LOC, obsenckey)
        self.__mem_write(self.OBS_INFO_LOC + 4, obspad)
        self.__mem_write(self.OBS_INFO_LOC + 8, obsloc1)
        self.__mem_write(self.OBS_INFO_LOC + 12, obsloc2)
    
    def execute(self, steps=float('inf')):
        steps_done = 0
        while not self.halted and steps_done < steps:
            self.exec_step()
            steps_done += 1
    
    def exec_step(self):
        if self.halted:
            return
        inst_raw = self.__mem_read(self.pc)
        if self.halted:
            return
        inst_num = inst_raw >> 24
        inst_data = inst_raw & 0xffffff
        if inst_num >= len(self.iset):
            self.__crash('Illegal instruction num 0x%02x out of bounds (max=%d): ' % (inst_num, len(self.iset)-1))
            return
        
        self.trace.append([self.pc, self.__mem_read(self.pc, False)])
        self.iset[inst_num](inst_data)
        if not self.halted:
            self.pc = (self.pc + self.INST_SIZE) % self.VAL_SPACE
        
    
    def get_state(self, reveal_inst=False):
        if self.halted:
            if self.crashed:
                runst = 'Program has crashed\nReason: %s' % self.crash_reason
            else:
                runst = 'Program has halted at current instruction'
        else:
            runst = 'Program is running'
        
        pcst = 'PC reg: 0x%08x, *PC: 0x%08x' % (self.pc, self.__mem_read(self.pc, False))
        spst = 'SP reg: 0x%08x, *SP: 0x%08x' % (self.sp, self.__mem_read(self.sp, False))
        ast = 'A  reg: 0x%08x, *A:  0x%08x' % (self.reg_a, self.__mem_read(self.reg_a, False))
        cst = 'C  reg: 0x%08x, *C:  0x%08x' % (self.reg_c, self.__mem_read(self.reg_c, False))
        xst = 'X  reg: 0x%08x, *X:  0x%08x' % (self.reg_x, self.__mem_read(self.reg_x, False))
        
        inst_raw = self.__mem_read(self.pc)
        inst_num = inst_raw >> 24
        inst_data = inst_raw & 0xffffff
        instc = 'Current Instruction: 0x%02x (#%d)' % (inst_num, inst_num)
        oob = inst_num >= len(self.iset)
        if reveal_inst or inst_num == 0 or oob:
            if oob:
                instc += ' (invalid instruction)'
            else:
                instc += ' (' + self.iset[inst_num].__name__.split('inst_')[1] +')'
        instc += '\nInstruction data parameter 0x%06x (%d)' % (inst_data, inst_data)
            
        sst = '\n'.join([runst, '', pcst, spst, ast, cst, xst, '', instc])
        return sst 
    
    def reveal_randomization(self):
        res = 'Instruction number -> Randomized instruction: \n'
        res += '\n'.join(['%d: %s' % (i, fn.__name__) for i,fn in enumerate(self.iset)])
        return res
    
    def get_trace(self, reveal_inst=False):
        ms = []
        for e in self.trace:
            inst_raw = e[1]
            inst_num = inst_raw >> 24
            inst_data = inst_raw & 0xffffff
            oob = inst_num >= len(self.iset)
            if reveal_inst or inst_num == 0 or oob:
                if oob:
                    instc = '(invalid instruction)'
                else:
                    instc = self.iset[inst_num].__name__.split('inst_')[1]
            else:
                instc = '0x%02x' % inst_num
            ms.append('PC: 0x%08x, *PC: 0x%08x -> %17s 0x%06x (%d)' % (e[0], e[1], instc, inst_data, inst_data))
        return 'Trace:\n' + '\n'.join(ms) 
    
    #
    # Instruction Set
    #
    
    # this halt instruction is always number 0
    def __z_inst_halt(self, unused):
        self.halted = True
    
    def __inst_load_A_imm(self, data_low_24b):
        self.reg_a = data_low_24b
        
    def __inst_load_A_next(self, unused):
        loc = (self.pc + 4) % self.VAL_SPACE
        self.reg_a = self.__mem_read(loc)
        self.pc = loc
    
    def __inst_load_A(self, loc):
        self.reg_a = self.__mem_read(loc)
    
    def __inst_store_A(self, loc):
        self.__mem_write(loc, self.reg_a)
        
    def __inst_load_A_idx_X(self, idxloc):
        loc = (idxloc + self.reg_x) % self.VAL_SPACE
        self.reg_a = self.__mem_read(loc)
    
    def __inst_store_A_idx_X(self, idxloc):
        loc = (idxloc + self.reg_x) % self.VAL_SPACE
        self.__mem_write(loc, self.reg_a)
        
    def __inst_load_A_ind(self, locmem):
        self.reg_a = self.__mem_read(self.__mem_read(locmem))
        
    def __inst_store_A_ind(self, locmem):
        self.__mem_write(self.__mem_read(locmem), self.reg_a)
    
    def __inst_jump_imm(self, jumploc):
        self.__helper_jump(jumploc)
        
    def __inst_jump_ind(self, indloc):
        self.__helper_jump(self.__mem_read(indloc))
    
    def __inst_add_A_imm(self, val):
        self.reg_a = (self.reg_a + val) % self.VAL_SPACE
    
    def __inst_sub_A_imm(self, val):
        self.reg_a = (self.reg_a - val) % self.VAL_SPACE
    
    def __inst_add_A_stackpop(self, loc):
        self.reg_a = (self.reg_a + self.__helper_stack_pop()) % self.VAL_SPACE
  
    def __inst_sub_A_stackpop(self, loc):
        self.reg_a = (self.reg_a - self.__helper_stack_pop()) % self.VAL_SPACE
        
    def __inst_and_A_stackpop(self, loc):
        self.reg_a = self.reg_a & self.__helper_stack_pop()
        
    def __inst_or_A_stackpop(self, loc):
        self.reg_a = self.reg_a | self.__helper_stack_pop()
        
    def __inst_xor_A_stackpop(self, loc):
        self.reg_a = self.reg_a ^ self.__helper_stack_pop()
    
    def __inst_push_A(self, unused):
        self.__helper_stack_push(self.reg_a)
        
    def __inst_pop_A(self, unused):
        self.reg_a = self.__helper_stack_pop()
        
    def __inst_push_X(self, unused):
         self.__helper_stack_push(self.reg_x)
        
    def __inst_pop_X(self, unused):
        self.reg_x = self.__helper_stack_pop()
        
    def __inst_push_C(self, unused):
         self.__helper_stack_push(self.reg_c)
        
    def __inst_pop_C(self, unused):
        self.reg_c = self.__helper_stack_pop()
        
    def __inst_push_imm(self, val):
         self.__helper_stack_push(val)
         
    def __inst_push_next(self, unused):
        loc = (self.pc + 4) % self.VAL_SPACE
        self.__helper_stack_push(self.__mem_read(loc))
        self.pc = loc
        
    def __inst_push_mem(self, loc):
        self.__helper_stack_push(self.__mem_read(loc))
        
    def __inst_push_ind(self, locmem):
        self.__helper_stack_push(self.__mem_read(self.__mem_read(locmem)))

    def __inst_call(self, dest):
        self.__helper_stack_push(self.pc)
        self.__helper_jump(dest)
        
    def __inst_ret(self, unused):
        self.pc = self.__helper_stack_pop()
        
    def __inst_jif_A_lt_C(self, jumploc):
        if self.reg_a < self.reg_c:
            self.__inst_jump_imm(jumploc)
        
    def __inst_jif_A_ge_C(self, jumploc):
        if self.reg_a >= self.reg_c:
            self.__inst_jump_imm(jumploc)
    
    # helper functions
    
    def __helper_stack_push(self, val):
        self.sp = (self.sp - 4) % self.VAL_SPACE
        self.__mem_write(self.sp, val)
        
    def __helper_stack_pop(self):
        res = self.__mem_read(self.sp)
        self.sp = (self.sp + 4) % self.VAL_SPACE
        return res
    
    def __helper_jump(self, jumploc):
        self.pc = (jumploc - self.INST_SIZE) % self.VAL_SPACE
    
    #
    # END instruction set
    #
    
    def __crash(self, reason='not given'):
        self.crashed = True
        self.halted = True
        self.crash_reason = reason
    
    def __mem_fail_handler(self, should_crash, msg):
        if should_crash:
            self.__crash(msg)
        return self.INVALID_MEM_READ_VAL
 
    def __array_read(self, array, offset):
        return (array[offset] << 24) + (array[offset + 1] << 16) + (array[offset + 2] << 8) + array[offset + 3]
    
    def __array_write(self, array, offset, data):
        array[offset] = (data >> 24) & 0xff
        array[offset + 1] = (data >> 16) & 0xff
        array[offset + 2] = (data >> 8) & 0xff
        array[offset + 3] = data & 0xff
 
    def __mem_read(self, loc, failcrash=True):
        if loc < 0 or loc > self.ADDR_MAX:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x out of bus range 0-0x%08x' % (loc, self.ADDR_MAX))
        if loc % self.INST_SIZE != 0:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x not aligned to %d byte interval' % (loc, self.INST_SIZE))
        
        if loc == self.flagloc:
            return self.__flag_read(loc)
        
        if loc < self.MEM_SIZE:
            if loc == 0:
                return 0
            return self.__array_read(self.mem, loc)
        elif loc >= self.PRG_LOC and loc < self.PRG_LOC + self.PRG_MAX_SIZE:
            return self.__array_read(self.program, loc - self.PRG_LOC)
        else:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x unmapped' % loc)
    
    def __mem_write(self, loc, val, failcrash=True):
        val = val & 0xffffffff
        if loc < 0 or loc > self.ADDR_MAX:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x out of bus range 0-0x%08x' % (loc, self.ADDR_MAX))
        if loc % self.INST_SIZE != 0:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x not aligned to %d byte interval' % (loc, self.INST_SIZE))
        
        if loc == self.flagloc:
            return self.__flag_write(val, loc)
        
        if loc < self.MEM_SIZE:
            if loc == 0:
                self.out_handler(val)
            return self.__array_write(self.mem, loc, val)
        elif loc >= self.PRG_LOC and loc < self.PRG_LOC + self.PRG_MAX_SIZE:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x in read only program area' % loc)
        else:
            return self.__mem_fail_handler(failcrash, 'mem location 0x%08x unmapped' % loc)
        
    def __flag_read(self, loc):
        if self.flaglocked:
            return self.__mem_fail_handler(True, 'mem location 0x%08x unmapped' % loc)
            
        maxi = self.FLAG_SIZE // self.INST_SIZE
        if self.flagindex < maxi:
            res = self.__array_read(self.flag, self.flagindex * 4)
            self.flagindex += 1
            return res
        else:
            return self.__mem_fail_handler(True, 'mem location 0x%08x unmapped' % loc)
    
    def __flag_write(self, val, loc):
        if val != self.flagkey:
            return self.__mem_fail_handler(True, 'mem location 0x%08x unmapped' % loc)
        self.flaglocked = False
        return 0

class RISE_Console(cmd.Cmd):
    def __init__(self, stdin=None, stdout=None):
        cmd.Cmd.__init__(self, stdin=stdin, stdout=stdout)
        if stdin: # custom stdin -> we can't use raw input
            self.use_rawinput = False
        self.prompt = '>>>> '
        self.intro = '\n'.join(['Welcome to the Randomized Instruction Set Emulation (RISE) Console!',
                      'You have been given a machine with instruction codes randomly assigned.',
                      'Try and get it to do what you want!',''])
        self.__new_machine()
        
    def __new_machine(self):
        self.machine = RISE(binascii.unhexlify(FLAG), self.__machine_data_out)
        
    def __machine_data_out(self, data):
        print('Program output 0x%08x' % data, file=self.stdout)
        
    def do_exec(self, line):
        '''Execute a program (given in hex) on the RISE machine instance'''
        try:
            program = binascii.unhexlify(line)
            self.machine.load_program(program)
            print('Program execution begins: \n', file=self.stdout)
            max_inst = 16 * 1024
            self.machine.execute(max_inst)
            if self.machine.halted:
                print('Execution halted.\n', file=self.stdout)
            else:
                print('Maximum of %d instructions exhausted\n' % max_inst, file=self.stdout)
            print('Status:\n' + self.machine.get_state(), file=self.stdout)
        except:
            print('error:', file=self.stdout)
            traceback.print_exc(file=self.stdout)
    
    def do_reset(self, line):
        '''Get a new randomized machine to work with'''
        print('Preparing new machine...', end='', file=self.stdout)
        self.__new_machine()
        print('done.', file=self.stdout)
        
    def default(self, line):
        '''Give error when we have an unrecognized command'''
        print('*** Error: unrecognized command: %s' % line, file=self.stdout)
        return

    do_exit = do_EOF = lambda self,line: True
    do_exit.__doc__ = do_EOF.__doc__  = 'Exit this console'  
 
class RISE_Assembler:
    def __init__(self, rise=None):
        self.rise = rise
        self.namefull = []
        self.nameshort = []
        if self.rise:
            self.namefull = [fn.__name__ for fn in rise.iset]
            self.nameshort = [name.split('inst_')[-1] for name in self.namefull]
        
    def assemble(self, code, int_dump=False):
        tokens = self.lex(code)
        tree = self.parse(tokens)
        if int_dump:
            print('Tokens:\n%s\n' % (str(tokens)))
            print('Parsed:\n%s\n' % (str(tree)))
        return self.gen(tree)
    
    def lex(self, code):
        lines = code.split('\n')
        tokens = []
        for line in lines:
            line = line.split('#')[0] # comments start with '#'
            tcs = filter(lambda x: x != '', re.split('\s', line))
            for tc in tcs:
                tokens.append(self.tokenclass(tc))
        return tokens
 
    def tokenclass(self, s):
        if re.match('0x[0-9a-fA-F]+', s):
            return 'num', int(s, 16) & 0xffffffff
        if re.match('\d+', s):
            return 'num', int(s) & 0xffffffff
        if re.match('\$[0-9a-fA-F]+', s):
            return 'inst', int(s[1:], 16) & 0xff
        if re.match('#\d+', s):
            return 'inst', int(s) & 0xff
        instfind = self.instname(s)
        if instfind:
            return instfind
 
        return 'err', 0
        
    def instname(self, s):
        i = -1
        if s in self.namefull:
            i = self.namefull.index(s)
        if s in self.nameshort:
            i = self.nameshort.index(s)
        if i != -1:
            if 'next' not in s:
                return 'inst', i
            return 'instnext', i
        return False
        
    def parse(self, tokens):
        tree = []
        i = 0
        while i < len(tokens):
            if tokens[i][0] == 'inst':
                if i + 1 < len(tokens) and tokens[i+1][0] == 'num':
                    tree.append({
                        't': 'inst', 
                        'code': tokens[i][1],
                        'val': tokens[i+1][1] & 0xffffff
                    })
                    i += 1
                else:
                    tree.append({
                        't': 'inst', 
                        'code': tokens[i][1],
                        'val': 0
                    })
            elif tokens[i][0] == 'instnext' and i + 1 < len(tokens) and tokens[i+1][0] == 'num':
                tree.append({
                    't': 'instnext', 
                    'code': tokens[i][1],
                    'val': tokens[i+1][1]
                })
                i += 1
            elif tokens[i][0] == 'num':
                tree.append({
                    't': 'data32', 
                    'val': tokens[i][1]
                })
            i += 1
        return tree
        
    def gen(self, tree):
        d = []
        for e in tree:
            if e['t'] == 'inst':
                val = e['val']
                d.extend([e['code'], (val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff])
            elif e['t'] == 'instnext':
                d.extend([e['code'], 0, 0, 0])
                val = e['val']
                d.extend([(val >> 24) & 0xff, (val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff])
            elif e['t'] == 'data32':
                val = e['val']
                d.extend([(val >> 24) & 0xff, (val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff])
        return b'' + bytearray(d)
    

if __name__ == '__main__':
    cmd = RISE_Console()
    cmd.cmdloop()
