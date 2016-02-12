# Hack Dat Kiwi CTF 2015: Simple Stegano

**Category:** Stegano
**Points:** 250
**Solves:** 31
**Description:**

> Just a basic stegano software. Find the message hidden in the original image, and you're good to go. You can hide any message you want in the image too!
> 
> [the-troll.png](./the-troll.png)


## Write-up

by [polym](https://github.com/abpolym)

We are given a PNG and a website that encodes a given string into the same troll picture.

Using [pixels.py](./pixels.py), we determine differences in the pixel values between pictures.

We choose pictures that contain the strings`password1` ([password1.png](./password1.png)) and `qassword0` ([qassword0.png](./qassword0.png)), because they differ at two bits in the string representations.

Using bash's built-in [process substitution](https://en.wikipedia.org/wiki/Process_substitution), we can run a diff between the pixels values between both pictures (`p2` is my alias for python2.7):

```bash
+bash4.3$ diff <(p2 pixels.py password1.png) <(p2 pixels.py qassword0.png)
65286c65286
< 255
---
> 254
66673c66673
< 142
---
> 143
```

Lets have a look at the output. This output means that one pixel value is set to `255` in `password1.png` and `254` in `qassword0.png`.
The first letter in `password1` (`p`) is represented in binary as `01110001`, the first letter in `qassword0` (`q`) is `01110000`.

Do you see the correlation between pixel value and binary representation?
It looks like the binary representation of our message is encoded in the pixel values (`!=0`) by either adding a 1 to the pixel value (`255=254+1`) to the base value of the original picture or not (`254`).

All we have to do is get the [base values](./basenumbers) of the original pictures and subtract the pixel values from the values of our given picture, [the-troll.png](the-troll.png).

The python script [getbinary.py](./getbinary.py) does the job:

```bash
+bash4.3$ p2 getbinary.py the-troll.png | perl -lpe '$_=pack"B*",$_'
In cryptography, a key is a piece of information (a parameter) that determines the functional [...]
[...]
+bash4.3$ p2 getbinary.py the-troll.png | perl -lpe '$_=pack"B*",$_' | grep -Eoi 'the key is .*'
the key is tSJ9F4KY04VLXt7mw3mQhu1LBoE. For the production of small amounts of keying material, ordinary dice provide a good source of high quality randomness.
```

The flag is `tSJ9F4KY04VLXt7mw3mQhu1LBoE`.

Alternative Solution script: [Solution](./stegano.py)

## Other write-ups and resources

* <http://hack.dat.kiwi/writeup#Simple_Stegano>
