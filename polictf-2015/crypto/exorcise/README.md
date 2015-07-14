# PoliCTF 2015: Exorcise

**Category:** Crypto
**Points:** 50
**Solves:** 132
**Description:**

> Simple Exorcise. Get the key! Connect to

>> exorcise.polictf.it:80

## Write-up

As you can see in the problem's name, eXORcise involve a classic xor encryption. First six characters and last 228 characters of the encrypted text is dummy, the rest is hex encoded string of (plain_text) xor (key). This information is enough to get the key because if a xor b = c, then b = a xor c. You can send a long enough string (because we don't know the length of the key), convert the hex encoded text to string (don't include the dummy), and xor both to get the key. Xor result is a repeated string like "g{_this_1s_s0_simple_you_should_have_solved__it_1n_5_sec}flag{_this_1s_s0_simple....".

The flag is `flag{_this_1s_s0_simple_you_should_have_solved__it_1n_5_sec}`

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/polictf-2015-exorcise/>
* <https://zeta-two.com/ctf/2015/07/14/polictf-writeup.html#crypto50-exorcise>
