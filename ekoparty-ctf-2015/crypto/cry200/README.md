# EKOPARTY CTF 2015: XOR Crypter

**Category:** Crypto
**Points:** 200
**Solves:** 160
**Description:**

> The state of art on encryption, can you defeat it?
>
> CjBPewYGc2gdD3RpMRNfdDcQX3UGGmhpBxZhYhFlfQA=
> 
> Attachment: [crypto200.zip](./crypto200.zip)


## Write-up

by [elliptic-shiho](https://github.com/elliptic-shiho)

Summary: Breaking XOR(-Right)-Shift

The "cryptor" is using XOR(-Right)-Shift.

XOR(-Right)-Shift is here.
```
y = enc(x) = x ^ (x >> 16)
```

this is very weak, and decrypt function is here:
```
dec(y) {
  x = y & (0b11111111111111111 << 16)
  x += (y ^ (res >> 16)) & (0b111111111111111)
  return x
}
```

so, I wrote this code to solve:

```python
import struct

# cipher text
ct = "CjBPewYGc2gdD3RpMRNfdDcQX3UGGmhpBxZhYhFlfQA=".decode("base64")

# decompose into 4 bytes.(and unpack)
c = []
while len(ct) > 0:
  c += [struct.unpack("I", ct[:4])[0]]
  ct = ct[4:]

# xor-(right)-shift decryptor
def dec_xorshift(x, b=16):
  res = x & (0b11111111111111111 << 32-b);
  res += (x ^ (res >> b)) & (0b111111111111111);
  return res

s = ""
for x in c:
  s += hex(dec_xorshift(x))[2:].replace("L", "").decode("hex")[::-1]
print s
```

flag is `EKO{unshifting_the_unshiftable}`

written by [@elliptic_shiho](https://twitter.com/elliptic-shiho)

## Other write-ups and resources

* <http://capturetheswag.blogspot.de/2015/10/ekoparty-2015-xor-crypter-crypto-200.html>
* <https://ctftime.org/writeup/2049>
* <https://en.internetwache.org/ekoparty-ctf-2015-writeups-24-10-2015/>
* <https://github.com/bl4de/ctf/blob/master/2015/Ekoparty_CTF_2015/XOR_Crypter_Crypto200.md>
* <https://github.com/p4-team/ctf/tree/master/2015-10-22-ekoparty/crpto_200_xorcrypter#eng-version>
* <https://github.com/pcchou/ctf-writeups/tree/master/2015/ekoparty/cry200>
* <http://www.nobbd.de/blog/artikel.php?titel=write-up-Ekoparty-CTF---Crypto-50-100-200#weirdvigenere>
* [Japanese](http://shiho-elliptic.tumblr.com/post/131769380689/ekoparty-ctf-2015-writeup)
