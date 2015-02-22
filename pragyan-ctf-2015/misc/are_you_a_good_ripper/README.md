# Pragyan CTF 2015: Are you a good ripper?

**Category:** Misc
**Points:** 5
**Solves** 75
**Description:**

> the flag is right infront of u :P
>
> [misc](misc)

## Write-up

After extracting the xz archive using `unxz < misc > here`, we are given a POSIX tar archive.

We unpack this archive with `tar xvf here` and get another archive, this time it is a zip archive named `misc.zip`.

If we try to `unzip` this archive, however, we are asked for a passphrase:

```bash
$ unzip misc.zip
Archive:  misc.zip
[misc.zip] flag.txt password:
```

We bruteforce the passphrase using a big list of passwords, e.g. [rockyou.txt](http://downloads.skullsecurity.org/passwords/rockyou.txt.bz2), and `fcrackzip`:

```bash
$ fcrackzip -u -D -p "./rockyou.txt" misc.zip


PASSWORD FOUND!!!!: pw == jumanji
```

Now we just extract the archive and receive a file `flag.txt` containing the flag:

```bash
$ cat file.txt
4pesb9b9blkfc08e3z2105b1b6bfif45
```

The flag is `4pesb9b9blkfc08e3z2105b1b6bfif45`.

## Other write-ups and resources

* none yet
