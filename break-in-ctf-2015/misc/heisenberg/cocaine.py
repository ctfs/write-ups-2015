#!/usr/bin/python
# vim: set fileencoding=latin-1 :
import sys

keydict = {
	'Z':'A',
	'I':'B',
	'O':'C',
	'P':'D',
	'K':'E',
	'C':'F',
	'V':'G',
	'B':'H',
	'U':'I',
	'X':'J',
	'R':'K',
	'A':'L',
	'Y':'M',
	'T':'N',
	'L':'Ñ',
	'D':'O',
	'H':'P',
	'Ñ':'Q',
	'E':'R',
	'N':'S',
	'M':'T',
	'J':'U',
	'S':'V',
	'Q':'W',
	'G':'X',
	'F':'Y',
	'W':'Z',
	'!':'@',
	'-':'?'
}

numdict = {
	'W':'0',
	'Z':'1',
	'M':'2',
	'L':'3',
	'E':'4',
	'X':'5',
	'J':'6',
	'R':'7',
	'I':'8',
	'B':'9'
}

def decode(key):
	msg = ""
	for i in key:
		if i in numdict:
			msg+='{'
			msg+=''
			msg += numdict[i]
			msg+=','
			msg += str(keydict[i])
			msg+='}'
			continue
		msg += str(keydict[i])
	print msg

def encode(msg):
	cipher=""
	for i in msg:
		for key, value in keydict.iteritems():
			if value == ord(i):
				cipher+=key
				break
	print cipher

cip='GZVBRTKQBKUNKTIKEVQZNZOBKYUNMIJMTDMOKEMZUTAFZNOEFHWVJFQBWQZNNYEEMKTWJVBMDPLOWPLRBKYLNNEVLZTFQLFQLTLLPEWWHWJTPXWCIAJLYLRBLTMKEBLZNLTILEVELPHZLRYELZNMBLCAEVMWLZETFDJEXOWELVWWPAJOR'
decode(cip)
