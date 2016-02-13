# WhiteHat Grand Prix Qualification Round 2015: Sa Pa

**Category:** Forensics
**Points:** 150
**Solves:** 5
**Description:**

> Malware tends to change its behaviors over time, can you trace it?
> 
> [for150_1fde98abea2f9b392522fd48016b24e4](for150_1fde98abea2f9b392522fd48016b24e4)


## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on a writeup by [Tin](https://blog.tinduong.pw/whitehat-grandprix-global-challenge/) <!-- hi Tin :) -->.

Note: This writeup is work in progress and not really finished :/

We are given a zip archive that contains a PE executable:

```bash
+bash-4.3$ file for150_1fde98abea2f9b392522fd48016b24e4 
for150_1fde98abea2f9b392522fd48016b24e4: Zip archive data, at least v2.0 to extract
$ 7z x for150_1fde98abea2f9b392522fd48016b24e4 -oout
$ cd out
$ file for150.exe
for150.exe: PE32 executable for MS Windows (console) Intel 80386 32-bit
```

Using an online Windows exectuable sandbox such as [malwr](https://malwr.com/analysis/NTVhMWU1NTQ0Y2E3NGQ0MTgxNjA3ZTZiYjQwZmJmOGQ/) or [reverse.it/hybrid-analysis.com](https://www.reverse.it/sample/668effa1a65a23fe674973bb20fe3f2c8eea0b19460d6b9319efc29f0c83f320?environmentId=1), we see that the exe contains several `.pyd` files, which are just [executables made from python code](https://docs.python.org/2/faq/windows.html)

TODO: Extract pyd files from exe -- help if you know how to do this :)

After extracting the pyd files, we can decompile them, e.g. using a [python decompiler](https://github.com/alex/python-decompiler).

Inside one of these decompiled python files, we find a HTTP GET request call to `222.255.46.146`.

By tracking this IP on sites such as [virustotal](https://www.virustotal.com/en/ip-address/222.255.46.146/information/), we find two malware analysis reports related to the same IP address:

* <https://www.virustotal.com/en/file/322172b401cf125a08d695966ed7b5cee9feaea6a4e6fc7a60c8da2c36f8ad93/analysis/>
* <https://www.virustotal.com/en/file/da13657f6e5580ff81517dc6199d0b2e2ab91a46dcab617b2db3c44dbc11454b/analysis/>

We find a HTTP GET request call to `http://222.255.46.146/g3tfla9_for100.php` with the User-Agent `Whitehat.vn`.

Replaying this request (curl ) yields the flag:


```bash
+bash-4.3$ curl http://103.237.99.150/g3tfla9_for100.php -A "Whitehat.vn" && echo
WhiteHat{1775d34e544b5b1d094e076b512130773990dbcc}
```

## Other write-ups and resources

* [Vietnamese](https://blog.tinduong.pw/whitehat-grandprix-global-challenge/)
