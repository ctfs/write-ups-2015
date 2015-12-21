# School CTF Winter 2015: Meaningless Text

**Category:** Stegano
**Points:** 200
**Solves:** 
**Description:**

> It is absolutely meaningless text, isn't it?
> 
> 
> [Text](./task12_5b01f6a519d9a567ca098416e1499f8464e10c0c.html)


## Write-up

<div><h3>Meaningless Text</h3><p>html page is given. It contains meaningless text, but some words are italic in it. Let's try cut all such words.</p>
<p><code>grep -o -e "&lt;em&gt;[^/]*&lt;/em&gt;" st2.html</code></p>
<pre><code>&lt;em&gt;flag&lt;/em&gt;
&lt;em&gt;is&lt;/em&gt;
&lt;em&gt;not&lt;/em&gt;
&lt;em&gt;this&lt;/em&gt;
&lt;em&gt;line&lt;/em&gt;
&lt;em&gt;but&lt;/em&gt;
&lt;em&gt;you&lt;/em&gt;
&lt;em&gt;think&lt;/em&gt;
&lt;em&gt;right&lt;/em&gt;
&lt;em&gt;way&lt;/em&gt;
</code></pre>
<p>Hmm.. So we need to cut something else. We can try words with <code>&lt;e&gt;</code> tag. There are many such words in the page.</p>
<pre><code>grep -o -e "&lt;e&gt;[^/]*&lt;/e&gt;" st2.html
&lt;e&gt;zero&lt;/e&gt;
...
&lt;e&gt;one&lt;/e&gt;
</code></pre>
<p>The output contains only zero and one words. So let's substitule them by 1 and 0 and translate to ASCII byte by byte. This python script does it.</p>
<p><code>solution.py:</code></p>
<pre><code>#!/usr/bin/env python
import re
import sys
f = open(sys.argv[1])
a = f.read()
b = ''.join(re.findall("&lt;e&gt;([^/]*)&lt;/e&gt;", a))
b = b.replace('zero', '0')
b = b.replace('one', '1')
print ''.join(map(lambda x: chr(int(x, 2)), [b[i:i+8] for i in xrange(0, len(b), 8)]))
f.close()
</code></pre>
<p><code>./solution.py st2.html</code></p>
<p><code>flag_is_this_is_a_simple_stego</code></p></div>

## Other write-ups and resources

* none yet
