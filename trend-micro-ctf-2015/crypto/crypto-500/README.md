# Trend Micro CTF 2015: crypto-500

**Category:** Crypto
**Points:** 500
**Solves:**
**Description:**

> Think about two different alphabetical strings with the same lengths. After you encode the strings with Base64 respectively, if you find characters located in the same position between the two strings, then you may want to extract them. You may find examples where the final strings are ‘2015’ and ‘Japan’ if you place the extracted characters from left to right in order.
>
> Example:
>
> CaEkMbVnD→(Base64)→Q2FFa01iVm5E
> GePoMjXNW→(Base64)→R2VQb01qWE5X
>                     2   01   5
>
> aBckjTiRgbpS→(Base64)→YUJja2pUaVJnYnBT
> URehZQjLyvwk→(Base64)→VVJlaFpRakx5dndr
>                         J a p a    n
> Character 'a' may appear in the extracted string like the example above, character f will never appear. Please find a list of characters that would not appear in the extracted string, even if you specify any alphabetical characters in the input. Once you come up with a list of characters, please sort the characters in the order of ASCII table and generate a SHA1 hash value in lower case. This is the flag you are looking for.
>
> Please submit the flag in the format of 'TMCTF{}'.


## Write-up

(TODO)

## Other write-ups and resources

* <https://github.com/RandomsCTF/write-ups/tree/master/Trend%20Micro%20CTF%20Asia%20Pacific%20%26%20Japan%202015%20Online%20Qualifier/Crypto%20500>
* <https://ctftime.org/writeup/1810>
