# Boston Key Party CTF 2015: Symphony

**Category:** School-Bus
**Points:** 25
**Solves:** 577
**Description:**

> A less than four characters number, bigger than 999?Maybe the bug is elsewhere. : 25

## Write-up

Given the [php source code](./52.10.107.64\:8002/index.txt), we see that we need an input that is less than 3 chars and get beyond `is_numeric`.

The solution to this problem is using float numbers, e.g. `http://52.10.107.64:8002/?password=1e3`.

The flag is `B4SE10_IS_F0R_LOSERS`.

## Other write-ups and resources

* <http://dook.biz/2015/03/boston-key-party-ctf-symphony-writeup/>
* <https://github.com/bl4de/ctf/blob/master/BostonKeyPartyCTF_2015/Symphony.md>
* <https://ctf-team.vulnhub.com/boston-key-party-2015-symphony/>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-symphony.html)
