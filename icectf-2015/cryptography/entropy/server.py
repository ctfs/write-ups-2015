#!/usr/bin/env python
import os
import SocketServer
import threading
import random
import time

class threadedserver(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
    pass

def make_pool():
    prime_pool = eval(open("primes.txt").read())
    assert len(prime_pool) == 40
    return set(prime_pool)

prime_pool = make_pool()

generated_keys = set([])

class incoming(SocketServer.BaseRequestHandler):
    def handle(self):
        cur_thread = threading.current_thread()
        self.request.send("Welcome to the Secure RSA key generation service. For sending messages to us, remember to use public exponent 257\n")
        p = random.choice(list(prime_pool))
        q = random.choice(list(prime_pool - set([p])))
        self.request.send(hex(p*q).strip('0x').strip('L') + '\n')
        generated_keys.add(tuple(sorted((p, q))))

server = threadedserver(("0.0.0.0", 30896), incoming)
server.timeout = 4
server_thread = threading.Thread(target=server.serve_forever)
server_thread.daemon = True
server_thread.start()
server_thread.join()
