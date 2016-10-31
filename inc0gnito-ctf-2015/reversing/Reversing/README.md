# Inc0gnito CTF 2015: Reversing

**Category: Reversing** 
**Points: 150** 
**Solves:** 
**Description:**

> Find the key


## Write-up

From the source code given, the KEY may not be hidden somewhere. So, by using `strings` and grep the output might lead us to the KEY.
```
$ strings problem.exe | grep KEY 
KEY : KACde45f
```
And yeah, thats the KEY. Another solution is using Stack Buffer Overflow,
```
$ python -c "print 'A'*8 + 'Please!'+ '@'  +'A'*77" 
AAAAAAAAPlease!@AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
$ problem.exe AAAAAAAAPlease\!@AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Value of Check : 65
buf2 : Please!@AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
temp = Please!@
KEY : KACde45f
```
the KEY is `KACde45f`

## Other write-ups and resources

* [Korean](https://protos37.github.io/2015/08/25/inc0gnito-2015-ctf-writeups/) or <https://gist.github.com/protos37/a8f7e5fe96b616d3dccd>
* [Korean](http://cfile26.uf.tistory.com/attach/250DC14255DC73E20B571F) (PDF)
* [Korean](http://cfile24.uf.tistory.com/attach/2476E04655DC7C6E1C6C0B) (PDF)
