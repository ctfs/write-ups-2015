# CodeGate General CTF 2015: Owlur

**Category:** Web
**Points:** 200
**Solves:** TODO
**Description:** 

> http://54.65.205.135/owlur/
> 
> if you use a web scanner, your IP will get banned
> no bruteforce required, take it easy

## Write-up

First of all, there is a LFI vulnerability in a GET parameter by testing parameters in the `index.php`.
As you analyze the mode parameter, you can see that the code executes in the form of `include(null_filter($var).".php");`.

At this rate, trying `php://filter` on the parameter would leak out the sourcecode of the `upload.php` and other files.
`payload: (index.php?mode=php://filter/convert.base64-encode/resource=upload)`

As we look further of how `upload.php` works,
we find out that the file checks for the extension, but does not check its contents of the uploaded file.

Based on this information, we can think about zipping the file and load the php script from the zip file.

The possible payload from this can be `index.php?mode=zip:///var/www/owlur/owlur-upload-zzzzzz/*returned_filename_from_upload_php*.jpg%23*your_real_payload*`

Through this method you will be able to list the directory and read files, and eventually let you to read the file named `OWLUR-FLAG.txt` on the `/` directory.

```
GET: index.php?zip:///var/www/owlur/owlur-upload-zzzzzz/tqpmLQ2.jpg%23stypr

Response:
owlur
pwning complete by stypr
FLAG->PHP fILTerZ aR3 c00l buT i pr3f3r f1lt3r 0xc0ffee
```


## Other write-ups and resources

* <https://0x1337seichi.wordpress.com/2015/03/15/codgate-2015-ctf-quals-owlur-writeup-web-200/>
* <http://chichou.0ginr.com/blog/1081>
* <http://dakutenpura.hatenablog.com/entry/2015/03/16/223424>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/CODEGATE/web/owlur>
* <https://github.com/pwning/public-writeup/blob/master/codegate2015/web200-owlur/writeup.md>