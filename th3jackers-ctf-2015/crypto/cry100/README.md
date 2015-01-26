# Th3Jackers CTF 2015: OHSHIT

**Category:** Crypto
**Points:** 100
**Solves** 49
**Description:**

> Description: Decrypt the cipher using the encryption program
>
> Attachment: [53036532009087f6faf540c84b32dace](53036532009087f6faf540c84b32dace)

## Write-up

We are given a binary and a Readme, called [crypto.txt](crypto.txt) and are instructed to use the binary to decode the message:

> 019t-0-080-3-1b-19t-25z-080-03f-8j-1b-12n-12n

We first call crypto without any parameters:

```
$ ./crypto
Enter the fucking argument
```

So we enter a parameter `a` and see, that the output is the decrypted character sequence for this char:

```
$ ./crypto a
Crypted text: 1b
```

Because this matches one of our encode character sequences, we will run the binary with every lower/uppercase character as well as number and special character we can think of:

```
for i in {{A..z},{0..9},.}; do echo -n "[$i]: "; ./crypto $i; done
```

The resulting coding table is [here](decode).

We are decoding the given ciphertext `019t-0-080-3-1b-19t-25z-080-03f-8j-1b-12n-12` using the coding table and get `S-0-.-3-a-s-y-.-c-h-a-l-l`.

Removing all dashes (`-`) and we get the flag: `flag{S0.3asy.chall}`

## Other write-ups and resources

* <http://0xa.li/th3jackers-2015-ctf-crypto100-writeup/>
* <https://ctf-team.vulnhub.com/th3jackers-2015-crypto100/>
