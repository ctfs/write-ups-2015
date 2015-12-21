# School CTF Winter 2015: 3 bits RGB

**Category:** Crypto
**Points:** 500
**Solves:** 
**Description:**

> Unfortunately, this task is inextricably linked with Russian language.
> 
> 
> Walking around the campus we have found a strange list of Russian words. Looks like it has been lost by someone who is really interested in Russian language and its idioms. Bellow of the list there is one more stange string
> 
> 
> 0x15 0x24 0x90 0xe5 0xed 0xfe 0x8f 0x16 0xb6 0x89 0x0e 0x48
> 
> 
> [Task](./task_c516d0c000419c7e7ab4de9b9dbe5751dad61eda.txt)


## Write-up

<div><h3>3 bits RGB</h3><p>﻿That one is really hard to do even for native Russian speakers, but if you are really good in googling or you are familar with some specialist in Russian language you can try to do it :)</p>
<p>All that words can be connected with some colors to form an idiom like "Голубой вагон", "Жёлтая пресса", "Белая горячка". The next hard part is to translate colors into English without losing its bit structure in RGB. According to task you should match every color with it representation in 3 bits RGB scheme. So if you have cyan color corresponding color will be <code>011</code> cos it consist of green and blue colors mixed in certain proportions.</p>
<p>When we encode all colors in the described way we should to XOR it with a given in the task byte-string and get the flag <code>magic_colors</code></p></div>

## Other write-ups and resources

* none yet
