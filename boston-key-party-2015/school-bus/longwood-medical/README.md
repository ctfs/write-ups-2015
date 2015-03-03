# Boston Key Party CTF 2015: Longwood Medical

**Category:** School-Bus
**Points:** 25
**Solves:** 430
**Description:**

> Because we dont trust mysqli_real_escape_string, we wrote our own military-grade sanitization method. : 25

## Write-up

The anti-SQL-Injection check is implemented by checking whether the values of `$_GET['name']` and `$_GET['password']` are alpha-numerical.
Usually, this would be sufficient, but in this case [the SQL query](https://github.com/ctfs/write-ups-2015/blob/ddbc91270893ac39adbd5640a3f82e005875d2d0/boston-key-party-2015/school-bus/longwood-medical/52.10.107.64:8005/index.txt#L17) does not surround quotes around the user-supplied values. This means that when a numerical value is entered, a textual value is compared to the numerical one, causing an implicit cast.
A cast from string to integer will result in `0` when the string does not start with numerical values (which seemed to be the case both for `$name` and `$password` in this challenge).

Consequently, making a request to `index.php?name=0&password=0` printed out the flag: `Did_you_know_that_in_french_a_chiken_makes_the_sound_quotquotquotquot?`

## Other write-ups and resources

* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-longwood-medical.html)