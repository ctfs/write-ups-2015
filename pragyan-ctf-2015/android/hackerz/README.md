# Pragyan CTF 2015: Hackerz

**Category:** Android
**Points:** 100
**Solves** 75
**Description:**

> Adam and Eve where in the Garden of Eden. Snake offered apple to Eve and that was the first SYN.
>
> [circle.apk](circle.apk)

## Write-up

When decompiling the `circle.apk` application file with [jadx](https://github.com/skylot/jadx), we see four Java files:

```bash
$ jadx -x circle.apk
INFO  - output directory: circle
INFO  - loading ...
WARN  - Indent < 0
INFO  - processing ...
INFO  - done
$ tree
.
├── AndroidManifest.xml
└── com
	└── pragyan
		└── circle
			├── Main.java
			├── a.java
			├── b.java
			└── c.java

3 directories, 5 files
```

In `b.java`, we see a base64 encoded string, `eTB1XzRyM180X2g0Y2szcg==`.

By base64 decoding this string, we get the flag:

```bash
$ base64 --decode <<< 'eTB1XzRyM180X2g0Y2szcg=='
y0u_4r3_4_h4ck3r
```

The flag is `y0u_4r3_4_h4ck3r`.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/pragyan-ctf-2015-android/>
