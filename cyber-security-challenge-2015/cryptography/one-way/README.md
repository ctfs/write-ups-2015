# Cyber Security Challenge 2015: One Way

**Category:** Cryptography
**Points:** 100
**Description:**

> We want our employees to be able to send us confidential information which only we can decrypt. Since we don’t believe in PKI (for religious reasons), we made our own crypto system. (Homemade is always better!). We prevent tampering, we took some precautions: A salt is added to each request and the IV is chosen at random for every connection. Take a look at [the given `clientFramework.py` file](clientFramework.py) for more info on how to use our crypto system.

## Write-up

_By Ruben Tytgat on <https://ruben.infogroep.be/?p=12>._

Yesterday I participated in the Cyber Security Challenge with my friends Kwinten, Tom and Youri (as team Infogroep).  One of the challenges I helped break was the 'One Way' crypto challenge. This was a fun challenge, so I wanted to share our solution.

The challenge consists of a server which encrypts your input using AES in CBC mode with an unknown key. The objective is to retrieve the salt this server appends to your input before it encrypts it. The server's code is mostly available.

Let's first have a look at the information we have:
* The encryption used is AES in CBC mode.
* Block size is 16 characters
* The flag is a salt appended to your input
* The flag is 8 characters long
* The IV is not randomized between requests
* We have no access to the key used for encryption
* We have most of the server's code

The encryption being applied on our input is AES in CBC mode. This would make the challenge a lot harder if the salt we are looking for were longer. As it turns out, however, in this challenge the salt is only 8 characters. This is smaller than our block size, so we can encrypt the entire salt in 1 block. If we focus only on the first block in the encryption result, this effectively makes the CBC encryption equivalent to a simple ECB encryption where our input is first XOR'ed with the IV.

Since we don't have the key, we can't decrypt the generated blocks. The trick here is that we don't have to. Due to the way the salt is appended to our input, it is extremely vulnerable to a padding attack.

Suppose the XOR with the IV is not present. In that case, we are just dealing with an AES encryption where the key is unknown. We can simply regard this AES encryption as a hashing algorithm and build up a rainbow table. The 8-character salt makes for a set of 2^64 possibilities, which is too much to be feasibly bruteforced. This is where the padding attack comes in. As mentioned before, we only keep the first block of the encryption result. We can also decide ourselves how much of the salt is present in the first block of the result by selecting an appropriate length for our input string. This way we can bruteforce the salt letter by letter and limit the set of possibilities to 2048, which is very feasible. For example, to calculate a rainbow table for the first character, we encrypt all the following strings:

	aaaaaaaaaaaaaaa\0x00
	aaaaaaaaaaaaaaa\0x01
	aaaaaaaaaaaaaaa\0x02
	...
	aaaaaaaaaaaaaaa\0xFF

We then encrypt only the 15 a's, and the server will pull in 1 character of the salt.

	aaaaaaaaaaaaaaas

We check the generated hash in our rainbow table and thus obtain the first character. Then we continue with the next character:

	aaaaaaaaaaaaaas\0x00
	aaaaaaaaaaaaaas\0x01
	aaaaaaaaaaaaaas\0x02
	...
	aaaaaaaaaaaaaas\0xFF

And so on until we have the full salt.

However, we can't actually directly input to the AES input, but have to first go through the XOR with the IV. Fortunately, an XOR is reversible by XOR'ing with the same value again, and the IV is not randomized between encryptions, but predictable. This means we can actually send raw data to the AES input by predicting the next IV and XOR'ing it with our input. We can now write a function that evades the IV XOR on our input and encrypts our input directly with the AES encryptor. We also update the original encrypt function so it returns the IV and the encrypted data instead of uselessly printing to STDOUT. Lastly, we need a function to predict the IV, which we can simply copy from the server code.

```python
def updateIV(currentIV):
	nextIV = ""
	for i in range(0, len(currentIV)):
		k = ord(currentIV[i])
		k += 42
		k %= 0xFF
		nextIV += chr(k)
	return nextIV

def encrypt(plaintext):

	# Send the data
	send_blob(s, plaintext)

	# Receive the data (yawn)
	data = recv_blob(s)

	# The IV is the first 16 bytes of the data
	iv = data[:16]

	# And the encrypted string is the rest. 
	encrypted = data[16:]

	# We don't care about the other blocks.
	return iv, encrypted[:16]

def xor_string(msg, iv):
	res = ""
	for i in range(0, len(msg)):
		k = ord(msg[i]) ^ ord(iv[i])
		res += chr(k)
	return res

def encrypt_directly(prevIV, msg):
	# Calculate the next IV.
	nextIV = updateIV(prevIV)

	# Do an XOR of the message with the IV. The server will XOR again, yielding
	# the original message.
	xored = xor_string(msg, nextIV)

	# Encrypt and return new IV and encrypted data.
	return encrypt(xored)
```

We can't, however, change the fact that the salt will be XOR'ed with the IV and will be encrypted in a garbled state, since it's not part of our input. This means that to build our rainbow table we'll also have to XOR the parts of the salt that we already calculated in order to get a correct hash, and we'll have to XOR it with the IV that we'll be using when we're encrypting the incomplete input. Thus we need a new function to predict far into the future.

```python
def find_iv_after_iterations(iv, amount):
	for i in range(amount):
		iv = updateIV(iv)
	return iv
```

We can now acquire the flag with the following piece of code:

```python
# IV is randomized when first connecting, so we need to get the initial random IV.
# Just encrypt something random to get the IV.
iv, ignore = encrypt("    ")
decoded_flag = ""

# For every character of the flag
for flag_length in range(8):
	# Initialize a rainbow table
	rainbow = {}

	# Create a padding string leaving space for the characters we already figured out
	# and for the one we are going to be guessing now.
	padding = 'a' * (16 - flag_length - 1)

	# We're going to be doing 256 requests to build our rainbow table
	# The request where we actually send a character less and pull one character
	# out of the salt will be the 257'th, so calculate the IV for that iteration.
	next_query_iv = find_iv_after_iterations(iv, 257)

	# For every possible value of the next character
	# Note: you really only need to iterate on the characters that are potentially
	# in the flag here. We're just checking every ASCII code for simplicity's sake.
	for j in range(256):
		# Send a guess to obtain the hash for that guess.
		# XOR the input with the IV to be used when checking in our table.
		# The padding gets XOR'ed as well, but we don't care, it's just padding.
		rainbow_preparation = xor_string(padding + decoded_flag + chr(j), next_query_iv)

		# Send the prepared string directly into the AES encryptor.
		# Store the IV for the next iteration.
		iv, encrypted = encrypt_directly(iv, rainbow_preparation)

		# Store in our rainbow table.
		rainbow[encrypted] = chr(j)

	# By now we should have next_query_iv as the next iv.
	# We send only padding, and let the server add a part of the salt.
	# We don't use encrypt_directly here, because we also XOR'ed the padding
	# when building the rainbow table.
	iv, encrypted = encrypt(padding)
	decoded_flag = decoded_flag + rainbow[encrypted]

# Full calculated flag
print "Decoded flag: ", decoded_flag
```

This code will do 8 iterations, collecting 1 more letter of the flag in every iteration. At the end we print the flag to STDOUT.
The flag we obtain this way is `saltmine`.

## Other write-ups and resources

* <https://ruben.infogroep.be/?p=12>
