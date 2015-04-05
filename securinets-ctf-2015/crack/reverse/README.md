# Securinets Quals CTF 2015: reverse

**Category:** Crack
**Points:** 250
**Solves:** TODO
**Description:** 

> Hint : Find the serial (Trouvez le céréale) 
>
> url : [http://41.231.22.133:8040/2/rev.tar.gz](rev.tar.gz)

## Write-up

That's my first write-up ever, so I apologize in advance if this is a bit clumsy.

What we have here is an ASPack packed binary. Usually, the proper way to solve a packed
binary is to put a breakpoint at the end of the unpacking process and
get a memory dump at that point. Then, we would only have to fix the import table
using tools like importREC and we'd be ready to begin reversing. However, I wasn't
able to achieve that quickly with this binary. I had problem stoping at `popad`, which
is a good sign that the binary is done unpacking. What I did is I used ollydbg and when the
GUI started, I pressed pause, start, pause, I clicked on the GUI app to bring focus 
to it and somehow, ollydbg managed to stop at the entry point of the unpacked binary.
While I can't explan an exact step-by-step process to get to the unpacked entry point,
it was really easy for me to reproduce it by pausing and resuming ollydbd as I just
explained. 

Let's assume you manage to do it as well, you'll get to that instruction:

``` nasm
01241020   . 55             PUSH EBP         ;  Real entry point of SFX code
01241021   . 8BEC           MOV EBP,ESP
01241023   . 81EC 40030000  SUB ESP,340
```

From here it's pretty straight forward. The binary uses a very basic validation
subroutine to make sure that you entered a valid e-mail address. If so, it runs
that code to validate the key you entered.

``` nasm
0124114E   > 66:0F6F05 70FD>MOVQ MM0,QWORD PTR DS:[124FD70]
01241156   . 8D8D C0FDFFFF  LEA ECX,DWORD PTR SS:[EBP-240]
0124115C   . F3:            PREFIX REP:                              ;  Superfluous prefix
0124115D   . 0F7F45 E4      MOVQ QWORD PTR SS:[EBP-1C],MM0
01241161   . 8D51 01        LEA EDX,DWORD PTR DS:[ECX+1]
01241164   . C745 F4 6C7572>MOV DWORD PTR SS:[EBP-C],6572756C
0124116B   . 66:0F6F05 60FD>MOVQ MM0,QWORD PTR DS:[124FD60]
01241173   . F3:            PREFIX REP:                              ;  Superfluous prefix
01241174   . 0F7F45 C0      MOVQ QWORD PTR SS:[EBP-40],MM0
01241178   . 66:C745 F8 2E0>MOV WORD PTR SS:[EBP-8],2E
0124117E   . 66:0F6F05 50FD>MOVQ MM0,QWORD PTR DS:[124FD50]
01241186   . F3:            PREFIX REP:                              ;  Superfluous prefix
01241187   . 0F7F45 D0      MOVQ QWORD PTR SS:[EBP-30],MM0
0124118B   . C745 E0 69733A>MOV DWORD PTR SS:[EBP-20],3A7369
01241192   > 8A01           MOV AL,BYTE PTR DS:[ECX]
01241194   . 41             INC ECX
01241195   . 84C0           TEST AL,AL
01241197   .^75 F9          JNZ SHORT rev.01241192
01241199   . 2BCA           SUB ECX,EDX
0124119B   . 83F9 10        CMP ECX,10
0124119E   . 0F85 FD000000  JNZ rev.012412A1
012411A4   . 80BD C0FDFFFF >CMP BYTE PTR SS:[EBP-240],42
012411AB   . 0F85 F0000000  JNZ rev.012412A1
012411B1   . 0FBE85 CFFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-231]
012411B8   . 83C0 42        ADD EAX,42
012411BB   . 3D 9B000000    CMP EAX,9B
012411C0   . 0F85 DB000000  JNZ rev.012412A1
012411C6   . 0FBE8D C1FDFFF>MOVSX ECX,BYTE PTR SS:[EBP-23F]
012411CD   . 8D41 FD        LEA EAX,DWORD PTR DS:[ECX-3]
012411D0   . 83F8 57        CMP EAX,57
012411D3   . 0F85 C8000000  JNZ rev.012412A1
012411D9   . 0FBE85 CEFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-232]
012411E0   . 03C1           ADD EAX,ECX
012411E2   . 3D 9B000000    CMP EAX,9B
012411E7   . 0F85 B4000000  JNZ rev.012412A1
012411ED   . 0FBE8D C2FDFFF>MOVSX ECX,BYTE PTR SS:[EBP-23E]
012411F4   . 8D41 01        LEA EAX,DWORD PTR DS:[ECX+1]
012411F7   . 83F8 3A        CMP EAX,3A
012411FA   . 0F85 A1000000  JNZ rev.012412A1
01241200   . 0FBE85 CDFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-233]
01241207   . 03C1           ADD EAX,ECX
01241209   . 3D 9B000000    CMP EAX,9B
0124120E   . 0F85 8D000000  JNZ rev.012412A1
01241214   . 80BD C3FDFFFF >CMP BYTE PTR SS:[EBP-23D],64
0124121B   . 0F85 80000000  JNZ rev.012412A1
01241221   . 0FBE85 CCFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-234]
01241228   . 83C0 64        ADD EAX,64
0124122B   . 3D 9B000000    CMP EAX,9B
01241230   . 75 6F          JNZ SHORT rev.012412A1
01241232   . 80BD C4FDFFFF >CMP BYTE PTR SS:[EBP-23C],6D
01241239   . 75 66          JNZ SHORT rev.012412A1
0124123B   . 0FBE85 CBFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-235]
01241242   . 05 81000000    ADD EAX,81
01241247   . 3D C8000000    CMP EAX,0C8
0124124C   . 75 53          JNZ SHORT rev.012412A1
0124124E   . 0FBE8D C5FDFFF>MOVSX ECX,BYTE PTR SS:[EBP-23B]
01241255   . 8D41 D3        LEA EAX,DWORD PTR DS:[ECX-2D]
01241258   . 83F8 44        CMP EAX,44
0124125B   . 75 44          JNZ SHORT rev.012412A1
0124125D   . 0FBE85 CAFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-236]
01241264   . 03C1           ADD EAX,ECX
01241266   . 3D AA000000    CMP EAX,0AA
0124126B   . 75 34          JNZ SHORT rev.012412A1
0124126D   . 80BD C6FDFFFF >CMP BYTE PTR SS:[EBP-23A],34
01241274   . 75 2B          JNZ SHORT rev.012412A1
01241276   . 0FBE85 C9FDFFF>MOVSX EAX,BYTE PTR SS:[EBP-237]
0124127D   . 83C0 34        ADD EAX,34
01241280   . 3D 9B000000    CMP EAX,9B
01241285   . 75 1A          JNZ SHORT rev.012412A1
01241287   . 80BD C7FDFFFF >CMP BYTE PTR SS:[EBP-239],63
0124128E   . 75 11          JNZ SHORT rev.012412A1
01241290   . 0FBE85 C8FDFFF>MOVSX EAX,BYTE PTR SS:[EBP-238]
01241297   . 83C0 63        ADD EAX,63
0124129A   . 3D 9B000000    CMP EAX,9B
0124129F   . 74 1A          JE SHORT rev.012412BB

```

So let's take a quick look at it.

First of all, we find out that the key will be 0x10 bytes long, so 16 bytes.

``` nasm
01241199   . 2BCA           SUB ECX,EDX
0124119B   . 83F9 10        CMP ECX,10
0124119E   . 0F85 FD000000  JNZ rev.012412A1
```

Accessing our key input was done using `EBP-240` so we know that the key
will be from `EBP-240` to `EBP-231`. From here, it's only arithmetic. It's
pretty straight forward.

``` nasm
012411A4   . 80BD C0FDFFFF >CMP BYTE PTR SS:[EBP-240],42
```
Ok, so the first char is 0x42 : 'B'

``` nasm
012411B1   . 0FBE85 CFFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-231]
012411B8   . 83C0 42        ADD EAX,42
012411BB   . 3D 9B000000    CMP EAX,9B
012411C0   . 0F85 DB000000  JNZ rev.012412A1
```
Here, we know that our letter + 0x42 = 0x9b, so 0x9b - 0x42 is our char : 'Y'
This char is the last char of the key as it must be at the 16th position
(`EBP-231`)

Math are pretty much that simple for the remainder of the code. The most
"tricky" part is when one value is computed based on another key value like this :

``` nasm
012411ED   . 0FBE8D C2FDFFF>MOVSX ECX,BYTE PTR SS:[EBP-23E]
012411F4   . 8D41 01        LEA EAX,DWORD PTR DS:[ECX+1]
012411F7   . 83F8 3A        CMP EAX,3A
012411FA   . 0F85 A1000000  JNZ rev.012412A1
01241200   . 0FBE85 CDFDFFF>MOVSX EAX,BYTE PTR SS:[EBP-233]
01241207   . 03C1           ADD EAX,ECX
01241209   . 3D 9B000000    CMP EAX,9B
0124120E   . 0F85 8D000000  JNZ rev.012412A1
```

So, on line `012411ED`, the 3rd char (`EBP-23E`) is moved into ECX register.
What we're looking at right now, is at address `01241200` and the followings.
The 14th char (`EBP-233`) must be: our char + ECX = 0x9b.
So we have to take our 3rd char computed just before and substract it from 0x9b
and we get our char. That's pretty much the trickiest arithmetic we have to do.

I did all the math by hand and wrote that python script to print the key from the hex values :

``` py
#!/usr/bin/env python3

key = [0x42,  0x5a, 0x39, 0x64, 0x6d, 0x71, 0x34, 0x63, 0x38, 0x67, 0x39, 0x47, 0x37, 0x62, 0x41, 0x59]

for c in key:
    print(chr(c), end='')

```

The key is : BZ9dmq4c8g9G7bAY

## Other write-ups and resources

* <http://maroueneboubakri.ctf.tn/securinets-ctf-2015-quals-re250-task-writeup/>
