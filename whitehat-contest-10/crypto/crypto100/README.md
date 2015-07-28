# WhiteHat Contest 10 2015: crypto100

**Category: Cryptography**
**Points: 100**
**Solves: 17**
**Author: WhiteHat Wargame**
**Description:**

> Do you love Arithmetic?

> [file](crypto100_c3747ddbe535de5601206babb456191b)


## Write-up

There must be 50 letters encoded in 10 numbers, 5 letters per number. All given numbers are less then 1. There are 64 letters in the charset.

If we multiply the first number and 64, we get 49.127273917. 49 is the position of letter "W" in the charset (if we start counting from 1). We take only fractional part of the new number and myltiply it x64:
.127273917 x 64 = 8.145530688, 8 - is number of "h" in the charset. This way we get "White" from the first given number. To get "Hat{" from the second number we need to substract 1 from encoded letter position
"H" = charset\[floor(0.5474434438*64) - 1\] (charset starts from 1, don't forget)

To decode N-th number:

    n = {N-th_number}
    for i = 0 to 4
        n = frac(n)*64
        char[i + N * 5] = charset[floor(n) - N - 1] //(if charset starts from the 0th element)

## Other write-ups and resources

* none yet
