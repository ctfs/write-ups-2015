# ASIS Quals CTF 2015: FalseCrypt

**Category:** Crypto
**Points:** 450
**Solves:** 3
**Description:**

> Connect there: 
>
> nc 217.218.48.84 12431

## Write-up

Ok, let's see what to do with the challange with the most points in this contest. It took me a long time to understand, how this is working and again a lot of time to get the output correct. However, solving was quite easy.

**First step**
> A Cryptosystems that uses public-key cryptography, as it is very small could be use for embeded systems as

> well as for servers and so on. It's been said that it's performance is much better than RSA and and can't 

> be broken by Shor's algorithm.

> What's the name of this cryptosystem?

This is how  you are welcomed on the server. So, we are looking for public-key cryptosystem that can't be broken by Shor's algorithm. Google knows the answer: NTRU

In Wikipedia: (http://en.wikipedia.org/wiki/NTRUEncrypt)

Math on polynoms: (https://www.securityinnovation.com/uploads/Crypto/NTRU%20Algebra%20Tutorial.pdf)

With a good example: (http://people.scs.carleton.ca/~maheshwa/courses/4109/Seminar11/NTRU_presentation.pdf)

Never heard about it. I was looking a long time to find good explanations. The Math was helpful to know, how to code the functions and the 3rd link had some examples to test everything.

Ok, let's see what we have to do.

**Encryption**
After the first question, we have to crack the NTRU cryptography (correct and fast, as always):
> pubkey:

> (5, 3, 16, 10*x^4 + 4*x^3 + 6*x^2 + 11*x + 14)

> enc: 15*x + 15

The public key is (N, p, q, h), the ciphertext (enc) e

| Variable | Explanation |
|----------|----------------|
| N | Integer, Modulus for exponent |
| p | Integer(small), Modulus for coefficients |
| q | Integer(large), Modulus for coefficients |
| h | Polynom |
| e | Polynom, ciphertext |

So, how does NTRU encryption work?
* Choose random polynom r with coefficients from (0, 1, -1)
* Convert message to polynom m with coefficients from (0, 1, -1) (Though the solution in the challange was the the polynom itself.)
* e = r * h + m (mod q)

We can crack the polynom h to be able to calculate the private key and than decrypt the whole message. But I didn't understand how this works and it looked like a lot of work.

So, we have small values everywhere. Why not Brute-force the random r and the message m? Both r and m are polynoms with N coefficients from the values (0, 1, -1). So 3^10 = 59049 possibilites.

So, I implemented the polynom arithmetic, a parser for the polynoms(sig) and a recursive function to generate the r and m. Then I tried these values, took the solution and sent it back to the server. And after one hundred tries, I finally fixed all presentation bugs etc. and the server accepted my decrypted message.

But as usual, parameter sizes increased. I changed the hardcoded N, p and q to variable values and continue. After 2 or 3 stages, the polynom was too big to bruteforce.

**Optimization**
Bruteforcing 2 * N coefficients took too long time, so I optimized.

> e = r * h + m (mod q)

> e - r * h = m (mod q)
 
I know e, h and q.  So, I changed my algorithm to only brute-force r and then calculated mN. I just had to check, if m is a valid message polygon (coefficientes = 0, 1, -1). As a result, I only had N coefficientes to brute-force. Tis took some time, but was still fast enough.

After 4 levels, the server answered with:
ASIS{b8eaee716e1d7e29b88b31e84272c6c2}

Was easier than it looked liked. Just find the one important function in the whole process and mess around with polygon parsing / writing.

## Other write-ups and resources

* none yet
