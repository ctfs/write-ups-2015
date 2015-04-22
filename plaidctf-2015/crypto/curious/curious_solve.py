#from pwn import *
from wiener_attack import *

nlist = list()
elist = list()
clist = list()
with open('captured_a4ff19205b4a6b0a221111296439b9c7') as f:
    # read the line {N : e : c} and do nothing with it
    f.readline()
    for i in f.readlines():
        (N, e, c) = i[1:-2].split(" : ")
        N = long(N, 16)
        e = long(e, 16)
        c = long(c, 16)
        nlist.append(N)
        elist.append(e)
        clist.append(c)

solutions = []
for i in range(0, len(elist)):
    (p,q,d) = wiener_attack(nlist[i],elist[i])
    if p != 0 and q != 0:
        solutions.append((nlist[i],clist[i],d))
    print "i: ", i
    print "p: ", p
    print "q: ", q
    print

for j in range(len(solutions)):
    (n,c,d) = solutions[j]
    plain = pow(c, d, n)
    print hex(plain)
    print hex(plain)[2:-1].decode('hex')
