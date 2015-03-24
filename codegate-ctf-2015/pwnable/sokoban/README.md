# CodeGate General CTF 2015: Sokoban

**Category:** Pwnable
**Points:** 1000
**Solves:** TODO
**Description:** 

> Binary : [http://binary.grayhash.com/2119d600d79a81bcfeca15676446bcc4/soko](soko)
> Server : gate.grayhash.com
> Port : TCP 12345 (telnet gate.grayhash.com 12345)
> OS : Ubuntu 14.04.2 LTS x86-64
> Env : /lib/x86_64-linux-gnu/libc-2.19.so
> 	/lib/x86_64-linux-gnu/ld-2.19.so
> Flag : /home/soko/flag

## Write-up

The problem is a game that called **sokoban**. lol  
After we pass the 0 ~ 5 levels, we will enter a menu and choose the game mode.  

The menu looks like:  

> 1. Go to random infinite challenge mode
> 2. Go to next stage

Next, we opened ida pro and reverse the binary.  
We can easily see the code like:  

```
if (playgame() == 1)
    get_flag();
puts(s);
return;
```

Then we traced how the return value assigned......  
```
// just pseudo code
if (win)
  passed++;
return (passed == 228) ? 2 : 0;
```
228 is the amount of level.  
It seems impossible to arrive `get_flag()`. XD  
But our goal is very clear, **control the EIP and go to `get_flag()`**.  

We inadvently found the game sometimes generate a blank map in random mode.  
Then checking the rule of movement, it restrict the character by the element in the map, not the size of map.  
Therefore, once we get the blank map, we can move the character to anyware in **bss segment** and **GOT segment**.  

There is a defination of element:  

- \x00: nothing
- \x01: destination of box
- \x02: wall
- other: it's not important.

According the rule of sokoban, we can push a byte onto \x00 or \x01.  
It's very difficult to use......  
I try to move the content of GOT at first, but I found GOT looks like:  

> <time@got.plt>:        0xf7ffafa0      0x00007fff      0x00400dd6      0x00000000  
> <wgetch@got.plt>:      0xf7bc2f90      0x00007fff      0x00400df6      0x00000000  
> <noecho@got.plt>:      0xf7bc0a50      0x00007fff      0x00400e16      0x00000000  
> <wmove@got.plt>:       0xf7bc4e40      0x00007fff      0xf799de70      0x00007fff  
> <mvprintw@got.plt>:    0xf7bc7db0      0x00007fff      0xf7bc0ad0      0x00007fff  

Almost all byte are adjacent to each other.  
Therefore, we can't change the GOT area at most situation except ASLR was enable.  
For example, it's possible to appear the libc address likes **0x7fffff00xx**.  
So we can modify a byte on GOT to somewhere in libc.  

It seem useless....  
But after I check all possible gadgets, I found a magic gadget at **0x3e260**.  
That is `add rsp, 0x28; (pop XX)*6; ret`.  
And the address of `rand()` is **0x3d060**.  
If we modify `rand()` to magic gadget, the return address is **0x401a9a** after we execute `rand()` again.  
Luckily, there are a hidden function in the game.  
If we press `v`, it will add 0x12 on **0x60c120**.  
And, 0x3e260 - 0x3d060 = 0x12......  

So, we have already bypassed the action of assign value to EAX.  
If we can control EAX and set EAX=1, we can enter the function `get_flag()`.  
Lucklily, if the argument of wgetch is \x00, the return value will be 1.  
At x86 architecture, the return value will store in EAX.  
EAX won't be modified until call `rand()`.  
Until here, the program will print the flag. :)  

flag: `WH0n in OOme, ZZ as 12e RolanS`  


## Other write-ups and resources

* <http://pastebin.com/CZR6H3VY>
* <http://winesap.logdown.com/posts/257682-codegate-ctf-preliminary-2015> (chinese)
