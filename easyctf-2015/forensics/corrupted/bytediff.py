import sys
a = open(sys.argv[1],'rb').read()
b = open(sys.argv[2],'rb').read()
o = []
msg = ''
for i in range(len(a)):
	msg+=str(abs(ord(a[i])-ord(b[i])))
print msg
