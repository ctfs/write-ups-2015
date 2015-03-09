# OpenToAll CTF 2015: Lost Flug

**Category:** Forensics
**Points:** 75
**Solves:** 88
**Author:** kee7a
**Description:** 

> [http://public.givemesecurity.info/cap.pcapng.zip](cap.pcapng.zip)

## Write-up

We are given a pcapNG capture file with a bunch of UDP and TCP traffic.

When searching the file for usual keywords using `strings`, we see something interesting whilst `grep`ing looking for `password`:

```bash
$ strings -a cap.pcapng | igrep password
:rajaniemi.freenode.net 372 logman1337 :- including SSL traffic - has been sniffed and passwords
:rajaniemi.freenode.net 372 logman1337 :- password(s) to a new value which is not shared with any
:rajaniemi.freenode.net 372 logman1337 :- You can do this with /msg nickserv set password newpasshere
:rajaniemi.freenode.net 372 logman1337 :- passwords again after analysis has completed.
```

This is suspicious, so we look for `logman1337`'s activity:

```bash
$ strings -a cap.pcapng | igrep logman1337
arB=NICK logman1337
:rajaniemi.freenode.net 001 logman1337 :Welcome to the freenode Internet Relay Chat Network logman1337
:rajaniemi.freenode.net 002 logman1337 :Your host is rajaniemi.freenode.net[195.148.124.79/6665], running version ircd-seven-1.1.3
:rajaniemi.freenode.net 003 logman1337 :This server was created Tue Oct 21 2014 at 11:19:23 UTC
:rajaniemi.freenode.net 004 logman1337 rajaniemi.freenode.net ircd-seven-1.1.3 DOQRSZaghilopswz CFILMPQSbcefgijklmnopqrstvz bkloveqjfI
[...]
:rajaniemi.freenode.net 305 logman1337 :You are no longer marked as being away
ardC)oR1:logman1337!~logman@162.245.177.238 JOIN #XPvCxHRTCFKBBzyb
:rajaniemi.freenode.net 353 logman1337 @ #XPvCxHRTCFKBBzyb :logman1337 @kee7a
:rajaniemi.freenode.net 366 logman1337 #XPvCxHRTCFKBBzyb :End of /NAMES list.
)oS":rajaniemi.freenode.net 352 logman1337 #XPvCxHRTCFKBBzyb ~logman 162.245.177.238 rajaniemi.freenode.net logman1337 H :0 logman
:rajaniemi.freenode.net 352 logman1337 #XPvCxHRTCFKBBzyb ~kee7a unaffiliated/kee7a kornbluth.freenode.net kee7a H@ :0 kee7a
:rajaniemi.freenode.net 315 logman1337 #XPvCxHRTCFKBBzyb :End of /WHO list.
```

He joined the channel `#XPvCxHRTCFKBBzyb` on `freenode.net`.

After joining the channel with the same username (no authentification as far as I know), we see a user named `flag{Us3EsS31}` using `\names` in IRC.

The flag is `flag{Us3EsS31}`

## Other write-ups and resources

* none yet