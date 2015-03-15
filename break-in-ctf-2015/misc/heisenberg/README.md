# BreakIn CTF 2015: Heisenberg

**Category:** Miscellaneous
**Points:** 200
**Description:**

> Heisenberg's phone is been secretly viewed by his wife and she sees a message from 'YaÃ±ez Sepulveda' and seems to be telling some secret message in an unknown text format.she figures it out that it is not a GZM.Crack it and get him the message.
>
> ciphertext:
>
> GZVBRTKQBKUNKTIKEVQZNZOBKYUNMIJMTDMOKEMZUTAFZNOEFHWVJFQBWQZNNYEEMKTWJVBMDPLOWPLRBKYLNNEVLZTFQLFQLTLLPEWWHWJTPXWCIAJLYLRBLTMKEBLZNLTILEVELPHZLRYELZNMBLCAEVMWLZETFDJEXOWELVWWPAJOR

## Write-up

The first thing we do is googling "'Yañez Sepulveda' cipher" to get the below mentioned Origin of the cipher we have to use.

After understanding what the substitute key is, we use [this code](cocaine.py) to substitute the ciphertext letters with the key letters and print out all possible combinations (since numbers and letters share the same cipher keys).

```bash
$ python cocaine.py
X{1,A}G{9,H}{7,K}NEW{9,H}EISEN{8,B}E{4,R}GW{1,A}S{1,A}C{9,H}EMIS{2,T}{8,B}{6,U}{2,T}NO{2,T}CE{4,R}{2,T}{1,A}INLY{1,A}SC{4,R}YP{0,Z}G{6,U}YW{9,H}{0,Z}W{1,A}SSM{4,R}{4,R}{2,T}EN{0,Z}{6,U}G{9,H}{2,T}OD{3,Ñ}C{0,Z}D{3,Ñ}{7,K}{9,H}EM{3,Ñ}SS{4,R}G{3,Ñ}{1,A}NYW{3,Ñ}YW{3,Ñ}N{3,Ñ}{3,Ñ}D{4,R}{0,Z}{0,Z}P{0,Z}{6,U}ND{5,J}{0,Z}F{8,B}L{6,U}{3,Ñ}M{3,Ñ}{7,K}{9,H}{3,Ñ}N{2,T}E{4,R}{9,H}{3,Ñ}{1,A}S{3,Ñ}N{8,B}{3,Ñ}{4,R}G{4,R}{3,Ñ}DP{1,A}{3,Ñ}{7,K}M{4,R}{3,Ñ}{1,A}S{2,T}{9,H}{3,Ñ}FL{4,R}G{2,T}{0,Z}{3,Ñ}{1,A}{4,R}NYO{6,U}{4,R}{5,J}C{0,Z}{4,R}{3,Ñ}G{0,Z}{0,Z}DL{6,U}C{7,K}
```

Now we can either guess words, such as `HEISENBERG` or print all possible combinations using `bash`'s brace expansion ability:

```bash
$ for i in W{1,A}S{1,A}C{9,H}EMIS{2,T}; do echo $i; done
W1S1C9EMIS2
W1S1C9EMIST
W1S1CHEMIS2
W1S1CHEMIST
W1SAC9EMIS2
W1SAC9EMIST
W1SACHEMIS2
W1SACHEMIST
WAS1C9EMIS2
WAS1C9EMIST
WAS1CHEMIS2
WAS1CHEMIST
WASAC9EMIS2
WASAC9EMIST
WASACHEMIS2
WASACHEMIST
```

Note that you should use this brace expansion ability with care, the more combinations are possible, the longer and more power does `bash` need. Only let `bash` expand the string _partially_.

The output is

> X{1,A}G{9,H}{7,K}NEW {9,H}EISEN{8,B}E{4,R}G
>
> X1GH KNEW HEISENBERG 
>
> W{1,A}S{1,A}C{9,H}EMIS{2,T}{8,B}{6,U}{2,T}NO{2,T}CE{4,R}{2,T}{1,A}INLY{1,A}SC{4,R}YP{0,Z}G
>
> WAS A CHEMIST BUT NOT CERTAINLY
>
> {1,A}SC{4,R}YP{0,Z}G{6,U}YW{9,H}{0,Z}W{1,A}SSM{4,R}{4,R}{2,T}EN{0,Z}{6,U}G{9,H}{2,T}OD{3,Ñ}C{0,Z}D{3,Ñ}
>
> AS CRYP0GUY WH0 WAS SM4RT EN0UGH TO D3C0D3
>
> {7,K}{9,H}EM{3,Ñ}SS{4,R}G{3,Ñ}{1,A}NYW{3,Ñ}YW{3,Ñ}N{3,Ñ}{3,Ñ}D
>
> THE M3SS4G3 ANYW3Y W3 N33D
>
> {4,R}{0,Z}{0,Z}P{0,Z}{6,U}ND{5,J}{0,Z}F{8,B}L{6,U}{3,Ñ}M{3,Ñ}{7,K}{9,H}
>
> 400 P0UND5 0F BLU3 M3TH
>
> {3,Ñ}N{2,T}E{4,R}{9,H}{3,Ñ}{1,A}S{3,Ñ}N{8,B}{3,Ñ}{4,R}G
>
> 3NT3R H31S3NB3RG
>
> {4,R}{3,Ñ}DP{1,A}{3,Ñ}{7,K}M{4,R}{3,Ñ}
>
> 4ND P1NKM4N 
>
> {1,A}S{2,T}{9,H}{3,Ñ}FL{4,R}G
>
> AS TH3 FL4G
>
> {2,T}{0,Z}{3,Ñ}{1,A}{4,R}N YO{6,U} {4,R}{5,J}C{0,Z}{4,R}{3,Ñ} G{0,Z}{0,Z}DL{6,U}C{7,K}
>
> T0 3ARN YOU 4 5C0R3 G00D LUCK

Our flag should be `H31S3NB3RG 4ND P1NKM4N`.

## Other write-ups and resources

* [Origin of cipher](http://crypto-tasks.livejournal.com/28226.html)
