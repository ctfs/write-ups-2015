# BCTF CTF 2015: backdoor

**Category:** Crypto + Programming
**Points:** 600
**Solves:** 1
**Description:** 

> tsh is my favorite backdoor in use. So I forked on github and add some my own functions.
> 
> <https://github.com/zTrix/tsh/commit/f3ef65cbe8a42995ef9c183fb59de2e2d966a8d5>
> 
> I’ve setup a tsh client in cb mode, running at 146.148.60.107 7586, with my secret set, and repeatedly ping some important info out.
> 
> But very weird someone can steal my info, can you steal it?
> 
> You need exploit, crypto, coding, debugging skills, as well as luck and network speed, to solve this challenge.
> 
> tip: flag length less than 22( BCTF{} included)
> 
> tip2: challenge constant in pel.c not modified
> 
> update:
> 
> The server running binary has alarm(3) uncommented in tsh.c. link here: <https://github.com/zTrix/tsh/commit/f3ef65cbe8a42995ef9c183fb59de2e2d966a8d5#diff-245ad4e8eff2c0fa695986cd7e83dff6R177>

## Write-up

(TODO)

## Other write-ups and resources

* <https://github.com/zTrix/tsh/blob/bctf/solve.py>