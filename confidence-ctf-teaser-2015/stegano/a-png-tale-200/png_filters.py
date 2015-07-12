#!/usr/bin/python

from struct import unpack
from binascii import hexlify, unhexlify
import sys, zlib

# Returns [Position, Chunk Size, Chunk Type, Chunk Data, Chunk CRC]
def getChunk(buf, pos):
	a = []
	a.append(pos)
	size = unpack('!I', buf[pos:pos+4])[0]
	# Chunk Size
	a.append(buf[pos:pos+4])
	# Chunk Type
	a.append(buf[pos+4:pos+8])
	# Chunk Data
	a.append(buf[pos+8:pos+8+size])
	# Chunk CRC
	a.append(buf[pos+8+size:pos+12+size])
	return a

def printChunk(buf, pos):
	print 'Pos : '+str(pos)+''
	print 'Type: ' + str(buf[pos+4:pos+8])
	size = unpack('!I', buf[pos:pos+4])[0]
	print 'Size: ' + str(size)
	#print 'Cont: ' + str(hexlify(buf[pos+8:pos+8+size]))
	print 'CRC : ' + str(hexlify(buf[pos+size+8:pos+size+12]).upper())
	print

if len(sys.argv)!=2:
	print 'Usage: ./this Stegano_PNG'
	sys.exit(2)

buf = open(sys.argv[1]).read()
pos=0

print "PNG Signature: " + str(unpack('cccccccc', buf[pos:pos+8]))
pos+=8

chunks = []
for i in range(3):
	chunks.append(getChunk(buf, pos))
	printChunk(buf, pos)
	pos+=unpack('!I',chunks[i][1])[0]+12

# http://hoshi-sano.hatenablog.com/entry/2013/08/18/113434
decompressed = zlib.decompress(chunks[1][3])
# Decompressed data length = height x (width * 3 + 1)
print "Data length in PNG file : ", len(chunks[1][3])
print "Decompressed data length: ", len(decompressed)

height = unpack('!I',(chunks[0][3][4:8]))[0]
width = unpack('!I',(chunks[0][3][:4]))[0]
blocksize = width * 3 + 1
filterbits = ''
for i in range(0,len(decompressed),blocksize):
	bit = unpack('2401c', decompressed[i:i+blocksize])[0]
	if bit == '\x00': filterbits+='0'
	elif bit == '\x01': filterbits+='1'
	else:
		print 'Bit is not 0 or 1... Default is 0 - MAGIC!'
		sys.exit(3)

s = filterbits
endianess_filterbits = [filterbits[i:i+8][::-1] for i in xrange(0, len(filterbits), 8)]

flag = ''
for x in endianess_filterbits:
	if x=='00000000': break
	flag += unhexlify('%x' % int('0b'+str(x), 2))

print 'Flag: ' + flag
