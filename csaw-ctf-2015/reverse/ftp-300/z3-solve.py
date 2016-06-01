from z3 import *
import sys

# https://wiremask.eu/writeups/csaw-ctf-2015-reverse-300-ftp/
def is_alphanum(x):
    return Or(And(x >= 0x41, x <= 0x5a), And(x >= 0x61, x <= 0x7a), And(x >= 0x30, x <= 0x39))

# Adapted version of https://wiremask.eu/writeups/csaw-ctf-2015-reverse-300-ftp/
def check_a(size):
    xs = [ 0 for i in range(size+1)]
    for i in range(size):
        xs[i] = BitVec("x{}".format(i), 32)
        s.add(is_alphanum(xs[i]))
    xs[size] = BitVecVal(0x0a, 32)

    ret, ecx, edx = BitVecs("ret ecx edx", 32)
    ret = 0x1505

    for x in xs:
            edx = (ret << 5)
            ecx = (edx + ret)
            ret = (x&0xff) + ecx
    return ret

# Minimalized version of http://bruce30262.logdown.com/posts/301425-csaw-ctf-2015-ftp
def check_b(size):
    xs = [ 0 for i in range(size+1)]
    for i in range(size):
        xs[i] = BitVec("x{}".format(i), 32)
        s.add(is_alphanum(xs[i]))
    xs[size] = BitVecVal(0x0a, 32)


    ret = BitVecVal(0x1505, 32)
    for x in xs:
        ret = ( ret << 5 ) + ret + (x&0xff)
    return ret

# http://bruce30262.logdown.com/posts/301425-csaw-ctf-2015-ftp
def check_c(size):
    xs = [ 0 for i in range(size+1)]
    for i in range(size):
        xs[i] = BitVec("x{}".format(i), 64)
        s.add(is_alphanum(xs[i]))
    xs[size] = BitVecVal(0x0a, 64)


    ret = BitVecVal(0x1505, 64)
    for x in xs:
            eax = ret & 0xffffffff
            eax <<= 5
            rdx = eax & 0xffffffff
            rax = (0xffffffff00000000 & eax) | (ret & 0xffffffff)
            ecx = (rdx + rax) & 0xffffffff
            ecx += x & 0xff
            ret = ecx
    return (ret & 0xffffffff)

# Own version
def check_d(size):
    xs = [ 0 for i in range(size+1)]
    for i in range(size):
        xs[i] = BitVec("x{}".format(i), 32)
        s.add(is_alphanum(xs[i]))
    xs[size] = BitVecVal(0x0a, 32)

    I = BitVecVal(0x1505, 32)
    for x in xs:
        #I += (I * 0x20) + (x & 0xff)
        I = (I * 0x21)  + (x & 0xff)

    return I

size = 6


s = Solver()

target = BitVec("hash", 32)
target = 0xD386D209

#ret = check_a(size)
#ret = check_b(size)
#ret = check_c(size)
ret = check_d(size)

s.add(ret == target)

if s.check() == unsat:
    print 'Unsat!'
    sys.exit(1)

model = s.model()

pwdict = {}
for x in model:
    if str(x)[0] != 'x': continue
    pwdict[str(x)[1:]] = chr(model[x].as_long())

pw = ''
for i in range(size):
    pw += pwdict[str(i)]
print 'FTP password is [{}]'.format(pw)
