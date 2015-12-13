from PIL import Image
import sys
im = Image.open(sys.argv[1])
width, height = im.size
msg=''
for h in range(height):
	tmpmsg=''
	for w in range(width):
		r,g,b,a = im.getpixel((w,h))
		if b==240: tmpmsg+='>'
		elif b==241: tmpmsg+='<'
		elif b==242: tmpmsg+='+'
		elif b==243: tmpmsg+='-'
		elif b==244: tmpmsg+='.'
		elif b==245: tmpmsg+=','
		elif b==246: tmpmsg+='['
		elif b==247: tmpmsg+=']'
		#elif b==248: tmpmsg+='+90',
		#elif b==249: tmpmsg+='-90',
		#else: print 'nop',
	if tmpmsg=='': continue
	if h%2==0: msg+=tmpmsg
	else: msg+=tmpmsg[::-1]
print msg
