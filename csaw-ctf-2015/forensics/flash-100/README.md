# CSAW QUALS 2015: flash-100

**Category:** Forensics
**Points:** 100
**Solves:** 809
**Description:**

> We were able to grab an image of a harddrive. Find out what's on it.
>
> [flash_c8429a430278283c0e571baebca3d139.img](https://drive.google.com/file/d/0B_zt1fDAjfM_ZHJkSjdTYThPdmc/view?usp=sharing)

## Write-up

by [polym](https://github.com/abpolym)

We are given an img that we can either mount or view with `FTK Imager`.

However, we can also apply `strings` to the image to get the flag:

```bash
$ strings flash_c8429a430278283c0e571baebca3d139.img  | igrep flag
    Like to a vagabond flag upon the stream,
    Than was his loss, to course your flying flags
[...]
against the world in arms; the black flag waved night and day from the
Over the chair they had thrown a red flag, and to the back of it they
flag{b3l0w_th3_r4dar}
```

The flag is `flag{b3l0w_th3_r4dar}`.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/csaw-quals-2015-flash/>
* <http://fadec0d3.blogspot.com/2015/09/csaw-2015-forensics-keep-calm-ctf-flash.html>
* <https://p4f.github.io/csaw-online-qual-forensics100/>
* <http://www.gameofpwnz.com/?p=144>
* <http://xd4rker.blogspot.com/2015/09/csaw-ctf-2015-forensics-100-flash-write.html>
* <https://github.com/ViviTurtle/Programming/tree/master/Competitions/CSAW_2015/Flash>
* <http://thekillingtime.com/?p=348>
* <https://www.youtube.com/watch?v=0Vbw7HNlRtc>
* <https://github.com/ByteBandits/writeups/blob/master/csaw-quals-2015/forensics/flash/chaitan94/README.md>
