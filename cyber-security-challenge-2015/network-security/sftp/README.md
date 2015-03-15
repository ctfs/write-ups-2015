# Cyber Security Challenge 2015: SFTP

**Category:** Network Security
**Points:** 50
**Description:**

> One of our employees uses an SFTP server to store sensitive company files. He ensured us it’s safe. I mean… Why wouldn’t SFTP be safe?
>
> 37.187.249.84:10003 (login with Kermit:MissPiggy)

## Write-up

Contrary to what one would expect at first sight, this SFTP server isn't a secure file server. The acronym 'SFTP' can also be used to denote the [Simple File Transfer Protocol](https://en.wikipedia.org/wiki/Simple_File_Transfer_Protocol).

In order to connect to the server, simply fire up netcat and connect to the server at the given port.

```bash
$ nc 37.187.249.84 20003
+NVISO SFTP server
```

Now, let's take a look at some of the commands we can use on this server. The most comprehensive documentation on the simple file transfer protocol can be found on its [rfc page](https://tools.ietf.org/html/rfc913).

Log in using the given credentials:

```
USER Kermit
+ Kermit ok
PASS MissPiggy
! Welcome Kermit
```

List directory contents:

```
LIST V
+.
drwxr-xr-x   2 Kermit  Kermit     68 Feb 19 14:42 documents
LIST F
+.
documents/
```

Change to another directory:

```
CDIR documents
! directory changed to documents
LIST V
+documents
-rw-r--r--@  1 Kermit  Kermit   201892 Feb 19 14:58 flag
```

It looks like we have found our flag. Now let's set the transmission mode to 'binary' (the only mode supported by the server) and pull the file in:

```
TYPE B
+ Using Binary mode
RETR flag
99204
SEND
```

Capture the output of the SEND command into a file (I used `tee` for this).

Now we can examine what type of file the flag is, using the old and trusty `file`

```bash
$ file out.raw
out: JPEG image data, JFIF standard 1.01, resolution (DPI), density 72x72, segment length 16, baseline, precision 8, 550x450, frames 3
```

So, let's open the image up: `xdg-open out.raw`

When you looks closely (this depends on monitor and color configuration), you can see the text 'KermitLovesBacon' in the top right corner. This is the flag.

## Other write-ups and resources

* none yet
