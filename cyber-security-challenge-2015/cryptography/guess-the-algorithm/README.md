# Cyber Security Challenge 2015: Guess the Algorithm

**Category:** Cryptography
**Points:** 15
**Description:**

> When will they finally learn to hash passwords! Another Fortune 500 company breached… Can you recover the password? Unfortunately we don’t have any information on the hashing algorithm…
>
> Hash: `06f8aa28b9237866e3e289f18ade19e1736d809d`

## Write-up

Let’s save the hash to a file and fire up [John the Ripper](http://www.openwall.com/john/):

```bash
$ echo '06f8aa28b9237866e3e289f18ade19e1736d809d' > hash.txt

$ john hash.txt
Warning: detected hash type "raw-sha1", but the string is also recognized as "raw-sha1-linkedin"
Use the "--format=raw-sha1-linkedin" option to force loading these as that type instead
Warning: detected hash type "raw-sha1", but the string is also recognized as "raw-sha"
Use the "--format=raw-sha" option to force loading these as that type instead
Warning: detected hash type "raw-sha1", but the string is also recognized as "raw-sha1-ng"
Use the "--format=raw-sha1-ng" option to force loading these as that type instead
Loaded 1 password hash (Raw SHA-1 [128/128 SSE2 intrinsics 4x])
guesses: 0  time: 0:00:00:36 0.00% (3)  c/s: 12146K  trying: slwerat - slweras
jrahyn+          (?)
guesses: 1  time: 0:00:00:37 DONE (Thu Mar  5 05:47:17 2015)  c/s: 12159K  trying: jrahyn+ - jrahyni
Use the "--show" option to display all of the cracked passwords reliably
```

That first warning is what the challenge description hinted at: this is a LinkedIn hash. The above command already gave us the solution, but just to make sure we recover the expected password, let’s explicitly tell `john` to use the `raw-sha1-linkedin` format:

```
$ john --format=raw-sha1-linkedin hash.txt
Loaded 1 password hash (Raw SHA-1 LinkedIn [128/128 SSE2 intrinsics 4x])
jrahyn+          (?)
guesses: 1  time: 0:00:00:36 DONE (Thu Mar  5 05:51:29 2015)  c/s: 12531K  trying: jrahyn+ - jrahyni
Use the "--show" option to display all of the cracked passwords reliably

$ john --show hash.txt
?:jrahyn+

1 password hash cracked, 0 left
```

The username is `?` and the password is `jrahyn+`.

## Other write-ups and resources

* none yet
