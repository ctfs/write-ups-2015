# OpenToAll CTF 2015: Gone

**Category:** Forensics
**Points:** 200
**Solves:** 30
**Author:** Eriner
**Description:** 

> It seems that my files are gone!
> 
> [http://public.givemesecurity.info/gone.img.tar.bz2](gone.img.tar.bz2)

## Write-up

We are given a bzip2 file. Let's extract it first.

```bash
$ tar -xvf gone.img.tar.bz2
1fdb86c25131bb3aa247bada29b29115.img
$ file 1fdb86c25131bb3aa247bada29b29115.img
1fdb86c25131bb3aa247bada29b29115.img: Linux rev 1.0 ext4 filesystem data, UUID=1385df22-b2ce-4b4f-858e-79ae1932ca1a (extents) (huge files)
```

So now we have an ext4 filesystem. However, if we mount it there is nothing inside.
Using extundelete on it reveal that the filesystem is corrupted.

```bash
$ extundelete 1fdb86c25131bb3aa247bada29b29115.img
No action specified; implying --superblock.
extundelete: The ext2 superblock is corrupt when trying to open filesystem 1fdb86c25131bb3aa247bada29b29115.img
```

Let's try to repair it using fsck:

```bash
$ fsck.ext4 1fdb86c25131bb3aa247bada29b29115.img
e2fsck 1.42.12 (29-Aug-2014)
ext2fs_open2: The ext2 superblock is corrupt
fsck.ext4: Superblock invalid, trying backup blocks...
1fdb86c25131bb3aa247bada29b29115.img was not cleanly unmounted, check forced.
Pass 1: Checking inodes, blocks, and sizes
Pass 2: Checking directory structure
Pass 3: Checking directory connectivity
Pass 4: Checking reference counts
Pass 5: Checking group summary information
Free blocks count wrong for group #0 (6789, counted=488).
Fix<y>? yes
Free blocks count wrong for group #1 (2006, counted=228).
Fix<y>? yes
Free blocks count wrong (8795, counted=716).
Fix<y>? yes
Free inodes count wrong for group #0 (1269, counted=1262).
Fix<y>? yes
Free inodes count wrong (2549, counted=2542).
Fix<y>? yes

1fdb86c25131bb3aa247bada29b29115.img: ***** FILE SYSTEM WAS MODIFIED *****
1fdb86c25131bb3aa247bada29b29115.img: 18/2560 files (11.1% non-contiguous), 9524/10240 blocks
```

Now if we mount it, we get some interesting files:

```bash
$ ls
AE5  file  fil.enc  lost+found  ran2  ran3  ran4  rand
$ binwalk fil.enc
Scan Time:     2015-03-09 15:35:08
Target File:   /tmp/wu/tmp/fil.enc
MD5 Checksum:  cb84f2cc7d776e83ebe0bd17efa163f4
Signatures:    328

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             OpenSSL encryption, salted, salt: 0x-6BC6193B4330E12E
$ cat AE5
4[71A3j9[\22?/+u0
```

The fil.enc file seems to be an openssl encrypted file according to binwalk while the AE5 file is clearly a hint about the encryption algorithm and probably the key. Decrypting it with various AES algorithms leads us to a valid png file :

```bash
$ openssl enc -d -aes-128-ctr -in fil.enc -out fil.out -kfile AE5 
$ file fil.out 
fil.out: PNG image data, 1300 x 1076, 8-bit/color RGBA, non-interlaced
```

Opening it gives us the flag:

![Decrypted file](fil.out)

```bash
flag : flag{ext_sooper_blocks_are_c00l}
```

## Other write-ups and resources

* none yet
