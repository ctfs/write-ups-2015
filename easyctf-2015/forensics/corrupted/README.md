# EasyCTF 2015: Corrupted (375)

**Category:** Forensics
**Points:** 375
**Solves:** 
**Description:**

> I'm not an anime person, but I have weeaboo friends. One of them uses [this](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/yuno.jpg) as her profile pic. Unfortunately, she sent me a corrupted version. Can you find out what she's hiding?
> 
> 
> Hint: Who is Yuno Gasai? From what I hear, she's a scary yandere.
> 
> Hint: On a more serious note, stop trying to fix the image. It's not broken -- it's hiding stuff.

## Write-up

by [polym](https://github.com/abpolym)

This write-up is based on following write-ups:

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/corrupted_375.md>

We are given an image of Yuno Gasai:

![](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/yuno.jpg)

It seems to be broken, but the hints tell us that it is not broken, but hiding stuff - most likely it changed bits in the original image.

So we try to find the original image that this modified one is based on.

This can be done by following these steps:

* Search for "Yuno Gasai" on <https://images.google.de/>
* Set the search options to only display pictures the same resolution as the modified version (`130`x`130`)
* Download the first non-broken image that represents the modified version
* Upload the non-broken image on <https://images.google.de/> to find similar images
* Select all resolutions to see only similar versions of this non-broken image
* Again, set the resolution option
* Get around 16 `130`x`130` versions of the non-broken image

The full image list is [here](yuno.list).

Then, we download all versions and have a look at their size in bytes:

```bash
$ ls -l yuno.jpg 
-rw-r--r--@ 1 xxx  xxx  6851 Jan  1 17:15 yuno.jpg
$ cd yunos/
$ ls -lS
total 264
-rw-r--r--@ 1 xxx  xxx  11211 Jan  4 09:05 10376136_803663996379870_881095011285469366_n.jpg
-rw-r--r--  1 xxx  xxx   6944 Jan  4 09:05 srS9LECHDAQ.jpg
-rw-r--r--  1 xxx  xxx   6943 Jan  4 09:05 72IAXH3Uf5M.jpg
-rw-r--r--  1 xxx  xxx   6932 Jan  4 09:07 tiUPEUczHYY.jpg
-rw-r--r--  1 xxx  xxx   6932 Jan  4 09:06 w_A8FR5avZc.jpg
-rw-r--r--  1 xxx  xxx   6931 Jan  4 09:07 0OcpdtbgLqY.jpg
-rw-r--r--  1 xxx  xxx   6897 Jan  4 09:06 nj8xr2wl0TM.jpg
-rw-r--r--  1 xxx  xxx   6893 Jan  4 09:06 jPpfSGtlCxY.jpg
-rw-r--r--  1 xxx  xxx   6892 Jan  4 09:05 VrRG4olxM9Y.jpg
-rw-r--r--  1 xxx  xxx   6878 Jan  4 09:06 QJlbvqtQgMQ.jpg
-rw-r--r--  1 xxx  xxx   6855 Jan  4 09:06 _A7qy52f8Vw.jpg
-rw-r--r--  1 xxx  xxx   6853 Jan  4 09:05 LYHxH-8DBsE.jpg
-rw-r--r--  1 xxx  xxx   6853 Jan  4 09:06 qkimpnfZfqM.jpg
-rw-r--r--  1 xxx  xxx   6851 Jan  4 09:06 5WzbbhtpMkQ.jpg
-rw-r--r--  1 xxx  xxx   6845 Jan  4 09:05 -nw21lTOJDA.jpg
-rw-r--r--  1 xxx  xxx   6234 Jan  4 09:06 10931434_890605537650928_5977686544027780096_n.jpg
```

Out of the downloaded versions only one, `5WzbbhtpMkQ.jpg`, has the same size (`6851`) as the corrupted version:

![](./5WzbbhtpMkQ.jpg)

We print out their differences first with `xxd` to see that a stream of bytes has been modified:

```bash
$ diff <(xxd yuno.jpg) <(xxd yunos/5WzbbhtpMkQ.jpg)
274,288c274,288
< 0001110: 7c45 9f9b 0f0e 362d df47 a5a6 ef37 110d  |E....6-.G...7..
< 0001120: c688 ee49 7724 fb10 d7b8 9fba 5faa de88  ...Iw$......_...
< 0001130: 8661 fb29 2d25 d74a 055d fadd 0461 445f  .a.)-%.J.]...aD_
< 0001140: 7e44 a03f 87c9 eb01 bda4 ad52 0f94 5344  ~D.?.......R..SD
< 0001150: da82 7335 42dc 2e31 dd68 ada6 b794 f469  ..s5B..1.h.....i
< 0001160: a10a 4d5c 61cb 4482 ce48 8262 34e9 011f  ..M\a.D..H.b4...
< 0001170: 1ae7 254b 7e3d 72cb 4039 5f62 e83c 3ef3  ..%K~=r.@9_b.<>.
< 0001180: 9f97 820b 0bd9 e276 263b b434 9a0b bcca  .......v&;.4....
< 0001190: 1e18 0d4f 913d c41f 39f5 d45c 8fcd e014  ...O.=..9..\....
< 00011a0: 16c8 4d9c e447 3ab8 cb73 5f8a 741a 331d  ..M..G:..s_.t.3.
< 00011b0: dc78 ae0b d9f5 929a 5165 f961 0f5e 999d  .x......Qe.a.^..
< 00011c0: 33ba 3a27 f8ec 6871 8f18 5c29 979f 1b8b  3.:'..hq..\)....
< 00011d0: eac9 9e80 1db1 4dad 83ef 5f9a faa2 67e4  ......M..._...g.
< 00011e0: 4abb 3ba9 8208 5dd4 e43c 0ef5 61d9 7c7f  J.;...]..<..a.|.
< 00011f0: e20c 7dd2 ff47 9a46 18f8 7e20 7e79 d624  ..}..G.F..~ ~y.$
---
> 0001110: 7c44 9e9b 0f0d 362c df46 a4a6 ef37 110c  |D....6,.F...7..
> 0001120: c687 ed48 7724 fa0f d7b7 9eb9 5eaa de87  ...Hw$......^...
> 0001130: 8660 fa29 2d25 d649 055c f9dc 0460 445f  .`.)-%.I.\...`D_
> 0001140: 7e43 9f3f 87c8 ea01 bda3 ac51 0e94 5243  ~C.?.......Q..RC
> 0001150: da81 7234 41dc 2e30 dd67 aca5 b793 f468  ..r4A..0.g.....h
> 0001160: a109 4c5c 60ca 4382 ce47 8162 33e8 001e  ..L\`.C..G.b3...
> 0001170: 1ae6 244b 7d3c 71ca 4039 5e61 e83c 3ef3  ..$K}<q.@9^a.<>.
> 0001180: 9f96 810b 0ad8 e175 263a b334 990a bbc9  .......u&:.4....
> 0001190: 1e17 0c4f 903c c31e 39f4 d35c 8ecc df13  ...O.<..9..\....
> 00011a0: 16c7 4c9c e346 39b7 cb72 5e8a 7319 321c  ..L..F9..r^.s.2.
> 00011b0: dc77 ad0b d8f4 9199 5164 f861 0e5d 989c  .w......Qd.a.]..
> 00011c0: 33b9 3927 f7eb 6770 8f17 5b29 969e 1a8a  3.9'..gp..[)....
> 00011d0: eac8 9d80 1cb0 4cac 83ee 5e9a f9a1 66e3  ......L...^...f.
> 00011e0: 4abb 3aa8 8208 5dd4 e43b 0df5 60d8 7b7e  J.:...]..;..`.{~
> 00011f0: e20b 7cd1 fe46 9a45 18f8 7e20 7e79 d624  ..|..F.E..~ ~y.$
```

We print out their differences using [this python script](bytediff.py):

```bash
$ python2.7 bytediff.py yuno.jpg 5WzbbhtpMkQ.jpg 
0000[...]0000
0110010101100001011100110111100101100011011101000110011001111011011110010111010101101110011011110110111100110000011011110110111101101111011011110110111101101111011011110110111101101111011011110110111101101111001100000110111101111101
0000[...]0000
```

Converting the resulting binary string to ASCII, we get the flag, `easyctf{yunoo0oooooooooooo0o}`:

```bash
$ echo "0110010101100001011100110111100101100011011101000110011001111011011110010111010101101110011011110110111100110000011011110110111101101111011011110110111101101111011011110110111101101111011011110110111101101111001100000110111101111101" | perl -lpe '$_=pack"B*",$_'
easyctf{yunoo0oooooooooooo0o}
```

## Other write-ups and resources

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/corrupted_375.md>
