# Ghost in the Shellcode 2015: The Alpha Molecule

**Category:** Forensics
**Points:** 200
**Description:**

> Find the key! [File](https://2015.ghostintheshellcode.com/alpha_molecule-d2c7516d19609eaccbffc57b2ff0a9ae93d06b53b8140529ee2edb8a60e08520)

[Alternative download](https://mega.nz/#!ORFBhCJT!Vr7z9AojPBOslR7A7z8UuQLtK-C2XN5wQvdZQkJ9y1s)

## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups and resources:

* <http://hxp.io/blog/10/Ghost%20in%20the%20Shellcode%202015:%20Forensics%20200%20%22The%20Alpha%20Molecule%22/>
* <http://pastebin.com/ZM55bhRs>
* [Oscilloscoping](https://www.youtube.com/watch?v=XM8kYRS-cNk)

We are given a xz compressed tar archive that we decompress with `unxz` and extract its contents with `tar xvf alpha.tar` to get a wav, `Fuzyll - The Alpha Molecule.wav`.

The audio can be rendered with an oscilloscope as seen [in this example](https://www.youtube.com/watch?v=RkJdADVy_Mg).

We can do render the individual frames using [this python script](./oscilloscope.py) to receive several frames as PNGs:

```bash
$ python oscilloscope.py
$ ls -1 test*
test00000000.png
test00010000.png
test00020000.png
test00030000.png
[...]
test10620000.png
test10630000.png
test10640000.png
$ ls -1 test* | wc
    1065    1065   18105
```

We can convert these `1065` PNGs into a single GIF for an easier visualization using `ffmpeg -framerate 75 -i 'test%04d0000.png' alpha.gif`:

![](./alpha.gif)

Looking at the GIF, we notice letters passing by that spell out a sentence containing the flag, `ARE YOU HAVING OSCILLOFUN FUZYL`.

The flag is `FUZYL`.

## Other write-ups and resources

* <http://hxp.io/blog/10/Ghost%20in%20the%20Shellcode%202015:%20Forensics%20200%20%22The%20Alpha%20Molecule%22/>
* <http://pastebin.com/ZM55bhRs>
* [Oscilloscoping](https://www.youtube.com/watch?v=XM8kYRS-cNk)
