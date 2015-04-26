# CONFidence CTF Teaser Mac Hacking 

**Category:** Crypto
**Points:** 150
**Solves:** 47
**Description:**

> They laughed at my XOR encryption. Then, they mocked me for using MD5. Hah! What do they even know. I bet they don't even code in PHP.
>
> Oh, so you think you're clever, too? Well then, Master Hacker, show me your mad skillz. Here, I'll even give you the [source code](). Go ahead, make my day.
>
> Alright, alright, there's an easier way to solve this one than we expected. The task is now worth 150 points.

## Write-up

### Explanation

To do this challenge, we had to understand how HMAC works. HMAC is constructed using the following formula and the hash function used in the challenge was `md5`:

    HMAC(hash, data, key) = hash(key XOR (0x5c repeated 64 times) + hash(key XOR (0x36 repeated 64 times) + data))

The challenge provided us a way to know the output of this where `input` is the value we provide:

    hash(key XOR input)
	
The first step was to send the input `(0x36 repeated 64 times) + "123"`. This would give us the value `hash(key XOR (0x36 repeated 64 times) + data)` in the HMAC formula for the data `123`.

    Query: /?a=sign&m=old&d=%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36%36123
    Output: 2054441aa609e0ff20bc628190e88c40
	
But we want to get a value with data that contains `get flag` in it. So we perform a hash length extension attack using the `HashPump` tool.

    Command: hashpump -s '2054441aa609e0ff20bc628190e88c40' --data '123' -a 'get flag' -k 64
    New hash: 4d6c75e7bb5336ab5dd63d156a0e7db5
    New data: 123\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x18\x02\x00\x00\x00\x00\x00\x00get flag
	  
The second step is to know the output of `hash(key XOR (0x5c repeated 64 times) + previous_hash)` where `previous_hash` is the value that we found in the previous step. So we do the same thing we did in the first step but with `0x5c` instead of `0x36`:

    Query: /?a=sign&m=old&d=%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%4d%6c%75%e7%bb%53%36%ab%5d%d6%3d%15%6a%0e%7d%b5
	Output: 24049ad4b163dd828bd71a8a5f37b642
	
The previous output is the HMAC result of the data  `123\x80\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x18\x02\x00\x00\x00\x00\x00\x00get flag`. Send it and collect the flag.

    Query: /?a=verify&m=new&d=123%80%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%00%18%02%00%00%00%00%00%00get+flag&s=24049ad4b163dd828bd71a8a5f37b642
	
### Flag

DrgnS{MyHardWorkByTheseWordsGuardedPleaseDontStealMasterCryptoProgrammer}

## Other write-ups and resources

* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/CONFIDENCE_TEASER/crypto/machacking>
