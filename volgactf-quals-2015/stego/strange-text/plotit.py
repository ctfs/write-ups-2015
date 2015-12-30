import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import sys
from pylab import rcParams

def parsexydata(fdata):
	keys=[]
	xy=[]
	with open(fdata,'r') as f:
		pre=''
		for idx, i in enumerate(f.read().replace('\n','').split(',')[2:]):
			if idx%2==0:
				pre=i
				continue
			tmp = pre.split('.')
			if len(tmp)!=3: continue
			[before,key,after] = pre.split('.')
			pre = before+'.'+after
			if key not in keys: keys.append(key)
			xy.append([pre,i,key])
	return [xy,keys]

#matplotlib.use('Agg')
rcParams['figure.figsize'] = 8,2
[xydata, keys] = parsexydata(sys.argv[1])
for idx, k in enumerate(keys):
	px=py=''
	for [x,y,key] in xydata:
		if key!=k: continue
		x=float(x)+float(k)
		plt.scatter(x,y, s=1)
		if px!='':
			plt.plot([px,x],[py,y],'-o', markersize=1)
		px,py=x,y

plt.axis('equal')
#plt.tight_layout()
plt.savefig('result2.png', dpi=200)
