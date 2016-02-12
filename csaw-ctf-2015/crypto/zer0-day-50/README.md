# CSAW QUALS 2015: zer0-day-50

**Category:** Crypto
**Points:** 50
**Solves:** 824
**Description:**

> [eps1.9_zer0-day_b7604a922c8feef666a957933751a074.avi](eps1.9_zer0-day_b7604a922c8feef666a957933751a074.avi)


## Write-up

by [x0w1](https://github.com/x0w1)

It looks like a base64 encoded string with '\n' (two printable characters) instead of new lines. Simple one-liner

```bash
cat eps1.9_zer0-day_b7604a922c8feef666a957933751a074.avi | sed 's/\\n//g' | base64 -d
```

gives us the decoded file:

_Evil Corp, we have delivered on our promise as expected. The people of the world who have been enslaved by you have been freed. Your financial data has been destroyed. Any attempts to salvage it will be utterly futile. Face it: you have been owned. We at fsociety will smile as we watch you and your dark souls die. That means any money you owe these pigs has been forgiven by us, your friends at fsociety. The market's opening bell this morning will be the final death knell of Evil Corp. We hope as a new society rises from the ashes that you will forge a better world. A world that values the free people, a world where greed is not encouraged, a world that belongs to us again, a world changed forever. And while you do that, remember to repeat these words: "flag{We are fsociety, we are finally free, we are finally awake!}"_

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/csaw-quals-2015-zer0-day/>
* <http://fadec0d3.blogspot.com/2015/09/csaw-2015-crypto-50-50-50-100.html>
* <https://github.com/Alpackers/CTF-Writeups/tree/master/2015/CSAW-CTF/Crypto/zer0-day>
