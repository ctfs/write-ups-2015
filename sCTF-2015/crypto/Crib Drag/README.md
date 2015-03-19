# Crib Drag

**Category:** Crypto
**Points:** 35
**Author:** 
**Description:**

>2d0710181b01111f0817171401071c11091a0a
>3c091311111a1a0e180003120d1a0811091a0a

## Writeup

Using our google-fu, two very great resources emerge... [link 1](http://travisdazell.blogspot.com/2012/11/many-time-pad-attack-crib-drag.html) [link 2](https://cryptocult.wordpress.com/cyber-challenges/stanford-cryptography-i-programs/program-1/)


After loading the python in, we start guessing cribs.
```
"the" gives nothing good.
"you" gives "hav". We should try "have"
"have" gives "youl". We should try "youll"
"youll" gives "havef". We should try "havefun"
"havefun" gives "youllne". We should try "youllnever"
"youllnever" gives "havefungue". We should try "havefunguessing"
"havefunguessing" gives "youllneverguess"
```
It looks like part of our plaintext messages are "havefunguessing" and "youllneverguess", with the end missing. The missing part is the same though, "11091a0a". We should assume "11091a0a" = "this", so our messages are "havefunguessingthis" and "youllneverguessthis"


That's pretty much it. To find the key, we just xor the hex of our plain text with the encrypted to get the flag.
```
xor 2d0710181b01111f0817171401071c11091a0a with 796f756c6c6e65766572677565737374686973
output 54686574776f74696d65706164746f65617379
hextoascii 54686574776f74696d65706164746f65617379 to Thetwotimepadtoeasy
```

## Flag
>Thetwotimepadtoeasy

## Other write-ups and resources


