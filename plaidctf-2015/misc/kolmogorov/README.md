# PlaidCTF CTF 2015: Kolmogorov

**Category:** Misc
**Points:** 150
**Solves:** 20
**Description:**

> All we know about [Kolmogorov's Pet Snake](http://play.plaidctf.com/files/kolmogorov_59658fc88748139edc32ec26c8a64af0) is that the flag has no uppercase letters nor numbers (note: this flag is not in the flag{} format)...
> 
> 
> Team	Points	Submission
> 0xffa	156	a day ago
> 217	153	a day ago
> LC BC	151	a day ago

## Write-up

The bunch of gibberish in the assignment is a program in the code golf-centric programming language Pyth. It translates to Python, that's probably where the pet snake in the name comes from.

The code below is what the (patched! there's a bug in the run-length encoding code, a single line is indented wrongly, I hope it'll be fixed by the time you read this) interpreter for Pyth translates the terse code to:

```python
z=copy(input())
J=copy(chop(z,"_"))
Pprint("\n",
  equal(
    Psum(
      Pmap(lambda d:Pchr(d)
          ,join(
            base_10(
              plus(
                Psum(
                  run_length_encoding(
                    Pmap(lambda k:Plen(k)
                        ,J)))
                ,Pmap(lambda k:index(G,k)
                     ,Psum(J)))
              ,25)
            ,(126))))
    ,"\n^[8^T^^Edi^Ep^H/]+^[?\n^H^[L.vD^Y{^F^Gr6c^UpE^PXT}Jfu^D,\"9iKhW4Xmmv;gf"))
```

(All non-standard functions are from the Pyth library)
As all of the Pyth functions are massively multifunctional I provide a rough translation of what the code inside the equal() means (in some semi-pseudocode).

```
concat(map(chr, tobase(tobase10from(concat(runLengthEncoding(map(len, J))) + map(letterOfAlphabet,concat(J)),25),126)))
```

And here's what it does in human-speak:
The program takes the flag as input, a long string of ascii chars with _ as a kind of group separator as input and checks if it corresponds to the compressed version that's in the program code (the thing with all the low-value bytes).
Here's how the compression happens:
Take the runlength encoding of the list of group lengths of the input (the groups are split by underscores), this returns a list of lists (`[[3,3][4,17]]` for the flag) which is flattened and prepended to a concatenated version of the list of groups (so the input without \_), transformed from letters to numbers (a -> 0, b -> 1, ...).
This list is interpreted as a base 25 number and converted to a regular int. This int is then encoded into a base126 string (the string is a number that uses the ascii chars (including the ones used for escape sequences) up to }).
The Kolmogorov in the name probably refers to Kolmogorov complexity (look it up ;) ).

I decoded the string by loading the Pyth interpreter in a py3 repl and reversing the operations.

```python
join(base_10(Pmap(lambda d:Pchr(d),"..."),126),25)
[3, 4, 4, 17, 7, 14, 22, 2, 0, 13, 19, 7, 4, 10, 4, 24, 5, 17, 14, 12, 18, 20, 2, 7, 21, 4, 17, 24, 18, 7, 17, 19, 2, 14, 3, 4, 12, 0, 10, 4, 18, 20, 2, 7, 11, 14, 13, 6, 5, 11, 0, 6, 22, 7, 0, 19, 19, 7, 4, 4, 7, 4, 11, 11, 7, 14, 22, 18, 19, 7, 0, 19, 18, 7, 8, 19, 15, 14, 18, 18, 8, 1, 11, 4]

Pmap(lambda k: lookup(G,k),...
['d', 'e', 'e', 'r', 'h', 'o', 'w', 'c', 'a', 'n', 't', 'h', 'e', 'k', 'e', 'y', 'f', 'r', 'o', 'm', 's', 'u', 'c', 'h', 'v', 'e', 'r', 'y', 's', 'h', 'r', 't', 'c', 'o', 'd', 'e', 'm', 'a', 'k', 'e', 's', 'u', 'c', 'h', 'l', 'o', 'n', 'g', 'f', 'l', 'a', 'g', 'w', 'h', 'a', 't', 't', 'h', 'e', 'e', 'h', 'e', 'l', 'l', 'h', 'o', 'w', 's', 't', 'h', 'a', 't', 's', 'h', 'i', 't', 'p', 'o', 's', 's', 'i', 'b', 'l', 'e']
```

Remembering that the "deer" in the beginning represents the run-length encoding of the group lengths [[3,4],[4,17]] that yields the following flag:
```
how_can_the_key_from_such_very_shrt_code_make_such_long_flag_what_thee_hell_hows_that_shit_poss_ible
```

## Other write-ups and resources

* none yet
