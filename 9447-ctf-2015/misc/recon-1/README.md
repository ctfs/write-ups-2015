# 9447 CTF 2015 2015: Recon 1

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

1. Inspecting the log reveals two IP addresses `37.139.17.15` and `192.241.254.77`. 
2. `192.241.254.77` resolves to `www.williestoleyour.pw`. 
3. Opening your web browser and navigating to `http://www.williestoleyour.pw` reveals an email address in the body of the website: `info@williestoleyour.pw`. 
4. Going to `http://archive.org` and entering `http://www.williestoleyour.pw` in the search bar reveals that an older version of the website is available for viewing from November 11th, 2015.
5. Viewing the older website `https://web.archive.org/web/20151115002534/http://www.williestoleyour.pw/` reveals a second password: `info@dynamiclock.pw`
6. Navigating to `http://dynamiclock.pw` in your web browser you see the flag `9447{YouAreStalKey}`

## Other write-ups and resources

* none yet
