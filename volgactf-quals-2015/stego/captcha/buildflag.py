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

def buildflag(hashfile):
	chdict = {}
	with open(hashfile, 'r') as f:
		for line in f.readlines():
			line = line.split()[1:]
			chdict[line[1]] = line[0]
	return chdict

pdir = sys.argv[1]
hashfile = sys.argv[2]
hashes = hashfiles(pdir)
configdict = buildflag(hashfile)
flag64 = ''
for [f,h] in hashes:
	flag64+=configdict.get(h)
print flag64
