# IceCTF 2015: Document Troubles

**Category:** Forensics
**Points:** 30
**Description:** 

> We found this [document](file.docx), and we think it contains the flag. Can you find it?

**Hint:**

> What exactly is a .docx file?

## Write-up

by [polym](https://github.com/abpolym)

We are given a file with a `.docx` file extension.

However, in reality, it actually is a zip file, which contains a file named `flag.txt` that contains our flag:

```bash
+bash-4.3$ file file.docx 
file.docx: Zip archive data, at least v2.0 to extract
+bash-4.3$ 7z x file.docx -oout

7-Zip [64] 9.20  Copyright (c) 1999-2010 Igor Pavlov  2010-11-18
p7zip Version 9.20 (locale=utf8,Utf16=on,HugeFiles=on,8 CPUs)

Processing archive: file.docx

Extracting  word/numbering.xml
Extracting  word/settings.xml
Extracting  word/fontTable.xml
Extracting  word/styles.xml
Extracting  word/document.xml
Extracting  word/_rels/document.xml.rels
Extracting  _rels/.rels
Extracting  [Content_Types].xml
Extracting  flag.txt

Everything is Ok

Files: 9
Size:       13393
Compressed: 4385
+bash-4.3$ cd out/
+bash-4.3$ cat flag.txt 
this_would_be_the_flag_you_are_looking_for
```

The flag is `this_would_be_the_flag_you_are_looking_for`.

PS: It could be that Window's `.docx` files are zip files in general - haven't looked that up.

## Other write-ups and resources

* <http://blog.oleaass.com/ctf-icectf-trivials-writeup/>
* <https://www.hasnydes.us/2015/09/writeup-ice-ctf/>
* <https://github.com/james9909/PracticeCTF/blob/master/IceCTF-2015/Document%20Troubles/Solution.txt>
