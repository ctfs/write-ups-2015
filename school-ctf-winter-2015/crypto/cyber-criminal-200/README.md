# School CTF Winter 2015: Cyber criminal

**Category:** Crypto
**Points:** 200
**Solves:** 
**Description:**

> Not long ago we have maged to arrest a dangerous cyber criminal known as m/-\d~M@Xor.
> 
> 
> We have managed to decrypt all files on his laptop, but the one on paper turned out to be too hard for our specialists!
> 
> 
> We have heard you are great at cracking ciphers so we are asking you for help. Decrypt the last message and help us close the deal!
> 
> 
> Detective Sergeant R.Mueller, FBI
> 
> 
> [Image](./image_2a3f9ab6e49d2b1b7ddd73506c6afa1060e19fd3.jpg)


## Write-up

<div><h3>Cyber criminal</h3><p>Obviously the table is some sort of a key for the message.</p>
<p>We could try to google for ciphers that uses a table with cutouts and found out that it is Cardan grille cipher. Or just make an assumption that table is used to get some characters from the text written in such table.</p>
<p>So we just need to write text in 8 rows and try to get some phrase from cut out cells. The only meaningfull begining is "we_glad", so we found starting position for our grille.</p>
<p>Then just read letters from cut areas and rotate the grille CW untill you get the flag.</p></div>

## Other write-ups and resources

* none yet
