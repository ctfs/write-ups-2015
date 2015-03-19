#I Like Bacon 

**Category:** Crypto
**Points:** 15
**Author:** 
**Description:**

>... .- -- ..- . .-.. ..--.- -- --- .-. ... . ..--.- .. ... ..--.- -.-. --- --- .-.. ..--.- -... ..- - ..--.- -... .- -.-. --- -. ..--.- .. ... ..--.- -.-. --- --- .-.. . .-. ..--.- -... .- .- -... -... .- .- -... -... -... .- -... .- .- .- -... .- .- -... .- .- -... .- .- .- -... .- .- -... .- -... .- .- -... -... .- .- -... -... -... .- .- -... .- .- .- .- -... .- -... .- -... .- -... -... .- .- .- .- .- .- .- -... -... .-


## Writeup
This is a cryptography question. Looking at it, the question appears to be in [morse code](http://en.wikipedia.org/wiki/Morse_code). Plugging that into a morse code decrypter, we get the following message:

```
SAMUEL MORSE IS COOL BUT BACON IS COOLER BAABBAABBBABAAABAABAABAAABAABABAABBAABBBAABAAAABABABABBAAAAAAABBA
```

The returned string seems to contain some sort of diss and a new ciphered text. 

```
BAABBAABBBABAAABAABAABAAABAABABAABBAABBBAABAAAABABABABBAAAAAAABBA
```

Looking up [Bacon cipher](http://en.wikipedia.org/wiki/Bacon%27s_cipher), we find what the second message was encoded with. Utilizing an online decipher we receive the flag.

## Flag

>THISISTHEFLAG

## Other write-ups and resources


