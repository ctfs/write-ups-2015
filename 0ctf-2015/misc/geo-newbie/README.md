# 0CTF 2015 Quals CTF: geo newbie

**Category:** Misc
**Points:** 200
**Solves:** 54
**Description:** 

> Talentyange gives lots of tedious apks and you know how bad he is now. Let's try some interesting geography knowledge.
> 
>   nc 202.112.26.111  29995 /  nc 202.112.28.118 29995

## Write-up

Connecting to the service, we see that we have to determine [Alpha-2 Codes](http://en.wikipedia.org/wiki/ISO_3166-1_alpha-2) of given Countries in the first level `Level 0` as seen in the [connection log](connection).

Doing that 20 times, we get to level `Level 1`, in which we have to determine Alpha-2 Codes of different cities, tourist attractions and companies.

After doing that 50 times, we get to level `Level 2`. Here, we have to determine Alpha-2 Codes of all countries, in which certain rivers and mountains are.

I wrote a [script](solve.py) that fetches Alpha-2 Codes for certain countries from a html extract of the [Alpha-2 Codes Wikipage](http://en.wikipedia.org/wiki/ISO_3166-1_alpha-2), as well as get the country for a specific city or tourist attraction using [geonames](http://www.geonames.org/) .

In hindsight, I could have just parsed the wikipedia page for each city and tourist attraction, since the author used the English wikipedia entries, e.g. for [Cape Town](http://en.wikipedia.org/wiki/Cape_Town), in which the corresponding country or Alpha-2 Code is listed.

After realizing this and having spent too much time on the automatisation of the task, I statically added answers for level `Level 2` in the last step.

The task had three levels and 75 rounds. However, the author sometimes misspelled certain cities or countries. Adding to that, I had some problems with encoding, so I had to enter some answers statically.

The script also supports caching to reduce the time needed for requests :).

```bash
Which countries does Danube run across?
 Next: Next: Next: Next: Next: Next: Next: Next: Next: 
--- Round 74 ---

Which countries does Alps span?
 Next: Next: Next: Next: Next: Next: Next: 
0CTF{eNj0y_geography_l0v3_7hE_w0lRd}
```

The flag is `0CTF{eNj0y_geography_l0v3_7hE_w0lRd}`.

## Other write-ups and resources

* <http://nullify-ctf.blogspot.com/2015/03/0ctf-2015-quals-misc-geo-newbie.html>