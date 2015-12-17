import binascii, re, sys
with open(sys.argv[1], 'r') as f:
	stream = f.read()
if stream is None: sys.exit(1)
seven='00110111'
sevenc=1
counter=0
msg=''
for i in re.findall(r'-?(\d+)\.\d+ Td',stream):
	if i not in ('14','17'): continue
	if i=='14': msg+='0'
	elif i=='17': msg+='1'
	else: print 'WTF'
	counter+=1
	if (counter%32)==0:
		msg+=seven[sevenc]
		sevenc+=1
msg+=seven[sevenc]
print 'FLAG:',binascii.unhexlify('%x' % int(msg,2))
