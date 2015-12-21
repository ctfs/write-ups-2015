# School CTF Winter 2015: Parallel Comparator

**Category:** Reverse
**Points:** 200
**Solves:** 
**Description:**

> Enter right key.
> 
> 
> [Source](task11_79e3a03bc339d6cbe51c0e8f22bd59234461f4f4.c)


## Write-up

<div><h3>Parallel Comparator</h3><p><code>highly_optimized_parallel_comparsion(user_string)</code> is the main function in a program. It checks a user string. There is a <code>variable first_letter = (initialization_number % 26) + 97</code> in the function. It seems that initialization_number variable is generated randomly. </p>
<p>But actually there is no <code>srandom()</code> call or any other function to seed a number generator. So the value of first_letter is the same in every program call. We can get the value from a debugger. </p>
<p>The next thing is a differences array a with length of <code>FLAG_LEN</code>. This is an array of differences beetween an <code>i-th</code> symbol of flag and <code>0-th</code> symbol of flag. If you understand this moment it is easy to get flag right now by script similar to this python one:</p>
<pre><code>differences = [0, 9, -9, -1, 13, -13, -4, -11, -9, -1, -7, 6, -13, 13, 3, 9, -13, -11, 6, -7]
first_letter = 108
print ''.join([chr(first_letter+differences[i]) for i in xrange(len(differences))])
</code></pre>
<p>Function <code>checking()</code> is called in a new thread with three arguments: <code>first_letter</code>, <code>differences[i]</code> and <code>user_string[i]</code>. This function checks <code>i-th</code> symbol of <code>user_string</code> comparing it with <code>first_letter+differences[i]</code> symbol.</p>
<p>After all the loops of the function <code>checking()</code> there goes a final check in a loop. On each iteration it takes the result of the <code>i-th</code> thread a forms an array named generated_string. It goes like this: </p>
<p><code>generated_string[i] = (char)result + just_a_string[i]</code></p>
<p>And the final step is checking whether each symbol of generated_string is equal to that of <code>just_a_string</code>. It is true if the correct string was inputed resulting in each thread returning <code>0</code>.</p></div>

## Other write-ups and resources

* <http://home.in.tum.de/~hagenloc/content/schoolctf-wu1/index.html>
