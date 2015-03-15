# nullcon HackIM 2015: Crypto Question 1

**Category:** Crypto
**Points:** 100
**Author:**
**Description:**

>Find the key: 
>TaPoGeTaBiGePoHfTmGeYbAtPtHoPoTaAuPtGeAuYbGeBiHoTaTmPtHoTmGePoAuGeErTaBiHoAuRnTmPbGePoHfTmGeTmRaTaBiPoTmPtHoTmGeAuYbGeTbGeLuTmPtTmPbTbOsGePbTmTaLuPtGeAuYbGeAuPbErTmPbGeTaPtGePtTbPoAtPbTmGeTbPtErGePoAuGeYbTaPtErGePoHfTmGeHoTbAtBiTmBiGeLuAuRnTmPbPtTaPtLuGePoHfTaBiGeAuPbErTmPbPdGeTbPtErGePoHfTaBiGePbTmYbTmPbBiGeTaPtGeTmTlAtTbOsGeIrTmTbBiAtPbTmGePoAuGePoHfTmGePbTmOsTbPoTaAuPtBiGeAuYbGeIrTbPtGeRhGeBiAuHoTaTbOsGeTbPtErGeHgAuOsTaPoTaHoTbOsGeRhGeTbPtErGePoAuGePoHfTmGeTmPtPoTaPbTmGeAtPtTaRnTmPbBiTmGeTbBiGeTbGeFrHfAuOsTmPd

## Write-up

If you had chemistry in school, you'll notice quickly that each two characters represent chemical symbols for different chemical elements out of the periodic table, e.g. `Ta` means `Tantalum`.

Each atom of a chemical element also has a [unique count](http://en.wikipedia.org/wiki/Atomic_number) of protons, e.g. `Ta` has the atomic number `73`.

Decoding the ciphertext with a [self-written script](chemical.py) results in the following cleartext:

> IT IS THE FUNCTION OF SCIENCE TO DISCOVER THE EXISTENCE OF A GENERAL REIGN OF ORDER IN NATURE AND TO FIND THE CAUSES GOVERNING THIS ORDER. AND THIS REFERS IN EQUAL MEASURE TO THE RELATIONS OF MAN - SOCIAL AND POLITICAL - AND TO THE ENTIRE UNIVERSE AS A WHOLE.

The task here is to find the "general reign of order in nature" or rather guess, where these atomic numbers are specified - in the `periodic table`.

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/hackim-2015-crypto-100/>
* <http://blog.tinduong.pw/nullcon-hackim-2014-write-ups/#crayon-54bed0c4c778b288261421>
* [Spanish](https://blog.ka0labs.net/post/20/)
* [Portuguese](https://ctf-br.org/wiki/nullcon-hackim/nullcon-hackim-2015/c100-question-1/)
