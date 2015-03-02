# Boston Key Party CTF 2015: Symphony

**Category:** School-Bus
**Points:** 25
**Solves** 
**Description:**

> A less than four characters number, bigger than 999?Maybe the bug is elsewhere. : 25

## Write-up

we need an input that is less than 3 chars and get beyond is_numeric
we can get beyond is_numeric with hex input likt 0x1 but 0x0->0xf noone is > 999
so the solution is with e like 5e8

## Other write-ups and resources

* none yet
