# Hack.lu CTF 2015: Salt

**Category:** Crypto
**Points:** 200
**Solves:** 20
**Description:**

> We managed to capture the following traffic from a user who retrieved a note from that new secure notebook service:
> 
> request: b'\xa0f?u\xfb;AZf\xfc@{M!\xcdP\x92\xf6\x0f\xea\x1d\xad@\xc5\x8c\xd0R\xd8\xfdX81\x01d\xc8\x9b\xc4\xfd\x04\x9b\x843a\x940U\xc4\x7fa\x11W\xa9uf\xa9\xf4%w;`s[\xad\xa8V\x90\xe0w,\xb6<\xbd\xb1\xcbh=\x0b\x80\xba\xd8\x9bM\x17\xc6\x1f\x83<G\xcfV\x93\x00E\xe97\xcc\x9a.\xa1\xe6\x13\x11\xe9<\xae'
> 
> response: b"e\xc8\x9b\xc4\xfd\x04\x9b\x843a\x940U\xc4\x7fa\x11W\xa9uf\xa9\xf4%\r6C\x8d\xe1Z\x95\xb1^\x92\xddF\xa7\xbb\x86\x19\xbaCW\xde\x9bo\xd3Z\x8d\x85kx\x81a\xb0\x0b\xc9\x14'L\xc6i\xc4V\x86=\xba\x11~\xcc\x9bw#i\xc7\xb2\xc0Z\x9d\x1d\xb3\x96\\\xf9\xffG\x8a\xa2"
> 
> That crypto is pretty much invincible - after all, they're using NaCl - but maybe you can figure out some crazy attack anyway? I count on you!!!
> 
> You need to install the "pynacl" python module for python 3 to make this work.
> 
> connect to school.fluxfingers.net:1512
> [download](salt_public_a2b3540e79e8628946ab873ffbeacc29.tar.gz)


## Write-up

by [derlaft](https://github.com/derlaft)

Let's see what do we have here. Client generates an assymetric keypair ([Box NaCl](http://nacl.cr.yp.to/box.html) is used) and sends an encrypted and signed message to a server:

      req = my_sk.public_key.encode() + bytes([command]) + box.encrypt(data.encode('utf8'), nonce)

Box signs the request, so there is no reason to change public key or encrypted data. Hovewer, we can change the command (it's just 0x00 for CMD_STORE and 0x01 for CMD_LOOKUP request).

These commands have different numbers of arguments which are separated by a '#' symbol. If server recieves an incorrect number of arguments for a command, it returns an error. Very large encrypted error.

    if cmd == CMD_STORE:
      if len(params) < 2:
            return reply("you need to send more parameters! seriously, why would you just send one parameter? I should just let this fail with a silent error. sending just one parameter is stupid.")

How can we use it? Let see how server encrypts response. It takes client's [nonce](https://en.wikipedia.org/wiki/Cryptographic_nonce) and increments it:

    # the client already picked a random nonce for the request, so we can just increment it by one for the reply
    answer_nonce = bytes([nonce[0] + 1]) + nonce[1:]
      def reply(str):
          s.sendall(my_box.encrypt(str.encode('utf8'), answer_nonce))

Great. It means that we can get that known response encrypted with the _same_ nonce and key. (You can check it by sending captured request and comparing an answer with the known one. They should be the same). Now we need to find out how Box encryption works.

According to the Internet, "Box uses Curve25519, XSalsa20 and Poly1305 to encrypt and authenticate messages". Curve25519 is some weird elliptic stuff, and Poly1305 is used for signing, so the encryption algorithm is XSalsa20. [The first 32 bytes of the output of XSalsa20 are used for the MAC, the rest are xored into the plaintext to encrypt it.](http://stackoverflow.com/a/13663945)

Wait, is that just a XOR? Solution becomes super-easy because of XOR properties:

    ((text XOR key) XOR (known_text XOR key) XOR (known_text) == text XOR (known_text XOR known_text) XOR (key XOR key) == text XOR 1 XOR 1 == text)
  
So we have only to perform this XOR:

      #!/usr/bin/env python3
      PLAINTEXT=b'you need to send more parameters! seriously, why would you just send one parameter? I should just let this fail with a silent error. sending just one parameter is stupid.'
    CIPHERTEXT=b"e\xc8\x9b\xc4\xfd\x04\x9b\x843a\x940U\xc4\x7fa\x11W\xa9uf\xa9\xf4%\r6C\x8d\xe1Z\x95\xb1^\x92\xddF\xa7\xbb\x86\x19\xbaCW\xde\x9bo\xd3Z\x8d\x85kx\x81a\xb0\x0b\xc9\x14'L\xc6i\xc4V\x86=\xba\x11~\xcc\x9bw#i\xc7\xb2\xc0Z\x9d\x1d\xb3\x96\\\xf9\xffG\x8a\xa2"
    
      # that is what we get if we re-send captured request with a 0x00 changed to 0x01
      # only PLAINTEXT is encrypted here
      RECV=b"e\xc8\x9b\xc4\xfd\x04\x9b\x843a\x940U\xc4\x7fa\x11W\xa9uf\xa9\xf4%\xcco\x95\xb8i\x10`Tz\xd6`\x8bJ&<i\xa5@C\x99\x8ed\xd9a\xce\x83}(\x86k\x81\x06\x9a&!P\xd5 \xdaT\x9d>\xbb\x11U\xc8\x8eek'\xc7\xa3\xed@\x86\x1d\xb0\x93A\xbc\xabI\x9f\xd1\xbcp\xf8\x1a\xba2u\xf8\x88\x05H\x16\xfe\xafX8K)\x03\xbb'&\x01\xcc\xaf\x1f\x1a{\x9dB\xb1\xb7\xc7\x17\x9ahe\x80'\x13\xdbG`\xf8~L\xcf@\x04Q\x97\xac\xf5\x157\x83b\xd4\x086\x08\xb1\xeb7\xf8*\xcf\x8a]q\xb1=\xc8\xd2\xb6\xc8\xdc\xf2)\x8e\x13\xd2\x16`\x84&Wn^\xce\xa8\x84\x9e\xc0\xeb\xb2\xc2\xcc\x92\xaf\x10\xad$c\x13\x92\xae]\x87\x83\x0c\x8a.D\xdf\xe0\xbf\x12\x87 \x11:"
      XOR=lambda s1,s2: bytes([(a ^ b) for a,b in zip(s1,s2)])

    # Messages have some tech data in the beginning: MAC and other stuff
    # I was too lazy to calculate the correct shift, so let's just iterate
    for i in range(23,42): 
        print( XOR(CIPHERTEXT[i:], XOR(RECV[i:], PLAINTEXT)) )

Result:

      ...
      b'flag{no_crypto_is_invincible_against_stupidity}\n'
      ...

## Other write-ups and resources

* <https://der.ttyh.ru/blag/post/salt-writeup/>
