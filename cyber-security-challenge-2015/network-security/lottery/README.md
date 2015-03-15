# Cyber Security Challenge 2015: Lottery

**Category:** Network Security
**Points:** 50
**Description:**

> Come and throw away your money at the NViso Lottery!
>
> 37.187.249.84:10004

## Write-up

Let's connect to the lottery service:
```
root@kali:~# nc localhost 55567
################################################################################
Welcome to the NVISO lottery!
You start out with $100.
Each bet will cost you $10.
Guess the correct number, and you'll win $75!
Each number is chosen at random from the range [0, 1000].
If you feel you've been cheated, you can use the ticket ID to get feedback

Earn more than $1337 and get a special prize!
################################################################################

Want to play another round?
Current money: $100
1. Yes
2. No

1
Good luck! (id #KEkxCihJMTg4MDkKSTg0MDIKSTIwNjUzCnRwMQpOdC4=)
Please enter a number between 0 and 1000:
100
Too bad, the answer was 729

Want to play another round?
Current money: $90
1. Yes
2. No

2
Oh.. okay then. Bye!
```
The ID is base64 encoded. Decoding it gives the following:
```python
>>> from base64 import b64decode
>>> b64decode("KEkxCihJMTg4MDkKSTg0MDIKSTIwNjUzCnRwMQpOdC4=")
'(I1\n(I18809\nI8402\nI20653\ntp1\nNt.'
>>>
```
This looks like python's Pickle format:
```python
>>> import pickle
>>> s = b64decode("KEkxCihJMTg4MDkKSTg0MDIKSTIwNjUzCnRwMQpOdC4=")
>>> pickle.loads(s)
(1, (18809, 8402, 20653), None)
>>>
```
This gives us the seed for a random number generator. It's not large enough to be used as the seed for the default python random number generator (MersenneTwiter), but it is the correct format for python's previous default random number generator: Wichmann-Hill.
```python
from cPickle import *
from random import WichmannHill
from base64 import b64decode

input = "KEkxCihJMTg4MDkKSTg0MDIKSTIwNjUzCnRwMQpOdC4="
r = WichmannHill()
print r.getstate()

newState = loads(b64decode(input))
r.setstate(newState)
print r.randrange(0, 1000)
```
This gives `729`, which is exactly what we were looking for.

Quick little solution:
```python
import cPickle as pickle
from random import WichmannHill
import base64
from pwn import *

r = remote('localhost', 55567);

while True:
	d = r.recvuntil("2. No")
	
	if "your prize" in d:
		print d
		break
	
	while r.can_recv():
		r.recvline()
		
	r.sendline("1")
	data = r.recvline()
	print data
	data = data[16:len(data)-2]
	data = base64.b64decode(data)
	
	seed = pickle.loads(data)
	
	prng = WichmannHill()
	prng.setstate(seed)
	
	while r.can_recv():
		r.recvline()

	nr = prng.randrange(0, 1000)
	print "> ", str(nr)
	r.sendline(str(nr))
	print r.recvline()
```

## Other write-ups and resources

* none yet
