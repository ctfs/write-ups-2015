#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import argparse
import codecs

"""
My über secure encryption script!
"""

def xor(text, key1, key2):
    key1 = key1 * (len(text)//len(key1) + 1)
    key2 = key2 * (len(text)//len(key2) + 1)

    res = ""
    for i in range(len(text)):
        res += chr(ord(text[i]) ^ ord(key1[i]) ^ ord(key2[i]))
    return res

def encrypt(input_data, password1, password2):
    return xor(input_data, password1, password2)

def decrypt(input_data, password1, password2):
    # This is XOR encryption, so decryption is just the same
    return xor(input_data, password1, password2)


def main():
    parser = argparse.ArgumentParser("My über secure encryption script!")

    parser.add_argument("action", choices=["encrypt", "decrypt"])
    parser.add_argument("file", help="The input file")
    parser.add_argument("outfile", help="The output file")
    parser.add_argument("password1", help="The first encryption password")
    parser.add_argument("password2", help="The second encryption password")

    opts = parser.parse_args()

    with codecs.open(opts.file, 'r', "utf-8") as in_file:
        input_data = in_file.read()
    result_data = ""

    if opts.action == "encrypt":
        result_data = encrypt(input_data, opts.password1, opts.password2)
    elif opts.action == "decrypt":
        result_data = decrypt(input_data, opts.password1, opts.password2)

    with codecs.open(opts.outfile, 'w', "utf-8") as out_file:
        out_file.write(result_data)

main()