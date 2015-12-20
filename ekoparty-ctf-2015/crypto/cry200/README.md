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

* none yet
