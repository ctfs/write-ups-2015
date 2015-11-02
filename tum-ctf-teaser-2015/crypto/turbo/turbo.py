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

