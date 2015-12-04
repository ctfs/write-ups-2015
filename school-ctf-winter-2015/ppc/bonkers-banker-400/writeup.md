<div><h3>Bonkers Banker</h3><p>When we connect to the service we will see something like <code>23x0 02x0 a2x0 02x0 23x0</code>. Let's try to decode it according to given algorithm.</p>
<ul>
<li>Reverse hex codes <code>0x32 0x20 0x2a 0x20 0x23</code>.</li>
<li>Decode it: <code>2 * 2</code></li>
<li>Solve <code>2 * 2 = 4</code></li>
<li>Encode the answer back <code>4</code> -&gt; <code>0x34</code> -&gt; <code>43x0</code></li>
<li>Send it to the server and get the next challenge</li>
<li>Repeat until you get the flag</li>
</ul></div>
