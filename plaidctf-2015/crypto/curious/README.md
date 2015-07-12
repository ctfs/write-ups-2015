# PlaidCTF CTF 2015: Curious

**Category:** Crypto
**Points:** 70
**Solves:** 78
**Description:**

> The curious case of the random e.
>
> We've [captured](http://play.plaidctf.com/files/captured_a4ff19205b4a6b0a221111296439b9c7) the flag encrypted several times... do you think you can recover it?
>
>
>
> Team	Points	Submission
> 0ops	72	16 hours ago
> mrx	71	16 hours ago
> fuzzi3	70	16 hours ago

## Write-up

_This write-up is made by Xarsman of the [HacknamStyle](https://www.hacknamstyle.net/) CTF team._

We are given a file which contained a list of tuples `{N : e : c}`. This seems like a common [RSA](http://en.wikipedia.org/wiki/RSA_%28cryptosystem%29) encryption and we get the public key `{N,e} = {modulus, exponent}` and `{c} = {ciphertext}`. If you aren't familiar with the [RSA cryptosystem](http://en.wikipedia.org/wiki/RSA_%28cryptosystem%29) I suggest you read up on wikipedia first before continuing this write-up.

The first thing we might notice is that the public exponent `e` is quite large. Usually this is `65537 == 2*16 + 1` or in some case even `3`. Our exponent though is of the same size as `N` which is unusual. After some googling and digging around we figure that this large public exponent means that there is a large chance that the private exponent `d` is rather small. This is interesting because a guy named [Wiener discovered an attack](http://en.wikipedia.org/wiki/Wiener%27s_attack) against the RSA cryptosystem when `d < 1/3*N^(1/4)`. 
I'll briefly summarize the attack below:
* you calculate the fractions of `e/N` in order to approximate `d` since `e/N ~ k/d`
* solve the equation `f(x) = x² - (N - phi(N) +1)*x + N` for `f(x) = 0`
* the roots of the above equation are the primes `p` and `q` and since `p*q = N` we've succesfully factorized `N` and thus cracked the RSA key.

Note that there are some conditions that apply; Not every root is a solution since `p` and `q` are primes they need to be perfect integers (so no real numbers as solutions). Also since this is an approximation we need to check that `p*q = N`.

Now that we know the general ideas and we kind of know the theory behind this all we can code (or find some code online) to solve this problem. I found [some code online](https://github.com/pablocelayes/rsa-wiener-attack) that already implements said attack but I rewrote them and put it together in a module named [wiener_attack](wiener_attack.py). The most interesting part is shown in the snippet below:

```python
def wiener_attack(N,e):
    (p,q,d) = (0,0,0)
    conv=convergents(partial_quotiens(e,N))
    for frac in conv:
        (k,d)=frac
        if k == 0:
            continue
        y = -(N - phiN(e, d, k) + 1)
        discr = y*y - 4*N
        if(discr>=0):
            # we need a perfect squared discriminant
            sqr_discr = is_perfect_square(discr)
            # test if discr is positive and the roots are integers
            if sqr_discr!=-1 and (-y+sqr_discr)%2==0:
                p = ((-y+sqr_discr)/2)
                q = ((-y-sqr_discr)/2)
                return p, q, d
    return p, q, d
```

So the thing is we make the continued fractions of `e/N` to approximate `k/d` but we don't solve each equation corresponding with al those values for `k` and `d`. This would be too time consuming. We only really need to solve an equation when we have a perfect squared discriminant. If we don't have that our would-be roots `p` and `q` won't be perfect integers, thus they won't be primes and not a valid solution. If we have a perfect squared discriminant wedo a last check to make sure `p` and `q` are really integers and if they succeed we have found our roots. 

Now we have to write a [small script](curious_solve.py) that loops through all the keys and tries to crack them all. We save all our roots in a list and try to decipher the chipertexts with the calculated roots.

```python
from wiener_attack import *

nlist = list()
elist = list()
clist = list()
with open('captured_a4ff19205b4a6b0a221111296439b9c7') as f:
    # read the line {N : e : c} and do nothing with it
    f.readline()
    for i in f.readlines():
        (N, e, c) = i[1:-2].split(" : ")
        N = long(N, 16)
        e = long(e, 16)
        c = long(c, 16)
        nlist.append(N)
        elist.append(e)
        clist.append(c)

solutions = []
for i in range(0, len(elist)):
    (p,q,d) = wiener_attack(nlist[i],elist[i])
    if p != 0 and q != 0:
        solutions.append((nlist[i],clist[i],d))
    print "i: ", i
    print "p: ", p
    print "q: ", q
    print

for j in range(len(solutions)):
    (n,c,d) = solutions[j]
    plain = pow(c, d, n)
    print hex(plain)
    print hex(plain)[2:-1].decode('hex')
```

Running that code gives us the flag
```bash
$ python curious_solve.py 
..
flag_S0Y0UKN0WW13N3R$4TT4CK!
```


## Other write-ups and resources

* [b01lers](https://b01lers.net/challenges/PlaidCTF%202015/curious/46/)
* [Lense](https://gist.github.com/Lense/8a84b2e6d140176bfad9)
* <http://capturetheswag.blogspot.com.au/2015/04/plaidctf-curious-crypto-70-point.html>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/PCTF/crypto/curious>
* <https://gist.github.com/anthonyclays/c530372fc5f15b05b843>
