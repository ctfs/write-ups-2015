from PIL import Image
import sys
im = Image.open(sys.argv[1])
width, height = im.size
for h in range(height):
	for w in range(width):
		r,g,b,a = im.getpixel((w,h))
		print b,
	print
