# Boston Key Party CTF 2015: Wood Island

**Category:** Cryptography
**Points:** 150
**Solves:** 90
**Description:**

> You can try to sign messages and send them to the server, 52.0.217.48 port 60231. Sign the right message and you'll get the flag! Only problem---you don't have the signing key. I will give you this, though: sigs.txt is a file containing a bunch of signatures. I hope it helps. (P.S. Don't try and send the exact signatures in that file---that's cheating!) : 150

## Write-up

Writeup by epochfail.

The task was to forge an ElGamal signature of a fixed string, given a collection of signatures. We are also provided with the prime, `p`, and generator element `g`: the public parameters of an ElGamal signing system.

The server reads the signed message as a tuple, `(r, s, m)`, verifying that the signature is valid and not one of the provided strings. If the message checks out (`m == "There is no need to be upset"`), it will send the flag.

#### Analysis

From Wikipedia, we know that ElGamal signature values are constructed from a private key, `x`, and a randomly chosen number, `k`. Then, the `r` value is simply `r := g**k (mod p)`. It also mentions that, if `k` is reused, the signature scheme can be broken with a pair of signatures using the same `k`. This is the case with signatures we have been given: some values of `r`, and therefore `k`, are reused:

```
~/ctf/bkpctf/wood-island $ grep -o '"r": [^,]*' sigs.txt  | sort | uniq -dc
      2 "r": 1559657422442360433717...  # Truncated for brevity
      2 "r": 2403055148312205362471...
      2 "r": 7642569978590436429035...
```

In theory, this is enough to break the signature scheme. But, turns out that two of these signatures are invalid. Consulting with the author...

    <gsilvis> I didn't say they were CORRECT signatures :)

And so we use `elgamal_verify()` from the provided `dsa.py` to filter out invalid tuples. In the end, the tuple with `15596...` remains, and this is our attack vector.

#### Actually solving

From Wikipedia, we know that a signature is correct iff `H(m) = xr + sk (mod p-1)`. Since we have two examples with known `(r, s, m)` and equal `k`, we get a system of equations:

```
H(m_1) = x * r_1 + s_1 * k (mod p-1)
H(m_2) = x * r_2 + s_2 * k (mod p-1)
```
with only `x` and `k` unknown. Solving these for `k`, we note that there is a shared factor of 2 between the modulus and the values we need to invert. Not a problem: we just solve it modulo (p-1)/2, making sure to check both solutions:
```python
# Assume m1, m2 have been hashed and modded.
half = (p - 1) / 2
k = (modinv(s1 - s2, half) * (m1 - m2)) % (p - 1)
assert r1 % p == pow(g, k, p)  # Fails
assert r1 % p == pow(g, k + half, p)  # Succeeds
k += half  # Use this one.
```

Now we can solve it for `x`, the private key:
```python
# We have m1 = x*r + k*s1, thus:
xr = (m1 - k * s1) % (p-1)
# Again, account for shared factor of 2:
x = modinv(r1 / 2, half) * (xr / 2)
x += half
x %= p-1
```

We now construct a correct signature:
```python
k = 3  # Use a different k
r = pow(g, k, p)
m = int(hashlib.sha384("There is no need to be upset").hexdigest(), 16)
s = ((m - x * r) * modinv(k, p - 1)) % (p-1)
assert s != 0, 'Pick a different k'
assert elgamal_verify(r, s, "There is no need to be upset")  # Passes
```

The full signature is thus:
```python
{"s": 3014878633137287394124127653489873288159630923151976475367110860665823037637967007108548419033983397235634088548630635608460601426846110437988798187839907543732012712339535128402199579515311964117424119775352438560229969973347567270238554852248811372675535769778593411780705689239120513635405191218285465254686432764036553625872828345641530781048387734401408069865444002089832141092673760743216330502251238391118869141618294878380090970580806911379005579922080899099717770415409502899325918107535114908790355754386169519151299225168135323147286722969796080575358595404216685633122420151399732715276797035035494161809, "r": 125, "m": "There is no need to be upset"}
```

## Alternative write-up by @mrexcessive

There also was an exploitable bug in the server code, it didn't check the contents of the hash sufficiently - sneaking in an extra key/value pair meant that the elgamal_verify() could be used with one of the supplied triplets.

This challenge was also breakable by exploiting a bug in the server code dsa.py
After getting through the proof/not a robot... step...
You then need to provide a JSON format representation of a hash containing valid r,s,m vals

You can use the entire line with 'm' value "There is no need to be upset" from the supplied sigs.txt file

But... surely this will fail the is_duplicate(sig) test ?
Not if you insert an extra entry into the hash...
See [this code](WoodIsland_try.py) for an example.

Glad of that - 'cos exploit easier than the mathematics!

## Other write-ups and resources

* <http://r3dey3.com/2015-03/bkpctf-wood-island-and-orient-heights/>
* <https://ctfcrew.org/writeup/98>
* [Japanese](http://math314.hateblo.jp/entry/2015/03/02/025356)
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-wood-island.html)
