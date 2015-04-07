import urllib2
import matplotlib.pyplot as plt
from collections import defaultdict
from cookielib import CookieJar

cj = CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))

poss = defaultdict(list)

for tries in range(255):
    url = opener.open("http://hack.bckdr.in/RAND/").read()
    for i in range(0, len(url)):
        poss[i].append(int(url[i], 16))

plt.plot(poss.keys(), poss.values(), "ro")
plt.show()

flag = ""
for i in range(999,1064):
    flag += "%x" % (len(set(poss[i])) - 1)
#print flag
