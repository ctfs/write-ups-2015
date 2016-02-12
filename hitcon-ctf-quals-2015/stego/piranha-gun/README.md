# HITCON QUALS CTF 2015: Piranha Gun

**Category:** Stego
**Points:** 50
**Solves:** 
**Description:**

> The Piranha Gun is a post-Plantera Hardmode ranged weapon that fires a single, returning "piranha" projectile that costs no ammunition.
>
> nc 54.178.235.243 10004


## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on a writeup by [Nandy Narwhals](http://nandynarwhals.org/2015/10/19/hitcon-2015-qualifiers-piranha-gun-stego/).

Connecting to the server, we get a shell as root.

`ls` does give us a README:

```bash
$ ls
ls
README
$ cat README
The Piranha Gun can be found in "jungle.chest".
```

Inside the `/proc/mounts` file, we see a mounted device named `chest` that we can unmount to reveal a hidden file in `/chest/`:

```bash
$ ls -la /chest
ls -la /chest
drwxr-xr-x  2 nobody nogroup 4096 Oct 16 13:31 .
drwxr-xr-x 23 nobody nogroup 4096 Oct 16 13:29 ..
$ cat /proc/mounts | grep chest
cat /proc/mounts | grep chest
/dev/disk/by-uuid/2ed4c374-2ddb-4a75-af24-98df753dbf6d /chest ext4 rw,relatime,discard,data=ordered 0 0
$ umount /chest
$ ls -la /chest
ls -la /chest
total 12
drwxr-xr-x  2 nobody nogroup 4096 Oct 16 13:31 .
drwxr-xr-x 23 nobody nogroup 4096 Oct 16 13:29 ..
-rw-r--r--  1 nobody nogroup   42 Oct 16 13:08 jungle.chest
$ cat /chest/jungle.chest
cat /chest/jungle.chest
hitcon{Wh1re d!d Y0u F1nd the Jungle Key}
```

The key is `hitcon{Wh1re d!d Y0u F1nd the Jungle Key}`.

## Other write-ups and resources

* <https://github.com/pwning/public-writeup/blob/master/hitcon2015/stego50-piranha_gun/writeup.md>
* <http://nandynarwhals.org/2015/10/19/hitcon-2015-qualifiers-piranha-gun-stego/>
* <https://www.youtube.com/watch?v=wXF65WSW2RI>
* <https://kt.pe/blog/2015/10/hitcon-2015-quals-piranha-gun/>
