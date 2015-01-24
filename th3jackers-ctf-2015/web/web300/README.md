# Th3Jackers CTF 2015: Don't wast your time

**Category:** Web
**Points:** 300
**Solves** 6
**Description:**

> Description: 159.8.48.196:3117
>
> Attachment:

## Write-up

Besides a question of the best command-line text editor, the given homepage had a HTML comment with a base64 encoded message in it:

> RWRpdGVkIGJ5IGphY2tzdG9uZSB1c2luZyBuYW5vIGVkaXRvcg==

Decoding this text with `echo 'RWRpdGVkIGJ5IGphY2tzdG9uZSB1c2luZyBuYW5vIGVkaXRvcg==' | base64 --decode`, we get `Edited by jackstone using nano editor`.

After trying to access several nano config files `*.nanorc`, nano backup files `index.php~`, `*.nanorc~` and other files `.htaccess`, `robots.txt`, we are reading about `nano`'s emergency file extension `.save`.

When applying this extension to `index.php` and accessing `159.8.48.196:3117/index.php.save`, we are getting [this php file](index.php.save).

Understanding this php file leads us to the exploit:
	* The server reads a query parameter called `passphase`
	* Test the length of the passph(r)ase by adding a character one by one, until the server returns `incorrect` instead of `nop`.
	* Now bruteforce the passphrase by trying all possible passwords, for example by using a big password list.

The command might look like:

```
$ grep -o ....... rockyou.txt | while read pw; do wget -qO- "http://159.8.48.196:3177/?passphase=$pw" & done | grep -v 'incorrect'

TODO: Correct flag?
```

## Other write-ups and resources

* none yet
