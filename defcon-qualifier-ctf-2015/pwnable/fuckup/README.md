# DEF CON Qualifier 2015: fuckup

**Category:** Pwnable
**Points:** 3
**Solves:** TODO
**Description:**

> fuckup_56f604b0ea918206dcb332339a819344.quals.shallweplayaga.me:2000
>
> OR fuckup_56f604b0ea918206dcb332339a819344.quals.shallweplayaga.me:46387
>
> [Download](http://downloads.notmalware.ru/fuckup_56f604b0ea918206dcb332339a819344)


## Write-up

Writeup by epochfail.

TLDR: break underlying PRNG without using z3.

### Summary

You get a binary with a bootleg implementation of in-process text-ASLR. The binary is PIC-compiled, and there's a function to re-randomize the text location. The re-randomization is done with page granularity and it changes text and stack locations.

Initial menu:

```
Welcome to Fully Unguessable Convoluted Kinetogenic Userspace Pseudoransomization, the new and improved ASLR.
This app is to help prove the benefits of F.U.C.K.U.P.
Main Menu
---------
1. Display info
2. Change random
3. View state info
4. Test stack smash
-------
0. Quit
```

Upon choosing `2`, you get `App moved to new random location` -- text and stack have been shifted and stack values rewritten to point to the new memory location. So from time to time, you get a segfault. Fun. Also probably not exploitable.

Option `3` will give us the last random number (which determiens the current textbase) and re-randomize the text. This is useful for e.g. PRNG prediction.

Option `4` is more interesting:
```
Input buffer is 10 bytes in size. Accepting 100 bytes of data.
This will crash however the location of the stack and binary are unknown to stop code execution
```

This leaves multiple avenues of attack:
* Predict PRNG used to shift text around
* Partial overwrite of data on the stack, hoping to hit something juicy
* Work with VDSO

All of these have been done by multiple teams in the CTF, most clean one being the partial overwrite of the return address (set its LSB to `\x14` to re-initialize the PRNG with known values at `0x08048114`).

I will describe a "proper" solution to this that does not use z3 and breaks the underlying PRNG.

### Solution


Analysing the PRNG, we see it is a Well512 generator (obtained by googling the only magic number in the decompiled code) with some floating-point adjustments. These do not change the mechanics of the PRNG, only that the results are off by 1, and we have to adjust for that. We do not need to know what PRNG it is, though, since HexRays decompiles the code to something like this:

```python
def prng_gen_next():
    state = self.state
    idx = self.idx

    v5 = state[(idx + 15) & 0xF];
    v5 &= 0xffffffff;
    v6 = state[(idx + 13) & 0xF] ^ state[idx] ^ (state[idx] << 16) ^ (state[(idx + 13) & 0xF] << 15);
    v6 &= 0xffffffff;
    v7 = state[(idx + 9) & 0xF] ^ (state[(idx + 9) & 0xF] >> 11);
    v7 &= 0xffffffff;
    v8 = ((v7 ^ v6) << 5) & 0xDA442D24 ^ v7 ^ v5 ^ (v5 << 2) ^ (v6 << 18) ^ (v7 << 28);
    v8 &= 0xffffffff;

    state[(idx + 10) & 0xF] = v7 ^ v6;
    state[(idx + 15) & 0xF] = v8;

    self.idx = (idx + 15) & 0xF;  # Subtract 1 modulo 16
    return v8
```

Three key observations:
* We see part of the state (`v8`) as returned by choosing `3` in the main menu.
* The state function uses only xor, bitwise-and, shifts to do its computation on state values.
* State values are either untouched, read from, or written to.

If you consider this function as an algebraic function that modifies state, that is, a function `f: State -> State` where `State` is a 512-bit vector (a vector in `GF(2)^512`)... then you can note that it is a [linear map](http://en.wikipedia.org/wiki/Linear_map). Linear maps have the property that, for two inputs `a` and `b`, it is true that `f(a+b) = f(a) + f(b)`. And, linear maps can be represented by matrices (and vice versa).

So, if we can build a matrix `M` for one application of `prng_gen_next`, then maybe we can invert it and directly solve for the initial seed of the PRNG from its outputs. Unfortunately, this is impossible: `state[(idx + 10) % 0xf]` is lost after the first call, and so the function is not invertible. But it does not mean we can't use the same method: we do not need to know what that value was (it is overwritten and its initial seed value is never used).

Another problem is that the matrix `M` does not work for two applications of `prng_gen_next` since we have another variable, `idx`, which changes with every call. But we can work around that by defining `M_0, M_1, ..., M_15` where each `M_i` is the result of calling `prng_gen_next` with `idx=i`.

Construction of these matrices is trivial: by the additive property, it is enough to call `f(1), f(2), f(4), f(8), ..., f(2**511)` to obtain each column of the matrix, in order. See Wikipedia or Google or an algebra coursebook for why that is so.

So, now that we have 16 matrices, we can solve for the initial state. Note that these matrices do not depend on the generated random values from the server, and so this can be precomputed and cached.

From here, there are 2 ways to solve this algebraically:
* Use an 8192x8192 bit matrix that is a block matrix made up of `M_i` (and your state is 512 bits embedded into a 8192-dim space via a monomorphism, with 8192-512 zeros)
* Use a 512x512 bit matrix and duct tape.

We go for the smaller (more elegant) solution here.

Suppose we had a vector `v` of 16 consecutive integer PRNG outputs. We know we can get it by repeatedly choosing `3`. Let's expand it into a 512-bit vector (512=32*16) by writing each integer as a bitstring. Then, we want to find a matrix `A` that gives `A.s = v` for all possible initial states `s`. In other words, we need a matrix that takes in an initial state `s` and produces a vector that is the outputs of PRNG. We already have `M_i` that almost do this, so we just need to combine them to produce `A`.

Note, that if stars align, we would be able to solve for `s` given `A` and `v`. The exact condition is that the rank of `A` must be at least 480 (512-32) as we lose one of the initial state values. This happens to (almost) always be the case.

Let's think about how matrix-vector multiplication works. If we only care about the ith value in the vector, then it comes from the ith row in the matrix. The rest of the rows do not affect that particular value. So we can try gluing some rows together from `M_i` matrices to form A.

Remember that each `M_i` is defined as if it started off at `idx=i`. So, for example, to go from `idx=0` to `idx=13` in one matrix, we need to multiply them together, producing `M_14 . M_15 . M_0 . s`. Note that it goes backwards from 0 to 15 to 14 to 13, etc. since `idx` is decremented every time.

Further, note how the PRNG returns a value that is part of the state. As such, calling PRNG 3 times will yield the 13th value in the vector `M_14 . M_15 . M_0 . s`, which is the bits `[13*32 .. 14*32)` in the new state vector. Hence, we know that these are determined by rows `[13*32 .. 15*32)` of our hypothetical matrix `A`.

But wait! Didn't we just determine that they are computed from a product of `M_i` matrices? Yes. Therefore, rows of matrix `A` come from rows of `M_i` products. In particular, every 32 rows come from different products. First 32 rows of `A` are last 32 rows of `M_0`, next 32 rows of `A` are second-last 32 rows of `M_15 . M_0`, etc. These are off-by-one because of `idx` returning its `idx-1`th value.

After the matrix `A` is built, we note it has rank 480, which is what we expected: we lose `state[(idx + 10) % 0xf]`.

Solution is obtained by taking 16 consecutive PRNG outputs, serializing them into 512 bits as a bitstring, and solving `A.x = v` for `x`. That gives us the initial state of the PRNG (with 1 value erased), so we seed with that state and skip 16 random values. The next random value will be in-sync with the server. You will need to subtract 1 from the PRNG obtained locally, and add 1 to all remote PRNGs leaked, since the binary uses floats which end up rounding down between conversions. Trololol.

As usual, the attached exploit has all the necessary details (it works!).

Now we have the text base, and the ROP chain is left as an exercise to the reader.


## Other write-ups and resources

* <http://lokalhost.pl/ctf/defcon2015/fuck.py>
* <http://hastebin.com/iyinepaxen.py>
