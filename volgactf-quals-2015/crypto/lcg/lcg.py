#!/usr/bin/python
import struct
import os


M = 65521
class LCG():
	def __init__(self, s):
		self.m = M
		(self.a, self.b, self.state) = struct.unpack('<3H', s[:6])

	def round(self):
		self.state = (self.a*self.state + self.b) % self.m
		return self.state

	def generate_gamma(self, length):
		n = (length + 1) / 2
		gamma = ''
		for i in xrange(n):
			gamma += struct.pack('<H', self.round())
		return gamma[:length]


def encrypt(data, key):
	assert(len(key) >= 6)
	lcg = LCG(key[:6])
	gamma = lcg.generate_gamma(len(data))
	return ''.join([chr(d ^ g)  for d,g in zip(map(ord, data), map(ord, gamma))])

def decrypt(ciphertext, key):
	return encrypt(ciphertext, key)



def sanity_check():
	data = 'A'*100
	key = os.urandom(6)
	ciphertext = encrypt(data, key)
	decrypted_data = decrypt(ciphertext, key)
	assert(data == decrypted_data)





if __name__ == '__main__':
	with open('flag.png', 'rb') as f:
		data = f.read()
	key = os.urandom(6)
	enc_data = encrypt(data, key)
	with open('flag.enc.bin', 'wb+') as f:
		f.write(enc_data)

