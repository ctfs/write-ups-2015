# -*- coding: utf-8 -*-
import sys
import zlib
import hashlib

#SHA = '354ebf392533dce06174f9c8c093036c138935f3'
#SHA = 'd961f81a588fcfd5e57bbea7e17ddae8a5e61333'
SHA = 'f8d0839dd728cb9a723e32058dcc386070d5e3b5'

BLOB_NAME = '.git/objects/%s/%s' % (SHA[:2], SHA[2:])

cdata = file(BLOB_NAME).read()
data = zlib.decompress(cdata)
data = data.replace('Part2: Input 51337:', 'Part2: Input 31337:')
data = data.replace('270031727027.', '272031727027.')

def sha(data):
  return hashlib.sha1(data).hexdigest()

if sha(data) == SHA:
  print 'VALID!'
  sys.exit(0)

for i in range(len(data)):
  for c in range(0, 256):
    new = data[:i] + chr(c) + data[i+1:]
    if sha(new) == SHA:
      print 'VALID!', repr(SHA)
      print repr(new)
      print new
      f = file(BLOB_NAME, 'wb')
      f.write(zlib.compress(new))
      f.close()
      sys.exit(0)
    print 'NOT FOUND!'
