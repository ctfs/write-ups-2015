# IceCTF 2015: Logoventures 2: Reloaded

**Category:** Forensics
**Points:** 40
**Description:** 

> <p>I know what you're thinking... Why am I storing all of this important data in images? Well, you should mind your own business.</p><p>Can you just get the information for me?</p> [Image](./logo.jpg)

**Hint:**

> The flag must eXist in the image somewhere!

## Write-up

by [polym](https://github.com/abpolym)

We are given a jpg:

![](./logo.jpg)

Reading the metadata of this jpg using `exiftool`, the flag is revealed in the User Comment Exif Data Field:

```bash
$ exiftool logo.jpg 
ExifTool Version Number         : 9.99
File Name                       : logo.jpg
Directory                       : .
File Size                       : 13 kB
File Modification Date/Time     : 2015:12:25 18:44:38+01:00
File Access Date/Time           : 2015:12:26 00:23:09+01:00
File Inode Change Date/Time     : 2015:12:25 18:44:38+01:00
File Permissions                : rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
Exif Byte Order                 : Little-endian (Intel, II)
Make                            : IceCTF
Camera Model Name               : 2015
Resolution Unit                 : inches
Y Cb Cr Positioning             : Centered
Exif Version                    : 0230
Components Configuration        : Y, Cb, Cr, -
User Comment                    : now_youre_thinking_with_exif
Flashpix Version                : 0100
Lens Make                       : The flag you're looking for is in another property...
Quality                         : 60%
XMP Toolkit                     : Adobe XMP Core 5.5-c021 79.155772, 2014/01/13-19:44:00
Creator Tool                    : Adobe Photoshop CC 2014 (Macintosh)
Instance ID                     : xmp.iid:BC4E26831D2211E582F697A30DCEE501
Document ID                     : xmp.did:BC4E26841D2211E582F697A30DCEE501
Derived From Instance ID        : xmp.iid:BC4E26811D2211E582F697A30DCEE501
Derived From Document ID        : xmp.did:BC4E26821D2211E582F697A30DCEE501
DCT Encode Version              : 100
APP14 Flags 0                   : [14], Encoded with Blend=1 downsampling
APP14 Flags 1                   : (none)
Color Transform                 : YCbCr
Image Width                     : 600
Image Height                    : 315
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:4:4 (1 1)
Image Size                      : 600x315
Megapixels                      : 0.189
```

The flag is `now_youre_thinking_with_exif`.

## Other write-ups and resources

* <http://blog.oleaass.com/ctf-icectf-logoventures-2-reloaded-40-forensics/>
* <https://github.com/james9909/PracticeCTF/blob/master/IceCTF-2015/Logoventures%202:%20Reloaded/Solution.txt>
