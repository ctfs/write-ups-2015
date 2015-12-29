import sys

def xor(data, key):
	l = len(key)
	return bytearray((
		(data[i] ^ key[i % l]) for i in range(0,len(data))
	))


data = bytearray(open(sys.argv[1], 'rb').read())
key = bytearray([0x00,0x00,0x2e,0x77])
print xor(data,key)
