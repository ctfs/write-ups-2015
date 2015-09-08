# ASIS Quals CTF 2015: Simple Algorithm

**Category:** Crypto
**Points:** 100
**Solves:** 102
**Description:**

> The flag is encrypted by this [code](http://tasks.asis-ctf.ir/simple_algorithm_5a0058082857cf27d6e51c095ac59bd5), can you decrypt it after finding the system?

## Write-up

We are given a long integer
> 2712733801194381163880124319146586498182192151917719248224681364019142438188097307292437016388011943193619457377217328473027324319178428

and a python code that converts a flag into an integer.

**Code**
My complete code can be found in simple_python.py

**Sidenote**: I don't need this, but who is interested:
FAN(n, m) interprets the binary representation of n as string of base m and returns the corresponding value with base 10. Example:
```
n = 6
m = 3
6 in binary is 101
FAN(6, 3) = 1 * 3^2 + 0 * 3^1 + 1 * 3^0 = 10
```
**Encryption**
The encryption algorith in Pseudocode is
```
Enc(flag):
encode flag as hex
convert large hex number to base 10
split it in parts of 2 digits
calculate for every part x the value FAN(x, 3) 
concatenate the values
```

**Idea**
The idea is to reverse the algorithm. Therefor we will:
Split the integer
Find corresponding x
concatenate the integer (base 10)
convert it to hex
end decode the flag

To find the x, I tried all possible values for x (0 .. 99). I precalculated the FAN(x, 3) values to save this time, but a reverse lookup table would be even faster ...

The biggest problem was finding the positions to split the integer. The FAN() values are 1 up to 4 digits long, so we don't know where to split. So I used Dynamic Programming to find all possibilities:
Let's say we have the following FAN() values:

| x | FAN(x, 3)|
| ----------|---|
| FAN(0, 3) | 17 |
| FAN(1, 3) | 1 |
| FAN(2, 3) | 76 |
| FAN(3, 3) | 6 |
and the integer 176.

At pos = 0, we can use the 17 or the 1. So, all posible options to generate 176 is, we use a 17 and than what we need from pos=2 until the end (only a 6 possible), or we use a 1 and what we need from pos=1 to the end. To calculate this, I started from the end of the integer going backwards and I always looked what i can match on the string. When I finally reached pos=0, I had a list of all possibilities to go from pos=0 to the end. These are 1105920 possibilities.
```python
arr = [FAN(i, 3) for i in range(100)]
for pos in range(len(str(s)) - 1, -1, -1):
    # [...] excluded some special cases
	for val in range(0, 100):
		if str(s)[pos:pos + len(str(arr[val]))] == str(arr[val]):
			possible[pos] += ['%02d|' % val + k for k in possible[pos + len(str(arr[val]))]]
```

After this, I reconstructed the flag and ignored all flags with non-printable bytes.
The result is the flag SIS{a9ab115c488a311896dac4e8bc20a6d7}. (I had to 'guess' the first letter, because the algorithm drops it)

Total runtime: 12 seconds

**Annotation**
With a different flag, the number of possibilities can maybe grow even more, and thus exceed memory limits. A solution is to split the long integer into 2 parts. Than calculated normally from the end until the middle and begin with only the '_' form the middle to the beginning. After this, you iterate over all possibilities in the first part and in the second part and concatenate them. This will dramatically reduce the number of stored values. I tried this, and it worked. However, I srun the program 4 times with different split positions: 70, 71, 72 and 73, because this ssplit position MUST be between to values.

## Other write-ups and resources

* <http://capturetheswag.blogspot.com.au/2015/05/asis-ctf-2015-simplealgorithm-100-point.html>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/ASISCTF/crypto/simplealgorithm>
* [Indonesian](https://github.com/rentjongteam/write-ups-2015/tree/master/asis-quals-2015/simple-algorithm)
