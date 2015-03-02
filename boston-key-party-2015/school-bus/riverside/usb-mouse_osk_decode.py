#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
plt.xlim(0, 1000)
plt.ylim(-350, 0)

filename = "mouse_data.txt"

char_sets = [
    ["       Qwerty flipped",    " zxcvbnm", "asdfghjkl", "qwertyuiop"],
    ["       Qwerty top-left",   "23456789", "wertyuiop", "asdfghjkl;"],
    ["       Qwerty top-right",  "34567890", "ertyuiop[", "sdfghjkl;'"],
    ["       Qwerty bottom",     "wertyuio", "sdfghjkl;", "zxcvbnm,./"],
    ["       Dvorak top-left",   "23456789", ",.pyfgcrl", "aoeuidhtns"],
    ["       Dvorak top-right",  "34567890", ".pyfgcrl/", "oeuidhtns-"],
    ["       Dvorak bottom",     ",.pyfgcr", "oeuidhtns", ";qjkxbmwvz"],
    ["       Colemak top-left",  "23456789", "wfpgjluy;", "arstdhneio"],
    ["       Colemak top-right", "34567890", "fpgjluy;[", "rstdhneio'"],
    ["       Colemak bottom",    "wfpgjluy", "rstdhneio", "zxcvbkm,./"],
]

def compliment(h):
    i = int(h, 16)
    return i - ((0x80 & i) << 1)

def plot(i, x, y, c="red"):
    plt.plot(x, y, color=c, marker="o")
    plt.annotate(i, [x, y])

def locate(x, y):
    r = (y - 20) / -100
    c = (x - 117 + (r % 2 * 40)) / 85
    for chars in char_sets:
	chars[4] += chars[r][c]

tx = ty = i = 0

for chars in char_sets:
    chars.append("")

for line in open(filename).readlines():
    if len(line) > 1:
	status, dx, dy, junk = line.split(":")
	tx += compliment(dx)
	ty += compliment(dy)
	if status != "00":
	    i += 1
	    locate(tx, ty)
	    print "%02d: %d %d" % (i, tx, ty)
	    plot(i, tx, ty)

for chars in char_sets:
    print chars[4], chars[0]

plt.show()
