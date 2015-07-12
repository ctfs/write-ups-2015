# PlaidCTF CTF 2015: Strength

**Category:** Crypto
**Points:** 110
**Solves:** 136
**Description:**

> Strength in Difference
>
> We've [captured](http://play.plaidctf.com/files/captured_827a1815859149337d928a8a2c88f89f) the flag encrypted several times... do you think you can recover it?
>
>
>
> Team	Points	Submission
> gn00bz	114	a day ago
> DatNoobs	112	a day ago
> 0x8F	111	a day ago

## Write-up

### Explanation

The general idea behind recovering the plaintext is the following:

	plaintext^exponent = c1 (mod N)
	plaintext^(exponent+1) = c2 (mod N)
	(c1^-1 * c2) = plaintext (mod N)

With this in mind we have to find `c1` and `c2` value for which the exponent has a difference of exactly one. There is no value provided that directly gives us this value. However it's possible to generate one using the value provided. The following principle is needed:

	plaintext^e = c1 (mod N)
	plaintext^(e*v) = c1^v (mod N)

So we essentially need to find a pair of `a*e1` and `b*e2` for which the difference is exactly one. It's impossible to find such pair if `gcd(e1, e2)` is not one. There's only 2 values in the ones given that match this criteria `71^5` and `29^7`. To find the value of `a` and `b`, we can use this:

	a*e1 + 1 = 0 (mod e2)
	-a * e1 = 1  (mod e2)
	a = (-e1)^-1 (mod e2)
	b = (a*e1 + 1) / e2

After this we just have to use the first formula and get back the original plaintext.

### Code

	import math

	def egcd(a, b):
	  if a == 0:
		return (b, 0, 1)
	  else:
		g, y, x = egcd(b % a, a)
		return (g, x - (b // a) * y, y)

	def inverse_mod(a, m):
	  g, x, y = egcd(a, m)
	  if g != 1:
		raise Exception('Modular inverse does not exist')
	  else:
		return x % m

	M = 0xa5f7f8aaa82921f70aad9ece4eb77b62112f51ac2be75910b3137a28d22d7ef3be3d734dabb9d853221f1a17b1afb956a50236a7e858569cdfec3edf350e1f88ad13c1efdd1e98b151ce2a207e5d8b6ab31c2b66e6114b1d5384c5fa0aad92cc079965d4127339847477877d0a057335e2a761562d2d56f1bebb21374b729743L

	b1 = 0x6fdcbfb5cd2cacd032ef7200fd49b9f304a6dbd8399f4a91a72d1d9150f97b3b513f44dfc56f6f7c8ec41a8ef9b93a80230a1e65e29d2ef519bb83931d4b0c7a589059cfdf2d571660ab790a9c7e085e3018bf19748abd6d521952b68bc9594c1ad34726658bd9bd445d3b6381ceee57328838e8a129867e505be0ca0d1a1da5L
	b2 = 0x8caeaa7d272f9606fee9222efd1d922143db738b95bd64746b27bc4c0fd979a2c57b4735131a4391a81bf5f0c0c8eea41d4f91bed4d17784b1956fd89882b97c98009051ac3a03964499c864524d3ddc10299c0290e91707b62ce89b118afe558151be39d61de0483def52c6cb546132ecab85143715bc593a2892b1e41b37b9L

	a1 = 71**5
	a2 = 29**7

	a = inverse_mod((-a1 + a2*100000) % a2, a2)
	b = (a*a1 + 1) / a2

	p1 = inverse_mod(pow(b1, a, M), M)
	p2 = pow(b2, b, M)

	r = (p1 * p2) % M

	print(r)
	print(hex(r)[2:-1].decode("hex"))

### Flag

`flag_Strength_Lies_In_Differences`

## Other write-ups and resources

* [b01lers](https://b01lers.net/challenges/PlaidCTF%202015/strength/45/)
* [sophia.re](https://www.sophia.re/plaid2015_strength_writeup.html)
* <https://github.com/everping/ctfs/blob/master/2015/4/plaidctf/crypto/strength/solve.py>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/PCTF/crypto/strength>
* <https://neg9.org/news/2015/4/24/plaidctf-2015-strength-in-difference-crypto-110-writeup>
* <http://capturetheswag.blogspot.com.au/2015/04/plaidctf-strength-crypto-110-point.html>
