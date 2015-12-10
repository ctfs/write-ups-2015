import re, sys
syscalltable = []
with open(sys.argv[1], 'r') as f_syscalltable:
	for i in range(128):
		syscalltable.append(f_syscalltable.readline().split()[2])
strace=''
with open(sys.argv[2], 'r') as f_strace:
	strace=f_strace.readlines()
msg=''
for line in strace:
	for m in re.findall(r'(^[a-z]+\()',line):
		m=m[:-1]
		if m in syscalltable:
			msg+=chr(syscalltable.index(m))
print msg
