# OpenToAll CTF 2015: Math Is Hard

**Category:** Misc
**Points:** 200
**Solves:** 110
**Author:** gaffe
**Description:**

> 104.131.107.153:12121

## Write-up

This challenge was in 3 steps:
* Compute a sum
* Solve an equation
* Compute the value of the derivated of the given function at a specific point

Each of these steps had to be done 8 times.

Let's begin by making a function for the first step. Since it's always a sum between 2 numbers, we can just extract the two numbers and naively compute the sum.

```python
def calc(s):
    data = s.recv(4096).decode().split()[-3:] # Extract the calc datas
    nb1 = int(data[0])
    nb2 = int(data[2])
    res = str(nb1 + nb2)
    s.send(res.encode())
```

For the second step we'll just use a module: numpy which already implement linear equation solving.
for two equations:

* a*x + b*y = c
* a'*x' + b'*y' = c'

With a, a', b, b', c, c' constants and x, y undefined values, we can use numpy to get the solution tuple (x, y) like this:

```python
import numpy

A = numpy.array([[a, b], [a', b']])
B = numpy.array([c], [c'])
r = numpy.linalg.solve(A, B)
```

Applying it to our case:

```python
def equation(s):
    data = s.recv(4096).decode()
    # Extract the equations
    eq1, eq2 = tuple(data.split('\n')[-4:-2])
    eq1, eq2 = eq1.split(), eq2.split()
    # Extract equations members
    eq1x, eq1y, eq1z = int(eq1[0][:-1]), int(eq1[2][:-1]), int(eq1[4])
    eq2x, eq2y, eq2z = int(eq2[0][:-1]), int(eq2[2][:-1]), int(eq2[4])
    # Solve with numpy
    a = numpy.array([[eq1x, eq1y], [eq2x, eq2y]])
    b = numpy.array([[eq1z], [eq2z]])
    res = numpy.linalg.solve(a, b)
    x = str(res[0])[1:-2]
    y = str(res[1])[1:-2]
    s.send(x.encode())
    s.send(y.encode())
```

Finally, the third part which seems to be the harder part is in fact really simple since the only functions we get are sums of constants or functions of the form :

> f(x) = a*x^b

Since constants are nullified by the derivation and the derivation of these functions is:

> f'(x) = a*b*x^(b - 1)

It allows us to implement a naive algorithm by just ignoring constant values and extracting values from the function to compute the derivated value at the given point.

```python
def derivation(s):
    data = s.recv(4096).decode().split('\n')
    pt = int(data[-4][-2:-1]) # Extract the point value
    fs = data[-3][7:].split() # Extract the function
    fs = [x for x in fs if 'x' in x] # Ignore constants
    a = int(f[0])
    b = int(f[-1])
    res = sum([a * b * pow(pt, b - 1) for f in fs]) # Compute derivated value
    s.send(str(res).encode())
```

Putting all these functions together with some loops and a nice socket we get:

[script.py](script.py)

And the flag:
> flag{l3ts_g0_shOpP1ng}

## Other write-ups and resources

* [Original source and writeup](https://github.com/gaffe23/gaffe-ota2/tree/master/math-is-hard)
