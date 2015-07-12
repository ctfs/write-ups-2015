# PlaidCTF CTF 2015: Sanity Check

**Category:** Misc
**Points:** 1
**Solves:** 879
**Description:**

> Plaid CTF 2015 requires internet to play. [Do you have internet](http://pewpewpew.xyz/)?

## Write-up

### Sanity Check - Do you have internet?

This challenge was awarded with a single point and was the easiest challenge in this ctf.

Upon visiting the provided link you were greeted with a simple html-page and the request to enter the **black** characters to claim the flag.
There was some text visible but by inspecting the html source or by trying to copy the characters one found that there was some invisble white text written in between the black characters.
The white characters were encapsulated in special div blocks. 

By skipping these blocks one was able to retrieve the following flag:

>flag{I_can_type_!l!I1!} 

## Other write-ups and resources

* none yet
