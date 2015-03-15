# Ghost in the Shellcode 2015: Nikoli

**Category:** Crypto
**Points:** 250
**Description:**

> Find the key! ([File](nikoli-a1039901ded721abdf42e3003725abb265a70386e8b3292b0a4262eaf5693e5b))

## Write-up

The archive contains two files [ciphertext.txt](ciphertext.txt) and [sudoku\_challenge.png](sudoku_challenge.png).

Solving the given sudoku with any online sudoku solver results in this [solution](solution).

The ciphertext is encrypted with a [Hill cipher](http://en.wikipedia.org/wiki/Hill\_cipher), they decryption key is the 3x3 block in the center of the solution.

Solving the Hill cipher with an online [service](https://cloud.sagemath.com/) results in the following cleartext:

> JACKANDJILLWENTUPTHEHILLTOFETCHAPAILOFWATERJACKFELLDOWNANDBROKEHISCROWNANDJILLCAMETUMBLINGAFTERTHEFLAGISCYMOPOLEIA

The python script using the sage libraries is [here](sage_decrypt.py).

I also wrote the encryption/decryption algorithmn in python [here](hilly.py).

## Other write-ups and resources

* <http://blog.tinduong.pw/ghost-in-the-shellcode-2015-write-ups/>
