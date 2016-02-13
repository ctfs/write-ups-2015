# TUM CTF Teaser 2015: pudel

**Category:** Crypto
**Points:** 30
**Solves:** 15
**Description:**

> Baby's 1st
> 
> [pudel.tar.xz](pudel.tar.xz)


## Write-up

by [f0rki](https://github.com/f0rki)

We received the code of the service, which is again written in python
and rather short, and a pcap of a client interacting with the service.
The service basically reads data from the socket and tries to decrypt
it using AES in a self-implemented CBC mode. It will then check the
padding and tell us whether the padding is bad or not. It concludes
by printing `kthx`.

```python
#!/usr/bin/env python3
import os, socket, binascii
from Crypto.Cipher import AES

key = open('key.bin', 'rb').read()

lsock = socket.socket()
lsock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
lsock.bind(('', 1043))
lsock.listen(16)

while True:

  sock, addr = lsock.accept()
  print(addr, end = ' ')

  message = sock.recv(0x100)
  if len(message) < 32 or len(message) % 16:
    print('len')
    sock.send(b'len\n')
    continue

  blocks = [message[i : i + 16] for i in range(0, len(message), 16)]

  aes = AES.new(key, AES.MODE_ECB)
  prev_block = blocks[0]
  blocks = blocks[1:]
  message = b''
  for block in blocks:
    message += bytes(x ^ y for x, y in zip(aes.decrypt(block), prev_block))
    prev_block = block

  n = message[-1]
  if n not in range(1, 17) or any(message[-i] != message[-1] for i in range(1, n + 1)):
    print('bad')
    sock.send(b'bad\n')
    sock.close()
    continue
  message = message[:-n]
  print(binascii.hexlify(message).decode())

  sock.send(b'kthx\n')
  sock.close()
```

So there isn't much interaction going on, so it's rather obvious that
this service acts as a 
[padding oracle](https://en.wikipedia.org/wiki/Padding_oracle_attack).
Also the challenge is called `Pudel`, which is german for poodle, which is the 
name for a prominent SSL vulnerability. So our goal is to use the service
as padding oracle and decrypt the encrypted data in the pcap file.

Padding oracle attacks are pretty cool because they allow you to guess
the content of a ciphertext block byte by byte, which reduces the guess
complexity in our case from `pow(256, 16)` to `256 * 16 == 4096`, which is 
pretty good. The attack works in the following way. We start by guessing
the last byte of the last plaintext block. To check whether the guess was 
correct we change the last byte of the previous ciphertext block to 
`guess ^ c[-2][-1] ^ 0x01`. Because of the way CBC works, this screws up the 
plaintext `p[-2]` and will XOR the value `guess ^ 0x01` to the last byte of 
the last plaintext block `p[-1]`. If we guessed right `guess ^ p[-1][-1] == 0` 
and the last byte of the decrypted plaintext will be `0x01`. This means we 
have a correct padding at the end of the plaintext. If we have guessed
wrong, there will be some other value and we get a bad padding error. We 
then continue guessing the next byte of `p[-1]` but aiming for a two byte 
padding with `0x02` bytes at the end.

This is all a little painful to implement, but fortunately there's a python 
module for that :) I used 
[python-paddingoracle](https://github.com/mwielgoszewski/python-paddingoracle)
and it worked like a charm. After implementing the client that queries
the service for the padding error, all that was left was to wait.

```python
from pwn import *  # NOQA
import socket
from Crypto.Cipher import AES

from paddingoracle import BadPaddingException, PaddingOracle

HOST = "131.159.74.81"
PORT = 1043

# extracted from pcap
encdata = [0xcb, 0x3f, 0x73, 0xdd, 0x38, 0x76, 0x1b, 0x17,
           0x5c, 0x9b, 0x38, 0x07, 0xef, 0x00, 0x46, 0x9b,
           0xd0, 0x9e, 0x46, 0xc3, 0x5f, 0xcd, 0xec, 0x07,
           0xbd, 0x06, 0xab, 0x61, 0x51, 0x82, 0xce, 0x21,
           0x06, 0xc2, 0x02, 0x9f, 0xd5, 0xd0, 0x27, 0x4f,
           0x6c, 0x84, 0x5b, 0x5a, 0x58, 0xaa, 0xfa, 0x2f,
           0xca, 0x23, 0xfb, 0xbd, 0xdb, 0x5d, 0x1c, 0x49,
           0xb3, 0x56, 0x7d, 0x62, 0x97, 0xda, 0x7d, 0x69]

log.info("%d blocks of AES", len(encdata) // AES.block_size)
# split the blocks
bs = AES.block_size
iv = encdata[:bs]
blocks = [encdata[bs:2 * bs],
          encdata[2 * bs:3 * bs],
          encdata[3 * bs:]]

encdata_s = ""
for b in blocks:
    for c in b:
        encdata_s += chr(c)

class PadBuster(PaddingOracle):
    def __init__(self, **kwargs):
        super(PadBuster, self).__init__(**kwargs)

    def oracle(self, data, **kwargs):
        log.info(hexdump(data))
        #rem = remote(HOST, PORT)
        rem = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rem.connect((HOST, PORT))
        rem.sendall("".join(chr(x) for x in data))
        line = rem.recv(5)
        #self.history.append(line)
        log.debug(line)
        if "len" in line:
            raise Exception("length of sent data is wrong!")
        if "bad" in line:
            raise BadPaddingException()
        rem.close()
        del rem


padbuster = PadBuster()
data = padbuster.decrypt(encdata_s, block_size=AES.block_size, iv=iv)
log.info(data)
```

After running the script for some time the flag 
`hxp{ev3n_1n_2015_SSL_st1LL_c4nT_g3t_1t_r1ghT}` appeared.

## Other write-ups and resources

* none yet
