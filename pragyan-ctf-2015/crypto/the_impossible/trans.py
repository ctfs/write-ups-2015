import string
cip = 'sfblvmlhyhpgrudnntagfxstbgxyk'
res = ''
for i, c in enumerate(cip):
	res += chr(ord('a') + ((ord(c) - ord('a') + i+1) % 26))
print res
