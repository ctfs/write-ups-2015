# Inc0gnito CTF 2015: leaks-suspected

**Category: Forensic** 
**Points: 150** 
**Solves:** 
**Description:**

> Alice found that important zip file is leaked by an attacker.
>
> The attacker couldn't delete logs.
>
> Analyze a corrupted pcap file and find the leaked file.


## Write-up

by [polym](https://github.com/abpolym)

We are given a broken pcap, which we can't read with `tshark` or `wireshark`.

Applying `strings` on the data blob, we find some ftp transmission messages:

```bash
$ strings leakage.pcap
EMd@
PORT 192,168,112,133,201,90
200 Port command successful
6Me@
STOR key.zip
150 Opening data channel for file upload to server of "/key.zip"
,Mf@
keyUT
73686b696b7475
keyUT
(Mh@
(Mi@
226 Successfully transferred "/key.zip"
(Mj@
421 Connection timed out.
(NS@
```

Looks like a file named key.zip has been uploaded.

Though we cannot read a broken pcap, we can still extract files inside this pcap using `foremost`:

```bash
$ foremost leakage.pcap 
Processing: leakage.pcap
|foundat=keyUT
*|
$ tree output/
output/
├── audit.txt
└── zip
    └── 00000001.zip

1 directory, 2 files
$ cd output/zip/
$ 7z x 00000001.zip -oout

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: 00000001.zip

Extracting  key

Everything is Ok

Size:       15
Compressed: 64684
$ cd out
$ cat key
73686b696b7475
```

`key` here is the hexadecimal representation of the final flag, `shkiktu`.


## Other write-ups and resources

* none yet
