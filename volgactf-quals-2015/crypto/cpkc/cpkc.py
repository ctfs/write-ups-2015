#!/usr/bin/python
import gmpy2
from gmpy2 import mpz, isqrt, invert, is_prime
import os
import base64



#
# key classes
#
class PrivateKey:
	def __init__(self, f=0, g=0, q=0):
		self.f = mpz(f)
		self.g = mpz(g)
		self.q = mpz(q)
	def export(self, path):
		with open(path, 'w+') as f:
			s = base64.b64encode(int_to_data(self.f)) + '\n'
			s += base64.b64encode(int_to_data(self.g)) + '\n'
			s += base64.b64encode(int_to_data(self.q))
			f.write(s)
	def read(self, path):
		with open(path, 'r') as f:
			s = f.read().split('\n')
			self.f = data_to_int(base64.b64decode(s[0]))
			self.g = data_to_int(base64.b64decode(s[1]))
			self.q = data_to_int(base64.b64decode(s[2]))
class PublicKey:
	def __init__(self, h=0, q=0):
		self.h = mpz(h)
		self.q = mpz(q)
	def export(self, path):
		with open(path, 'w+') as f:
			s = base64.b64encode(int_to_data(self.h)) + '\n'
			s += base64.b64encode(int_to_data(self.q))
			f.write(s)
	def read(self, path):
		with open(path, 'r') as f:
			s = f.read().split('\n')
			self.h = data_to_int(base64.b64decode(s[0]))
			self.q = data_to_int(base64.b64decode(s[1]))


def generate_key(q_bit_length):
	q = gen_big_prime(q_bit_length)
	while True:
		try:
			f = gen_big_random(q_bit_length/2, msb = 0)
			g = gen_big_random(q_bit_length*3/8)
			assert(f.bit_length() > 0 and f.bit_length() < q_bit_length/2)
			assert(g.bit_length() > q_bit_length/4 and g.bit_length() < q_bit_length/2)
			h = invert(f, q)*g % q
			f_inv = invert(f, g)
			return (PrivateKey(f, g, q), PublicKey(h, q))
		except:
			continue

def gen_big_random(bit_len, msb=1):
	n = (bit_len + 7) / 8
	shift = bit_len % 8 - 1
	if shift < 0: shift = 7
	bit = msb << shift
	mask = (1 << shift) - 1
	s = list(os.urandom(n))
	s[0] = chr((ord(s[0]) & mask) | bit)
	return data_to_int(''.join(s))

def gen_big_prime(bit_len, msb=1):
	while True:
		p = gen_big_random(bit_len, msb)
		if is_prime(p):
			return p

def data_to_int(s):
	return mpz(s.encode('hex'), 16)

def int_to_data(e):
	h = hex(e)
	h = h.replace('0x', '').replace('L', '')
	if len(h) % 2:
		h = '0' + h
	return h.decode('hex')



#
# CPKC
#
def encrypt(plaintext, publicKey):
	q = mpz(publicKey.q)
	h = mpz(publicKey.h)
	m = data_to_int(plaintext)
	assert(m < isqrt(q/4) and m > 0)
	r = generate_ephemeral_key(q)
	assert(r < isqrt(q/2) and r > 0)
	e = (r*h + m) % q
	return int_to_data(e)

def decrypt(ciphertext, privateKey):
	q = mpz(privateKey.q)
	f = mpz(privateKey.f)
	g = mpz(privateKey.g)
	f_inv = invert(f, g)
	e = data_to_int(ciphertext)
	a = f*e % q
	b = f_inv*a % g
	return int_to_data(b)


def generate_ephemeral_key(q):
	r = gen_big_random(q.bit_length()/2, msb = 0)
	return r





#
# check the scheme
#
def sanity_check():
	(privateKey, publicKey) = generate_key(3072)
	M = 'ABCDEFGHI'
	ciphertext = encrypt(M, publicKey)
	decrypted_M = decrypt(ciphertext, privateKey)
	assert(M == decrypted_M)



def encrypt_flag(flag, bit_length=3072):
	(privateKey, publicKey) = generate_key(bit_length)
	C = encrypt(flag, publicKey)
	assert(decrypt(C, privateKey) == flag)
	publicKey.export('key.public')
	privateKey.export('key.private')
	with open('ciphertext.bin', 'wb+') as f:
		f.write(C)

def decrypt_flag():
	privateKey = PrivateKey()
	privateKey.read('key.private')
	with open('ciphertext.bin', 'rb') as f:
		C = f.read()
	return decrypt(C, privateKey)


if __name__ == '__main__':
	# sanity_check()
	print decrypt_flag()
