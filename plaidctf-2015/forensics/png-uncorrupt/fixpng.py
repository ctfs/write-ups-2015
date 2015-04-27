import argparse, binascii, itertools, re, sys

def fbytes(gfile):
	with open(gfile, 'rb') as f: return f.read()

def findA(blob):
	a = []
	ptr = blob.find('\x0a')
	while ptr!=-1:
		a.append(ptr)
		ptr = blob.find('\x0a', ptr+1)
	return a

def get_missing(blob, offsets):
	loff = len(offsets)
	missing = []
	for i in range(0,loff-1):
		thex = binascii.hexlify(blob[offsets[i]-4:offsets[i]])
		missing.append(offsets[i+1]-offsets[i]-12-int(thex,16))
	missing.append(len(blob) - 20 - offsets[loff-1] - int(binascii.hexlify(blob[offsets[loff-1]-4:offsets[loff-1]]),16))
	return missing

def get_crcs(blob, offsets):
	crcs = []
	for i in range(0,len(offsets)-1):
		crcs.append(binascii.hexlify(blob[offsets[i+1]-8:offsets[i+1]-4]))
	i = blob.find('IEND', offsets[len(offsets)-1])
	crcs.append(binascii.hexlify(blob[i-8:i-4]))
	return crcs

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument('fpng',type=str,help=' Input PNG File')
parser.add_argument('opng',type=str,help='Output PNG File')
args = parser.parse_args()

# Get bytes from input file
blob = fbytes(args.fpng)
# Fix first 0d0a
blob = blob[:4] + '\x0d' + blob[4:]
# Get all IDAT offsets to fix
offsets = [m.start() for m in re.finditer('IDAT', blob)]
# Get all missing \x0a
missing = get_missing(blob, offsets)
# Get all 32bit-CRCs
crcs = get_crcs(blob, offsets)

fix = []

for i in range(0,len(offsets)):
	if i!=len(offsets)-1: end=offsets[i+1]
	else: end = blob.find('IEND', offsets[len(offsets)-1])
	saveblob = blob[offsets[i]:end-8]
	print binascii.hexlify(blob[end-8:end-4])
	for c in itertools.combinations(findA(saveblob),abs(missing[i])):
		tmpblob = saveblob
		if missing[i]==0:
			crc = binascii.crc32(tmpblob) & 0xffffffff
			if (crc & 0xffffffff) != int(crcs[i],16):
				print 'No missing bytes. CRC not the same, should be ' + str(hex(crc)[2:])
				blob = blob[:end-8] + binascii.unhexlify(hex(crc)[2:]) + blob[end-4:]
			continue
		for idx, p in enumerate(c): tmpblob = tmpblob[:p+idx] + '\x0d' + tmpblob[p+idx:]
		crc = binascii.crc32(tmpblob) & 0xffffffff
		if crc != int(crcs[i],16): continue
		for z in c: fix.append(z+offsets[i])
		break

for idx, i in enumerate(fix): blob = blob[:i+idx] + '\x0d' + blob[i+idx:]

with open(args.opng, 'wb') as f: f.write(blob)
