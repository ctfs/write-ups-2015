import string
cip = 'dhkuagsn'
trans = string.maketrans("prgyanbcdefhijklmoqstuvwxz", "abcdefghijklmnopqrstuvwxyz")
print cip.translate(trans)
