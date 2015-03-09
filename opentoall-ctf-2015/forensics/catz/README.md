# OpenToAll CTF 2015: Catz

**Category:** Forensics
**Points:** 100
**Solves:** 120
**Author:** Eriner
**Description:** 

> I have some pictures of catz on my drive! I also had a sensitive file on there, but even after it was deleted, it was still there! I took some extra precautions to prevent prying eyes...
> 
> [http://public.givemesecurity.info/d17c5ed999bc505ec80e64c714c6d965.tar.bz2](d17c5ed999bc505ec80e64c714c6d965.tar.bz2)

## Write-up

In this challenge we are given a bzip2 file. After extracting it, we get an ext4 filesystem.

```bash
$ tar -xvf d17c5ed999bc505ec80e64c714c6d965.tar.bz2 
catz.img
$ file catz.img 
catz.img: Linux rev 1.0 ext4 filesystem data, UUID=2d362e1b-69ae-4137-bdbb-4fde2775ac91 (extents) (huge files)
```

After mounting it, the only thing we have is some pictures of cats. Unfortunately, none of them gives us the flag. Let's check if we can recover some deleted files with extundelete.

```bash
$ extundelete --restore-all catz.img
NOTICE: Extended attributes are not restored.
Loading filesystem metadata ... 2 groups loaded.
Loading journal descriptors ... 146 descriptors loaded.
Searching for recoverable inodes in directory / ... 
2 recoverable inodes found.
Looking through the directory structure for deleted files ... 
1 recoverable inodes still lost.
$ ls -Alh RECOVERED_FILES 
total 16K
-rw-r--r-- 1 coriolis coriolis  54 Mar  9 16:52 .cat.jpg
-rw-r--r-- 1 coriolis coriolis 12K Mar  9 16:52 file.17
```

So we recovered two files and checking their content gives us the flag :).

```bash
$ cat RECOVERED_FILES/.cat.jpg 
flag{fugly_cats_need_luv_2}
```

## Other write-ups and resources

* <http://team-jihfu.github.io/2015/03/09/otactf2-2015-catz-forensics-100/>
* <http://www.xenocidewiki.net/blog/ota-ctf-2-2015-catz-writeup>
