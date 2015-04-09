# Nuit du Hack Quals CTF 2015: faceBox

**Category:** Web
**Points:** 100
**Solves:** 18
**Description:** 

> A shady company decided to write their own software for storing files in the cloud.
> 
> "No no no, this is OUR filebox. We decline any responsability in the usage of our filebox. In any event your files get lost, trashed, stolen or spy on : it's your fault, not ours."
> 
> You are investigating on the security of their cloud storage as it might have disastrous consequences if it were to get hacked by malicious actors.
> 
> <http://prod.facebox.challs.nuitduhack.com/>

## Write-up

_This write-up is made by the [HacknamStyle](https://www.hacknamstyle.net/) CTF team._

The first thing to figure out in this challenge, was that the website was running on the "production" server (hence the `prod` in the hostname). This then lead to discovering the development server (`.facebox.challs.nuitduhack.com/`), which contained a `.git/` folder.

After cloning the `.git/` folder, we found [a file](main.py) containing the method used to generate the random filename of uploaded files.
Basically, filenames were generated as follows: `md5(privkey + filename)` with `privkey` being a random value between 10000000 and 99999999, unique per user.

The first file uploaded to the service `confidentials.txt` private, i.e. we did not know the link. However, for the second file, we knew the original filename (`paste01.txt`) and the randomly generated filename (`3686d78a6e9d5258773a6ae0469d3ed4`). Bruteforcing the privkey for that user, we found the value was `95594864`.

Using this value, all we had to do is compute the "random" filename of the private file: `md5("95594864confidentials.txt")` → `35e2cb0b2e8bd40347ecd4e32767a060`. This allowed us to [see the `confidentials.txt` file](http://prod.facebox.challs.nuitduhack.com/files/view/35e2cb0b2e8bd40347ecd4e32767a060), which contained the flag: `M4x_M4i5_DR`.

## Other write-ups and resources

* <https://hexpresso.wordpress.com/2015/04/06/quals_ndh-2k15-facebox-web-100-writeup/>
* <http://www.matthieukeller.com/2015/04/ctf-ndh-qualifications.html#facebox/> (English)
* <http://wiki.zenk-security.com/doku.php?id=ndhquals2015:facebox/> (Fench)
