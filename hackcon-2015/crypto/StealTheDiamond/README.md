# Hackcon 2015: Steal the Diamond

**Category:** Crypto
**Points:** 25
**Author:** [Mayank Vachher](https://github.com/mvachher)
**Difficulty:** Easy
**Description:** 

D4RKBLU3 is a novice cracker and is starting to learn the basics of Cryptography.
He comes across this encryption system which uses the following python function to encrypt data:

    def enc(message, key):
        message = message.decode('hex')
        key = key.decode('hex')
        return (''.join(chr(ord(k)^ord(c)) for c,k in zip(message,itertools.cycle(key)))).encode('hex')

D4RKBLU3 used this function to encode the message "omg thisisfoobar" with two keys.

He tried devising a complex system which he claims cannot be broken.
He just provided us with the following flowchart and the final result after using 2 layer encryption.
    
              a
             / \
      key1  /   \  key2
           /     \
          b       c
           \     /
      key2  \   /  key1
             \ /
              d
    

    a = "omg thisisfoobar"
    d = "0b59154b16041c400e1c121f180c0416"

He used the above mentioned system in such a way that enc(b,c) gave out his password. Are you smart enough to find his password?

## Write-up

(TODO)

## Other write-ups and resources

* <http://vimvaders.github.io/hackcon2015/2015/08/20/steal-the-diamond.html>
