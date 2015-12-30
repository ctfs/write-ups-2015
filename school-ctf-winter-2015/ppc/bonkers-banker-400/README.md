# School CTF Winter 2015: Bonkers Banker

**Category:** Ppc
**Points:** 400
**Solves:** 
**Description:**

> I know an old mad moneybags. He had invented his own language but nobody wanted to talk in it. Then he decided to give all his money to the guy who can talk with him and will be very good at accounting.
> 
> 
> nc sibears.ru 10028
> 
> 
> nc sibears.ru 12028
> 
> 
> nc sibears.ru 13028
> 
> 
> May be that piece of code will be useful for you:
> 
> 
> def encode(self, str):
> 
>    codes = []
> 
>    for c in str:
> 
>      codes.append(hex(ord(c))[::-1])
> 
>    return ' '.join(codes)


## Write-up

<div><h3>Bonkers Banker</h3><p>When we connect to the service we will see something like <code>23x0 02x0 a2x0 02x0 23x0</code>. Let's try to decode it according to given algorithm.</p>
<ul>
<li>Reverse hex codes <code>0x32 0x20 0x2a 0x20 0x23</code>.</li>
<li>Decode it: <code>2 * 2</code></li>
<li>Solve <code>2 * 2 = 4</code></li>
<li>Encode the answer back <code>4</code> -&gt; <code>0x34</code> -&gt; <code>43x0</code></li>
<li>Send it to the server and get the next challenge</li>
<li>Repeat until you get the flag</li>
</ul></div>

## Other write-ups and resources

* none yet
