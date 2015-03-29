# Insomni'hack CTF 2015: iBadMovie Season 2

**Category:** Mobile
**Solves:** 20
**Description:** 

> Hi HackLady,
> 
> Thank you for the password. Apparently, the app is decrypting something, maybe a secret. Unfortunately, I just broke my iDevice and I don't have enough money to buy a new one (also because I keep my money to buy a new gold iWatch. Oh my gosh, they are so nice!). Can you help me, please!
> 
> IMPORTANT: You can solve this challenge with an Android device or emulator but also WITHOUT.
> Author : Britney - Difficulty : easy

## Write-up

We don't much more except there's something else to find. So, this time we have a look at the iOS application. The .ipa format is a Zip file, that we unzip. 
In the application, we notice a file 'Blackhat.mp4'. That startles me, especially because the file does not appear to be a valid video:


   $ hexdump -C Blackhat.mp4 | head
   00000000  42 6c 61 7f 0d 1c 18 04  2f 1c 55 51 6b 68 61 75  |Bla...../.UQkhau|
   00000010  2f 1c 55 52 06 18 55 46  2b 1f 0e 0e 6b 69 55 87  |/.UR..UF+...kiU.|
   00000020  2f 03 0e 15 6b 68 61 18  2f 1a 09 07 6b 68 61 74  |/...kha./...khat|
   00000030  93 72 f2 bd ba 76 f2 9c  42 6c 3c a3 6b 5d 4a 35  |.r...v..Bl<.k]J5|
   00000040  42 6d 61 63 6a 68 61 74  42 6c 61 63 6b 68 61 74  |BmacjhatBlackhat|
   00000050  42 6d 61 63 6b 68 61 74  42 6c 61 63 6b 68 61 74  |BmackhatBlackhat|
   ...

We notice there seems to be a mixture of the word Blackhat in there. With IDA Pro, we disassemble the iOS executable to learn more.
Obviously, the file Blackhat.mp4 is loaded.

We also notice a list of interesting functions: showVideo, playVideo and ... decryptVideoWithXOR. So, we guess that the video Blackhat.mp4 is encrypted by XOR. There are no obvious password in the executable apart from Blackhat. We write a quick Python script to do the XOR, load the encrypted Blackhat.mp4 and decrypt.

   
      from itertools import izip, cycle
      import string

      def xor(message, key):
      	  return ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(message, cycle(key)))

      mp4buffer = open('Blackhat.mp4','rb').read()
      dec = xor(mp4buffer,'Blackhat')
      open('dec.mp4','wb').write(dec)


And we're lucky! This is indeed turns the file into a valid MP4 video that we view... at the end lies the flag.

So, those challenges were pretty easy, and indeed, did not require an iPhone at all to solve them. Nice.

## Other write-ups and resources

[French](http://snipefoo.blogspot.fr/2015/03/insomnihack-2015.html?m=1)