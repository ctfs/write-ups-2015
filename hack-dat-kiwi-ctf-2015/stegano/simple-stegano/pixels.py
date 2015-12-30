from PIL import Image
import sys
im = Image.open(sys.argv[1])
bands = ''.join(im.getbands())
width, height = im.size
pre=''
for h in range(height):
	for w in range(width):
		pixels = im.getpixel((w,h))
		if bands=='RGBA':
			r,g,b,a = pixels
			print r,g,b,a
		elif bands=='RGB':
			r,g,b = pixels
			print r,g,b
		else:
			print pixels
	print
