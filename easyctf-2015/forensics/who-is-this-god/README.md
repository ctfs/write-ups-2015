# EasyCTF 2015: Who is this god? (175)

**Category:** Forensics
**Points:** 175
**Solves:** 
**Description:**

> My friend Mich uses this nice [tulip](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/tulip.png) as her profile pic because she likes historical stuff. Did I mention that one of the EasyCTF developers worships her as a god?
> 
> 
> Hint: A tulip a day keeps the economy away :)
> 
> Hint: P.S. Everything you need is in the image...although you might need sharper vision.

## Write-up

by [polym](https://github.com/abpolym)

We are given a picture of a tulip:

![](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/tulip.png)

The hint tells us to sharpen the picture, which we can do using [ImageMagicks `sharpen` tool](http://www.imagemagick.org/Usage/blur/#sharpen):

```bash
$ convert tulip.png -sharpen 0x10 sharp_tulip.png
```

![](sharp_tulip.png)

We see a slight highlighted text in the upper left corner that spells out the flag, `easyctf{all_hail_michy}`, which can be highlighted a bit more using a random color map by `stegsolve`:

![](./random-color-tulip.png)

According to [this writeup](https://github.com/1lastBr3ath/EasyCTF-2015-Writeup/blob/master/forensics.md), we can use [this forensic tool](https://29a.ch/photo-forensics/#forensic-magnifier) to see a better contrast without sharpening the image.

## Other write-ups and resources

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/who_is_this_god_175.md>
