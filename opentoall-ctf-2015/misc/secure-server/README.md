# OpenToAll CTF 2015: Secure Server

**Category:** Misc
**Points:** 75
**Solves:** 150
**Author:** kee7a
**Description:** 

> this server is hacker proof... i think.
> 
> 104.131.124.226
>
> Hint: You do not need to bruteforce anything
>
> Hint: The challenge has been tweaked to be less confusing

## Write-up

When running `nmap -p0-65535 -T5 104.131.124.226`, wee see that there are two public services running:

```bash
$ nmap -p0-65535 -T5 104.131.124.226
Starting Nmap 6.47 ( http://nmap.org ) at 2015-03-06 14:12 CET
Warning: 104.131.124.226 giving up on port because retransmission cap hit (2).
Strange error from connect (49):Can't assign requested address
Nmap scan report for 104.131.124.226
Host is up (0.10s latency).
Not shown: 64610 closed ports, 924 filtered ports
PORT     STATE SERVICE
22/tcp   open  ssh
8080/tcp open  http-proxy

Nmap done: 1 IP address (1 host up) scanned in 271.32 seconds
```

The two services is a [simple http server](./104.131.124.226:8080/index.html) that does not reveal any further information and a SSH service, which we don't have the username+password or username+sshkey information for. Bruteforcing is not a solution according to the task authors (see hint).

So we look for common files that can be accessed on the http server, such as `.htaccess`, `index.html~` or `robots.txt` etc.

We see a `robots.txt` file that gives us another directory to search for any hidden information, `/secret`.

Inside `http://104.131.124.226:8080/secret`, we find a [secret.zip](./104.131.124.226\:8080/secret/secret.zip) file that we download and extract:

```bash
$ unzip secret.zip && tree -a
├── __MACOSX
│   ├── ._secret
│   └── secret
│       ├── ._SECRETobservation15september11Rhodes, Greece.jpg
│       ├── ._observation 19november32013.jpg
[...]
│       └── ._observation9december52010.jpg
├── secret
│   ├── .ssh
│   │   ├── key
│   │   └── key.pub
│   ├── SECRETobservation15september11Rhodes, Greece.jpg
│   ├── observation 19november32013.jpg
[...]
│   └── observation9december52010.jpg
└── secret.zip
```

We don't see anything useful in the pictures, which are showing snakes with hats, presumably from [/r/snakeswithhats](http://www.reddit.com/r/SnakesWithHats/) or in the `\_\_MACOSX` folder, so we use the sshkey `key` in the `secret/.ssh` folder and test several usernames, such as `snake`, `root`, `user`, `secret` etc.

We can connect using the username `secret`, but are disconnected immediately:

```bash
$ ssh -i key secret@104.131.124.226
Linux OTAMISC 3.2.0-4-amd64 #1 SMP Debian 3.2.65-1+deb7u1 x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
You have mail.
Last login: XXX
hello, welcome to my secret server
I thought somone may try to break into my server so i setup some extra protection
i dont want to give you a shell, but here is some ascii art for you:
Connection to 104.131.124.226 closed.
```

So the author does not want to give us a shell and setup some extra protection to do so (e.g. setting the default user shell to /bin/false).

However, we can execute commandos using `ssh` itself and see several [different responses](asciiart) for each connection until finally a ascii-flag with a link appears:

```bash
$ ssh -i key secret@104.131.124.226 'echo'
hello, welcome to my secret server
I thought somone may try to break into my server so i setup some extra protection
i dont want to give you a shell, but here is some ascii art for you:
http://cl.ly/image/2c2a3O1T3q3j
[ascii-flag]
```

The link is a picture containing the flag:

![](putthebinthec.jpg)

The flag is `flag{pUttHeBintheC}`.

## Other write-ups and resources

* <http://team-jihfu.github.io/2015/03/09/otactf2-2015-secure-server-misc-75/>
