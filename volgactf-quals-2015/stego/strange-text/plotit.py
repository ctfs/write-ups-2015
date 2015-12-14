import numpy as np
import matplotlib.pyplot as plt
import sys

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

[xydata, keys] = parsexydata(sys.argv[1])
px=py=''
for k in keys:
	for [x,y,key] in xydata:
		if key!=k: continue
		plt.scatter(x,y)
		if px!='':
			plt.plot([px,x],[py,y],'-o')
		px,py=x,y
	plt.savefig(k+'.png')
	plt.cla()
