# Pragyan CTF 2015: One More Headache

**Category:** Cryptography
**Points:** 20
**Solves** 41
**Description:**

> This is a PRGYAN event
>
> [substitution.txt](substitution.txt)

## Write-up

We substitute the given ciphertext letters with the "new" alphabet `prgyanbcdefhijklmnoqstuvwxz`. Proof of concept is `switch.py`:

```bash
$ python switch.py
ilovectf
```

The flag is `ilovectf`.

## Other write-ups and resources

* none yet
