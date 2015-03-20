# Pragyan CTF 2015: Fast and Furious

**Category:** Android
**Points:** 100
**Solves** 69
**Description:**

> [fast.apk](fast.apk)

## Write-up

After decompiling the `fast.apk` application file, we detect a hardcoded string, `65544231587a52794d3138316458417a636c396d4e44553343673d3d`, in `Main.java`.

Converting this Hex string to an ASCII string, we get `eTB1XzRyM181dXAzcl9mNDU3Cg=`, which is a base64 encoded string.

Base64 Decoding this string results in the flag:

```bash
$ base64 --decode <<< 'eTB1XzRyM181dXAzcl9mNDU3Cg='
y0u_4r3_5up3r_f457
```

The flag is `y0u_4r3_5up3r_f457`.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/pragyan-ctf-2015-android/>
