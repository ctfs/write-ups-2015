import sys, zbarlight
from PIL import Image
with open(sys.argv[1],'rb') as f:
	image = Image.open(f)
	image.load()
res = zbarlight.scan_codes('qrcode',image)
print sys.argv[1],res
