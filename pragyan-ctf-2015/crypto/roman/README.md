# Pragyan CTF 2015: Roman

**Category:** Cryptography
**Points:** 10
**Solves** 119
**Description:**

> [question2.tar.gz](question2.tar.gz)

## Write-up

After extracting the gzipped tar archive using `tar xzvf question2.tar.gz`, we are given two files, `clue` and `encrypt`:

```bash
$ cat clue
\#greatest roman generals of all time
$ cat encrypt
ghowdirufhdwqlw
```

One of the "greatest roman generals of all time" is caesar, so maybe we have to do decrypt this ciphertext using the Caesar Rot cipher, e.g. using [rot.py](https://github.com/YASME-Tim/crypto-tools/tree/master/rot), lowercase only.

```bash
$ for i in {0..25}; do python rot.py $i ghowdirufhdwqlw; done
ghowdirufhdwqlw
hipxejsvgiexrmx
ijqyfktwhjfysny
jkrzgluxikgztoz
klsahmvyjlhaupa
lmtbinwzkmibvqb
mnucjoxalnjcwrc
novdkpybmokdxsd
opwelqzcnpleyte
pqxfmradoqmfzuf
qrygnsbeprngavg
rszhotcfqsohbwh
staipudgrtpicxi
tubjqvehsuqjdyj
uvckrwfitvrkezk
vwdlsxgjuwslfal
wxemtyhkvxtmgbm
xyfnuzilwyunhcn
yzgovajmxzvoido
zahpwbknyawpjep
abiqxclozbxqkfq
bcjrydmpacyrlgr
cdkszenqbdzsmhs
deltaforceatnit
efmubgpsdfbuoju
fgnvchqtegcvpkv
```

We see `deltaforceatnit`, which is the flag.

NOTE: The ROT value here is therefore `23`:

```bash
$ python rot.py 23 ghowdirufhdwqlw
deltaforceatnit
```

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/pragyan-ctf-2015-crypto-roman/>
