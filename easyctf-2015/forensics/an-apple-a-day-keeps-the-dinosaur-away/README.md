# EasyCTF 2015: An apple a day keeps the dinosaur away? (35)

**Category:** Forensics
**Points:** 35
**Solves:** 
**Description:**

> Oh look, it's a perfectly innocent picture of an [apple](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/apple.jpg). Nothing to see here!
> 
> 
> Hint: Apples are suspicious. Don't trust apples. They always have something to hide . . .


## Write-up

by [polym](https://github.com/abpolym)

We are given a picture of an apple:

![](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/apple.jpg)

Applying `strings` on the file in combination with a `grep` for `easyctf` yields the flag:

```bash
$ strings -a apple.jpg | grep 'easyctf'
   the flag is easyctf{w0w_much_appl3s}
```

The flag is `easyctf{w0w_much_appl3s}`.

## Other write-ups and resources

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/an_apple_a_day_keeps_the_dinosaur_away_35.md>
