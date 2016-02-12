# Vancouver BSides CTF 2015: Kicker of Elves

**Category:** Forensics
**Points:** 200
**Solves:** 34
**Description:** 

> I stole this file, but it doesn't work. Halp plz.
> 
> [koe-118c28da8a435978a957cf3cba03ab20932d94fb](koe-118c28da8a435978a957cf3cba03ab20932d94fb)
>
> [koe-118c28da8a435978a957cf3cba03ab20932d94fb](koe-118c28da8a435978a957cf3cba03ab20932d94fb)

## Write-up

by [polym](https://github.com/abpolym)

We are given an ELF:

```bash
file koe-118c28da8a435978a957cf3cba03ab20932d94fb 
koe-118c28da8a435978a957cf3cba03ab20932d94fb: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), stripped
```

Executing the ELF does not work, it looks like something is broken or missing.

Disassembling the binary with `objdump` is also a bit harder - it gives an error:

```bash
$ objdump -D -M intel koe-118c28da8a435978a957cf3cba03ab20932d94fb
gobjdump: koe-118c28da8a435978a957cf3cba03ab20932d94fb: File format not recognized
```

Turns out we can fix the binary by following [these instructions](http://www.askrprojects.net/software/objdump.html) to disassemble it.

In the [assembly code](./koe.asm) of this binary we see a simple XOR with `0x41` == `A` that encrypts a certain block.

In comes a helpful tool named [XORSearch](http://blog.didierstevens.com/?s=xorsearch) that we can use to find the flag automatically:

```bash
$ xorsearch koe-118c28da8a435978a957cf3cba03ab20932d94fb flag
Found XOR 00 position 13BC: flag
Found XOR 41 position 071E: flag{4nything_is_b3tter_than_that_1train}
```

The flag is `flag{4nything_is_b3tter_than_that_1train}`.

## Other write-ups and resources

* <https://neg9.org/news/2015/3/22/kicker-of-elves-solution>
* <http://captf.com/2015/bsides-vancouver/forensics/kickerofelves/kickerofelves-psifertex-solve.txt>
* [Japanese](http://mage-ctf-writeup.blogspot.jp/2015/03/b-sides-vancouver-2015.html)