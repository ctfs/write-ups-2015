# 32C3 CTF 2015 : config.bin

**Category:** Forensics
**Points:** 150
**Solves:** 27
**Description:**

> We have obtained what we believe is a configuration backup of an embedded device. However, it seems to be encrypted. Maybe you can help us with decryption?


## Write-up

After a quick hexdump we might realize that the first 4 bytes are looking pretty much like a magic header.

    hexdump -C config.bin | head
    00000000  43 46 47 31 00 00 32 d0  ef 92 7a b0 5a b6 d8 0d  |CFG1..2...z.Z...|
    00000010  30 30 30 30 30 30 00 00  00 05 00 03 00 00 00 00  |000000..........|

After searching for "CFG1" with the search engine of our choice, we might find [this](https://heinrichs.io/207) blog entry.  This tells us it might be a firmware image of some router (or at least something which looks like it).  
There is a windows tool on that website to decrypt the firmware images, lets see if it works for us:

    decrypting config.bin...
    reading config.bin... 13056 bytes read.
    parsing header... ok.
    setting crypto key... ok.
    decrypting... MD5 of plaintext invalid.
    
Hmm, nope. That looks like it might be in deed the right algorithm, but something is wrong (maybe the password).  
Well, that would have been too easy otherwise.  
So lets try if we can parse the file header with the information provided in that block entry.
As a a python ctypes Structure the header looks like this:

    class Header(ctypes.BigEndianStructure):
        _fields_ = [
                    ("magic", ctypes.ARRAY(ctypes.c_char, 4)),
                    ("payload_size", ctypes.c_uint32),
                    ("header_md5", ctypes.ARRAY(ctypes.c_ubyte, 8)),
                    ("etl", ctypes.ARRAY(ctypes.c_uint8, 7)), # always zero
                    ("unused_1", ctypes.c_char),
                    ("password_len", ctypes.c_uint16),
                    ("padding_len", ctypes.c_uint16),
                    ("unused_2", ctypes.ARRAY(ctypes.c_ubyte, 4)),
                    ("plaintext_md5", ctypes.ARRAY(ctypes.c_ubyte, 16))
                    ]

The header contains a field for the first 8 bytes of a md5 over the header. After testing if it is correct, we can be pretty sure the header structure is right.  
So, chances are good we need to find the correct password.  
~~Stupidly~~Luckily the length of the password is saved in the header and an MD5 sum over the plaintext, too (The password is of 5 chars length).
According to the linked blog post the *plaintext* is encrypted with AES256 in ECB mode.
That sounds reasonable enough to bruteforce it.  
... But it is way to slow. The decryption of the whole cryptext needs way to long (~13kb after all).  
With ~8k tries per second we'll never find the password.

Maybe we find some other way to verify the password.  
After some searching we might find out that the plaintext of the images in this format always seem to be gzip compressed.  
This is **awesome**, as the gzip format has a 3 byte (2 byte in theory, 3 in fact) magic header.  
So we only need to decrypt the first block with AES and verify the first 3 bytes (With additionally md5 verification IF the magic header was found).  
This gives us about 280k try per second. Not really fast, but it might be fast enough for a password with 5 chars.  
Finally we can start bruteforcing.
After some (more) time we find our password and are able to decrypt the file.  
It is an tar.gz archive containing two files.
Digging through them we find a line like this *(password changed)*:

    PASSWORD="MzJDM19hc2QxMjE1NjRxMTIxZD/nU2NGE1NnNkMWYzMmFkMTMyYTQ1"
After removing that evil `/n` in there we are able to base64 decode it and get the password. **YAY**

*The tool i wrote to crack and decrypt the firmware now makes about 1000000 check per second on my system and is linked in `Other write-ups and resources`*



## Other write-ups and resources

* <https://github.com/SleepProgger/ctf_stuff/blob/master/32C3/config.bin/crack_config.py>
* <https://irq5.io/2015/12/30/32c3-ctf-write-up-config-bin/>
* [Information about the fileformat and decrypter @https://heinrichs.io/](https://heinrichs.io/207)
