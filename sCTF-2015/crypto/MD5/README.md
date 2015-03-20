# MD5 

**Category:** Crypto
**Points:** 30
**Author:** 
**Description:**

>Given the following MD5 hash:

>0AB1A9222A15DA1159EB94212C5C8BAF

>There are 3 parts to the original text. The first part is a random number, 0-99 inclusive. The second part is a random letter, lowercase a-z inclusive. The third and final part is a random number, 0-999 inclusive.

>For example, 19f599 or 0a159 could be possible combinations. There are no 0's for blank spaces, for example 0a001 is not valid. It would be 0a1.

>Find the original text.

## Writeup
After been given an MD5 hash the user could either attempt to brute-force it, or utilise an online service to attempt to find the plain-text matching the hashed one.

Attempting to bruteforce it would take several hours depending on software utilised, and thus using an online database is the best option between the two (or at least worth a try).

Simply pasting the MD5 into [HashKiller.co.uk](http://www.hashkiller.co.uk/md5-decrypter.aspx) the user receives the flag.

## Flag
>15q478

## Other write-ups and resources
