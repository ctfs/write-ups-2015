#!/usr/bin/env python
from PIL import Image
import sys
def tobits(s):
    result = []
    for c in s:
        bits = bin(ord(c))[2:]
        bits = '00000000'[len(bits):] + bits
        result.extend([int(b) for b in bits])
    return result

def frombits(bits):
    chars = []
    for b in range(len(bits) / 8):
        byte = bits[b*8:(b+1)*8]
        chars.append(chr(int(''.join([str(bit) for bit in byte]), 2)))
    return ''.join(chars)

def encode(img,img_out,message):
	img=Image.open(img)
	pixels=img.load()
	message_binary=tobits(message)
	message_binary.extend([0]*16) #2bytes of 0 appended
	# print message_binary
	message_index=0
	for i in range(0,img.size[0]):
		for j in range (0,img.size[1]):
			if (pixels[i,j]!=0): 
				pixels[i,j]=pixels[i,j] & 0xFE
				if (pixels[i,j]==0): pixels[i,j]=2; #edge case
				if (message_index<len(message_binary)): #still left
					pixels[i,j]=pixels[i,j] | message_binary[message_index]
					message_index+=1
	img.save(img_out)

def decode(img):
	img=Image.open(img)
	message_binary=[]
	pixels=img.load()
	zero_count=0
	for i in range(0,img.size[0]):
		for j in range (0,img.size[1]):
			if (pixels[i,j]!=0): 
				message_binary.append(pixels[i,j]&1)
				if (message_binary[-1]==0):
					zero_count+=1
				else:
					zero_count=0
		if (zero_count>=16): break #end of message
	message_binary=message_binary[:-16]
	# print message_binary
	return frombits(message_binary)

if (len(sys.argv)<3):
	print "Usage: \n\t",sys.argv[0]," msgfile.txt basefile.png outfile.png\n\t",sys.argv[0]," -d stegano_file.png"
	exit(0);
if (sys.argv[1]=="-d"):
	print decode(sys.argv[2]);
else:
	# encode(sys.argv[2],sys.argv[3],message=open(sys.argv[1]).read(1024*1024));
	encode(sys.argv[2],sys.argv[3],message=sys.argv[1]);
	# decode(sys.argv[3],sys.argv[4],message=open(sys.argv[2]).read(10000));

