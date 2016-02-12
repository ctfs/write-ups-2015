# Hack Dat Kiwi CTF 2015: SSL Sniff 2

**Category:** Forensics
**Points:** 120
**Solves:** 77
**Description:**

> We received a network capture file of an HTTPS request that was MITMd. This time we know that the actual request had useful information, and thanks to
> 
> you we now have the culprit's private key [server.key.insecure](./server.key.insecure). Find the useful information.
> 
> [Download](./client.pcap)


## Write-up

by [polym](https://github.com/abpolym)

We are given a tcpdump of SSL encrypted data and a RSA key that should decrypt this conversation.

This is easily done using `wireshark`: `Preferences -> Protocols -> SSL -> Edit RSA keys list`, then input all required information (e.g. key file location, IP etc):

![](./wireshark-sslkey.png)

Afterwards, we can just see the decrypted SSL conversation using `Analyze -> Follow -> SSL Stream`:

![](./wireshark-sslfollow.png)

The flag is `39u7v25n1jxkl123`.

## Other write-ups and resources

* <http://justpentest.blogspot.in/2015/11/CTF-hack-dat-kiwi-writeups.html>
* <https://ctftime.org/writeup/2143>
* <http://cafelinux.info/articles/writeups-hack-dat-kiwi-ssl-sniff-1-50>
* <http://edholabs.ga/ctf_writeups/dump.png>
* <http://hack.dat.kiwi/writeup#SSL_Sniff_2>
