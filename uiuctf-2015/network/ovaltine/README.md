# UIU CTF 2015: ovaltine

**Category:** Network
**Points:** 100
**Solves:** 78
**Description:** 

> NETWORK: Welcome to the 1337 LOASS...Ralphie!. [ovaltine.7z](https://ctf.acm.illinois.edu/archive/ovaltine.7z)

## Write-up

The challenge consists in a pcap file containing network traffic.
Most of it is encrypted, but a few TCP streams are here, and we quickly find emails exchanged about joining the Little Orphan Annie fanclub.
By exporting the HTTP objects from the capture we can retrieve those emails and find two interesting ones.
The first one is :
```
Ralphie,

Set your ring to shift 8!

The message is: ZMUMUJMZ BW LZQVS GWCZ WDITBQVM!

Annie
```
This is a classic Caesar cypher, and by shifting all letters 8 positions we get:
```
REMEMBER TO DRINK YOUR OVALTINE!
```
Which does not look like the flag.
The second interesting email does not give information on how the messages has been encrypted:
```
Ralphie,

The secret message this week uses a new type of encoding!

The message is: ZmxhZ3todHRwczovL3d3dy55b3V0dWJlLmNvbS93YXRjaD92PXpkQV9fMnRL
b0lVfQ==

Annie
```
But from the == signs at the end of the message, it looks like base64 encoding.
Indeed, decoding the message using base46 yields:
```
flag{https://www.youtube.com/watch?v=zdA__2tKoIU}
```

## Other write-ups and resources

* <http://bobbyblues.com/misc/CTF/uiu2015-ovaltine/>