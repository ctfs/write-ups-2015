#!/usr/bin/env python
import sys
import os

import socket
import pickle
import base64
import marshal
import types
import inspect
import encodings.string_escape

class Flag(object):
    def __init__(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect(("172.17.0.1", 1234))
        self.flag = s.recv(1024).strip()
        s.close()
flag = Flag()

from seccomp import *

f = SyscallFilter(KILL)
f.add_rule_exactly(ALLOW, "read")
f.add_rule_exactly(ALLOW, "write", Arg(0, EQ, sys.stdout.fileno()))
f.add_rule_exactly(ALLOW, "write", Arg(0, EQ, sys.stderr.fileno()))
f.add_rule_exactly(ALLOW, "close")
f.add_rule_exactly(ALLOW, "exit_group")

f.add_rule_exactly(ALLOW, "open", Arg(1, EQ, 0))
f.add_rule_exactly(ALLOW, "stat")
f.add_rule_exactly(ALLOW, "lstat")
f.add_rule_exactly(ALLOW, "lseek")
f.add_rule_exactly(ALLOW, "fstat")
f.add_rule_exactly(ALLOW, "getcwd")
f.add_rule_exactly(ALLOW, "readlink")
f.add_rule_exactly(ALLOW, "mmap", Arg(3, MASKED_EQ, 2, 2))
f.add_rule_exactly(ALLOW, "munmap")
f.load()

data = os.read(0, 4096)
try:
    res = pickle.loads(data)
    print 'res: %r\n' % res
except Exception as e:
    print >>sys.stderr, "exception", repr(e)

os._exit(0)
