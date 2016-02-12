# IBTeam Blackvalentine CTF 2015: Forensic3 100

**Category:** Forensic
**Points:** 100
**Author:** mirfansulaiman
**Description:**

> Snake , Password: P0=sK[@0-1=3Kjs!aQ|aM.2C9v?
>
> http://ctf.web-attack.info/misssion/8

## Write-up

by [polym](https://github.com/abpolym)

First, we extract the given password protected zip:

```bash
$ 7z x Forensic-3.zip -p'P0=sK[@0-1=3Kjs!aQ|aM.2C9v?'

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: Forensic-3.zip

Extracting  FORENSIC SOAL 3 LEVEL 1
Extracting  FORENSIC SOAL 3 LEVEL 1/pL4n3t.mp3

Everything is Ok

Folders: 1
Files: 1
Size:       1559
Compressed: 841
```

The file `pl4n3t.mp3` actually are hexadecimal characters separated by a colon (`:`).

We transform the hex characters back to binary using `xxd`:

```bash
$ cat pL4n3t.mp3 && echo
53:58:6c:46:64:6d:46:48:57:6d:78:4d:4d:6a:6b:79:57:56:4d:35:61:6d:4a:48:5a:44:46:5a:62:55:56:6e:59:7a:4a:57:61:57:56:70:51:6d:31:61:4d:6c:59:79:57:56:68:52:5a:32:52:75:63:47:70:5a:62:56:5a:75:53:55:68:77:64:57:56:49:53:6d:35:61:56:7a:56:6f:57:6d:6c:43:4e:46:6c:70:51:54:6c:4a:51:30:70:31:5a:47:31:4b:62:31:4e:48:52:57:6c:4a:53:45:4a:70:5a:55:4e:42:4f:55:6c:44:53:6b:46:4e:56:47:73:78:59:55:56:46:61:55:6c:49:61:47:6c:6a:52:30:6f:30:5a:47:35:72:5a:31:42:54:51:6a:5a:69:62:6d:68:35:57:6a:4a:57:64:56:6c:58:57:57:39:6c:52:30:6c:7a:53:55:68:43:61:57:56:44:61:32:64:61:62:57:52:76:57:6c:4e:42:4f:55:6c:73:64:33:64:68:65:6c:55:77:57:45:52:43:63:6b:35:71:61:47:4e:4e:52:33:4d:79:54:6c:5a:33:64:32:46:36:53:58:64:59:52:45:4a:79:54:6b:52:61:59:30:31:48:63:7a:42:6a:52:6e:64:33:59:58:70:52:65:46:68:45:51:6e:4a:4f:52:47:52:6a:54:55:64:7a:65:55:31:47:64:33:64:68:65:6b:70:34:57:45:52:43:63:6b:30:7a:53:6d:4e:4e:52:33:4e:35:54:55:5a:33:64:32:46:36:57:6e:5a:59:52:45:4a:79:54:6c:52:57:59:30:31:48:63:7a:4a:4e:56:6e:64:33:59:58:70:4e:4d:56:68:45:51:6e:4a:4f:52:45:5a:6a:54:55:64:7a:4d:55:35:47:64:33:64:68:65:6d:4d:78:57:45:52:43:63:6b:35:45:61:47:4e:4e:52:33:4d:79:54:56:5a:33:64:32:46:36:57:6e:6c:59:52:45:4a:79:54:6e:70:73:59:30:31:48:63:7a:42:4e:56:6e:64:33:59:58:70:61:65:56:68:45:51:6e:4a:4e:65:6d:78:6a:54:55:64:7a:65:6b:30:78:64:33:64:68:65:6c:56:36:57:45:52:43:63:6b:35:71:52:57:6c:50:65:55:4a:71:57:6c:68:61:61:46:70:35:51:6d:31:61:4d:6d:68:73:54:47:31:6b:62:47:4a:74:52:6d:31:6c:56:7a:56:75:59:32:6c:6f:4e:46:6c:75:51:6d:6c:6c:53:46:6f:31:53:31:52:7a:50:51:3d:3d
$ cat pL4n3t.mp3 | tr -d ':' | xxd -r -p | xxd
0000000: 5358 6c46 646d 4648 576d 784d 4d6a 6b79  SXlFdmFHWmxMMjky
0000010: 5756 4d35 616d 4a48 5a44 465a 6255 566e  WVM5amJHZDFZbUVn
0000020: 597a 4a57 6157 5670 516d 3161 4d6c 5979  YzJWaWVpQm1aMlYy
0000030: 5756 6852 5a32 5275 6347 705a 6256 5a75  WVhRZ2RucGpZbVZu
0000040: 5355 6877 6457 5649 536d 3561 567a 566f  SUhwdWVISm5aVzVo
0000050: 576d 6c43 4e46 6c70 5154 6c4a 5130 7031  WmlCNFlpQTlJQ0p1
0000060: 5a47 314b 6231 4e48 5257 6c4a 5345 4a70  ZG1Kb1NHRWlJSEJp
0000070: 5a55 4e42 4f55 6c44 536b 464e 5647 7378  ZUNBOUlDSkFNVGsx
0000080: 5955 5646 6155 6c49 6147 6c6a 5230 6f30  YUVFaUlIaGljR0o0
0000090: 5a47 3572 5a31 4254 516a 5a69 626d 6835  ZG5rZ1BTQjZibmh5
00000a0: 576a 4a57 6456 6c58 5757 396c 5230 6c7a  WjJWdVlXWW9lR0lz
00000b0: 5355 6843 6157 5644 6132 6461 6257 5276  SUhCaWVDa2dabWRv
00000c0: 576c 4e42 4f55 6c73 6433 6468 656c 5577  WlNBOUlsd3dhelUw
00000d0: 5745 5243 636b 3571 6147 4e4e 5233 4d79  WERCck5qaGNNR3My
00000e0: 546c 5a33 6432 4636 5358 6459 5245 4a79  TlZ3d2F6SXdYREJy
00000f0: 546b 5261 5930 3148 637a 426a 526e 6433  TkRaY01HczBjRnd3
0000100: 5958 7052 6546 6845 516e 4a4f 5247 526a  YXpReFhEQnJORGRj
0000110: 5455 647a 6555 3147 6433 6468 656b 7034  TUdzeU1Gd3dhekp4
0000120: 5745 5243 636b 307a 536d 4e4e 5233 4e35  WERCck0zSmNNR3N5
0000130: 5455 5a33 6432 4636 576e 5a59 5245 4a79  TUZ3d2F6WnZYREJy
0000140: 546c 5257 5930 3148 637a 4a4e 566e 6433  TlRWY01HczJNVnd3
0000150: 5958 704e 4d56 6845 516e 4a4f 5245 5a6a  YXpNMVhEQnJOREZj
0000160: 5455 647a 4d55 3547 6433 6468 656d 4d78  TUdzMU5Gd3dhemMx
0000170: 5745 5243 636b 3545 6147 4e4e 5233 4d79  WERCck5EaGNNR3My
0000180: 5456 5a33 6432 4636 576e 6c59 5245 4a79  TVZ3d2F6WnlYREJy
0000190: 546e 7073 5930 3148 637a 424e 566e 6433  TnpsY01HczBNVnd3
00001a0: 5958 7061 6556 6845 516e 4a4e 656d 786a  YXpaeVhEQnJNemxj
00001b0: 5455 647a 656b 3078 6433 6468 656c 5636  TUdzek0xd3dhelV6
00001c0: 5745 5243 636b 3571 5257 6c50 6555 4a71  WERCck5qRWlPeUJq
00001d0: 576c 6861 6146 7035 516d 3161 4d6d 6873  WlhaaFp5Qm1aMmhs
00001e0: 5447 316b 6247 4a74 526d 316c 567a 5675  TG1kbGJtRm1lVzVu
00001f0: 5932 6c6f 4e46 6c75 516d 6c6c 5346 6f31  Y2loNFluQmllSFo1
0000200: 5331 527a 5051 3d3d                      S1RzPQ==
```

Looks like the result is a base64 encoded string.

We can pipe the result right into `base64` to decode it:

```bash
$ cat pL4n3t.mp3 | tr -d ':' | xxd -r -p | base64 --decode | xxd
0000000: 4979 4576 6147 5a6c 4c32 3932 5953 396a  IyEvaGZlL292YS9j
0000010: 6247 6431 596d 4567 6332 5669 6569 426d  bGd1YmEgc2VieiBm
0000020: 5a32 5632 5958 5167 646e 706a 596d 566e  Z2V2YXQgdnpjYmVn
0000030: 4948 7075 6548 4a6e 5a57 3568 5a69 4234  IHpueHJnZW5hZiB4
0000040: 5969 4139 4943 4a75 646d 4a6f 5347 4569  YiA9ICJudmJoSGEi
0000050: 4948 4269 6543 4139 4943 4a41 4d54 6b31  IHBieCA9ICJAMTk1
0000060: 6145 4569 4948 6869 6347 4a34 646e 6b67  aEEiIHhicGJ4dnkg
0000070: 5053 4236 626e 6879 5a32 5675 5957 596f  PSB6bnhyZ2VuYWYo
0000080: 6547 4973 4948 4269 6543 6b67 5a6d 646f  eGIsIHBieCkgZmdo
0000090: 5a53 4139 496c 7777 617a 5530 5844 4272  ZSA9IlwwazU0XDBr
00000a0: 4e6a 6863 4d47 7332 4e56 7777 617a 4977  NjhcMGs2NVwwazIw
00000b0: 5844 4272 4e44 5a63 4d47 7330 6346 7777  XDBrNDZcMGs0cFww
00000c0: 617a 5178 5844 4272 4e44 6463 4d47 7379  azQxXDBrNDdcMGsy
00000d0: 4d46 7777 617a 4a78 5844 4272 4d33 4a63  MFwwazJxXDBrM3Jc
00000e0: 4d47 7379 4d46 7777 617a 5a76 5844 4272  MGsyMFwwazZvXDBr
00000f0: 4e54 5663 4d47 7332 4d56 7777 617a 4d31  NTVcMGs2MVwwazM1
0000100: 5844 4272 4e44 4663 4d47 7331 4e46 7777  XDBrNDFcMGs1NFww
0000110: 617a 6331 5844 4272 4e44 6863 4d47 7332  azc1XDBrNDhcMGs2
0000120: 4d56 7777 617a 5a79 5844 4272 4e7a 6c63  MVwwazZyXDBrNzlc
0000130: 4d47 7330 4d56 7777 617a 5a79 5844 4272  MGs0MVwwazZyXDBr
0000140: 4d7a 6c63 4d47 737a 4d31 7777 617a 557a  MzlcMGszM1wwazUz
0000150: 5844 4272 4e6a 4569 4f79 426a 5a58 5a68  XDBrNjEiOyBjZXZh
0000160: 5a79 426d 5a32 686c 4c6d 646c 626d 466d  ZyBmZ2hlLmdlbmFm
0000170: 6557 356e 6369 6834 596e 4269 6548 5a35  eW5ncih4YnBieHZ5
0000180: 4b54 733d                                KTs=
```

The result is again base64 encoded, lets decode it once again to get the following:

```bash
$ cat pL4n3t.mp3 | tr -d ':' | xxd -r -p | base64 --decode | base64 --decode | xxd
0000000: 2321 2f68 6665 2f6f 7661 2f63 6c67 7562  #!/hfe/ova/clgub
0000010: 6120 7365 627a 2066 6765 7661 7420 767a  a sebz fgevat vz
0000020: 6362 6567 207a 6e78 7267 656e 6166 2078  cbeg znxrgenaf x
0000030: 6220 3d20 226e 7662 6848 6122 2070 6278  b = "nvbhHa" pbx
0000040: 203d 2022 4031 3935 6841 2220 7862 7062   = "@195hA" xbpb
0000050: 7876 7920 3d20 7a6e 7872 6765 6e61 6628  xvy = znxrgenaf(
0000060: 7862 2c20 7062 7829 2066 6768 6520 3d22  xb, pbx) fghe ="
0000070: 5c30 6b35 345c 306b 3638 5c30 6b36 355c  \0k54\0k68\0k65\
0000080: 306b 3230 5c30 6b34 365c 306b 3470 5c30  0k20\0k46\0k4p\0
0000090: 6b34 315c 306b 3437 5c30 6b32 305c 306b  k41\0k47\0k20\0k
00000a0: 3271 5c30 6b33 725c 306b 3230 5c30 6b36  2q\0k3r\0k20\0k6
00000b0: 6f5c 306b 3535 5c30 6b36 315c 306b 3335  o\0k55\0k61\0k35
00000c0: 5c30 6b34 315c 306b 3534 5c30 6b37 355c  \0k41\0k54\0k75\
00000d0: 306b 3438 5c30 6b36 315c 306b 3672 5c30  0k48\0k61\0k6r\0
00000e0: 6b37 395c 306b 3431 5c30 6b36 725c 306b  k79\0k41\0k6r\0k
00000f0: 3339 5c30 6b33 335c 306b 3533 5c30 6b36  39\0k33\0k53\0k6
0000100: 3122 3b20 6365 7661 6720 6667 6865 2e67  1"; cevag fghe.g
0000110: 656e 6166 796e 6772 2878 6270 6278 7679  enafyngr(xbpbxvy
0000120: 293b                                     );
```

Looks like python code thats encrypted using caesar cipher, most likely rot13 - so we try to decipher the result:

```bash
$ cat pL4n3t.mp3 | tr -d ':' | xxd -r -p | base64 --decode | base64 --decode | tr '[a-zA-Z]' '[n-za-mN-ZA-M]' && echo
#!/usr/bin/python from string import maketrans ko = "aiouUn" cok = "@195uN" kocokil = maketrans(ko, cok) stur ="\0x54\0x68\0x65\0x20\0x46\0x4c\0x41\0x47\0x20\0x2d\0x3e\0x20\0x6b\0x55\0x61\0x35\0x41\0x54\0x75\0x48\0x61\0x6e\0x79\0x41\0x6e\0x39\0x33\0x53\0x61"; print stur.translate(kocokil);
```

What's left to do is save the output to [run.py](./run.py), fix the indentation and run it:

```bash
$ python2.7 run.py 
x54x68x65x20x46x4cx41x47x20x2dx3ex20x6bx55x61x35x41x54x75x48x61x6ex79x41x6ex39x33x53x61
```

We have to decode these hex characters once again to binary to finally receive the flag, `kUa5ATuHanyAn93Sa`:

```bash
$ python2.7 run.py | tr -d 'x' | xxd -r -p && echo
The FLAG -> kUa5ATuHanyAn93Sa
```

## Other write-ups and resources

* none yet
