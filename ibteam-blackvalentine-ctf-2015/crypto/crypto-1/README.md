# IBTeam Blackvalentine CTF 2015: Crypto1 100

**Category:** Crypto
**Points:** 100
**Author:** arieftirta
**Description:**

> * [crypto-1](crypto-1)

## Write-up

The hint suggests that the ciphertexts are related. Ciphertext #1 is very clearly just backwards, giving us the text:
```
"Beware the ARPANET, my son; The bits that byte,"
```
This bears resemblence to the gibberish poem "Jabberwocky" by Lewis Carroll:
```
"Beware the Jabberwock, my son! The jaws that bite, the claws that catch!"
```

Ciphertext #2 is a simple substitution cipher: With some resemblance to the letter patterns and word lengths of the line:
```
"Twas brillig, and the slithy toves did gyre and gimble in the wabe"
```
After doing some letter substitution we arrive at the solution to ciphertext #2:
```
"TWAS BRILLIG, AND THE PROTOCOLS DID USER-SERVER IN THE WABE"
```

Ciphertext #3 is clearly 1337-speak. Applying the original Lewis Caroll line:
```
"All mimsy were the borogoves, and the mome raths outgrabe"
```
to the horribly unreadable leetspeak:
```
qll mi/|\sey wa? the F||?,An|] |he RJ& <>utg|2abe,
```
We get, with some guessing involved:
```
all mimsey was the (AR)?, and the (RJG)? outgrabe,
```

Ciphertext #4 is navajo code, and translates to:
```
THEY HEADSTHAT SCRATCH
```

Putting the lines in the order they appear in the original poem, we get:
```
"Twas brillig, and the protocols did user-server in the wabe
all mimsey was the AR, and the RJG outgrabe,
Beware the ARPANET my son; the bits that byte, they heads that scratch"
```

NOTE: As this was solved after the CTF ended, it's not clear if this reassembled poem was the flag or not, but this at least provides the steps to decrypting the ciphertexts.


## Other write-ups and resources

* none yet
