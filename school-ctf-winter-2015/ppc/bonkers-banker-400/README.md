# School CTF Winter 2015 2015: Bonkers Banker

**Category:** Ppc
**Points:** 400
**Solves:** 
**Description:**

> I know an old mad moneybags. He had invented his own language but nobody wanted to talk in it. Then he decided to give all his money to the guy who can talk with him and will be very good at accounting.
> 
> 
> nc sibears.ru 10028
> 
> 
> nc sibears.ru 12028
> 
> 
> nc sibears.ru 13028
> 
> 
> May be that piece of code will be useful for you:
> 
> 
> def encode(self, str):
> 
>    codes = []
> 
>    for c in str:
> 
>      codes.append(hex(ord(c))[::-1])
> 
>    return ' '.join(codes)


## Write-up

[writeup.md](./writeup.md)

## Other write-ups and resources

* none yet
