# School CTF Winter 2015: With a Speed Force

**Category:** Ppc
**Points:** 300
**Solves:** 
**Description:**

> Agent! We have been informed that so called "superheroes" have secrets from the goverment! It's absolutely unacceptalbe! We order you to infiltrate their team and get an access to the secret information on their server.
> 
> 
> Do it as soon as possible! National security is under a big threat!
> 
> 
> Agent Smith, NSA.
> 
> 
> <http://sibears.ru:10002/>
> 
> 
> <http://sibears.ru:12002/>
> 
> 
> <http://sibears.ru:13002/>


## Write-up

<div><h3>With a Speed Force</h3><p>Obviously to get the secret we need to join the team, but when we try to join it says that we must save world more often. </p>
<p>We have 10 seconds to click the button enough times and register the user. It can be done with any mouse clicker tool or simple javascipt like that: </p>
<pre><code>for (var i = 0; i &lt; 101; i++) {
  $("i.circle").click()
}
$("form").submit()
</code></pre>
<p>When you succeed you will be able to see the secret - it's your flag.</p></div>

## Other write-ups and resources

* none yet
