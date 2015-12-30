#!/usr/bin/env python

from __future__ import print_function
import sys

print("Welcome to my Python sandbox! Enter commands below! Please don't mess up my server though :/")
sys.stdout.flush()

banned = [
    "import",
    "exec",
    "eval",
    "pickle",
    "os",
    "subprocess",
    "input",
    "banned",
    "sys"
]

targets = __builtins__.__dict__.keys()
targets.remove('raw_input')
targets.remove('print')
for x in targets:
    del __builtins__.__dict__[x]

while 1:
    print(">>>", end=' ')
    sys.stdout.flush()
    data = raw_input()

    for no in banned:
        if no.lower() in data.lower():
            print("No bueno")
            break
    else:
        exec data