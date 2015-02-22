encrypt='dhkuagsn'
trans = 'prgyanbcdefhijklmnoqstuvwxz'

res=''
for i, c in enumerate(encrypt):
	res += trans[i]
print res
