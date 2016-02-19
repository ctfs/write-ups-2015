# ASIS Quals CTF 2015: Zrypt

**Category:** Forensic
**Points:** 200
**Solves:** 19
**Description:**

> Download [file](http://tasks.asis-ctf.ir/zrypt_6a370fc7e33aa5f6a44a2be4999c4966) and find the flag.

[Alternative download](https://mega.nz/#!aAU2mJbQ!USGve99wek6A10RR0ky459TlkG2P1-3yQfRZv4j3Jqw)

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups:

* <https://xmgv.wordpress.com/2015/05/11/asis-ctf-quals-2015-zrypt/>
* <http://www.thice.nl/asis-ctf-2015-write-ups/>

For more information on `pkcrack`, on why this works and for a more detailed write-up, please read the write-ups mentioned above.

We are given a xz compressed pcap traffic dump that we first decompress using `unxz` and then open with `wireshark`.

Looking at the HTTP packets, we see seven GET HTTP requests to the host `a.asis.io`:

* `BOQqupmS`
* `E0frzRAi`
* `EO4qqhn8`
* `EX8UPdUb`
* `VuwP09eM`
* `YupE1RB8`
* `xnCub4eW`

Trying to export the Objects (`File->Export Objects->HTTP...`) did not work in my case (OS X), so I had to manually save them by following the TCP Stream (`Analyze->Follow->TCP Stream`) and then save the packet as a binary data (`Show data as RAW`, then `Save as...`).

We then have seven encrypted zip files given that each contain two other files:

```bash
$ file *
BOQqupmS: Zip archive data, at least v2.0 to extract
E0frzRAi: Zip archive data, at least v2.0 to extract
EO4qqhn8: Zip archive data, at least v2.0 to extract
EX8UPdUb: Zip archive data, at least v2.0 to extract
VuwP09eM: Zip archive data, at least v2.0 to extract
YupE1RB8: Zip archive data, at least v2.0 to extract
xnCub4eW: Zip archive data, at least v2.0 to extract
$ sha256 *
3a4751eaeecd1be4624e378db9ed8dbff55bc290f01ffeab06ec2f90d71dc65c  BOQqupmS
7e55684baa112ed2b053fc351fae1fe8a1c59ea5efe995a80f76ecef60ff2461  E0frzRAi
66a2cc46df3910b6a4c9a234c4fdbefe6ff1473479f5bb09b3e5eb24442aa9f4  EO4qqhn8
8e8576584c5576b968e8f327a99a63b11cc9eaff2dbd7c3dbc2e0cb85ac957bc  EX8UPdUb
7667d3eabaade9d66f0228c7eeda9f41a52c106ee04b0b7af7d9a409648707cc  VuwP09eM
a61c419281ea93dee466e8ac1947fc51be801d28ce776d4162a8b2479f0f6c72  YupE1RB8
f4a6f087f6dc4cde6c6c245f58489cd23d80848de267c7d6319494a61bbf9224  xnCub4eW
$ ll -Sr | awk '{print $9}' | grep -v '\.' | while read line; do [[ ! -z "$line" ]] && zipinfo "$line"; done
Archive:  VuwP09eM   91319 bytes   2 files
-rwxrw-rw-  3.0 unx    90927 BX defN 13-Apr-15 13:50 9Ux)@Zzr1h03PA#p&#u~JWWgUtpF
-rwxrw-rw-  3.0 unx       38 TX stor 13-Apr-15 12:53 flag.txt
2 files, 90965 bytes uncompressed, 90779 bytes compressed:  0.2%
Archive:  EO4qqhn8   293764 bytes   2 files
-rwxrw-rw-  3.0 unx   202671 BX defN 13-Apr-15 13:06 7^&V8S(J63s$K9csDk~xaFRDGK&Z
-rwxrw-rw-  3.0 unx    90927 BX defN 13-Apr-15 13:50 %dQ+skWS84uT#KSKY1uND$v+
2 files, 293598 bytes uncompressed, 293176 bytes compressed:  0.1%
Archive:  YupE1RB8   518532 bytes   2 files
-rwxrw-rw-  3.0 unx   315786 BX defN 13-Apr-15 13:06 e7m1Jy+#%H!%bBD1FvCB)m!JM0gE
-rwxrw-rw-  3.0 unx   202671 BX defN 13-Apr-15 13:06 fU2G8r)1DD2QQ_xNWuclyde#
2 files, 518457 bytes uncompressed, 517944 bytes compressed:  0.1%
Archive:  EX8UPdUb   810609 bytes   2 files
-rwxrw-rw-  3.0 unx   494676 BX defN 13-Apr-15 13:50 7U0(ZB%8AFX8pd!9FN~v1fePI@s
-rwxrw-rw-  3.0 unx   315786 BX defN 13-Apr-15 13:06 l@IqLO0zJkujH0h3Fj#Ztp!m
2 files, 810462 bytes uncompressed, 810024 bytes compressed:  0.1%
Archive:  BOQqupmS   1098688 bytes   2 files
-rwxrw-rw-  3.0 unx   605502 BX defN 13-Apr-15 13:50 JxdIs^43_74nc-1h3WGphjSUGigLPl
-rwxrw-rw-  3.0 unx   494676 BX defN 13-Apr-15 13:50 fIIutQ+18TE0*Odi*XxM
2 files, 1100178 bytes uncompressed, 1098106 bytes compressed:  0.2%
Archive:  E0frzRAi   2372707 bytes   2 files
-rwxrw-rw-  3.0 unx  1793362 BX defN 15-Apr-15 10:29 cohaxOTDL4Iy4sK7DWFU6Mw6
-rwxrw-rw-  3.0 unx   605502 BX defN 13-Apr-15 13:50 Yy#FoK+YmAgM0#4*C2^i+WWA
2 files, 2398864 bytes uncompressed, 2372131 bytes compressed:  1.1%
Archive:  xnCub4eW   4494528 bytes   2 files
-rwxrw-rw-  3.0 unx  2731504 BX defN  8-Apr-15 08:32 317fc6d41e3d0f79f3e9c470cda48f52a7168c6f
-rwxrw-rw-  3.0 unx  1793362 BX defN 15-Apr-15 10:29 2VT&Wb!XJ0dzG7JyvyH-II#J
2 files, 4524866 bytes uncompressed, 4493994 bytes compressed:  0.7%
```

We see some sort of cascade: Out of the two files in each bigger zip, the smaller one is the biggest file in a smaller zip.

This suggests a plain-text attack on zips using tools such as `pkcrack`.

The only requirement is to get a hold of one of the files in the biggest zip.

By searching for the hashsum `317fc6d41e3d0f79f3e9c470cda48f52a7168c6f`, we find [a malware database](http://malwaredb.malekal.com/index.php?hash=317fc6d41e3d0f79f3e9c470cda48f52a7168c6f) that provides the malware with this hashsum for download. (Password is given in the link... `infected`)

We extract the file and confirm the hashsum:

```bash
$ 7z x c0d2dbb60f18f74c239cd17199e74979.zip -oout

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: c0d2dbb60f18f74c239cd17199e74979.zip

file out/c0d2dbb60f18f74c239cd17199e74979
already exists. Overwrite with 
c0d2dbb60f18f74c239cd17199e74979?
(Y)es / (N)o / (A)lways / (S)kip all / A(u)to rename all / (Q)uit? Y
Extracting  c0d2dbb60f18f74c239cd17199e74979
Enter password (will not be echoed) :


Everything is Ok

Size:       2731504
Compressed: 2725696
$ sha1 out/c0d2dbb60f18f74c239cd17199e74979
317fc6d41e3d0f79f3e9c470cda48f52a7168c6f  out/c0d2dbb60f18f74c239cd17199e74979
```

Now we need to create a zip containing this file in plaintext to use it to crack the encrypted zip containing the encrypted version of this file:

```bash
$ zip xnCub4eW_plain.zip out/c0d2dbb60f18f74c239cd17199e74979 
  adding: out/c0d2dbb60f18f74c239cd17199e74979 (deflated 0%)
$ zipinfo xnCub4eW_plain.zip 
Archive:  xnCub4eW_plain.zip   2725676 bytes   1 file
-rw-r--r--  3.0 unx  2731504 bx defN  8-Apr-15 11:02 out/c0d2dbb60f18f74c239cd17199e74979
1 file, 2731504 bytes uncompressed, 2725454 bytes compressed:  0.2%
```

Now start `pkcrack` with the correct parameters to get the three encryption keys and an decrypted version of the biggest zip:

```bash
$ pkcrack -p out/c0d2dbb60f18f74c239cd17199e74979 -c 317fc6d41e3d0f79f3e9c470cda48f52a7168c6f -P xnCub4eW_plain.zip -d xnCub4eW_decrypted.zip -C xnCub4eW
Files read. Starting stage 1 on Sat Jan  2 21:23:45 2016
Generating 1st generation of possible key2_2725465 values...done.
Found 4194304 possible key2-values.
Now we're trying to reduce these...
Lowest number: 959 values at offset 2722246
Lowest number: 934 values at offset 2722244
[...]
Lowest number: 101 values at offset 2689992
Lowest number: 97 values at offset 2689991
Done. Left with 97 possible Values. bestOffset is 2689991.
Stage 1 completed. Starting stage 2 on Sat Jan  2 21:23:59 2016
Ta-daaaaa! key0=70a8cda4, key1=547222ce, key2=4c7d562e
Probabilistic test succeeded for 35479 bytes.
Ta-daaaaa! key0=70a8cda4, key1=547222ce, key2=4c7d562e
Probabilistic test succeeded for 35479 bytes.
Ta-daaaaa! key0=70a8cda4, key1=547222ce, key2=4c7d562e
Probabilistic test succeeded for 35479 bytes.
Ta-daaaaa! key0=70a8cda4, key1=547222ce, key2=4c7d562e
Probabilistic test succeeded for 35479 bytes.
Ta-daaaaa! key0=70a8cda4, key1=547222ce, key2=4c7d562e
Probabilistic test succeeded for 35479 bytes.
Stage 2 completed. Starting zipdecrypt on Sat Jan  2 21:24:02 2016
Decrypting 317fc6d41e3d0f79f3e9c470cda48f52a7168c6f (ed5e829f7f1c27cbb62e5458)... OK!
Decrypting 2VT&Wb!XJ0dzG7JyvyH-II#J (15b6960191cbc71256147d67)... OK!
Finished on Sat Jan  2 21:24:02 2016
$ zip -d xnCub4eW_decrypted.zip '317fc6d41e3d0f79f3e9c470cda48f52a7168c6f'
deleting: 317fc6d41e3d0f79f3e9c470cda48f52a7168c6f
$ zipinfo xnCub4eW_decrypted.zip 
Archive:  xnCub4eW_decrypted.zip   1768810 bytes   1 file
-rwxrw-rw-  3.0 unx  1793362 bx defN 15-Apr-15 10:29 2VT&Wb!XJ0dzG7JyvyH-II#J
1 file, 1793362 bytes uncompressed, 1768540 bytes compressed:  1.4%
$ 7z x xnCub4eW_decrypted.zip -oout

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: xnCub4eW_decrypted.zip

Extracting  2VT&Wb!XJ0dzG7JyvyH-II#J

Everything is Ok

Size:       1793362
Compressed: 1768810
```

Rinse and repeat the process for each encrypted zip:

```bash
$ pkcrack -p '2VT&Wb!XJ0dzG7JyvyH-II#J' -c 'cohaxOTDL4Iy4sK7DWFU6Mw6' -P xnCub4eW_decrypted.zip -d E0frzRAi_decrypted -C E0frzRAi
Files read. Starting stage 1 on Sat Jan  2 21:34:49 2016
Generating 1st generation of possible key2_1768551 values...done.
Found 4194304 possible key2-values.
Now we're trying to reduce these...
Lowest number: 980 values at offset 1762081
Lowest number: 933 values at offset 1762074
[...]
Lowest number: 101 values at offset 1684821
Lowest number: 96 values at offset 1640087
Done. Left with 96 possible Values. bestOffset is 1640087.
Stage 1 completed. Starting stage 2 on Sat Jan  2 21:35:32 2016
Ta-daaaaa! key0=279cb96e, key1=ed67df2c, key2=3045ab32
Probabilistic test succeeded for 128469 bytes.
Ta-daaaaa! key0=279cb96e, key1=ed67df2c, key2=3045ab32
Probabilistic test succeeded for 128469 bytes.
Ta-daaaaa! key0=279cb96e, key1=ed67df2c, key2=3045ab32
Probabilistic test succeeded for 128469 bytes.
Stage 2 completed. Starting zipdecrypt on Sat Jan  2 21:35:34 2016
Decrypting cohaxOTDL4Iy4sK7DWFU6Mw6 (fac01cd5a743442f46237d67)... OK!
Decrypting Yy#FoK+YmAgM0#4*C2^i+WWA (eded5ebca7181ac782928982)... OK!
Finished on Sat Jan  2 21:35:34 2016
```

Finally, you have all decryption keys:

* 70a8cda4 547222ce 4c7d562e
* 279cb96e ed67df2c 3045ab32
* f790f319 6b813996 18929df1
* f30895b7 fc7cf9d4 9ed67a05
* bb7f9b6f de8e004c 1b6d2cf5
* d912d4a1 03e40028 655847f3
* 1764f2b7 42de2cb6 c3f66d33

And adding to that, you also get the flag:

```bash
$ 7z x VuwP09eM_decrypted.zip -oout

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: decrypted/VuwP09eM_decrypted.zip

Extracting  9Ux)@Zzr1h03PA#p&#u~JWWgUtpF
Extracting  flag.txt

Everything is Ok

Files: 2
Size:       90965
Compressed: 91295
$ cat out/flag.txt && echo
ASIS{b72be7f18502dde0c2ca373ee3c2b03e}
```

The flag is `ASIS{b72be7f18502dde0c2ca373ee3c2b03e}`.
## Other write-ups and resources

* <https://xmgv.wordpress.com/2015/05/11/asis-ctf-quals-2015-zrypt/>
* <http://www.thice.nl/asis-ctf-2015-write-ups/>
