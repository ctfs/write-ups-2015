# Pragyan CTF 2015: Haunted 1's

**Category:** Cryptography
**Points:** 20
**Solves** 33
**Description:**

> Find the {flag}.
>
> [crypted.txt](crypted.txt)

## Write-up

We notice that the numbers in the ciphertext are only `0` or in the range `2-9`.
The number `1` is missing, hence the task name `Haunted 1's`.
So we replace everything that is not `0` with `1` and decode the resulting binary text into an ASCII string:

```bash
$ cat crypted.txt | sed 's/[1-9]/1/g' | perl -lpe '$_=pack"B*",$_'
the flag is {NiCe_0bsErvaTion}
```

The flag is `{NiCe_0bsErvaTion}`.

## Other write-ups and resources

* none yet
