# OpenToAll CTF 2015: Doggie

**Category:** Forensics
**Points:** 50
**Solves:** 49
**Author:** Eriner
**Description:** 

> woof!
> 
> [b927033257a4604c06e791619a4c0713.tar.bz2](b927033257a4604c06e791619a4c0713.tar.bz2)
>
> Hint: Did Eriner really make this challenge?
>
> Hint: It's not encoded.

## Write-up

We are given a dog PNG picture.

Running `pngcheck` on the picture reveals that it is not a PNG, however:

```bash
$ pngcheck a038218191c05846099054a9f21ff22a.png
a038218191c05846099054a9f21ff22a.png  this is neither a PNG or JNG image nor a MNG stream
ERROR: a038218191c05846099054a9f21ff22a.png
```

It's actually a JPEG:

```bash
file a038218191c05846099054a9f21ff22a.png
a038218191c05846099054a9f21ff22a.png: JPEG image data, JFIF standard 1.01
```

We can't find anything interesting using `strings -a` or `binwalk`, so we run `exiftool` on the file to get the metadata of the JPEG:

```bash
$ exiftool a038218191c05846099054a9f21ff22a.png 
ExifTool Version Number         : 9.76
File Name                       : a038218191c05846099054a9f21ff22a.png
Directory                       : .
File Size                       : 790 kB
File Modification Date/Time     : 2015:02:27 11:43:41+01:00
File Access Date/Time           : 2015:03:09 11:16:02+01:00
File Inode Change Date/Time     : 2015:03:09 11:14:29+01:00
File Permissions                : rw-r--r--
File Type                       : JPEG
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Resolution Unit                 : None
X Resolution                    : 1
Y Resolution                    : 1
XMP Toolkit                     : Image::ExifTool 9.76
Author                          : 00ffb.01039.011a9.013e3.013e8.00ffb.01590.015cb.8a461.8a612.8a6f3.8a8a0.b24ce.b2663.b2751.b2663.a2a23.a2a37.a272d.a2742.6d677.57092.57357.36515.5d538
Image Width                     : 1944
Image Height                    : 2904
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:2:0 (2 2)
Image Size                      : 1944x2904
```

We see a strange author and, after some time, see that these are specific hex positions in the JPEG that form the flag.

Extracting the flag is possible through a quick bash cmd:

```bash
$ exiftool a038218191c05846099054a9f21ff22a.png | grep --color=none Author | awk '{print $3}' | sed 's/\.//g' | grep --color=none -o "....." | while read p; do xxd "-s0x$p" -l1 -p a038218191c05846099054a9f21ff22a.png; done | xxd -r -p
flag{fck snow i has hat!}
```

## Other write-ups and resources

* none yet
