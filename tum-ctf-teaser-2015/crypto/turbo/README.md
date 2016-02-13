# TUM CTF Teaser 2015: turbo

**Category:** Crypto
**Points:** 100
**Solves:** 13
**Description:**

> Here's some kind of semi-secure shell, however we don't have the key. Can you obtain the secret nevertheless?
> 
> nc 1.ctf.link 1033
> 
> [turbo.py](turbo.py)


## Write-up

by [f0rki](https://github.com/f0rki)

This was a fun challenge. Again the service is written in python. This services seems
to involve two secrets we don't know. We can send a password and a command, if the 
password is correct it will be executed. The flag and the output are then encrypted
with AES-CBC and an unkown key.

```python

#!/usr/bin/env python3
from Crypto.Cipher import AES
import binascii, gzip, subprocess

try:
    pw, cmd = input().split(' ', 1)
except ValueError:
    exit(1)

goodpw = open('password.txt', 'r').read().strip()
assert len(goodpw) >= 32

key = open('key.bin', 'rb').read()
assert len(key) in AES.key_size
iv = open('/dev/urandom', 'rb').read(AES.block_size)
assert len(iv) == AES.block_size
aes = AES.new(key, AES.MODE_CBC, iv)

flag = open('flag.txt', 'r').read().strip()

r = b''
r += 'Today\'s special: {}.\n'.format(flag).encode()
if pw == goodpw:
    r += subprocess.check_output(cmd, shell = True)
else:
    r += 'Wrong password: {}.\n'.format(pw).encode()

padded = gzip.compress(r)
padded += bytes([AES.block_size - len(padded) % AES.block_size or AES.block_size])
padded += b'\0' * (AES.block_size - len(padded) % AES.block_size)

print(binascii.hexlify(iv + aes.encrypt(padded)).decode())
```

The password is at least 32 bytes long, so too long to guess. But if we take a closer
look at the code, we see that the data is compressed before it is encrypted. Furthermore
we control parts of the output, because the password is added to the encrypted data.
We can use the service as an oracle, by abusing the compression. Remember 
[CRIME](https://en.wikipedia.org/wiki/CRIME) and 
[BREACH](https://en.wikipedia.org/wiki/BREACH_%28security_exploit%29)?

So the way this attack works is that we will guess the flag byte by byte and supply
our guess of the flag as the password. The flag is already in the data that is
compressed. If we guessed the flag correctly the compression will remove this
redundant data and we will see no increase in length. If we guessed wrong we will
see longer data. The tricky part here is that we won't see a change in length if 
the bytes we are guessing are not at the "boundary" of a cipher block. But this
is relatively easy to achieve by gradually filling the supplied data with random
characters, that probably won't be compressed, until we see a length change. 

One thing that puzzeled me while playing around is that there is a bug in the padding
code. If you have zero bytes of padding you will get an additional ciphertext block, 
filled with `0x01` bytes. Fortunately this doesn't matter much for the attack, we just
have to make sure that there is always 2 bytes padding in the last block.

In this case we know that the flags start with `hxp{`. So we can start by checking
whether this increases the length of ciphertext. Of course we have to account for 
the bytes that the backreference that is added by gzip needs. As expected it
didn't increase the length, so we are on a good track. Now we have to guess
the following bytes, of which we can assume they are printable. So we start
by supplying `hxp{a`, `hxp{b` etc. until we receive a ciphertext that has
the same length as only `hxp{`. Then we have guessed correct and we can continue
with the next byte: `hxp{1a`, `hxp{1b` etc. I wrote the following script to solve
the challenge:

```python
import sys
from pwn import remote, log, context, process
import string
import zlib

#context.log_level = 'debug'
BLKSIZE = 16
#doremote = True
doremote = False


def get_length(inp):
    rem = None
    inp = inp + " a"
    if doremote:
        rem = remote("1.ctf.link", 1033)
        rem.sendline(inp)
        rem.shutdown("write")
        ret = rem.recvline().strip()
        rem.shutdown("read")
    else:
        rem = process("./turbo.py")
        out, err = rem.communicate(inp + "\n")
        ret = out.strip()
        log.info("\n".join(ret.split("\n")[:-1]))
        ret = ret.split("\n")[-1].strip()
        if err:
            log.info(err)
    rem.close()
    del rem
    if not ret:
        raise Exception("Received empty response!")
    return len(ret) / 2 / BLKSIZE


printables = string.digits + "_" + string.ascii_letters
printables = printables[::-1]


# We can find out how long the flag is by gradually increasing the length of
# the password we supply. If we get another block of encrypted data, we know we
# filled up the padding. Therefore we know how much padding there is given an
# empty password. We can then calculate the length of the flag by subtracting
# the length of the padding and the other known plaintext. The only thing
# that's left must be the length of the flag. At least that's the idea. For
# some reason (I guess gzip) this isn't working so well...
flaglen = 0
minlen = get_length("")
datalen = len(zlib.compress('Today\'s special: .\nWrong password: .\n', 9))
padlen = 0
pl = minlen
for i in range(1, BLKSIZE):
    log.info("trying {} chars".format(i))
    l = get_length(printables[:i])
    log.info("got length {}".format(l))
    if l != pl:
        padlen = i + 1
        break
log.info("deduced padding length {}".format(padlen))
flaglen = ((minlen - 1) * 16) - datalen - padlen
flaglen -= 2  # to account for padding bug
log.info("flag must be {} bytes long".format(flaglen))

#sys.exit(0)

#### some testing

# the password will be the guessed flag.
# "hxp{" + guess
log.info("Trying hxp{ flag prefix")
s = printables[:(padlen - 2)]
log.info(s)
pl = get_length(s)
assert pl == minlen
s = printables[:(padlen - 4)] + ""
x = s + "hxp{"
log.info(x)
l = get_length(x)
assert l == minlen

if not doremote:
    testflag = open("./flag.txt").read().strip()
    # these strings will be compressed and replaced by a ref to lz dictionary
    for teststr in ("hxp{1", "hxp{1_r3", testflag):
        x = s + teststr
        log.info(x)
        l = get_length(x)
        assert l == minlen, "teststr not compressed: " + repr(teststr)

    x = s + "hxp{X"
    log.info(x)
    l = get_length(x)
    assert l > minlen


#### The actual flag bruteforcing,
# byte by byte using the compression oracle

# block boundary, # bytes that can be added before next block
# the padding length from above - some guesssed value (because of gzip? I don't
# know)
BB = padlen - 4
# the guess results
previous = []
pl = 0
for i in range(len(previous), flaglen):
    log.info("guessing character number {}".format(i))
    test = "hxp{" + "".join(previous)
    test = printables[:BB] + test
    log.info("trying prefix: " + test)
    pl = get_length(test)
    log.info("got length = {}".format(pl))
    foundit = False
    for c in printables + "}":
        test = "hxp{" + "".join(previous)
        test = printables[:BB] + test + c
        log.info("trying prefix: " + test)
        l = get_length(test)
        log.info("l = {}, pl = {}".format(l, pl))
        if l == pl:
            log.info("deduced next char: " + c)
            previous.append(c)
            foundit = True
            break
        else:
            log.info("guess was wrong")
    if foundit:
        log.info("Current flag prefix guess is hxp{{{}"
                 .format("".join(previous)))
    else:
        log.error("Couldn't guess char {}".format(i))
    if previous[-1] == "}":
        break

flag = "hxp{" + "".join(previous)
if flag[-1] != "}":
    flag += "}"
log.info("final flag should be " + flag)

with open("./real_flag.txt", "w") as f:
    f.write(flag)
```

Running the script will guess the flag byte for byte. Unfortunately I didn't manage to 
complete the script in time and it finished guessing only a few minutes after the CTF 
ended. The service was still up so I got the flag `hxp{1_r34LLy_L1k3_0r4cL3s__n0T_7h3_c0mp4nY}` 

## Other write-ups and resources

* none yet
