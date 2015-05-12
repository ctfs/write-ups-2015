# ASIS Quals CTF 2015: Golden Metal

**Category:** Crypto
**Points:** 300
**Solves:** 21
**Description:**

> The flag is encrypted by this [code](http://tasks.asis-ctf.ir/golden_medal_bfbbc8cf9f1be465ccf2ff9bf17a64b2), can you decrypt it after finding the system?

## Write-up

This challenge is [Goldwasser–Micali cryptosystem](http://en.wikipedia.org/wiki/Goldwasser%E2%80%93Micali_cryptosystem). so, this is a factoring challenge!
I've used the [msieve](http://sourceforge.net/projects/msieve/) to factorization.
```
Mon May 11 09:51:40 2015  Msieve v. 1.52 (SVN Unversioned directory)
Mon May 11 09:51:40 2015  random seeds: c17e5382 d4318f7e
Mon May 11 09:51:40 2015  factoring 1746706403628138819652874617603544146781763497759635411369593250306792101284958553453421021829757 (97 digits)
(snip)
Mon May 11 11:24:41 2015  prp49 factor: 1285380609783825451015579898011805465763518244839
Mon May 11 11:24:41 2015  prp49 factor: 1358902095093762824984385249873903079031552839163
Mon May 11 11:24:41 2015  elapsed time 01:32:47
```

`p , q = 1285380609783825451015579898011805465763518244839, 1358902095093762824984385249873903079031552839163`

Now, we can solve the challenge!

solver code is here:

```python
p = 1285380609783825451015579898011805465763518244839
q = 1358902095093762824984385249873903079031552839163

d = eval(open("enc.txt").read()[5:])
e = ((p-1)*(q-1)+4)/8

m = ""
for x in d:
  k = pow(x, e, p*q)
  if pow(k, 2, p*q) == x:
    m += "0"
  else:
    m += "1"


print m

print ("%x"%int(m, 2)).decode("hex")
```

written by [@elliptic_shiho](http://twitter.com/elliptic_shiho)

## Other write-ups and resources

* [b01lers](https://b01lers.net/challenges/ASIS%202015/Golden%20Metal/53/)
