# IBTeam Blackvalentine CTF 2015: Forensic1 100

**Category:** Forensic
**Points:** 100
**Author:** mirfansulaiman
**Description:**

> hash , Password: B4JAkL4uT1bUk0t4J4kaRT4
>
> http://ctf.web-attack.info/misssion/6

## Write-up

We are given a password-protected zip, which we can unpack using the provided password `B4JAkL4uT1bUk0t4J4kaRT4`.

This yields a picture `wallpaper.jpg` and yet another password-protected zip `clue.zip`.

Running `exiftool` on the JPEG gives us another clue:

```bash
$ exiftool wallpaper.jpg
[...]
XP Title                        : Musuh betmen
XP Comment                      : OWIxYTgxZmUwYzcyMGMwZGUyMWQ4MTVlNDM1ZDI5MWQ=
XP Author                       : IBTeam Jabodetabek
[...]
```

The `XP Comment` looks base64 encoded, so we decode it using `base64`:

```bash
$ echo OWIxYTgxZmUwYzcyMGMwZGUyMWQ4MTVlNDM1ZDI5MWQ= | base64 --decode
9b1a81fe0c720c0de21d815e435d291d
```

This looks like a MD5 hash, which we can crack using a [hash cracker](https://github.com/YASME-Tim/crypto-tools/tree/master/crackmd5)

```bash
$ python go.py 9b1a81fe0c720c0de21d815e435d291d
We did need [8] tries to crack this md5... damn :(
9b1a81fe0c720c0de21d815e435d291d MD5 :j0k3r
```

We can now unpack the password-protected zip:

```bash
$ 7z x clue.zip -p"j0k3r"

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: clue.zip

Extracting  clue
Extracting  clue/history.txt
Extracting  clue/jokerBrangkas.zip

Everything is Ok

Folders: 1
Files: 2
Size:       1951
Compressed: 1359
```

The `clue/history.txt` file contains a bunch of Indonesian text and the `clue/jokerBrangkas.zip` is another password-protected zip.

Looking at `history.txt`, we see some upper-case and numbers that don't fit in the rest of the text, so we extract these characters hoping that this is the needed password:

```bash
$ cd clue/
$ cat history.txt | grep -oE '[0-9A-Z]' | tr -d '\n'
TP4J4KAPR113UM3B9I4C
$ 7z x jokerBrangkas.zip -p"TP4J4KAPR113UM3B9I4C"

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: jokerBrangkas.zip

Extracting  PL49!.txt

Everything is Ok

Size:       34
Compressed: 192
$ cat PL49\!.txt 
Selamat Coeg !

fL4G0nd0L-j0K3rS
```

The flag is `fL4G0nd0L-j0K3rS` (or something similar, Google Translate didn't help, so minor TODO here :))

## Other write-ups and resources

* none yet
