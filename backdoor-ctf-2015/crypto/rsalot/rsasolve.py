from fractions import gcd
import glob

def getint(filename):
	res = 0
	with open(filename,'r') as f:
		res = f.read()
	return int(res,16)

def getmods(modglob):
	mods = []
	for fmod in glob.glob(modglob):
		mods.append((getint(fmod),fmod))
	return mods

def printres(res):
	for (tf,tm,f,m) in res:
		print 'GCD != 1 FOUND!!!'
		print 'TF: ['+tf+'] TM: ['+str(tm)+']'
		print 'F: ['+f+'] M: ['+str(m)+']'

def findgcd(modglob):
	res = []
	mods = getmods('pems/*.mod')
	for (tm, tf) in mods:
		for (m,f) in mods:
			if f==tf: continue
			if gcd(tm,m)==1: continue
			res.append((tf,tm,f,m))
	return res

def mult_inv(e,t):
	return extended_Euclidian_algo(t,e,0,1)%t

def extended_Euclidian_algo(r0, r1, t0, t1):
	q = r0/r1
	r2 = r0%r1
	if r2==0: return t1
	t2=t0-q*t1
	return extended_Euclidian_algo(r1,r2,t1,t2)
#res = findgcd('mod2/*.mod')
#printres(res)

na = getint('mods/64.pem.mod')
nb = getint('mods/87.pem.mod')

#print na
#print nb
print
print '[x] GENERATING p,q'
#print na>nb
p = gcd(na,nb)
#print divmod(na,nb)
(q,_) = divmod(nb,p)
print '[ ] p: ' + str(p)
print '[ ] q: ' + str(q)
print
#print '[x] GENERATING n,t,e,d'
#n = p*q
#t = (p-1)*(q-1)
#e = 65537
#d = mult_inv(e,t)
#print '[ ] n: ' + str(n)
#print '[ ] t: ' + str(t)
#print '[ ] e: ' + str(e)
#print '[ ] d: ' + str(d)
#print

#print n==na
#print n==nb
#print '[x] GETTING CIPHERTEXT'
#c = getint('flag.enc.2')
#print '[ ] c: ' + str(c)
#print

#m = pow(c,d,n)
#print '[x] DECRYPTED MESSAGE: ' + str(m)
