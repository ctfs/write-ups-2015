# ASIS Cyber Security Contest 2015: particles

**Category:** forensic
**Points:** 175
**Solves:** 9
**Description:**

> I had a bet with Gordon Kane of Michigan University that the Higgs particle wouldn't be found.
> 
> - Stephen Hawking

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writups:

* <https://kt.pe/blog/2015/10/asis-2015-finals-particles/>
* <https://www.ibrahim-elsayed.com/?p=124>

We are given a xz compressed tar archive that we extract using `unxz` and `tar xvf` to find a tcpdump capture file:

```bash
$ file particles.pcap
particles.pcap: tcpdump capture file (little-endian) - version 2.4 (Ethernet, capture length 262144)
```

Opening the pcap using `wireshark` reveals that `zsync` was used to transfer files between two machines.

The header of each `zsync` request and response looks like this:

![](./wireshark-zsync.png)

We can see a SHA-1 hashsum of the file transferred.

All in all, 6 files have been transmitted:

```bash
$ strings particles.pcap | grep SHA-1 
SHA-1: 9be3800b49e84e0c014852977557f21bcde2a775
SHA-1: e227c6d298358d53374decb9feaacb463717e2d9
SHA-1: 2d27f6e5bafdf23c7a964a325ebf3a5ee9ca4b18
SHA-1: 8f1fa762c3bf865d0298e7a8fd3640c606962122
SHA-1: 7e05370d87196157bc35f920d7fcf27668f8e8af
SHA-1: e8c7d65370947b40418af55bdc0f65e06b7b0c59
```

Searching for these hashsums we finally find a [malware analysis result](https://www.hybrid-analysis.com/sample/688a3ac91914609e387111e6382911ecd0aefe9f4f31bed85438b65af390cf6f?environmentId=2) that contains a screenshot with the flag:

![](./screen_0.png)

The flag is `ASIS{c295c4f709efc00a54e77a027e36860c}`.

The actual and intended solution is to reassemble the files transmitted [as this writeup describes](https://kt.pe/blog/2015/10/asis-2015-finals-particles/) and run one of these files, a PE executable, to get the flag.

## Other write-ups and resources

* <https://kt.pe/blog/2015/10/asis-2015-finals-particles/>
* <https://www.ibrahim-elsayed.com/?p=124>
