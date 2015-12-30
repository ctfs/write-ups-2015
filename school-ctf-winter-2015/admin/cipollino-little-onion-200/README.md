# School CTF Winter 2015: Cipollino, little onion

**Category:** Admin
**Points:** 200
**Solves:** 
**Description:**

> Do you like containers as we do?
> 
> [Image](./image_1cfb4379b82626f0b5d28129ddb5918f8c010aa8.jpg)


## Write-up

We have an image of a rar archieve and the task description tell us about containers, so given image is obviously rarjpeg.

Open it as archieve and exctract an image with QR code.

Decode QR with any online tool and realize that it contains program in C++.

Compile and run it and we get base64 from python code.

Runned python code gives as some hex.

Trait hex as ASCII codes and get the flag.

## Other write-ups and resources

* none yet
