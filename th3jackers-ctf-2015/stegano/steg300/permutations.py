import itertools
from base64 import b64decode

d = ["3tKdX","N0LWF","ZmxhZ","TaU1w","TGUtU"]

for x in itertools.permutations(d):
	print(b64decode(''.join(x) + "3RlZ30="))
