# TUM CTF Teaser 2015: bad_apple

**Category:** Crypto
**Points:** 15
**Solves:** 43
**Description:**

> Baby's 1st
> 
> [bad_apple.tar.xz](bad_apple.tar.xz)
> 
> try:
>     ncat 1.ctf.link 1027 < good.bin
> expect:
>     "hello"


## Write-up

by [f0rki](https://github.com/f0rki)

The code for the service is pretty small and given the low amount of
points it will be pretty straight forward. 

The service expects a message with a very simple format:
```
[tag][message]
```
whereas the tag is a `SHA256` hash over a unknown key and the message.
If the service cannot verify the tag it will just print `bad`. Otherwise
if it contains the string `hello pls` it will return the string `hello`
and if it contains the string `flag pls` it will return the flag.

```python
#!/usr/bin/env python3
import sys, binascii
from Crypto.Hash import SHA256

key = open('key.bin', 'rb').read()

message = sys.stdin.buffer.read(0x100)
if len(message) < SHA256.digest_size:
  print('len')
  exit(0)

tag, message = message[:SHA256.digest_size], message[SHA256.digest_size:]

if SHA256.new(key + message).digest() != tag:
  print('bad')
  exit(0)

if b'hello pls' in message:
  print('hello')
if b'flag pls' in message:
  print(open('flag.txt', 'r').read())
```

Additionally we are given the content of `good.bin`, which is a valid message
that contains the `hello pls` string. Obviously our goal is to craft a valid
message that contains the string to print the flag.

If we look at the computation of the tag, it is just `SHA256(K || M)`. This is
a very unfortunate implementation of an HMAC. There is a very good reason that
the standard way of constructing [HMACs is a little more complex](https://en.wikipedia.org/wiki/Hash-based_message_authentication_code).

The reason for this is that all hash functions that are constructed using
the Merkle–Damgård construction are prone to [length extension attacks](https://en.wikipedia.org/wiki/Length_extension_attack). These types of hash
functions basically split the data into blocks of the same size and apply a 
compression function, which updates the internal state of the hash function.
The last block is padded in a standardized way and then the internal state is
the output of the hash function. 

This means that you can take a hash `H(M1)` as the internal state of your hash
function and update it with further data and you receive a valid hash 
`H(M1 || pad || M2)` and you don't even have to know `M1`.

In our case it's the `key` we don't know, but we can construct a valid tag
for the message `"hello pls" + pad + "flag pls"` given the valid message
we have.

To perform the length extension attack we can use the excellent [HashPump](https://github.com/bwall/HashPump)
tool, which even has python bindings now called `hashpumpy` (available via pip).
The only tricky part here is that for a hash length extension attack to work we
need to know the length of `key`. But as it turns out the bruteforce approach worked
pretty well in this case. Here is the attack script:

```python
from pwn import *
from base64 import b16encode, b16decode
from hashpumpy import hashpump

taglen = 256 / 8
tag = None
orig_msg = None
append_msg = "flag pls"

with open("./good.bin") as f:
    tag = f.read(taglen)
    orig_msg = f.read()

log.info("original tag was: \n" + hexdump(tag))
log.info("original message was: " + orig_msg)


def check_for_flag(msg):
    """send msg to service and check if we received the flag"""
    rem = remote("1.ctf.link", 1027)
    rem.send(msg)
    rem.shutdown("write")
    data = rem.recv()
    rem.close()
    if "bad" in data:
        return False
    m = re.search("(hxp{.+})", data)
    if m:
        log.info("hooray found the flag: " + m.groups()[0])
        return True
    log.info("received\n" + hexdump(data))
    return False


def perform_hlext(tag, orig_msg, append_msg, keylen):
    """take the tag and the orig_msg, perform hash length extension
    for the given key length.
    returns [tag][message]"""
    newdgst, newmsg = hashpump(b16encode(tag),
                               orig_msg,
                               append_msg,
                               keylen)
    log.info("hashpump returned: \ndigest: {}\nmsg: {}"
             .format(newdgst, repr(newmsg)))
    return b16decode(newdgst.strip().upper()) + newmsg


# bruteforce the key length
for i in range(256):
    log.info("Trying key length {}".format(i))
    m = perform_hlext(tag, orig_msg, append_msg, i)
    if check_for_flag(m):
        break
```

After running this for a little and looking at some `bad`'s, it will find the right key 
length and we get the flag `hxp{M3rkL3_D4mg4rd_h4s_s0m3_Pr0bl3mZ}`

## Other write-ups and resources

* <https://github.com/ByteBandits/writeups/blob/master/tum-ctf-teaser-2015/crypto/bad_apple/sudhackar/README.md>
