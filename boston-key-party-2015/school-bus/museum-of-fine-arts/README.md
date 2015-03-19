# Boston Key Party CTF 2015: Museum Of Fine Arts

**Category:** School-Bus
**Points:** 25
**Solves:** 377
**Description:**

> Because cryptography is hard, we only implemented a hand-made PRNG. What could possibly go wrong? : 25

## Write-up

From the [source code](./52.10.107.64\:8004/index.txt) we can see that we need to guess a random number, this is stored in the session to be compared.

The actual comparison between `$_GET['password']` and `$_SESSION['password']` takes place before the assignment of the next random number and with a `==` instead of `===`. 

Therefore, by deleting the session cookie and sending the request `http://52.10.107.64:8004/?password=` we can get the flag as `$_SESSION['password']` would not contain anything.

## Other write-ups and resources

* <https://github.com/bl4de/ctf/blob/master/BostonKeyPartyCTF_2015/MuseumOfFineArts.md>
* <https://ctf-team.vulnhub.com/boston-key-party-2015-museum/>
* [Japanese](http://kazu1130-h.hatenablog.jp/entry/2015/03/02/034426)
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-museum-of-fine.html)
