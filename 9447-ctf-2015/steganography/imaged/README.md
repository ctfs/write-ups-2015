# 9447 CTF 2015: imaged

**Category:** Steganography
**Points:** 90
**Solves:** 80
**Description:**

> Our spies found this image. They think something is hidden in it... what could it be?
>
> [imaged.zip](https://mega.nz/#!KYEDhCxT!-ds4cnfwADzH0JxHiokiFXTFSxqddsRqaPmP86ZXDcE)  384077bcc914fd7a2a5afd60c4e4874e


## Write-up

by [stefan2904](https://github.com/stefan2904)

After looking at the provided PNG file with the Hex Editor of our choice, we spotted the sequence *9447*, indicating the start of a flag. Furthermore, we noticed flag-like ascii-characters close to the headers of *IDAT* chunks. (To be precise: the flag-parts were the CRC checksum of the *IDAT* chunks.)

```
0000000: 8950 4e47 0d0a 1a0a 0000 000d 4948 4452  .PNG........IHDR
0000010: 0000 0bb5 0000 3903 0403 0000 0039 3434  ......9......944
0000020: 3700 0000 3050 4c54 4518 140c f4f0 e8c4  7...0PLTE.......
0000030: 4448 3084 5cf0 e848 3430 74bc 306c 2874  DH0.\..H40t.0l(t
0000040: c400 0000 ffff ffc4 4492 23bc 7287 8569  ........D.#.r..i
0000050: 0603 3830 b08f d486 1f7b 5374 6500 0020  ..80.....{Ste..
0000060: 0049 4441 5478 0100 e880 177f 00c9 e441  .IDATx.........A
0000070: e479 aa92 6193 be9a 1a97 9fa9 9e49 99ae  .y..a........I..
0000080: 949a f999 99af 979b 45ee 9999 99e1 9b71  ........E......q
0000090: a445 4e1a bbaa 7412 4b99 79ee 114b 1921  .EN...t.K.y..K.!
```


After realizing this is also the case for other *IDAT* chunks, a quick python script revealed the rest of the flag:

```python
#!/usr/bin/python

import mmap

with open("imaged.png", "rw+b") as f:
    mm = mmap.mmap(f.fileno(), 0)
    idx = 0
    flag = "9447"
    while '}' not in flag:
        idx = mm.find('IDAT', idx+1)
        flag += mm[idx-8:idx-4]
    print flag
```

9447{Steg0_redunDaNcy_CHeck}

## Other write-ups and resources

* <http://secgroup.github.io/2015/11/30/9447ctf2015-writeup-imaged/>
* <https://github.com/pwning/public-writeup/tree/master/9447ctf2015/steg90-imaged>
* [sophia.re](http://www.sophia.re/94472015_imaged_writeup.html)
