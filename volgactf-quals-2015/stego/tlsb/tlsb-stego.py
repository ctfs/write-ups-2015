from PIL import Image
import binascii, sys
if len(sys.argv)!=3: sys.exit(1)
im = Image.open(sys.argv[1])
bands = ''.join(im.getbands())
width, height = im.size
msg=''
for h in range(height):
	for w in range(width):
		pixels = im.getpixel((w,h))
		if bands=='RGBA':
			r,g,b,a = pixels
			print r,g,b,a
		elif bands=='RGB':
			r,g,b = pixels
			# r&1 == a1, b&1==a2, g&1==a3
			x1 = (r & 1) ^ (g & 1) # x1 = a1 xor a3
			x2 = (b & 1) ^ (g & 1) # x2 = a3 xor a3
			msg+=str(x1)+str(x2)
		else:
			print pixels
with open(sys.argv[2], 'w') as f:
	f.write(binascii.unhexlify('%x' % int(msg,2)))
