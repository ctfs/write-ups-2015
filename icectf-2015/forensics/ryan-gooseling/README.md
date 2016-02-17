# IceCTF 2015: Ryan Gooseling

**Category:** Forensics
**Points:** 50
**Description:** 

> We found this [disk image](./disk.img), looks like the file system is b0rked... Can you take a look at it?

**Hint:**

> Where we're going we don't need file systems

## Write-up

by [polym](https://github.com/abpolym)

We are given an image:

```bash
$ +bash-4.3$ file disk.img 
disk.img: Linux rev 1.0 ext2 filesystem data (extents) (huge files)
```

Applying `foremost` on the image to carve out existing files on the system reveals three jpgs:

```bash
$ foremost disk.img
Processing: disk.img
|*|
$ tree output/
tree output/
output/
├── audit.txt
└── jpg
    ├── 00002562.jpg
    ├── 00002726.jpg
    └── 00002828.jpg

1 directory, 4 files
```

`00002562.jpg` contains the flag, `Flag_gooselings_cant_drive`:

![](./00002562.jpg)

## Other write-ups and resources

* <http://73696e65.github.io/blog/2015/08/24/icec-dot-tf-writeup/>
