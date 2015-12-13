import sys, hashlib
from os import listdir
from os.path import isfile, join

def hashfiles(hashdir):
	hashes = []
	if hashdir[-1]!='/': hashdir+='/'
	for f in listdir(hashdir):
		if not isfile(join(hashdir, f)): continue
		m = hashlib.md5()
		ff = hashdir+f
		with open(ff,'r') as of:
			m.update(of.read())
		hashes.append([f, m.hexdigest()])
	return hashes

def getuniques(hashes):
	uniques=[]
	curh=''
	for [f, h] in sorted(hashes, key=lambda x: x[1]):
		if h==curh: continue
		uniques.append([f,h])
		curh=h
	return uniques

pdir = sys.argv[1]
hashes = hashfiles(pdir)
uniques = getuniques(hashes)
for [f,h] in uniques:
	print f,h
