# 9447 CTF 2015: Recon 1

**Category:** Misc
**Points:** 140
**Solves:** 85
**Description:**

> Someone has attacked your site. We have attached a log collected from the time of the attack.
> 
> This task is split into two parts. The end goal (Recon 2) is to find the full name of the attacker.
> 
> The flag for Recon 1 is not the name of the attacker. Recon 1 flag will appear as 9447{...} on your screen when you find it.
> 
> Hint! The attacker has gone on vacation, and won't be reading or responding to emails. You do not need to email anyone for this challenge.
> 
> [log.tar.gz](./log-8dbfb01501680891caf2dc03252b951e.tar.gz)  8dbfb01501680891caf2dc03252b951e


## Write-up

by [allfro](https://github.com/allfro)

1. Inspecting the log reveals two IP addresses `37.139.17.15` and `192.241.254.77`. 
2. `192.241.254.77` resolves to `www.williestoleyour.pw`. 
3. Opening your web browser and navigating to `http://www.williestoleyour.pw` reveals an email address in the body of the website: `info@williestoleyour.pw`. 
4. Going to `http://archive.org` and entering `http://www.williestoleyour.pw` in the search bar reveals that an older version of the website is available for viewing from November 11th, 2015.
5. Viewing the older website `https://web.archive.org/web/20151115002534/http://www.williestoleyour.pw/` reveals a second email: `info@dynamiclock.pw`
6. Navigating to `http://dynamiclock.pw` in your web browser you see the flag `9447{YouAreStalKey}`

## Other write-ups and resources

* <https://github.com/philo0x90/CTF-write-ups/blob/master/9447-ctf-2015/misc-recon1.md>
* <http://corb3nik.github.io/2015/11/29/9447-recon-1/>
* <https://github.com/pwning/public-writeup/tree/master/9447ctf2015/misc140-recon1>
* <https://gist.github.com/Invizory/2905c34fe4d2a885efec>
* [sophia.re](http://www.sophia.re/94472015_recon12_writeup.html)
