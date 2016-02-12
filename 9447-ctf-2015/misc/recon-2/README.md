# 9447 CTF 2015: Recon 2

**Category:** Misc
**Points:** 190
**Solves:** 32
**Description:**

> Find the attackers full name. See attached file on Recon 1.
> 
> The format of the flag is 9447{firstname.lastname}. It will be obvious when you've found the name.


## Write-up

by [allfro](https://github.com/allfro)

1. An `nslookup` reveals that `http://dynamiclock.pw` is sitting behind CloudFlare.
2. At the bottom of the page there is a "Contact Me" form that allows you to fill in your email address, name, and a comment.
3. By filling in the form successfully with a valid email address you should receive an email confirmation from the server itself.
4. Inspecting the email's metadata, you find the real IP address of the server: `162.243.7.88`
5. Navigating to `http://162.243.7.88` in a web browser reveals a directory listing containing a contact card: `dynamicWarl0ck.vcf`
6. Using a service like `http://checkusernames.com/` you look for the availability of `dynamicWarl0ck` on different social networks.
7. Noticing that `github.com` is unavailable, you navigate to `https://github.com/dynamicWarl0ck` where in the comments it says that the account was moved to bitbucket
8. Going to `https://bitbucket.org/dynamicWarl0ck/` you see the user has one repo: `dynamics`
9. Browsing the repo you notice one commit with the comment `add key`.
10. Once at the commit (`https://bitbucket.org/dynamicWarl0ck/dynamics/commits/63614345e143579befcb3b2dff1d9e9740598d10`) the flag will appear `nine four four seven lbrace william.clutterbuck rbrace` in the diffs.

## Other write-ups and resources

* <http://corb3nik.github.io/2015/11/29/9447-recon-2/>
* <https://github.com/pwning/public-writeup/tree/master/9447ctf2015/misc190-recon2>
* [sophia.re](http://www.sophia.re/94472015_recon12_writeup.html)
