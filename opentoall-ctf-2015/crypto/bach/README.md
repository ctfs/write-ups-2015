# OpenToAll CTF 2015: bach

**Category:** Crypto
**Points:** 150
**Solves:** 46
**Author:** Eriner
**Description:** 

> Well, not quite...
> 
> Note: the format is flag{secret goes here}
> 
> [8aec78b8dca5541b69d07404f1a6be68.tar.bz2](8aec78b8dca5541b69d07404f1a6be68.tar.bz2)

## Write-up

We are given a picture of a play with several notes.

Googling `Bach crypto` leads us to the Wikipedia entry for [Musical Cryptograms](http://en.wikipedia.org/wiki/Musical_cryptogram).

There, we see that the alphabet is encoded into different notes and their [accidentals](http://en.wikipedia.org/wiki/Accidental_%28music%29) natural (♮), sharp (♯) and flat (♭).

After some fiddling, we see that the decryption key is as follows:

```
- A B C D E F G
♯ H I J K L M N
♮ O P Q R S T U
♭ V W X Y Z
```

A similar example is <http://myplace.frontier.com/~evaew/wilkinsworks/NA_example_2.html>, which is more explained [here](http://myplace.frontier.com/~evaew/wilkinsworks/NoteAlpha.html)

The flag is `flag{erinersmusicalmasterpiece}`.

## Other write-ups and resources

* none yet