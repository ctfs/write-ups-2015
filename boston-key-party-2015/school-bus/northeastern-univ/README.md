# Boston Key Party CTF 2015: Northeastern Univ

**Category:** School-Bus
**Points:** 25
**Solves:** 511
**Description:**

> Of course, a timing attack might be the answer, but Im quite sure that you can do better than that. : 25

## Write-up

If we look at the given [php file](./52.10.107.64\:8003/index.txt) we see that the author compares the `password` with the contents of `$flag` using `strcmp`:

```php
if (strcmp($_GET['password'], $flag) == 0)
```

However, if you compare the result of `strcmp` using `==` instead of `===`, it [might fail](https://coderwall.com/p/lflzkq/php-strcmp-could-leave-you-alone-in-deep-sh-t).

So if we specify the `password` parameter as an array, e.g. `http://52.10.107.64:8003/?password[]=`, we will get the flag:

> Flag: `Still_better_than_the_d0uble_equals`

## Other write-ups and resources

* <http://capturetheswag.blogspot.com.au/2015/03/boston-key-party-2015-school-bus-flag-3.html>
* <https://ctf-team.vulnhub.com/boston-key-party-2015-northeastern-university/>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-northeastern-univ.html)
