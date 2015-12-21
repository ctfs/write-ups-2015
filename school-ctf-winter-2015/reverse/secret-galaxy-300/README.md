# School CTF Winter 2015: Secret Galaxy

**Category:** Reverse
**Points:** 300
**Solves:** 
**Description:**

> They say there is an inhabited galaxy next to ours.
> 
> 
> We've got a strange program that gives information about nearby galaxies. At the first glance one would think it says nothing about the secret one...
> 
> 
> [Task.x86](./task10_x86_ff48c020ee7031c05d725ccca9a4f0ddb548a79b) [Task.x86-64](./task10_x86_64_381edebcfd6c9fccf683fe8315842030591ea434) [Task-x86.exe](./task10_x86_89ec72d2e52ccd6a8fef8a95ed868187ed2f0202.exe)


## Write-up

<div><h3>Secret Galaxy</h3><p>Program otput is a content of galaxy database. According to the story we need to find one more galaxy hiding in the binary. Let's check the program for debug information.</p>
<pre><code>strip task4
task4: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=1577ba67c51b6a8c49caacd2b4fe578c502619a9, not stripped
</code></pre>
<p>Binary not stripped, so it has debug info. So debugger will be usefull to solve it. We can use GDB.</p>
<pre><code>gdb ./task4
(gdb) br main
(gdb) r
78      fill_starbase(starbase);
(gdb) n
79      print_starbase(starbase);
(gdb) print starbase
$1 = [{name = 0x400a38 "NGS 2366", distance = 1804289383, is_inhabited = 0, secret_information = 0x0, next = 0x6010bc &lt;starbase+40&gt;, pred = 0x0}, {name = 0x400a41 "Andromeda", distance = 846930886, is_inhabited = 0, secret_information = 0x0, next = 0x6010e4 &lt;starbase+80&gt;, pred = 0x601094 &lt;starbase&gt;}, {name = 0x400a4b "Messier", distance = 1681692777, is_inhabited = 0, secret_information = 0x0, next = 0x60110c &lt;starbase+120&gt;, pred = 0x6010bc &lt;starbase+40&gt;}, {name = 0x400a53 "Sombrero", distance = 1714636915, is_inhabited = 0, secret_information = 0x0, next = 0x601134 &lt;starbase+160&gt;, pred = 0x6010e4 &lt;starbase+80&gt;}, {name = 0x400a5c "Triangulum", distance = 1957747793, is_inhabited = 0, secret_information = 0x0, next = 0x60115c &lt;sc&gt;, pred = 0x60110c &lt;starbase+120&gt;}]
</code></pre>
<p>Starbase is a mapped list. Every item has pointer to the next one. One of the fields of the galaxy structure is secret_information field, which doesn't appears in an output of the program. The next thing is that a <code>next</code> field of the last item of list is not equal to <code>NULL</code>. Let's look at that address.</p>
<pre><code>(gdb) x/10qw 0x60115c
0x60115c &lt;sc&gt;:  0x00400a67  0x00000000  0x00007a69  0x00000001
0x60116c &lt;sc+16&gt;:   0x00601184  0x00000000  0x00000000  0x00000000
0x60117c &lt;sc+32&gt;:   0x00000000  0x00000000
</code></pre>
<p>Look at every address in the structure and find a flag.</p>
<pre><code>...
(gdb) x/1s 0x00601184
0x601184 &lt;sc+40&gt;:   "aliens_are_around_us"
</code></pre></div>

## Other write-ups and resources

* none yet
