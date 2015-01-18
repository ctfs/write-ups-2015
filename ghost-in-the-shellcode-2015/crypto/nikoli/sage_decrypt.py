from sage.all import *
H = HillCryptosystem(AlphabeticStrings(), 3)
P = H.encoding("DKBRHSBTJVPHFKYJASSTZBOCOXXMRCKTNRJGGRSCBQJBRZVKPGAJOVANNEIHIKITIHKHUOFYISZBOCSIGEXQZYWEFANOAVEWQBJNYVUUYEAOIRRSWY")
keys = [
	[[1,7,2], [6,4,5], [3,8,9]],
	[[5,4,9], [8,7,3], [2,6,1]],
	[[6,8,3], [2,1,9], [7,4,5]],
	[[4,9,6], [8,1,3], [2,5,7]],
	[[3,2,7], [4,5,6], [1,9,8]],
	[[8,5,1], [9,7,2], [4,3,6]],
	[[9,6,4], [7,3,1], [5,2,8]],
	[[7,1,5], [6,8,2], [9,3,4]],
	[[3,2,8], [5,9,4], [1,6,7]],
	[[12,10,6], [24,5,20], [6,14,11]],
	[[0,0,0], [0,0,0], [3,0,9]],
	[[0,0,0], [0,7,3], [0,0,0]],
	[[6,8,0], [0,0,9], [0,4,5]],
	[[4,9,0], [8,0,3], [0,0,0]],
	[[0,0,0], [0,5,0], [0,0,0]],
	[[0,0,0], [9,0,2], [0,3,6]],
	[[9,6,0], [7,0,0], [0,2,8]],
	[[0,0,0], [6,8,0], [0,0,0]],
	[[3,0,8], [0,0,0], [0,0,0]]
]
for i in range(0,len(keys)):
	print keys[i]
	M = Matrix(IntegerModRing(26),keys[i])
	try:
		print H.deciphering(M, P)
	except ValueError:
		continue
