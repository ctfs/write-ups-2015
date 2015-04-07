# BCTF CTF 2015: sqli_engine

**Category:** Web
**Points:** 200
**Solves:** 123
**Description:** 

> http://104.197.7.111:8080/
> 
> geohot told me he has a lot of sql injection tricks. So I wrote a sql injection detection engine in defense.
> 
> Now you have a simple website protected by my engine, try to steal the admin’s password(not hash).
> 
> form = web.input()
> 
> username = form.get('username')
> password = form.get('password')
> 
> if sqliengine.is_sqli(username):
>     raise web.BadRequest(u'username contains SQL injection, IP recorded.')
> 
> if sqliengine.is_sqli(password):
>     raise web.BadRequest(u'password contains SQL injection, IP recorded')
> 
> if sqliengine.is_sqli(username + password):
>     raise web.BadRequest(u'username + password contains SQL injection, IP recorded')
> 
> \# continue normal db operation
> There are only two pages: login and register, please do not use web scanner to brute force, just do the sqli part.

## Write-up

(TODO)

## Other write-ups and resources

* <http://linux.im/2015/03/23/BCTF-WEB-Writeup.html#sqlienginescore-200>
* <https://rzhou.org/~ricky/bctf2015/sqli_engine/>
* <https://github.com/pwning/public-writeup/blob/master/bctf2015/web200-sqli_engine/test.py>
* <http://pastebin.com/5exPuAFR>