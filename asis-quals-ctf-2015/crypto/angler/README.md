# ASIS Quals CTF 2015: Angler

**Category:** Crypto
**Points:** 150
**Solves:** 22
**Description:**

> Connect there and find the flag.
> 
> nc 217.218.48.84 34211
> 
> mirror 1 : nc 217.218.48.84 34213
> 
> mirror 2 : nc 217.218.48.84 34215
> 
> mirror 3 : nc 217.218.48.84 34210

## Write-up

**Observing**
When we connect, the server asks for the solution of a simple addition
> Welcone to AngriCrypt challange :)
>
> Bot detection: Are you ready?
>
> 2 + 25 = 

After solving this, we get an encrypted message and the possibility to en/decryt our own messages:
> Encrypted message is: shaTetfirpr  a stog fli:f 0A9 SeS{0eeI6e5o14n Whsm, i  ebnesssclgym oeoto ,d ur  onit detovyerhm awaho tngsuhkthaes lheense. Tscs tn od parff o a6lgais:8a e7c77ce607c363_c_52_}
>
> ___d_
> Tell us your choice:
>
> [E]ncrypt: [D]ecrypt:

Both, E and D will ask for a message and a key. We can use this to find out, how the algorithm works. After this, we can try to decrypt the server's message manually. This weird string already looks a bit like a flag ('{', '}', ASIS-letters), but it looks a bit scrambled up.
After playing around a bit with different trivial messages and keys, I tried:

message: "abcdefghijklmnopqrstuvwxyz"

key: "aud"

Which gives the ciphertext: "acbdfegihjlkmonprqsutvxwy_z"
Here we can see: always 3 characters form one 'block' and are mixed up with the same algorithm:
the first character stays at his position, the other two change position. If you take a look at the key:
If we order the letters in alphabetic order ("adu") and apply the exakt same reordering as in the message, we get the key. The '_' seems to be a padding character to make the message dividable by 3.

**Cracking**
So, we have to find a permutation P of length L that will reorganize the letters in the given message to form a valid flag.
There are a lot of possibilities, but we can use some hints:
* The total message is 182 bytes long and we know L divides the message length. So L is on of: 1, 2, 7, 13, 14, 26, 91, 182. We have 7 '_'s, so the key has to be bigger. 13 (prime number) sounds like a reasonable possibility
* The padding bytes have to go to the end and I guessed the original message ended in "}\n"
This will give me the following permutation list:
[(1, 3, 4, 11), 6, 7, (0, 2, 5, 8, 9, 10, 12)]
Where the i'th number means, in the original message at position i is the character that is at P[i] in the ciphertext.
The 6 and 7 ('}' and '\n') are fixed. About the 4 values in the beginning and 7 in the end, we don't have any information yet, how to order them.
The following code transforms the string acording to the permutation.
```python
res = ""
for i in range(0, 182, len(perm)):
	for k in range(len(perm)):
		res += string[i + perm[k]]
	res += "|" # to show blocks
print(res)
```
This will give us:

*"hTe fisatrpr | tof fasgli: |A SIS{09e0ee6|514, Weonhsm | eblesi nsscg|moe toy o ,du| onot r idetv|ehm awyr ahot|guh thnskaesl|enss. heeTsc |nod pat  rffo|alg is 6a:8ae|c7c66077e7c33|c52d}#_______|"*

Let's fix the ASIS (swap first and second bytes. 3rd and 4th are in correct order already)

[3, 1, 4, 11, 6, 7, (0, 2, 5, 8, 9, 10, 12)]

*"The fisatrpr |t of fasgli: | ASIS{09e0ee6|154, Weonhsm |e blesi nsscg|ome toy o ,du|o not r idetv|hem awyr ahot|ugh thnskaesl|ness. heeTsc |ond pat  rffo|lag is 6a:8ae|7cc66077e7c33|5c2d}#_______|"*

Now, we can bruteforce the remaining 7! = 5040 possibilities, or we just guess the beginning text:
"The first part of flag:"

This leads us to the (final) permutation of

[3, 1, 4, 11, 6, 7, 8, 0, 5, 12, 9, 2, 10]

And the decrypted message:

*The first part of flag is: ASIS{00e6e9e154, When some blessings come to you, do not drive them away through thanklessness. The second part of flag is: ae86a7cc66077e3c735c2d}#_______*

And so the flag is: ASIS{00e6e9e154ae86a7cc66077e3c735c2d}

So, as soon as you get the idea on how the algorithm works and how to get a few letters organized, it is solved in a short time.

## Other write-ups and resources

* none yet
