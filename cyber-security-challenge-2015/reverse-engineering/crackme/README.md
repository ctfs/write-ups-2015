# Cyber Security Challenge 2015: Crackme

**Category:** Reverse Engineering
**Points:** 120
**Description:**

> We found this binary, but we lost the password. Please retrieve it for us.
>
> [`Crackme`](Crackme)

## Write-up

_By haxelion on <http://haxelion.eu/writeup/Crackme_In_Memory_Bruteforce/>_._

As with any crackme, you have to provide a password in order to obtain the flag. If you start reverse engineering the crackme you will quickly understand that the password checking function is far from trivial and that the flag is generated from that password. The only way to obtain the flag is to reverse the password checking algorithm.

Instead of spending a lot of precious time on reversing all that assembly code, I decided to try instrumentation based techniques. Unfortunately, instruction counting using intel Pin and breakpoint counting using `gdb` both failed because of the algorithm specifics. So we have to learn more about that algorithm.

Here is what the password checking algorithm does:

* the main function (`0x400809`) only accepts 20 characters long passwords
* each character of the password is split in individual bits to form a 160
integers array of `0`’s and `1`’s (functions `0x40074a` and `0x4006bd`)
* a loop (`0x400924`) loads 12 different ranges of different sizes of the integer array in a single integer by reassembling the bits (function `0x4007ac`)
* those 12 integers are checked by 11 (one is used twice) different functions
through a call table (function `0x4009f0`)
* each of those functions is different and non-trivial (some of them even use
`sprintf`…)

The instruction counting and breakpoint counting could not work because the checksum ranges are not byte aligned and sometimes cover more than 4 characters. Thus any guided bruteforce of the password would have been slow
and tricky to implement.

But I still did not want to reverse those checksum functions.

What if we could bruteforce those checksum functions directly? We would obtain the correct values and could then reassemble the bit array and obtain the password. The biggest range is 31 bits long which should not take long to
bruteforce.

What is the easiest way to instrument those functions for the bruteforce? An old time reverser best friend: `LD_PRELOAD` of course. Our code will be loaded with the crackme and we can bruteforce those checksum functions
in the init function of our preloaded library.

```c
#include <stdio.h>

// Function pointer of the check functions
unsigned int (*f[]) (unsigned int) = {0x400aaf, 0x400ae1, 0x400b2d, 0x400c21,
                                   0x400ca3, 0x400cb6, 0x400ce2, 0x400e53,
                                   0x400d07, 0x400d2c, 0x400dc1, 0x400cb6};

// The number of bits checked by each function
int bits[] = {4,7,24,31,4,10,15,7,12,27,13,6};

// Declare an init function for our preloaded library
void __attribute__((constructor)) init()
{
    unsigned int i, j;
    for(i = 0; i < 12; i++)
    {
        // compute the maximum value for the bruteforce of each function
        unsigned int limit = 1 << (bits[i]);
        printf("Bruteforcing sub_%x (limit = %u): \n", f[i], limit);
        for(j = 0; j < limit; j++)
        {
            // Call the function and check the output
            if(f[i](j) == 1)
            {
                printf("%u\n", j);
            }
        }
    }
}
```

```bash
$ gcc -o bruteforce.so -shared -fpic bruteforce.c
// Lots of GCC warnings reminding us of how dirty this is

$ LD_PRELOAD=./bruteforce.so ./Crackme
Bruteforcing sub_400aaf (limit = 16):
10
Bruteforcing sub_400ae1 (limit = 128):
103
Bruteforcing sub_400b2d (limit = 16777216):
805098
Bruteforcing sub_400c21 (limit = 2147483648):
0
13
3341
150797
12995853
717638925
1791380749
Bruteforcing sub_400ca3 (limit = 16):
9
Bruteforcing sub_400cb6 (limit = 1024):
0
1
5
21
85
341
Bruteforcing sub_400ce2 (limit = 32768):
24903
Bruteforcing sub_400e53 (limit = 128):
96
Bruteforcing sub_400d07 (limit = 4096):
3336
Bruteforcing sub_400d2c (limit = 134217728):
0
94148244
Bruteforcing sub_400dc1 (limit = 8192):
882
Bruteforcing sub_400cb6 (limit = 64):
0
1
5
21
```

As we can see, more than one values are validated by some checksum functions. However, because the result needs to be a printable password, the largest
values are a safe bet. We can now reassemble the bits and obtain the flag.

```python
#!/usr/bin/python2

# Value obtained from the in memory bruteforce
v = [10,103,805098, 1791380749, 9, 341,  24903, 96,3336, 94148244, 882, 21]
# Number of bit each value should be coded on
b = [ 4,  7,    24,         31, 4,  10,     15,  7,  12,       27,  13,  6]

out = ''
flag = ''
for i in range(len(v)):
    # write a binary string, reverse the order of bits
    out += ('{:0' + str(b[i]) + 'b}').format(v[i])[::-1]
# reverse the final output
out = out[::-1]

# convert each byte into a character
for i in range(0, len(out), 8):
    print('{} {}'.format(out[i:i+8], chr(int(out[i:i+8],2))))
    flag += chr(int(out[i:i+8],2))
```

```
$ python2 reassemble.py
01010100 T
01101110 n
01010110 V
01110010 r
01011010 Z
01010011 S
01000010 B
00110000 0
01100001 a
01000111 G
01010101 U
01100111 g
01010110 V
00110010 2
01101000 h
01101000 h
01100010 b
01000111 G
01010110 V
01111010 z
TnVrZSB0aGUgV2hhbGVz

$ ./Crackme TnVrZSB0aGUgV2hhbGVz
Cookies for you!
The solution is: Nuke the Whales
```

The flag `Nuke the Whales` is simply the base64 decoding of the password (see function `0x400e9c`).

## Other write-ups and resources

* <http://haxelion.eu/writeup/Crackme_In_Memory_Bruteforce/>
