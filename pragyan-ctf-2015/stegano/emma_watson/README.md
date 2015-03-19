# Pragyan CTF 2015: Emma Watson

**Category:** Steganography
**Points:** 100
**Solves** 28
**Description:**

> [the_bling_ring.png](the_bling_ring.png)

## Write-up

We are given a picture of Emma Watson:

![](the_bling_ring.png)

We notice a stream of pixels in the first row of the picture and extract the information using `carve.py` and `this.bmp`:

```bash
$ python carve.py
010101000110100001100101010111110110001001100101011000010111010101110100011110010101111101101111011001100101111101110000011000010111001001100001011001000110100101110011011001010101111101101001011100110101010001101000011001010101111101100010011001010110000101110101011101000111100101011111011011110110011001011111011100000110000101110010011000010110010001101001011100110110010101011111011010010111001101010100011010000110010101011111011000100110010101100001011101010111
```

After that, we just decode this binary string to an ASCII string:

```bash
$ python carve.py | perl -lpe '$_=pack"B*",$_'
The_beauty_of_paradise_isThe_beauty_of_paradise_isThe_beaup
```

The flag is `The_beauty_of_paradise_is`.

## Other write-ups and resources

* none yet
