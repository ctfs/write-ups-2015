#/usr/bin/env python

from Crypto.PublicKey import RSA, DSA
from Crypto.Random import random, atfork
from Crypto.Cipher import PKCS1_OAEP

import SocketServer,threading,os,time
import socket

from priv import privkey, privkey_enc
# corresponding public keys for clients:
_server_pub_enc = RSA.importKey('-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDGRrsdIqf8K39Ncwzsi9k2lr5G\nJ8aEFkYGrYqOQRbU5xOReMj8wWHgnSUC0fjH0gjffGiUC2HfrrNIQvXKGiSBetOu\nIWOmFiESG8IhrPyvLwX53NbMWeCihzbYGJxGyiL0bvDHxqDxzuvteSaEfNm1miPA\nQ9rs5vFnHM0R3kFjdQIDAQAB\n-----END PUBLIC KEY-----')
server_pub_enc = PKCS1_OAEP.new(_server_pub_enc)

server_pub_sig = DSA.construct([6492988819243051335053735606322819439099395961135352303030066825351059776939776358522765113843576255727411249922052441719518573282010295240606387519552263L,5720927070571587652595864015095152811124313453716975619963331476834195150780326792550956895343289380256771573459290257563350163686508250507929578552744739L,6703916277208300332610863417051397338268350992976752494932363399494412092698152568009978917952727431041521105933065433917303157931689721949082879497208537,1022875313346435070370368907571603203095488145799L])

msg = """/------------------------------------------------------------------------------\\
| Welcome to the betting parlor version 2!                                     |
|                                                                              |
| Here's how it works: you choose your betting odds and an amount to bet, and  |
| then you send us your guessed value. We then pick a secure random number.    |
| If random number % odds == guessed value, you win!                           |
|                                                                              |
| In order to address complaints of cheating, your guessed value is sent to us |
| encrypted. Therefore, our random number will not be generated adversarially! |
|                                                                              |
| To encourage use of our service after the issues with version 1, we have     |
| decided to give all new users of the service $100. Wow! Such gratitude!      |
|                                                                              |
| (Oh, and if you win a billion dollars, we'll give you a flag.)               |
\______________________________________________________________________________/
"""

def recv(s, length):
  buf = s.recv(1)
  start = time.time()
  s.setblocking(0)
  while (len(buf) < length) and (time.time() - start) < 0.2:
    try:
      buf += s.recv(1)
    except socket.error:
      time.sleep(0.01)
  s.setblocking(1)
  return buf

def getn(s):
  try:
    b = recv(s,1024)
    return int(b)
  except:
    return 0

class incoming(SocketServer.BaseRequestHandler):
  def process(self, public_key_string):
    if True: #try:
      enc_pk = [chunk.strip().decode("hex") for chunk in public_key_string.split(",")]

      dec_str = ''.join(map(privkey_enc.decrypt,enc_pk))
      
      pkdat = map(long,dec_str.split(","))
      if len(pkdat) != 4:
        return None
      self.client_pk = DSA.construct(pkdat)
      return privkey.sign(dec_str, random.randint(1,privkey.__getstate__()['q']-1))
    else: #except:
      return None

  def verify_guess(self, guess_string):
    if True: #try: 
      self.enc_guess, sig_guess = guess_string.split("~")
      sig_guess = map(long, sig_guess.split(","))
      return self.client_pk.verify(self.enc_guess, sig_guess)
    else: #except:
      return None

  def decrypt_guess(self, privkey):
    if True: #try:
      privkeystr, sig_privkey = privkey.split("~")
      sig_privkey = map(long, sig_privkey.split(","))
      if not self.client_pk.verify(privkeystr, sig_privkey):
        return None
      privkey = PKCS1_OAEP.new(RSA.importKey(privkeystr))
      print self.enc_guess
      print sig_privkey
      guess = privkey.decrypt(self.enc_guess.decode("hex"))
      if not guess.startswith("I hereby commit to a guess of "):
        return None
      self.guess = int(guess[len("I hereby commit to a guess of "):])
      return True
    else: #except
      return None

  def handle(self):
    atfork()

    self.monies = 100

    self.request.send(msg)

    self.request.send("\nBefore we begin, please send us an encrypted version of your public DSA key.\n")
    self.request.send("This will be used to ensure no one attempts to intercept our communications\n")

    pk = recv(self.request,4096)
    sig = self.process(pk)
    if not sig:
      self.request.send("There was an error processing your key. For your safety, we are aborting this session\n")
      return 0

    self.request.send("We received your key as (%s), with our signature (%s)\n" % 
                      (str(self.client_pk.__getstate__()), ','.join(map(str,sig))))
    self.request.send("Please verify this information before proceeding, to ensure your safety\n")

    time.sleep(0.5)
    self.request.send("Shall we play a game?\n")

    for _ in xrange(100):
      if self.monies >= 1000000000:
        self.request.send("Holy shit you have a lot of money. Here's a flag: XXXXXXXXXXXXXXX\n")
      while True:
        self.request.send("How much money would you like to bet? (You have $%d)\n"%self.monies)
        m = getn(self.request)
        if m > self.monies:
          self.request.send("You don't have that much money...\n")
        if m < 0:
          self.request.send(" :| \n")
          return 0
        else:
          break
      self.monies -= m

      while True:
        self.request.send("At what odds would you like to play?\n")
        o = getn(self.request)
        if o > 1000000:
          self.request.send("Sorry, due to the expense of generating random numbers, please keep odds below 1000000\n")
        if o <= 0:
          self.request.send(" :| \n")
          return 0
        else:
          break

      self.request.send("Alright, what is your encrypted guess for the prefix\n")
      g = recv(self.request, 4096)
      if not self.verify_guess(g):
        self.request.send("We had an issue validating your encrypted guess. Please ensure your connection is secure\n")
        return 0

      self.request.send("Ok, generating the secure random number now....\n")
      time.sleep(0.2)
      self.request.send("Beep  ")
      time.sleep(0.2)
      self.request.send("Boop  ")
      time.sleep(0.2)
      self.request.send("Beep\n")
      time.sleep(0.2)
      
      r = int(os.urandom(5).encode("hex"),16)
      self.request.send("Okay, the secure RNG is %d\n"%r)
      self.request.send("Now what is your secret key?\n")
      
      k = recv(self.request, 4096)
      if not self.decrypt_guess(k):
        self.request.send("We had an issue verifying your encrypted guess...\n")
        self.request.send("Either your connection is insecure, or your trying to cheat us D:\n")
        return 0

      if self.guess == r%o:
        self.request.send("Congratulations! You have won $%d!\n"%(o*m))
        self.monies += o*m
      else:
        self.request.send("Sorry, %d %% %d != %d\n"%(r,o,self.guess))


class ReusableTCPServer(SocketServer.ForkingMixIn, SocketServer.TCPServer):
  pass

SocketServer.TCPServer.allow_reuse_address = True
server = ReusableTCPServer(("0.0.0.0", 4321), incoming)
server.timeout = 60
server.serve_forever()
