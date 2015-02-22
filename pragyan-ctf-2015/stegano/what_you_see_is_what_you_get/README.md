# Pragyan CTF 2015: What you see is what you get.

**Category:** Steganography
**Points:** 50
**Solves** 87
**Description:**

> Find and submit the {flag}
>
> [stego_50.jpg](stego_50.jpg)

## Write-up

using `binwalk`, we see that the provided picture contains a zip archive:

```bash
$ binwalk stego_50.jpg
DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             JPEG image data, JFIF standard  1.02
10541         0x292D          Zip archive data, at least v1.0 to extract, compressed size: 37,  uncompressed size: 37, name: "usethis"
10720         0x29E0          End of Zip archive
```

We extract this archive using `binwalk -e stego\_50.jpg` and get a zip archive, which contains a txt file named `usethis`:

```bash
$ cat usethis
steghide.sourceforge.net/download.php
```

So we use `steghide` to extract additional hidden data in the picture:

```bash
$ steghide extract -sf stego_50.jpg
Enter Passphrase: 
```

We get the passphrase using `strings -a stego\_50.jpg`
```bash
$ strings -a stego_50.jpg
JFIF
  %*5-%'2(  .?/279<<<$-BFA:F5;<9
  9& &99999999999999999999999999999999999999999999999999
[...]
RP!h
usethisUT
steghide.sourceforge.net/download.phpPK
usethisUT
Delta_Force\m/
```

The passphrase to extract data using `steghide` is `Delta\_Force\m/`:


```bash
$ steghide extract -sf stego_50.jpg
Enter Passphrase: (Delta_Force\m/)
wrote extracted data to "key_stego_1"
$ cat key_stego_1
Congrats! This was way too wasy :P

This is the key:

PrAgyaNCTF_sTeg1_key
```

The flag is `PrAgyaNCTF_sTeg1_key`.

## Other write-ups and resources

* none yet
