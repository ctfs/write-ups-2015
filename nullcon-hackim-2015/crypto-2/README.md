# nullcon HackIM 2015: Crypto Question 2

**Category:** Crypto
**Points:** 100
**Author:**
**Description:**

>A message has been intercepted from Alice to Bob. Decode and find the flag.
>
>Message:
>11313221111241132131614122141231311261112124131111132131623212141221322111131312141321222141621211124114212162114241131222211121623122211112211112133162321214121211135321221412121112112113221221111221416231242121613111131222211121124163221214216352123221111241132212211121621322141311322111216241121322214163111113221221112163113211422111216213222111131321623212141221322111231131721142123213221142312262131221112222221111222212411222322132221221322111123222311221112211421322312211423122111112312231222143212221322221135111211111321142411213221112132221126111215112123211211232122111

## Write-up

by [jagotu](https://github.com/jagotu)

First thing we'll notice is that the distribution of the numbers is very uneven:

1: 261  
2: 202  
3: 66  
4: 31  
5: 4  
6: 19  
7: 1  
8: 0  
9: 0

We can see that small numbers occur way more often than large ones. This hints that the message uses [run-length encoding](https://en.wikipedia.org/wiki/Run-length_encoding), most likely encoding the binary represantation of an string. As all ASCII chars begin with a 0, we know that we should start by zeros. Every number of the message corresponds to the number of repetitions of 0 or 1.

Sample python code:
```python
import sys
input = "113132...1"

c = 0
for i in range(len(input)):
    sys.stdout.write(str(c) * int(input[i]))
    c = 1 - c
```

When the output is interpreted in ASCII, we get the resulting message:
>Dear Bob,  
>Our codeword may have been compromised by Eve, so please note and use the new code: 4674107e353af23dec1e471415bbd923.  
>Thanks,  
>Alice  

## Other write-ups and resources

* none yet