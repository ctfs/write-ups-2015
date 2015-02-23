import sys
import re
import itertools
from PIL import Image

if len(sys.argv) != 2: sys.exit(2)
f = open(sys.argv[1],'r')

x = []
for line in f:
	(r,g,b) = map(int, re.findall(r'\d+', line))
	x.append((r,g,b))

# 27100
width = 640
height = 480

img = Image.new('RGB', (width, height))
pixels = img.load() # create the pixel map

idx = 0
for i in range(width):
	for j in range(height):
		pixels[i,j] = x[idx]
		idx += 1
img.save('out.bmp')
img.show()
