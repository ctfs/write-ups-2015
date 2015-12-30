from PIL import Image
import sys
im = Image.open(sys.argv[1])
pix = im.load()
width, height = im.size

msg=''
for h in range(1,height):
	for w in range(1,width,2):
		nr=ng=nb=0
		r,g,b=pix[w,h]
		pr,pg,pb=pix[w-1,h]
		db = b-pb
		if db<0:
			pix[w,h]=(256,256,256)
			msg+='0'
		else:
			pix[w,h]=(0,0,0)
			msg+='1'
		pix[w-1,h]=(128,128,128)
print msg
im.show()
