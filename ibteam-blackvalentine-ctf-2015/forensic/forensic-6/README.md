# IBTeam Blackvalentine CTF 2015: Forensic6 100

**Category:** Forensic
**Points:** 100
**Author:** mirfansulaiman
**Description:** 

> http://ctf.web-attack.info/misssion/12

## Write-up

by [polym](https://github.com/abpolym)

We are given [a pdf](./get.pdf) that contains nothing much:

![](./get.pdf)

Applying `exiftool` on the PDF reveals that something is wrong with its `xref` table:

```bash
$ exiftool get.pdf 
ExifTool Version Number         : 9.99
File Name                       : get.pdf
Directory                       : .
File Size                       : 1021 bytes
File Modification Date/Time     : 2015:12:26 01:58:57+01:00
File Access Date/Time           : 2015:12:26 02:48:37+01:00
File Inode Change Date/Time     : 2015:12:26 02:46:20+01:00
File Permissions                : rw-r--r--
File Type                       : PDF
File Type Extension             : pdf
MIME Type                       : application/pdf
PDF Version                     : 1.1
Linearized                      : No
Warning                         : Invalid xref table
```

We can open the pdf using any editor (such as `vim`) to find interesting hexadecimal characters that decoded yield a `bit.ly` link:

```bash
[...]
 /JS (68 74 74 70 25 33 41 25 32 66 25 32 66 62 69 74 2e 6c 79 25 32 66 31 76 31 4e 6d 35 4d)
[...]
$ echo '68 74 74 70 25 33 41 25 32 66 25 32 66 62 69 74 2e 6c 79 25 32 66 31 76 31 4e 6d 35 4d' | xxd -r -p  && echo
http%3A%2f%2fbit.ly%2f1v1Nm5M
```

[This bit.ly link](http://bit.ly/1v1Nm5M) leads us to a QR code:

![](2djtr89.jpg)

We decode this QR code using [an online QR decoder](https://zxing.org/w/decode.jspx) to get the flag, `IrJendr4LSo3DirMan`.

## Other write-ups and resources

* none yet
