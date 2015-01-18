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
# -*- coding: utf-8 -*-
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

## Other write-ups and resources

* none yet
