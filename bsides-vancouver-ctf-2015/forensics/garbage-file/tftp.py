import binascii, os, sys

def hexdatatobin():
	lines = []
	with open('data','r') as f:
		lines = f.readlines()

	for idx,l in enumerate(lines):
		l=l.rstrip('\n')
		print "l[:-1]: ",l,'rl'
		print idx, l
		with open('out/'+str(idx), 'wb') as f:
			f.write(binascii.unhexlify(l));

def tftp_parse(binary):
	datablob = ''
	with open(binary, 'rb') as f:
		datablob = f.read()
	tftp_read_package(datablob)

currentfilename = ''

def tftp_read_package(hexdata):
	global currentfilename
	opcode = hexdata[:2]
	hexdata= hexdata[2:]
	if opcode=='\x00\x01':
		print '  RRQ'
	elif opcode=='\x00\x02':
		print '  WRQ file: [',
		first00 = hexdata.index('\x00')
		name = hexdata[:first00]
		currentfilename = name
		print name,']',' mode: [',
		hexdata = hexdata[first00+1:]
		second00 = hexdata.index('\x00')
		mode = hexdata[:second00]
		print mode,']'
		hexdata = hexdata[second00+1:]
		open('tftp-out/'+os.path.basename(currentfilename),'wb').close()
	elif opcode=='\x00\x03':
		print ' DATA Block# [',
		blocknumber = hexdata[:2]
		hexdata = hexdata[2:]
		print binascii.hexlify(blocknumber), ']'
		datalen=len(hexdata)
		cont=False
		if len(hexdata)>511:
			cont=True
			datalen=512
		#print datalen, cont
		data = hexdata[:datalen]
		hexdata = hexdata[datalen:]
		with open('tftp-out/'+os.path.basename(currentfilename),'ab') as f:
			f.write(data)
		if cont==False:
			sys.exit(1)
	elif opcode=='\x00\x04':
		print '  ACK Block# [',
		blocknumber = hexdata[:2]
		hexdata = hexdata[2:]
		print binascii.hexlify(blocknumber), ']'
	elif opcode=='\x00\x05':
		print 'ERROR'
	else:
		print binascii.hexlify(hexdata)
		print 'Error: Wrong opcode. Exiting now'
		sys.exit(1)
	if len(hexdata)!=0:
		tftp_read_package(hexdata)

tftp_parse(sys.argv[1])
