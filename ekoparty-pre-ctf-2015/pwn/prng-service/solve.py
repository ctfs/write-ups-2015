from pwn import *
H,P='challs.ctf.site',20003
H,P='localhost',6666
r = remote(H,P)
print r.recvuntil('\n') # Welcome to PRNG service
print r.recvuntil('\n') # Please wait while we generate 64 random numbers...
print r.recvuntil('\n') # Process finished
flag=''
for i in range(-64,-54):
    print r.recvuntil('Choose a number [0-63]?'),
    print i
    r.sendline(str(i))
    resp = r.recvuntil('\n') # Your number is: 0x<hex> \r\n
    resp = resp[18:].rstrip()
    print 'resp: [',resp,']'
    flag+=resp.decode('hex')[::-1]
print flag
