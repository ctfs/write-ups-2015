import binascii, sys
def xor_strings(xs, ys):
	return "".join(chr(ord(x) ^ ord(y)) for x, y in zip(xs, ys))

string = sys.argv[1]
sinput = sys.argv[2]
if len(string) > len(sinput):
	sinput='0'*(len(string)-len(sinput))+sinput
elif len(sinput) > len(string):
	string='0'*(len(sinput)-len(string))+string
if len(string) % 2 != 0:
	string='0'+string
if len(sinput) % 2 != 0:
	sinput='0'+sinput
string = binascii.unhexlify("0b"+string)
sinput = binascii.unhexlify("0b"+sinput)
print binascii.hexlify(xor_strings(string,sinput))
