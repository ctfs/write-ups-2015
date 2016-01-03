# 32C3 CTF 2015 : aes

**Category:** Misc
**Points:** 250
**Solves:** 5
**Description:**

> Today, everything needs crypto! We developed an AES encrypt module for your ARM chip!
> 
> 
> The module can be accessed via the address range 0x40048000..0x4004807f, see the example for details (binary is best documentation!)
> 
> 
> This demo <http://136.243.194.38:8080/index.htm> device is only capable of encrypting 10 times, afterwards, the cpu has to be powercycled to encrypt anything else.
> 
> 
> Every module is preseeded with a random key and a serial number as input(Hint: this is the flag) the result can be found in the output buffer before anything else is encrypted.


## Write-up

(TODO)

## Other write-ups and resources

* <http://pastebin.com/FZxMidiG>
* [Patch against qemu to add the custom device](http://shells.aachen.ccc.de/~spq/0001-challenge-device-added-and-chip-which-has-this.patch.gz)
