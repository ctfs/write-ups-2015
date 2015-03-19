# Boston Key Party CTF 2015: Prudential

**Category:** School-Bus
**Points:** 25
**Solves:** 426
**Description:**

> I dont think that sha1 is broken. Prove me wrong. : 25

## Write-up

We are given the [php source code](./52.10.107.64\:8001/index.txt) and see that the author compares the sha1 hashes of the `name` and `password` query parameters:

```php
[...]
else if (sha1($_GET['name']) === sha1($_GET['password']))
[...]
```

We can force the results for both inputs to be null, e.g. with `http://52.10.107.64:8001/?name[]=s&password[]=ss` so that it results in the following check:

```php
[...]
else if (sha1(NULL) === sha1(NULL))
[...]
```

The flag is `I_think_that_I_just_broke_sha1`.

## Other write-ups and resources

* <https://github.com/bl4de/ctf/blob/master/BostonKeyPartyCTF_2015/Prudential.md>
* <https://ctf-team.vulnhub.com/boston-key-party-2015-prudential/>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-prudential.html)
