# School CTF Winter 2015: Hunger games

**Category:** Web
**Points:** 100
**Solves:** 
**Description:**

> Oh, that monkey is really annoying, can you feed it please?
> 
> 
> <http://sibears.ru:10023/>
> 
> 
> <http://sibears.ru:12023/>
> 
> 
> <http://sibears.ru:13023/>


## Write-up

<div><h3>Hunger games</h3><p>Monkey wants a banana but we cant choose it from select. We can change sending value using browser's developer tools (F12) or use simple javascript: </p>
<p><code>$("input").val("banana")</code></p>
<p>and then just submit the form with any checked input.</p></div>

## Other write-ups and resources

* none yet
