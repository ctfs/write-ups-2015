# 32C3 CTF 2015 : Sequence Hunt

**Category:** Web
**Points:** 200
**Solves:** 19
**Description:**

> May we interest you in a little programming exercise?
> 
> 
> <http://136.243.194.36:18888>

This is what we see opening: http://136.243.194.36:18888/
```
Sequence Hunt

Welcome to my integer sequence hunt. You have to compute five numbers between 0 and 100 implementing 
the algorithms below. When you think you have a correct solution, send them as GET parameters here. 
You can also get some info about you here.
I expect a lot of load, so I built this around async IOLoops.
Have Fun!

[EDIT] 
Someone sent me this. Since each check takes considerable time, the server now waits until 
three seconds have passed since the request came in to prevent these attacks. 
[/EDIT]

Algorithms

TODO publish algorithms
```

Opening http://136.243.194.36:18888/info we get
```
you are 37.120.106.140
request count on your IOLoop: 1
```


## Write-up

(TODO)

## Other write-ups and resources

* none yet
