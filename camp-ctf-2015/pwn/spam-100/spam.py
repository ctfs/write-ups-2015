#!/usr/bin/env python2
import signal, socket, pickle, zlib, os

signal.signal(signal.SIGCHLD, signal.SIG_IGN)

s = socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(("0.0.0.0", 1024))
s.listen(5)

entries = {}

def rl():
	l = ""
	while not l.endswith("\n"):
		c = s.recv(1)
		assert(c)
		l += c
	return l[:-1]

def spam_list():
	s.sendall("Listing %d passwords:\n" % len(entries))
	for k, v in entries.iteritems():
		s.sendall("%s: %s\n" % (k,v))
	s.sendall("---\n")

def spam_add():
	s.sendall("Enter name of the site: ")
	name = rl()
	s.sendall("Enter password: ")
	pasw = rl()
	entries[name] = pasw
	s.sendall("Password successfully added.\n")

def spam_del():
	s.sendall("Enter name of the site which should be deleted: ")
	name = rl()
	if name not in entries:
		s.sendall("Entry not found.\n")
	else:
		del entries[name]
		s.sendall("Entry successfully deleted.\n")

def spam_backup():
	s.sendall("Your backup: %s\n" % zlib.compress(pickle.dumps(entries)).encode("base64"))

def spam_restore():
	s.sendall("Paste your backup here: ")
	backup = rl()
	global entries
	entries = pickle.loads(zlib.decompress(backup.decode("base64")))
	s.sendall("Successfully restored %d entries\n" % len(entries))

while 1:
	c, _ = s.accept()
	p = os.fork()
	if p != 0:
		c.close()
		continue
	else:
		s.close()
		break

s = c
del c

s.sendall("Welcome to Super Password Authentication Manager (SPAM)!\n")

while 1:
	while 1:
		s.sendall("Menu:\n")
		s.sendall("1) List Passwords\n")
		s.sendall("2) Add a Password\n")
		s.sendall("3) Remove a Password\n")
		s.sendall("4) Backup Passwords\n")
		s.sendall("5) Restore backup\n")
		l = rl()
		if len(l) == 1 and l in "12345":
			[spam_list, spam_add, spam_del, spam_backup, spam_restore][int(l) - 1]()
		else:
			s.sendall("Invalid choice.\n")

