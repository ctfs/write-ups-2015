# ASIS Quals CTF 2015: My Ped

**Category:** Forensic
**Points:** 175
**Solves:** 18
**Description:**

> What you see in my [ped](http://tasks.asis-ctf.ir/My_Ped_11ceeee7565e3bbd5c9db2c1a791236f) ?

## Write-up

We are served an xz compressed binary My_Ped_11ceeee7565e3bbd5c9db2c1a791236f which decompresses to
![1](https://cloud.githubusercontent.com/assets/10586902/7574178/4f02afae-f7f9-11e4-9940-bb1300ef57e5.png)

to find some more details on the file xxd | head was ran
xxd My_Ped_11ceeee7565e3bbd5c9db2c1a791236f~ | head

0000000: 376b 5374 a031 83d3 8cb2 28b0 d37a 5051  7kSt.1....(..zPQ
0000010: 0201 0700 0000 0000 0000 0001 6a44 4332  ............jDC2
0000020: 3031 3530 3530 3830 3630 3231 3763 3030  0150508060217c00
0000030: 3030 3030 3030 3031 0038 206a 4443 0100  00000001.8 jDC..

running a quick scrape of low hanging fruit reveals a few interesting things:
-2 PNG files from a zpaq website http://mattmahoney.net/dc/zpaq.html
-1 PNG file with half the flag
![00000284](https://cloud.githubusercontent.com/assets/10586902/7574335/87bd9d3a-f7fa-11e4-884b-9abe07425dc2.png)
-1 PDF with a writeup of ZPAQ incremental journaling utility

lets sudo apt-get zpaq and see what it yields:
Error: not ZPAQ

that's not nice but also the version is from the stone age that was installed so i visited the site mentioned about, downloaded the source and compiled a newer release.  Low and behold it acctually worked.
![2](https://cloud.githubusercontent.com/assets/10586902/7574479/9c984880-f7fb-11e4-9fd4-dbdb89ed580a.png)
and there are all our carved files plus inside 0001 another zpaq journal (0644).

looking inside the second journal 'archive' if you want to call it that was the following:
![3](https://cloud.githubusercontent.com/assets/10586902/7574577/52aa5d52-f7fc-11e4-8bc0-44c6013caadb.png)
17 entries named flag, and we are missing 17 pieces to our flag.  Perfect is what I thought but ran into errors when i ran zpaq -all extract new.zpaq.

to get around this I created my own journal with just one file to get the format required and painstakingly ripped them apart one by one like so

![4](https://cloud.githubusercontent.com/assets/10586902/7574658/e3a15838-f7fc-11e4-92da-52e7092fea99.png)
insert data here
![6](https://cloud.githubusercontent.com/assets/10586902/7574695/3acd5eb8-f7fd-11e4-9f6e-f3d26e3b964d.png)

once raw data saved in 17 files .zpaq i extracted them to get each piece.

some of the images were broken i'm not sure exactly why but using display allowed me to view what I needed to view, the last 17 chars of the flag.

ASIS{0e9800346489a3ac4f30c45976e325cf}

-reap

## Other write-ups and resources

* [Indonesian](https://github.com/rentjongteam/write-ups-2015/tree/master/asis-quals-2015/my-ped)
