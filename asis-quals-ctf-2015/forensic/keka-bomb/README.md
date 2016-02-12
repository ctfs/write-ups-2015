# ASIS Quals CTF 2015: Keka Bomb

**Category:** Forensic
**Points:** 75
**Solves:** 49
**Description:**

> Find the flag in this [file](http://tasks.asis-ctf.ir/keka_bomb_9e0f1863259c578f3231b5cfbc10e258).

## Write-up

by [polym](https://github.com/abpolym)

We extract the given xz compressed file to find a 7-zip archive:

```bash
+bash-4.3$ file keka_bomb_9e0f1863259c578f3231b5cfbc10e258 
keka_bomb_9e0f1863259c578f3231b5cfbc10e258: xz compressed data
+bash-4.3$ mv keka_bomb_9e0f1863259c578f3231b5cfbc10e258{,.xz}
+bash-4.3$ unxz keka_bomb_9e0f1863259c578f3231b5cfbc10e258.xz 
+bash-4.3$ file keka_bomb_9e0f1863259c578f3231b5cfbc10e258
keka_bomb_9e0f1863259c578f3231b5cfbc10e258: 7-zip archive data, version 0.3
```

Inside the archive, we see a bunch of very big files named `001.7z` to `016.7z`:

```bash
+bash-4.3$ 7z l keka_bomb_9e0f1863259c578f3231b5cfbc10e258 

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Listing archive: keka_bomb_9e0f1863259c578f3231b5cfbc10e258

--
Path = keka_bomb_9e0f1863259c578f3231b5cfbc10e258
Type = 7z
Method = LZMA
Solid = -
Blocks = 16
Physical Size = 9508910
Headers Size = 210

   Date      Time    Attr         Size   Compressed  Name
   ------------------- ----- ------------ ------------  ------------------------
   2015-04-30 03:46:35 ....A   4194304000       594004  001.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  002.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  003.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  004.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  005.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  006.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  007.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  008.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  009.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  010.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  011.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  012.7z
   2015-04-30 03:46:35 ....A   4194304000       598640  013.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  014.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  015.7z
   2015-04-30 03:46:35 ....A   4194304000       594004  016.7z
   ------------------- ----- ------------ ------------  ------------------------
                              67108864000      9508700  16 files, 0 folders
```

Unzipping this file right away looks like a trap - it is a bomb that explodes your hard drive space usage!

However, we see a file that differs in the CRC:

```bash
$ 7z -slt l keka_bomb_9e0f1863259c578f3231b5cfbc10e258.zip | tail -n+17 | sed ':a;N;$!ba;s/\n/ /g' | sed 's/  /\n/g' | sort -k20
Path = 013.7z Size = 4194304000 Packed Size = 598640 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = 36EB76E2 Encrypted = - Method = LZMA:24 Block = 12
Path = 001.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 0
Path = 002.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 1
Path = 011.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 10
Path = 012.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 11
Path = 014.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 13
Path = 015.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 14
Path = 016.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 15 
Path = 003.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 2
Path = 004.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 3
Path = 005.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 4
Path = 006.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 5
Path = 007.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 6
Path = 008.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 7
Path = 009.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 8
Path = 010.7z Size = 4194304000 Packed Size = 594004 Modified = 2015-04-30 03:46:35 Attributes = ....A CRC = ED145EFF Encrypted = - Method = LZMA:24 Block = 9
```

Lets extract `013.7z` to find another bomb (I made an alias for the above command, `7zl`):

```bash
$ 7zl 013.7z 
Path = 0001.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 0
Path = 0002.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 1
Path = 0011.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 10
Path = 0012.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 11
Path = 0013.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 12
Path = 0014.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 13
Path = 0015.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 14
Path = 0016.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 15 
Path = 0003.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 2
Path = 0004.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 3
Path = 0005.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 4
Path = 0006.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 5
Path = 0007.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 6
Path = 0008.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 7
Path = 0010.7z Size = 4194304000 Packed Size = 593444 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 0DAFB4B9 Encrypted = - Method = LZMA:24 Block = 9
Path = 0009.7z Size = 4194304000 Packed Size = 596019 Modified = 2015-04-29 20:32:54 Attributes = ....A CRC = 4D60DC32 Encrypted = - Method = LZMA:24 Block = 8
```

Extract the archive with the unique CRC, remove the last archive and rinse and repeat!

```bash
$ 7z x 013.7z 0009.7z && rm 013.7z
$ 7z x 0009.7z 0000007.7z && rm 0009.7z
$ 7z x 0000007.7z 0000000008.7z && rm 0000007.7z
$ 7z x 0000000008.7z bomb_08 && rm 0000000008.7z
$ 7z l bomb_08

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Error: bomb_08: Can not open file as archive

Errors: 1+
$ file bomb_08
bomb_08: data
```

The remaining file `bomb_08` mostly contains of 0-bytes:

```bash
$ hexdump bomb_08 
0000000 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
*
7d000000 41 53 49 53 7b 66 39 37 34 64 61 33 32 30 33 64
7d000010 31 35 35 38 32 36 39 37 34 66 34 61 36 36 37 33
7d000020 35 61 32 30 62 7d 0a 00 00 00 00 00 00 00 00 00
7d000030 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
*
fa000000
```

The part beginning at `7d000000` is the flag, which we can print using `strings -a`:

```bash
$ strings -a bomb_08
ASIS{f974da3203d155826974f4a66735a20b}
```

The flag is `ASIS{f974da3203d155826974f4a66735a20b}`!

## Other write-ups and resources

* <http://dakutenpura.hatenablog.com/entry/2015/05/12/011233>
* <https://github.com/rentjongteam/write-ups-2015/tree/master/asis-quals-2015/keka-bomb>
* <http://fadec0d3.blogspot.com/2015/05/asis-ctf-2015-keka-bomb-75.html>
* <https://ucs.fbi.h-da.de/writeup-asis-ctf-quals-2015-keka-bomb/>
* [Vietnamese](https://babyphd.net/2015/05/asis-quals-ctf-2015-grids-writeup/)
