#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import SocketServer
import threading
import time
import random
from Crypto.PublicKey import RSA

AGENTS=1000 # The agents count

class threadedserver(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
    pass

def load_keys():
    a = []
    with open("keys.txt", "r") as f:
        a = [long(i) for i in f.read().strip().split("\n")]
    assert len(a) == AGENTS # Make sure the keys for all our agents were loaded
    return a

# Clean hex
def chex(n):
    return hex(n).lstrip("0x").rstrip("L")

keys = load_keys()

class incoming(SocketServer.StreamRequestHandler):
    def handle(self):
        cur_thread = threading.current_thread()
        self.request.send("Welcome to the Evilcorp message distribution service. Please enter your key number:\n")
        keyno = self.rfile.readline().strip()
        try:
            keyno = int(keyno)
            assert keyno < AGENTS and keyno >= 0
        except:
            self.wfile.write("Invalid key number\n")
            return
        self.wfile.write("Key number recieved. Incoming transmission\n")

        rsakey = keys[keyno]
        self.wfile.write(chex(rsakey) + '\n')
        with open("motd.txt", "r") as f:
            m = int(f.read().encode("hex"), 16)
        self.wfile.write(chex(pow(m, 17, rsakey)) + '\n')
        self.wfile.write("End of transmission")

server = threadedserver(("0.0.0.0", 31896), incoming)
server.timeout = 4
server_thread = threading.Thread(target=server.serve_forever)
server_thread.daemon = True
server_thread.start()
server_thread.join()
