# Hackover CTF 2015: brainplant

**Category:** Pwn
**Points:** 300
**Solves:** 5
**Description:**

> Brainplant 0.13.37 alpha - a power plant configuration tool
> 
> 
> Brainplant (or brain) is a highly secure, fast and extensible configuration tool,
> 
> meant for use in power plants. Since a main requirement was to make use of an easily
> 
> readable and concise configuration language, Brainfuck seemed a reasonable choice.
> 
> However, it's still WIP - currently, the only functional part is the brainfuck
> 
> interpreter.
> 
> 
> Usage:
> 
> just connect to the IP and port (default: 1313) of the service and enter your
> 
> configuration program in the prompt, the output will be returned.
> 
> The maximum length for the program is 4096 characters, you can also terminate the
> 
> program using a null-byte.
> 
> 
> Example:
> 
> Send helloworld.bf, receive "Hello World!"
> 
> Fri Oct 16 20:58:04 CEST 2015:
> 
> - WARNING: Please redownload the tarball, the binary inside it was borked
> 
> 
> Fri Oct 16 21:51:38 UTC 2015:
> 
> Debian 8 x86_64 with 32bit multilib (Linux 3.16.0-4-amd64) 0b2056fc041e8d3922c4dc5ae41cf607 /lib/i386-linux-gnu/i686/cmov/libc-2.19.so
> 
> 
> Sat Oct 17 01:33:43 UTC 2015:
> 
> make sure to use brainplant2.hackover.h4q.it (46.101.249.202) 31337, the old host turned out to behave weird
> 
> 
> 
> /web.hackover.h4q.it/[brain-4bab49d431f87ea1632df6a045067419.tgz](./brain-4bab49d431f87ea1632df6a045067419.tgz)
> 
> 
> nc brainplant2.hackover.h4q.it 31337
> 
> OR
> 
> nc brainplant.hackover.h4q.it 31337


## Write-up

(TODO)

## Other write-ups and resources

* none yet
