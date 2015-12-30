#!/usr/bin/python2.7
import sys
import argparse
import math
import random

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def inverse_mod(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % m

def is_probable_prime(m, k = 7):
    s=1
    t = (m-1)/2
    while t%2 == 0:
        t /= 2
        s += 1
    for r in range(0,k):
        rand_num = random.randint(1,m-1)
        y = pow(rand_num, t, m)
        prime = False
        if (y == 1):
            prime = True
        for i in range(0,s):
            if (y == m-1):
                    prime = True
                    break
            else:
                    y = (y*y)%m
        if not prime:
            return False
    return True

def next_prime(n):
    while True:
        n += 1
        if is_probable_prime(n):
            return n

def gen_private_key(length, density):
    r"""
    Generates an easy superincreasing subset sum problem
    """
    current = random.getrandbits(int((length * (1 - density))/density))
    keys = []
    for i in xrange(length):
        current += current + random.randint(1, length**2)
        keys.append(current)

    current *= 2
    N = next_prime(current)
    r = randint(1, N)
    return (N, r, keys)

def gen_public_key(private_key):
    r"""
    Creates a difficult subset sum problem mod N
    """
    N, r, key = private_key
    return [k * r % N for k in key]

def encrypt(public_key, message):
    assert len(message) <= len(public_key) / 8
    M = int(message.encode('hex'), 16)
    return sum([public_key[i] for i in xrange(M.bit_length()) if M & (1 << i)])

def decrypt(private_key, ciphertext):
    N, r, key = private_key
    s = inverse_mod(r, N)
    C = (ciphertext * s) % N

    p = 0
    for i,k in enumerate(key[::-1]):
        if C >= k:
            C -= k
            p |= (1 << (len(key)-i-1))

    return hex(long(p))[2:-1].decode('hex')

def main(argv):
    parser = argparse.ArgumentParser(description='Merkle-Hellman encrypt0r')
    subparsers = parser.add_subparsers(title="subcommands")
    gen = subparsers.add_parser("generate", description="Generate a new keypair")
    gen.add_argument('key_length', type=int)
    gen.add_argument('density', nargs="?", type=float, default=0.9)
    gen.add_argument('pubkey_file', nargs="?", default="pubkey.txt")
    gen.add_argument('privkey_file', nargs="?", default="privkey.txt")
    gen.set_defaults(cmd="generate")
    enc = subparsers.add_parser("encrypt", description="Encrypt a message")
    enc.add_argument('pubkey_file', nargs="?", default="pubkey.txt")
    enc.add_argument("plaintext_file", nargs="?", default="plaintext.txt")
    enc.add_argument("ciphertext_file", nargs="?", default="ciphertext.txt")
    enc.set_defaults(cmd="encrypt")
    dec = subparsers.add_parser("decrypt", description="decrypt a message")
    dec.add_argument('privkey_file', nargs="?", default="privkey.txt")
    dec.add_argument("ciphertext_file", nargs="?", default="ciphertext.txt")
    dec.add_argument("plaintext_file", nargs="?", default="plaintext.txt")
    dec.set_defaults(cmd="decrypt")

    opts = parser.parse_args()

    if opts.cmd == "generate":
        private_key = gen_private_key(opts.key_length, opts.density)
        public_key = gen_public_key(private_key)

        f = open(opts.pubkey_file, "w")
        f.write(repr(public_key))
        f.close()
        print "** Public key written to {}".format(opts.pubkey_file)

        f = open(opts.privkey_file, "w")
        f.write(repr(private_key))
        f.close()
        print "** Private key written to {}".format(opts.privkey_file)

    elif opts.cmd == "encrypt":
        public_key = eval(open(opts.pubkey_file).read())
        plaintext = open(opts.plaintext_file).read()

        ciphertext = str(encrypt(public_key, plaintext))
        f = open(opts.ciphertext_file, "w")
        f.write(ciphertext)
        f.close()
        print "** Encrypted message written to {}".format(opts.ciphertext_file)

    elif opts.cmd == "decrypt":
        private_key = eval(open(opts.privkey_file).read())
        ciphertext = int(open(opts.ciphertext_file).read())

        plaintext = decrypt(private_key, ciphertext)
        f = open(opts.plaintext_file, "w")
        f.write(plaintext)
        f.close()
        print "** Decrypted message written to {}".format(opts.plaintext_file)

if __name__ == "__main__":
    main(sys.argv)
