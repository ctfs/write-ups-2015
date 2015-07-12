# Ghost in the Shellcode 2015: Cloudfs

**Category:** Forensics
**Points:** 200
**Description:**

> Find the key! ([File](cloudfs-31c938df3531611b82fddf0685784a2b67373305ec689015f193a555b756beb2))

## Write-up

Writeup by boogy

The file we were given if a pcapng file. To be able to read'it with scapy we need to convert it to pcap. The easiest way is to use tcpdump as so:

```bash
tcpdump -r cloudfs-31c938df3531611b82fddf0685784a2b67373305ec689015f193a555b756beb2 -w cloudfs.pcap
```

Use scapy to extract all icmp packets:

```python
#!/usr/bin/env python
# -\*- coding: utf-8 -\*-
from scapy.all import *

r = rdpcap("cloudfs.pcap")
l = len(r)
print l
D = []
for i in range(0, l):
    if ICMP in r[i]:
        print 'OK'
        print r[i][ICMP].summary()
        if r[i][ICMP].type == 8 : # ICMP request
            d = str(r[i][Raw]).encode('hex')
            if d not in D:
                D.append(d)
f = open('flag.bin', 'w')
f.write(''.join(D))
f.close()
```
Convert the flag.bin hex to binary in another file named *flag* and use binwalk to extract the archive:

```bash
$ binwalk flag
DECIMAL           HEX               DESCRIPTION
-------------------------------------------------------------------------------------------------------
1480              0x5C8             bzip2 compressed data, block size = 900k
````
```bash
$ binwalk --dd='.*' -e flag
````
We have a *5C8* file which we'll rename in key.
```bash
$ file 5C8
    5C8: POSIX tar archive (GNU)
````
Rename the file and add .tar extension to it and extract:

```bash
$ mv 5C8 key.tar
$ tar xf key.tar
$ cat key
$ key{WhyWouldYouEverUseThis}
````
So the flag is: **key{WhyWouldYouEverUseThis}**

## Alternate Writeup

**forensics/CloudFS** - Ghost in the shell code 2015

On initial investigation I noticed there were 4 differant ICMP request ID's with 1066 bytes of data.

ID's in order being: 0x0d00, 0x0e00, 0x0f00, 0x1000

In the first ICMP request there was a bz2 file header after the first 32 bytes of ICMP request.

42 5a 68 39 31 41 59 26 53 59 | BZh91AY&SY

Copy the hex data and paste it into a hex editor for each of the unique ICMP requests using the data after the inital 32 bytes.

once all pasted and the bz2 file recompiled 

Uncompress it and find "key" which included the **flag: key{WhyWouldYouEverUseThis}**
along with a copy of the python script used to create the challenge.

I'm sure there was an easier way to do this with automation but this seemed to work for me.

## Other write-ups and resources

* <http://blog.reverser.ninja/2015/01/ghost-in-shellcode-2015-cloudfs-writeup.html>
* <http://0xa.li/ghost-in-the-shellcode-2015-ctf-cloudfs-writeup/>
* <http://blog.tinduong.pw/ghost-in-the-shellcode-2015-write-ups/>
* <http://0x1337seichi.wordpress.com/2015/01/18/ghost-in-the-shellcode-2015-cloudfs-writeup/>
* <http://labs.jumpsec.com/2015/01/19/ghost-shellcode-2015-ctf-write-cloudfs-challenge/>
* <https://ctf-team.vulnhub.com/ghost-in-the-shellcode-2015-cloudfs/>
