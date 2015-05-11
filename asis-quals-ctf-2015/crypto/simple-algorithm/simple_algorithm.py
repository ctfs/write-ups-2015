#!/usr/bin/python
import sys

# This part is unmodified
def FAN(n, m):
    i = 0
    z = []
    s = 0
    while n > 0:
    	if n % 2 != 0:
    		z.append(2 - (n % 4))
    	else:
    		z.append(0)
    	n = (n - z[i])/2
    	i = i + 1
    z = z[::-1]
    l = len(z)
    for i in range(0, l):
        s += z[i] * m ** (l - 1 - i)
    return s

# This part is unmodified, but I don't need it
#i = 0
#r = ''
#while i < len(str(iflag)):
#    d = str(iflag)[i:i+2]
#    nf = FAN(int(d), 3)
#    r += str(nf)
#    i += 2

# This is the ciphertext
s = 2712733801194381163880124319146586498182192151917719248224681364019142438188097307292437016388011943193619457377217328473027324319178428

# all possible FAN values (it will only be called with 1- or 2-digit numbers)
arr = [FAN(i, 3) for i in range(100)]

# possible[i] is a list of all 2-digits ints, that will, if put in the algorithm,
# produce the sequence str(s)[pos:]
# so, for each list L in possible[i], this should be True
# "".join([str(arr[x]) for x in L]) == str(s)[pos:]
possible = [[] for i in range(len(str(s)) + 10)]
# after the last possible index, we insert a single '_' just to say:
# "If we can find values that will end at len(str(s))-1, is is valid"
possible[len(str(s))] = ["_"]

# now we go backwards through all positions:
# assume the last FAN value ends at pos-1 and the next begins at pos
# we see which 2-digit values would be possible, to produce the string starting at pos
for pos in range(len(str(s)) - 1, -1, -1):
	# 0 can never be the beginning, because FAN returns integers without leading zeros
	if str(s)[pos] == "0":
		continue
	start = 0
	# see comment below for this if
	if pos == 0:
		start = 10
	# ok, let's try all 1- or 2-digit values
	# 	if we are at the beginning (pos == 0), only 2-digits, because 'str(iflag)[i:i+2]'
	# 	would not select a single digit
	for val in range(start, 100):
		# ok, lets see if the corresponding FAN value matches the result
		if str(s)[pos:pos + len(str(arr[val]))] == str(arr[val]):
			# matches, so now we say:
			# We can use 'val' here at pos
			# This will give us the next len(str(arr[val])) digits
			# And than we can continue with all options that will finish the string starting at 'pos + len(str(arr[val]))'
			# The '|' is just a seperator
			possible[pos] += ['%02d|' % val + k for k in possible[pos + len(str(arr[val]))]]

# Reconstruct flag
# ----------------
# In possible[0], we have a list of strings, each describing the 2-digits values used to
# construct the final result. These are 1105920 possibilities
# we will now get the flag from this
print(len(possible[0]))
for b in possible[0]:
	# split again and drop the '_'
	splitted = b.split("|")[:-1]
	
	# This is tricky:
	# if the original integer has an even value of digits, we don't have a problem
	# ...|12|34|56|78 can be splitted without problems
	# But if the lenghts is odd
	# ...|12|34|56|7  the last one is a 1-digit number
	# In the middle of the string, we had to add this padding '0', but at the end, we are not sure
	# Both is valid
	# ...|12|34|56|7
	# ...|12|34|56|07
	# so, we have to try both, but I was to lazy to code this, so I run the code twice
	# ONe time with this line, one time without. It just drops the '0' again
	splitted[-1] = str(int(splitted[-1]))

	# now built the looong integer
	res = "".join(splitted)
	# convert it to hex
	gr = hex(int(res))[2:-1]
	# if length is odd, it's not a valid hex-encoded string, so we drop it
	if len(gr) % 2 == 0:
		flagCandidate = gr.decode('hex')

		# and last but not least, check if all bytes are printable ASCII			
		found = True
		for xx in flagCandidate:
			if ord(xx) < 32 or ord(xx) > 128:
				found = False
				break
		if found:
			# Hey, we found a solution (and guess what, it's the only one)
			# But the flag here is missing the leading 'A' because the given algorithmn droped it
			print flagCandidate
