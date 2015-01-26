# Th3Jackers CTF 2015: Weird Text

**Category:** Misc
**Points:** 100
**Solves** 32
**Description:**

> Description: Giv m th flg plz !
>
> Attachment: [ec5883451bb7d0aa6b5950e39ed5f16d](ec5883451bb7d0aa6b5950e39ed5f16d)

## Write-up

We are given [this textfile](ec5883451bb7d0aa6b5950e39ed5f16d), consisting of blank newlines, lines containing a specific number of underscores (`_`) and lines with a lone character.

After noticing that four underscore lines preceding the `{` symbol might match `flag`, we are convinced that the number of underscores of each line represent a character.

Therefore, we can decode the given ciphertext using this command:

```
$ cat ec5883451bb7d0aa6b5950e39ed5f16d | while read line; do [[ $line =~ '_' ]] && printf \\$(printf "%o" $((${#line}+96))) || echo -n $line; done
thisizjus7ali77lej0k3;)flag{g1v3-m3-th4-flag}
```

## Other write-ups and resources

* <http://0xa.li/th3jackers-2015-ctf-misc100-writeup/>
* <https://ctf-team.vulnhub.com/the3jackers-2015-misc100/>
