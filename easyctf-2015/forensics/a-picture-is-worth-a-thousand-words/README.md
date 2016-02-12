# EasyCTF 2015: A Picture is Worth a Thousand Words (100)

**Category:** Forensics
**Points:** 100
**Solves:** 
**Description:**

> A picture is worth a thousand words. Can you find the (JPEG) picture among a thousand files? Connect to the EasyCTF SSH server and find the files in `/problems/1000words`. The files are also available for download [here](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/data.zip).
> 
> 
> Hint: Grep is always your friend.


## Write-up

by [polym](https://github.com/abpolym)

We are given a zip containing several files with random names such as `yVtcAVSqX31NBNEf` or `xFchwoeIko36ZmTU`.

The first thing to do is call the `file` command on each to find out what kind of files we are dealing with:

```bash
$ file *
file * | head
02EGypzE5VkCbZB9: ASCII text, with very long lines
06cL1JpILiS48QoA: ASCII text, with very long lines
086lVtmY2jzPJbTi: ASCII text, with very long lines
08Du4VJdtpvC6MZy: ASCII text, with very long lines
[...]
zb0VNgbT8MrEZxXl: ASCII text, with very long lines
zbUrg2VOULBucFVg: ASCII text, with very long lines
zmPUxLoUMH9N2GdY: ASCII text, with very long lines
zmgiDg4NhouKpbDV: ASCII text, with very long lines
```

A lot of ASCII files containing random ASCII characters.

Maybe there are other files except ASCII only files?

```bash
$ file * | awk '{print $2}' | sort | uniq -c | sort -n
   1 Arhangel
   1 Bio-Rad
   1 Clarion
   1 JPEG
   1 Microsoft
   2 MGR
   4 Netpbm
 989 ASCII
```

We see a JPEG, lets `grep` for it!

```bash
$ file * | grep 'JPEG'
UgeVjTlmZjNFvULk: JPEG image data, JFIF standard 1.01
```

The flag, `easyctf{it_must_be_pretty_hard_reading_this}`, is inside the picture:

![](./UgeVjTlmZjNFvULk)

## Other write-ups and resources

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/a_picture_is_worth_a_thousand_words_100.md>
