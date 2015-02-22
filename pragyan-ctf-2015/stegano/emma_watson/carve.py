from PIL import Image
flag_img = Image.open("this.bmp")
w,h = flag_img.size
msg=''
for x in range(0, flag_img.size[1]):
	g,b,a = flag_img.getpixel((x,0))
	if g==255: msg +='0'
	else: msg+='1'
print msg
