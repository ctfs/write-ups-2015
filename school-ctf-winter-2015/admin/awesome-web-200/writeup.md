<div><h3>Awesome web</h3><p>We know that it should be admin mistake so first of all we should check a very common misconfiguration - acces to the parent directory of the site.</p>
<p>In the parent directory we can see <code>flag.txt</code> but we can't read it. </p>
<p>Fortunately we have an access to the admin's ssh keys so we can download the private key and then just use <code>scp admin@&lt;host&gt;:flag.txt . -i admin</code></p></div>
