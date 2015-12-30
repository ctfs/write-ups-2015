# School CTF Winter 2015: Simple Check

**Category:** Reverse
**Points:** 100
**Solves:** 
**Description:**

> Enter the right key.
> 
> 
> [Task.x86](./task9_x86_2fb0b7e96f097597851f24faaf664fdb20ad8b8a) [Task.x86-64](./task9_x86_2fb0b7e96f097597851f24faaf664fdb20ad8b8a) [Task_x86.exe](./task9_x86_ed82b6faaf979658e040c77422d01b1b3db183f7.exe)


## Write-up

<div><h3>Simple Check</h3><p>Binary wants us to enter a key. Lets analyse it by GDB.</p>
<pre><code>gdb ./task5
(gdb) br main
(gdb) r

Key:12345
</code></pre>
<p>Get to this line.</p>
<pre><code>=&gt; 0x804870f &lt;main+249&gt;:    call   0x804851b &lt;check_key&gt;
(gdb) ni
=&gt; 0x8048714 &lt;main+254&gt;:    add    esp,0x10
(gdb) ni
=&gt; 0x8048717 &lt;main+257&gt;:    test   eax,eax
(gdb) i r eax
eax            0x0  0
</code></pre>
<p>Obviously <code>12345</code> is a wrong key and checiking falied. Let's try to change situation and put in eax non-zero value.</p>
<pre><code>(gdb) set $eax = 1
(gdb) c
Continuing.
</code></pre>
<p><code>flag_is_you_know_cracking!!!</code></p></div>

## Other write-ups and resources

* none yet
