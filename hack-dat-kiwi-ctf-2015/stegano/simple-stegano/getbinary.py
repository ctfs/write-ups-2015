from PIL import Image
import sys
bases=[]
with open('basenumbers', 'r') as f:
	for line in f.readlines():
		bases.append(int(line))

if len(sys.argv)!=2: sys.exit(1)
im = Image.open(sys.argv[1])
im.convert('L')
width, height = im.size
pixels = im.load()
arr=[]
for x in range(width):
	for y in range(height):
		p = pixels[(x,y)]
		if p!=0: arr.append(p)

msg=''
for i in range(len(arr)):
	msg+=str(arr[i]-bases[i])

print msg
