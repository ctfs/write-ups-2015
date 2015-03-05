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

(TODO SQL injection)

## Other write-ups and resources

* none yet
