# Pragyan CTF 2015: 255,255,255 is the best color

**Category:** Misc
**Points:** 50
**Solves** 27
**Description:**

> find the {flag}
>
> [misc-2](misc-2)

## Write-up

Extracting the xz compressed archive using `unxz < misc-2 > here` and the resulting POSIX tar archive using `tar xvf here`, we get a file named `flag.txt`.

The file contains `307200` RGB values.

We visualize these RGB values and guess a picture format using [go.py](go.py):

```bash
$ python go.py flag.txt
```

The resulting picture is:

![](out.bmp)

At this point we guessed the flag `a_life_without_color`. The actual flag might be a different one (e.g. `a_life_without_coding`), since the challenge itself ["wasn't framed for perfection"](https://ctf.pragyan.org/home) and the points were given for similar flags.

The solution might have been bruteforcing the letters one by one by reversing the applied blurring effect.

## Other write-ups and resources

* none yet
