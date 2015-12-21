# School CTF Winter 2015: Lazy cryptanalyst

**Category:** Crypto
**Points:** 100
**Solves:** 
**Description:**

> Looks like I'm too lazy to complete it. >_< Can you help me a little?
> 
> 
> bsxz xz om rxuvi. bsiri qri oqym gbsirz vxji xb, whb bsxz gyi xz oxyi. om rxuvi xz om wizb urxiye. xb xz om vxui. x ohzb oqzbir xb qz x ohzb oqzbir om vxui. fxbsghb oi, om rxuvi xz hzivizz. fxbsghb om rxuvi, x qo hzivizz. x ohzb uxri om rxuvi brhi. x ohzb zsggb zbrqxlsbir bsqy om iyiom, fsg xz brmxyl bg jxvv oi. x ohzb zsggb sxo wiugri si zsggbz oi. x fxvv. wiugri lge x zfiqr bsxz kriie: om rxuvi qye omzivu qri eiuiyeirz gu om kghybrm, fi qri bsi oqzbirz gu ghr iyiom, fi qri bsi zqpxgrz gu om vxui. zg wi xb, hybxv bsiri xz yg iyiom, whb ciqki. uvql xz q eqm fxbsghb wvgge xz vxji q eqm fxbsghb zhyzsxyi. qoiy.
> 
> 
> [Image](./image_0faf3e88f05801b6084363586617de51e128dea2.jpg)


## Write-up

<div><h3>Lazy cryptanalyst</h3><p>Looking at the picture in task we could realize that it is simple substitution cipher.</p>
<p>Let's google for that nice site from picture. To do it google for phrase from the picture <code>To Crack a Substitution Cipher</code> and find the site looking like our example.</p>
<p>On a picture we have some letters cracked so we need to continue doing some assumptions about the plaint text, like "bsi" is a "the", "bsiri" - "these", "xb" - "it" and so on.</p>
<p>Trying to get meaningful words we can decrypt all the message. The phrase in the message that follows "flag is" is obviously our flag.</p></div>

## Other write-ups and resources

* <https://en.internetwache.org/school-ctf-2015-writeups-06-11-2015/>
