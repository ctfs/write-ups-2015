# Pragyan CTF 2015: The Impossible

**Category:** Cryptography
**Points:** 50
**Solves** 43
**Description:**

> [question1.tar.gz](question1.tar.gz)

## Write-up

We are given a ciphertext and a clue:

```bash
$ cat clue.py
#!/usr/bin/python

i = 1
while (i>0):
	print i
	i = i + 1

# i feel so sad for you if you couldn't find the clue :-(
$ cat encrypt
sfblvmlhyhpgrudnntagfxstbgxyk
```

The clue hints that we get the nth successor of the letter in the alphabet, depending on the index `n+1` of this ciphertext.

Proof of concept is `trans.py`:

```bash
$ python trans.py
thepassphraseisdeltaatpragyan
```

The flag is `deltaatpragyan`.

## Other write-ups and resources

* none yet
