# IBTeam Blackvalentine CTF 2015: Forensic5 100

**Category:** Forensic
**Points:** 100
**Author:** abdilahrf
**Description:**

> hohohahiho  , Password: `P3nYimP4n94NG+_::{127.0.0.1}`
>
> http://ctf.web-attack.info/misssion/11

## Write-up

by [polym](https://github.com/abpolym)

We are given a password protected zip that we extract using `7z x Forensic-5.zip -p'P3nYimP4n94NG+_::{127.0.0.1}' -oout`.

Two files are extracted - another password encrypted zip, `Koala.zip`, and an ASCII file `passwd.txt`, which just contains `SHA256 : BINARY`.

`passwd.txt` suggests to use the sha256 of binary as password for the second password protected zip.

However, using the sha256 hash of `BINARY` as password for `Koala.zip` doesn't work.

The authors were quite cheeky and meant to use the binary representation of SHA256 as password:

```bash
$ 7z x Koala.zip -p'01010011 01001000 01000001 00110010 00110101 00110110'

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: Koala.zip

Extracting  Koala.jpg

Everything is Ok

Size:       789101
Compressed: 780128
```

We get a picture of a Koala bear and have a look at the exif metadata using `exiftool`:

```bash
$ exiftool Koala.jpg 
ExifTool Version Number         : 9.99
File Name                       : Koala.jpg
Directory                       : .
File Size                       : 771 kB
File Modification Date/Time     : 2014:11:11 17:33:29+01:00
File Access Date/Time           : 2015:12:26 02:39:38+01:00
File Inode Change Date/Time     : 2015:12:26 02:39:34+01:00
File Permissions                : rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.02
DCT Encode Version              : 100
APP14 Flags 0                   : (none)
APP14 Flags 1                   : (none)
Color Transform                 : YCbCr
Exif Byte Order                 : Big-endian (Motorola, MM)
Image Description               : Could this be the flag? : Tm9wZSAsIG5vdCBoZXJlIDspCg==
Make                            : http://indonesianbacktrack.or.id
Camera Model Name               : 0x12999 Mega Pixel
Modify Date                     : 2009:03:12 13:48:28
Artist                          : MO
Copyright                       : OR ,  All Rights Reserved.
Date/Time Original              : 2008:02:11 11:32:43
Create Date                     : 2008:02:11 11:32:43
Sub Sec Time Original           : 17
Sub Sec Time Digitized          : 17
XP Title                        : Could this be the flag? : Tm9wZSAsIG5vdCBoZXJlIDspCg==
XP Comment                      : XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX..AABA ABAA AB BBA BBBAAA BAB AAAAB ABBA B AAABB BA ABBA AAAAB B ABBBB BB AAB ABA AAAAB..Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras faucibus odio ut metus vulputate, id laoreet magna..volutpat. Integer nec enim vel arcu porttitor egestas
XP Author                       : MO
XP Keywords                     : SE
XP Subject                      : <| tr AB .- |>
Padding                         : (Binary data 2060 bytes, use -b option to extract)
Compression                     : JPEG (old-style)
X Resolution                    : 96
Y Resolution                    : 96
Resolution Unit                 : inches
Thumbnail Offset                : 5758
Thumbnail Length                : 6625
Quality                         : 100%
XMP Toolkit                     : Adobe XMP Core 4.1-c036 46.276720, Mon Feb 19 2007 22:40:08
Marked                          : True
Web Statement                   : http://pro.corbis.com/search/searchresults.asp?txt=42-15564978&openImage=42-15564978
Rights                          : OR ,  All Rights Reserved.
Creator                         : MO
Subject                         : SE
Title                           : Could this be the flag? : Tm9wZSAsIG5vdCBoZXJlIDspCg==
Description                     : Could this be the flag? : Tm9wZSAsIG5vdCBoZXJlIDspCg==
Rating                          : 4
Warning                         : [minor] Fixed incorrect URI for xmlns:MicrosoftPhoto
Rating Percent                  : 63
Lens Manufacturer               : CODE
Last Keyword XMP                : SE
Image Width                     : 1024
Image Height                    : 768
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:4:4 (1 1)
Image Size                      : 1024x768
Megapixels                      : 0.786
Create Date                     : 2008:02:11 11:32:43.17
Date/Time Original              : 2008:02:11 11:32:43.17
Thumbnail Image                 : (Binary data 6625 bytes, use -b option to extract)
```

The base64 encoded string `Tm9wZSAsIG5vdCBoZXJlIDspCg==` is a red herring:

```bash
$ echo 'Tm9wZSAsIG5vdCBoZXJlIDspCg==' | b64d | xxd
0000000: 4e6f 7065 202c 206e 6f74 2068 6572 6520  Nope , not here 
0000010: 3b29 0a                                  ;).
```

But we see a string that only consists of `A` and `B`:

    AABA ABAA AB BBA BBBAAA BAB AAAAB ABBA B AAABB BA ABBA AAAAB B ABBBB BB AAB ABA AAAAB

This looks like morse-code, so we translate it to real morse-code:

```bash
$ echo 'AABA ABAA AB BBA BBBAAA BAB AAAAB ABBA B AAABB BA ABBA AAAAB B ABBBB BB AAB ABA AAAAB' | tr 'AB' '.-'
..-. .-.. .- --. ---... -.- ....- .--. - ...-- -. .--. ....- - .---- -- ..- .-. ....-
```

Decoding this morse-code using [an online morse-code decoder](https://gc.de/gc/morse/), we get the flag `flag:k4pt3np4t1mur4`.
## Other write-ups and resources

* none yet
