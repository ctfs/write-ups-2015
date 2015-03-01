#!/usr/bin/python

import time
import random

def slowpower(base, power, mod):
    accum = 1
    for bit in bin(power)[2:]:
        if accum == 4:
            time.sleep(1.0)
        accum = accum*accum % mod
        if bit == '1':
            accum = accum*base % mod
    return accum


SAFEPRIME = 27327395392065156535295708986786204851079528837723780510136102615658941290873291366333982291142196119880072569148310240613294525601423086385684539987530041685746722802143397156977196536022078345249162977312837555444840885304704497622243160036344118163834102383664729922544598824748665205987742128842266020644318535398158529231670365533130718559364239513376190580331938323739895791648429804489417000105677817248741446184689828512402512984453866089594767267742663452532505964888865617589849683809416805726974349474427978691740833753326962760114744967093652541808999389773346317294473742439510326811300031080582618145727L
# generated with gensafeprime.generate(2048)
# https://pypi.python.org/pypi/gensafeprime

GENERATOR = 4

FLAG = ''

def rand_exponent(p):
    return random.randrange(1, (p - 1)/2)

def group_check(p, m):
    if m <= 0:
        return False
    elif m >= p:
        return False
    elif pow(m, (p-1)/2, p) != 1:
        return False
    else:
        return True


import base64, SocketServer, os, sys, hashlib

class ServerHandler(SocketServer.BaseRequestHandler):

    def fail(self, message):
        self.request.sendall(message + "\nGood-bye.\n")
        self.request.close()
        return False

    def captcha(self):
        proof = base64.b64encode(os.urandom(9))
        self.request.sendall(proof)
        test = self.request.recv(20)
        ha = hashlib.sha1()
        ha.update(test)
        if test[0:12]!=proof or not ha.digest().endswith('\xFF\xFF\xFF'):
            self.fail("You're a robot!")

    def exponentiate(self):
        base = int(self.request.recv(1024))
        if not group_check(SAFEPRIME, base):
            self.fail("Bad group element.")
        result = slowpower(base, self.SECRET, SAFEPRIME)
        if result != 4:
            self.request.sendall(str(result))
        else:
            self.request.sendall(FLAG)

    def setup(self):
        self.SECRET = rand_exponent(SAFEPRIME)

    def handle(self):
        self.captcha()
        while True:
            self.exponentiate()
        self.request.close()


class ThreadedServer(SocketServer.ForkingMixIn, SocketServer.TCPServer):
    pass

if __name__ == "__main__":
    HOST = sys.argv[1]
    PORT = int(sys.argv[2])

    FLAG = open('flag.txt', 'r').read()

    server = ThreadedServer((HOST, PORT), ServerHandler)
    server.allow_reuse_address = True
    server.serve_forever()
    
