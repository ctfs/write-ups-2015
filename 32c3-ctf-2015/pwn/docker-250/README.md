# 32C3 CTF 2015 : docker

**Category:** Pwn
**Points:** 250
**Solves:** 7
**Description:**

> Extract some flag from ssh://eve@136.243.194.40
> 
> 
> Password: nohaxplz

## System Information

Here are some information that can help to set up the challenge locally.

@tsuro via IRC: `and you want a kernel that is not too ancient. I used ubuntu 14.04`

    eve@docker:/$ uname -a
    Linux docker 3.19.0-42-generic #48~14.04.1-Ubuntu SMP Fri Dec 18 10:24:49 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
    eve@docker:/$ id
    uid=1338(eve) gid=65534(nogroup) groups=65534(nogroup)
    eve@vault:/$ cat /etc/passwd
    # snip... relevant users:
    adam:x:1337:65534::/home/adam:
    eve:x:1338:65534::/home/eve:

The user adam owns the flag and there is a setuid binary `dockerrun`, which just executes `/usr/bin/docker run -it --privileged=false -u 1337:65534 --cap-drop=ALL --net=host ubuntu /bin/bash`.

    eve@docker:/$ ls -la /home/adam
    total 24
    dr-xr-xr-x 2 root root 4096 Dec 27 14:21 .
    drwxr-xr-x 4 root root 4096 Dec 27 13:47 ..
    -rwsr-xr-x 1 root root 8556 Dec 27 13:40 dockerrun
    -r-------- 1 adam root   53 Dec 27 14:32 flag
    eve@docker:/$ /home/adama/dockerrun 
    I have no name!@docker1404:/$ 

## Write-up

(TODO)

## Other write-ups and resources

* <https://kitctf.de/writeups/32c3ctf/docker/>
* <http://ebfe.dk/2016/01/04/pwning-docker/>
* <https://gist.github.com/stephenR/5d0987531e2b3ab3a730>
