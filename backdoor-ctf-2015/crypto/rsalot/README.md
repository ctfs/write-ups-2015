# backdoor CTF 2015: [RSALOT](https://backdoor.sdslabs.co/challenges/RSALOT)

**Category:** Crypto
**Points:** 250
**Author:** [Abhishek Das](https://backdoor.sdslabs.co/users/abhshkdz)
**Difficulty:** TODO
**Solves:** 31
**Description:** 

* <https://backdoor.sdslabs.co/challenges/RSALOT>

> The flag is encrypted using a system that makes use of prime factorization of large numbers. Decrypt the flag from [this](http://hack.bckdr.in/RSALOT/RSALOT.tar.gz).

## Write-up

We are given 100 public keys with the names `1.pem`-`100.pem`, as well as a `flag.enc` that contains our base64 encoded ciphertext.

After understanding what RSA does, e.g. with [this nice quick overview](http://doctrina.org/How-RSA-Works-With-Examples.html) containing all basic mathematical concepts needed to understand RSA as well as an explaination of RSA by example.

We need to understand following:

* A public key is composed of the pair `(n,e)` - the modulus `n` and the public exponent `e`
* A private key is composed of the pair `(n,d)` -  the modulus `n` and the private exponent `d`
* Decrypting a ciphertext is taking the integer value of a ciphertext to the private exponent and applying modulo `n` to it - `c^d mod n = m`
* Encrypting a message is taking the integer value of a message to the public exponent and applying modulo `n` to it - `m^e mod n = c`
* A modulus `n` is composed of a multiplication of two (large) prime numbers `p` and `q`
* This multiplication is a trapdoor - easy in one way (multiplication), difficult in the other (factoring)
* The totien `phi(n)` can be calculated as follows: `phi(n) = phi(p*q) = (p-1)*(q-1)`
* The public exponent `e` is chosen in the range `[3,phi(n)[`, often `65537` as it is in this case
* The private exponent `d` is calculated using the `phi(n)` modular multiplicative inverse of `e` so that `e*d = 1 mod phi(n)`
* Private components are therefore `p`, `q`, `d` and `phi(n)`
* Public components are therefore `e` and `n`
* [OAEP](http://en.wikipedia.org/wiki/Optimal_asymmetric_encryption_padding) Padding is used to avoid several attacks against RSA

Using `openssl rsa -pubin -inform PEM -noout -text -modulus < x.pem` for each public key, we see that the same public exponent `e=65537` has been used and different moduli have been created.

Our guess of an attack given many public keys is that some private components are reused in the computation of a public key, i.e. `p`, `q` or `d`.

E.g. we have two moduli `na=p_1*q_1` and `nb=p_1*q_2`, we can find the greatest common divisor of both numbers, which is `p_1`. If there is no such common divisor, we get as result `1`, since the primes of both moduli are not part of the other.

After finding such a `gcd(na,nb)!=1`, we divide `nb` by `p_1` to get `q_2`: `nb/p_1 = (p_1*q_2)/p_1 = q_2` and can calculate `d` using the modular multiplicative inverse of with the help of the extended euclidian algorithm.

Finally, we get the decimal representation of the base64 decoded ciphertext and apply the decryption function on the ciphertext `c` using the private exponent `d` and the modulus `n` as previously mentioned.

[This script](rsasolve.py) does exactly that. The public keys, which moduli do have common primes, are `64.pem` and `87.pem`. `flag.enc.2` is the base64 decoded hexadecimal representation of `flag.enc`, which can be created using this command `cat flag.enc | base64 --decode | xxd -p | tr -d '\n'`.

To generate the private key `private.pem` with the knowledge of `p` and `q`, we use [rsatool.py](https://github.com/ius/rsatool):

```
python rsatool.py -p 168736462866079204789584058199620418225526506348478399447895958829038354002285480486576728303147995561507709511105490546002439968559726489519296139857978907240880718150991015966920369123795034196767754935707681686046233424449917085120027639055362329862072939086970892956139024391556483288415208981014264336691 -q 139208418683860744636489594107518498051692876942105482068436575406002091300025595750940476658875774324613311765708231971440632450100860632595797604226237831396754383891914573698131769762436941837224713009721577421233571830899874638297795728204831707647487557389464078420524002550428515370686466308350190419191 -o private.pem
```

However, we have to add OAEP padding to reimplement a correct encryption/decryption function. This time, searching the [2014 writeup repo](https://github.com/ctfs/write-ups-2014/tree/master/asis-ctf-finals-2014/rsa-in-real-world) for the needed code gives us a [decrypt function](decrypt.py):

```bash
$ python decrypt.py 
the_flag_is_b7[...]
```



## Other write-ups and resources

* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/BACKDOORCTF/crypto/rsalot>
* <https://gist.github.com/Bono-iPad/e908ddc67b3994069950>