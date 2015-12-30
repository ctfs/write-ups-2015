# School CTF Winter 2015: Awesome web

**Category:** Admin
**Points:** 200
**Solves:** 
**Description:**

> My friend is the greatest web designer I've ever seen. Once he even made the web site for his favourite husky Fourier. Sadly he is not very good at site administration.
> 
> <http://sibears.ru:10026/site>
> 
> <http://sibears.ru:12026/site>
> 
> <http://sibears.ru:13026/site>
> 
> Some ports: 11026, 15026, 16026


## Write-up

<div><h3>Awesome web</h3><p>We know that it should be admin mistake so first of all we should check a very common misconfiguration - acces to the parent directory of the site.</p>
<p>In the parent directory we can see <code>flag.txt</code> but we can't read it. </p>
<p>Fortunately we have an access to the admin's ssh keys so we can download the private key and then just use <code>scp admin@&lt;host&gt;:flag.txt . -i admin</code></p></div>

## Other write-ups and resources

* <https://en.internetwache.org/school-ctf-2015-writeups-06-11-2015/>
