# PoliCTF 2015: John in The Middle

**Category:** Forensics
**Points:** 100
**Solves:** 86
**Description:**

> Can John hijack your surfin'? :)

>> GPG key: GhairfAvvewvukDetolicDer-OcNayd#

> [john-in-the-middle](john-in-the-middle_153a4fa94b9c23459897157df4ed4105.tar.gz.gpg)

## Write-up

Extract all files from pcap (you can use wireshark) and you can see logo.png is very different with original logo.png from http://polictf.it/images/logo.png. Using stegsolve or image manipulation tool, you can see the hidden text in the image.

![](logo.png?raw=true)

The flag is `flag{J0hn_th3_Sn1ff3r}`

## Other write-ups and resources

* <http://www.pwntester.com/blog/2015/07/12/polictf-forensics100/>
