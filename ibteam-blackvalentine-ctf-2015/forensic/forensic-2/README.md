# IBTeam Blackvalentine CTF 2015: Forensic2 100

**Category:** Forensic
**Points:** 100
**Author:** mirfansulaiman
**Description:**

> Clue: Wota , Password: `Nz3#s)2=1@./AS|\sas;192Sljd!*&^`
>
> http://ctf.web-attack.info/misssion/7

## Write-up

We are given a password-protected zip and extract it given the given password.

Out comes another encrypted zip file `ke0n9.zip` and a picture `cewe.jpg`.

Running `exiftool` on the picture, we see a suspicious comment:

```bash
$ exiftool cewe.jpg
[...]
Copyright                       : IBTeam Jabodetabek
XP Comment                      : 56 6D 31 34 55 31 4E 74 56 6B 5A 4E 56 57 52 59 59 6B 5A 77 55 46 5A 73 57 6D 46 68 52 6C 4A 56 55 6D 74 30 56 31 5A 75 51 6C 6C 61 52 57 52 48 56 47 78 61 63 31 4E 75 62 46 64 69 57 45 4A 51 56 6C 5A 61 56 31 5A 56 4D 55 56 68 65 6A 41 39
XP Keywords                     : Q29iYSBsYWdpIDp2
[...]
```

We convert this hexadecimal text to ASCII text using `xxd` (and pipe the output into `xxd` to avoid scrambling our shell):

```bash
$ echo '56 6D 31 34 55 31 4E 74 56 6B 5A 4E 56 57 52 59 59 6B 5A 77 55 46 5A 73 57 6D 46 68 52 6C 4A 56 55 6D 74 30 56 31 5A 75 51 6C 6C 61 52 57 52 48 56 47 78 61 63 31 4E 75 62 46 64 69 57 45 4A 51 56 6C 5A 61 56 31 5A 56 4D 55 56 68 65 6A 41 39' | xxd -r -p | xxd
0000000: 566d 3134 5531 4e74 566b 5a4e 5657 5259  Vm14U1NtVkZNVWRY
0000010: 596b 5a77 5546 5a73 576d 4668 526c 4a56  YkZwUFZsWmFhRlJV
0000020: 556d 7430 5631 5a75 516c 6c61 5257 5248  Umt0V1ZuQllaRWRH
0000030: 5647 7861 6331 4e75 6246 6469 5745 4a51  VGxac1NubFdiWEJQ
0000040: 566c 5a61 5631 5a56 4d55 5668 656a 4139  VlZaV1ZVMUVhejA9
```

The output looks base64 encoded. Lets decode it:

```bash
$ echo [...] | xxd -r -p | base64 --decode | xxd
0000000: 566d 7853 536d 5646 4d55 6458 6246 7050  VmxSSmVFMUdXbFpP
0000010: 566c 5a61 6146 5255 526b 7457 566e 4259  VlZaaFRURktWVnBY
0000020: 5a45 6447 546c 5a73 536e 6c57 6258 4250  ZEdGTlZsSnlWbXBP
0000030: 5656 5a57 5655 3145 617a 303d            VVZWVU1Eaz0=
```

Looks like it is a recursive base64 encoded text.

After decoding it layer by layer, we come to a non-base64 encoded text:


```bash
$ echo [...] | [...] | base64 --decode | base64 --decode | xxd
0000000: 4a6b 5434 382d 4b31 6e34 4c              JkT48-K1n4L
```

Using this string `JkT48-K1n4L` as the password for the encrypted zip we get another file `r4cUn`:

```bash
$ 7z x ke0n9.zip -p"JkT48-K1n4L"

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: ke0n9.zip

Extracting  ke0n9
Extracting  ke0n9/r4cUn

Everything is Ok

Folders: 1
Files: 1
Size:       25
Compressed: 286
$ cat ke0n9/r4cUn 
Fl4g ->> D3v1-Kin4L-pUtRI
```

The flag is `D3v1-Kin4L-pUtRI`.


## Other write-ups and resources

* none yet
