# backdoor CTF 2015: [LHC](https://backdoor.sdslabs.co/challenges/LHC)

**Category:** Misc
**Points:** 100
**Author:** [Abhay Bir Singh Rana](https://backdoor.sdslabs.co/users/nemo)
**Difficulty:** Medium
**Solves:** 81
**Description:** 

* <https://backdoor.sdslabs.co/challenges/LHC>

> The flag is in the middle of [this dataset](https://lhc-cdn.herokuapp.com/data.txt) kindly provided to us by the Large Hadron Collider.

## Write-up

We are told to download a big file (2.0T according to `wget https://lhc-cdn.herokuapp.com/data.txt`) and that we receive the flag in the middle of the big file.

The solution is not to download the whole file but to begin at a specific offset using e.g. the ranges option of `curl`:

To get the correct `Content-Range` and `Content-Length` tags, we download the last byte of the file:

```bash
curl -I https://lhc-cdn.herokuapp.com/data.txt -r -1 > headers.html
```

[headers.html](headers.html)

We see some weird tags that make us suggest that we have to begin at the index `2200000000000/2-32 = 1099999999968` and end at index `1099999999968 + len(sha256flag) = 1099999999968 + 64 = 1100000000032`

We can specify the ranges using the `-r` flag of `curl`:

```bash
$ curl -r 1099999999968-1100000000032 https://lhc-cdn.herokuapp.com/data.txt
 flag is: bf[...]
```

After some fiddling, we see that the actual ranges are `1099999999952-1100000000049`:

```bash
$ curl -r 1099999999952-1100000000049 https://lhc-cdn.herokuapp.com/data.txt
            The flag is: bf[...]
```

The flag won't be printed here, since this CTF is a long lived one.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/backdoor-ctf-2015-lhc/>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/BACKDOORCTF/misc/lhc>
* [Indonesian](https://docs.google.com/document/d/1zzxRVmmF7rbZp6pWSljbmA6d2yCwIkxkUJFKHSUJiHQ/edit?usp=drive_web)
