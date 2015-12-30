#!/usr/bin/env python
import sys
from PIL import Image

im = Image.open(sys.argv[1])
bin_array = []
braille_array = []
pix = im.load()
for y in range (0, im.size[0]):
	bin_row=''
	for x in range (0, im.size[1]):
		bit = int(str(pix[x,y][0]).replace("255", "1"),2)
		bin_row += str(bit)
	bin_array.append(bin_row)

for i in xrange(1,72,3):
	for j in xrange(1,72,2):
		braille = ''
		braille += bin_array[i][j]
		braille += bin_array[i][j+1]

		braille += bin_array[i+1][j]
		braille += bin_array[i+1][j+1]

		braille += bin_array[i+2][j]
		braille += bin_array[i+2][j+1]
		braille_array.append(braille)

chabra = {'a':'100000','b':'101000','c':'110000','d':'110100','e':'100100',
	  'f':'111000','g':'111100','h':'101100','i':'011000','j':'011100',
	  'k':'100010','l':'101010','m':'110010','n':'110110','o':'100110',
	  'p':'111010','q':'111110','r':'101110','s':'011010','t':'011110',
	  'u':'100011','v':'101011','w':'011101','x':'110011','y':'110111',
	  'z':'100111','.':'001101',',':'001000','!':'001110','?':'001011',
	  '\'':'000010','-':'000011','1':'100000','2':'101000','3':'110000',
	  '4':'110100','5':'100100','6':'111000','7':'111100','8':'101100',
	  '9':'011000','0':'011100','#':'010111','^':'000001'};
bracha = {v: k for k, v in chabra.items()}
for chunk in braille_array:
	if chunk in bracha.keys():
		sys.stdout.write(bracha[chunk])