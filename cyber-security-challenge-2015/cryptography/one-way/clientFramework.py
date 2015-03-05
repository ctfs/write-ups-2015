import socket, struct
import binascii

HOST = '37.187.249.84' # The remote host
PORT = 20017           # The same port as used by the server

def send_blob(s, data):
	# First send length, then data
	s.sendall(struct.pack('<I', len(data)))
	s.sendall(data)
	return

def recv_blob(s):
	# First 4 bytes are the length
	data = s.recv(4)
	length, = struct.unpack('<I', data)

	# Gimme some data!
	data = ''
	while len(data) < length:
		newdata = s.recv(length - len(data))
		if newdata == '':
			raise Exception('Uh oh. Please contact a staff member')
		data += newdata

	return data

def encrypt(plaintext):

	# Send the data
	send_blob(s, plaintext)

	# Receive the data (yawn)
	data = recv_blob(s)

	# The IV is the first 16 bytes of the data
	iv = data[:16]

	# And the encrypted string is the rest.
	encrypted = data[16:]

	# Using base64 to display properly
	print "Plaintext: ", plaintext
	print "Data: ", binascii.b2a_base64(data),
	print "IV: ", binascii.b2a_base64(iv),
	print "Encrypted: ", binascii.b2a_base64(encrypted),


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

# As long as the connection is open, you can keep sending data
encrypt("Popoi? Popoi!")
print "", ""
encrypt("Bananana")

# So long and thanks for all the fish
s.close();


"""
Some info:
- FLAG = 8 LOWERCASE ASCII characters
- IV = os.urandom(16) at start of session
- IV is updated after every encryption
- key = ... private, d'uh
- encrypted = encrypt(plaintext + FLAG, IV)

def main():
	IV = os.urandom(16)
	while True:
		# Receive some data
		plain = recv_blob(conn)

		# Make a message
		message = "%s%s" % (plain, FLAG)

		# Encrypt it
		ciphertext = encrypt(message, IV)

		# Send it
		send_blob(conn, ciphertext)

		# Let's keep this secure and update the IV
		IV = updateIV(IV)


def encrypt(data, IV):
	global key, secret, block_size

	# CBC Is the algorithm of the future!
	cipher = AES.new(key, AES.MODE_CBC, IV)

	# Add some padding. Everybody loves padding
	data += '\x00' * (block_size - len(data) % block_size)

	encrypted = cipher.encrypt(data)

	return IV + encrypted


def updateIV(currentIV):
	nextIV = ""
	for i in range(0, len(currentIV)):
		k = ord(currentIV[i])
		k += 42
		k %= 0xFF
		nextIV += chr(k)
	return nextIV
"""
