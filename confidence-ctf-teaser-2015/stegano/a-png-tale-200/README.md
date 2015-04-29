# CONFidence CTF Teaser A PNG Tale

**Category:** Steganography
**Points:** 200
**Solves:** 43
**Description:**

> Find the flag hidden in this [PNG file](hidden.png).

## Write-up

Note: This writeup is based on [This Writeup](http://mail.pri-vate.net/tmp/writeup-CONFidence_DS_CTF_2015-200stegano-A_PNG_Tale.txt).

We are given a 800x800 PNG picture that seemingly contains no hidden information on first sight:

![](hidden.png)

Examining the picture with common steganotools such as `stegsolve` or `outguess` and hexeditors, we also don't see anything obvious.

However, PNG applies certain [filters](http://www.w3.org/TR/PNG-Filters.html) ([more](http://www.libpng.org/pub/png/book/chapter09.html).[source](http://en.wikipedia.org/wiki/Portable_Network_Graphics#Filtering)) before compression.

There are several filter types that can be applied, such as `None` (byte `0x0`), `Sub` (byte `0x1`), `Up` (byte `0x2`) etc.

Bytes of these filter types can be used to hide information, i.e. the flag, in the PNG.

In our case, we have to decompress the PNG `IDAT` chunk data and extract the filter type bytes from the decompressed data.

[This script](png_filters.py) does exactly that:

```bash
$ python png_filters.py hidden.png 
PNG Signature: ('\x89', 'P', 'N', 'G', '\r', '\n', '\x1a', '\n')
Pos : 8
Type: IHDR
Size: 13
CRC : 5412913F

Pos : 33
Type: IDAT
Size: 10980
CRC : 98F96EEB

Pos : 11025
Type: IEND
Size: 0
CRC : AE426082

Data length in PNG file :  10980
Decompressed data length:  1920800
Flag: DrgnS{WhenYouGazeIntoThePNGThePNGAlsoGazezIntoYou}
```

The flag is `DrgnS{WhenYouGazeIntoThePNGThePNGAlsoGazezIntoYou}`.

## Other write-ups and resources

* <http://mail.pri-vate.net/tmp/writeup-CONFidence_DS_CTF_2015-200stegano-A_PNG_Tale.txt>
