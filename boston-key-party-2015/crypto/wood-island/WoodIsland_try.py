 #!/usr/bin/python
#try to talk with socket server

import socket
import sys
import hashlib
import base64
import os
import itertools
import string
import json

def ProcessA(data,s):
    # expect a BASE64 encoded 9 digit binary number
    # send back 20 bytes such that sha1 hash [0:12] == original number
    # and last three bytes are \xff\xff\xff
    proven_not_robot = find_proof(data)
    print "Sending not robot = "
    for b in proven_not_robot:
        sys.stdout.write("%02x" % ord(b))
    print
    s.send(proven_not_robot)
    
def find_proof(proof):
    # see https://stratum0.org/blog/posts/2013/09/23/csaw2013-slurp/
    for i in itertools.product(string.lowercase+string.uppercase, repeat=5):
        sh = hashlib.sha1()
        real_proof = proof + "".join(i)
        sh.update(real_proof)
        if sh.digest()[-3:] == "\xff\xff\xff":
            return real_proof

def ProcessAOLD(data,s):   # s is socket
    # expect a BASE64 encoded 9 digit binary number
    # send back 20 bytes such that sha1 hash [0:12] == original number
    # and last three bytes are \xff\xff\xff
    ubytes = base64.b64decode(data)
    print
    for b in ubytes:
        sys.stdout.write("%02x" % ord(b))
    print
    
    # generate a content such that hash endswith xFFxFFxFF
    sanity = 50000000
    while (1):
        ha = hashlib.sha1()
        response = data                 # the original base64 encoding
        response += os.urandom(8)       # we need 20 bytes, we have 12 in base64
        ha.update(response)
        if ha.digest().endswith('\xFF\xFF\xFF'):
            break
#        elif True:
#            print response
        sanity -= 1
        if sanity <= 0:
            break
        elif sanity % 10000 == 0:
            sys.stdout.write('.')
            sys.stdout.flush()
    print
    sys.stdout.write("SENDING")
    for b in response:
        sys.stdout.write("%02x" % ord(b))
    s.send(response)

def ProcessB(data,s):
    print "B in trial"
#    values = {}
#    values["r"] = "1"
#    values["s"] = "23"
#    values["m"] = "There is no need to be upset"
#    jsonString = json.dumps(values)
#    print "B about to send %s" % jsonString
    jsonbit = {   "s": 21054468908426331574045415757705596312490608697034679252162205415258689488938792588831531807614306762187107454355496991706280940746682086684651382392894440056488208110510117519357395297916485175485376815711109501315034875521798843436925869757482592549470778789601115554255653914305843242151026272506459011629018207321332425287985213417534380034990214393005755147720206544994968697500781616394595450665975848378431384407629728617806162081729861628808736537317534949224293348236319554315763862173514513324698536191701038439870012572806910098312290000388970881226934180445872436810927891008412644093329663435621581021347, \
                 "r": 14556450625812013575484254421723445809678777888922992010061032704679042904146923866457426159198384764425155312389074479869246038712459861363560250202380689697680368931395645962819850774655376322711776181621394119949333235937168169126299818515407603115358673337217251397556879636425925559398418798688723285385352425490135869490681971673314086977191132841003292451662521230410289882511683145128157815153694864096645608834771938938231775760394427067003660948668863059181615823395710566418746839898936118863944244851022473133036526007136492008659921439714025852802299228292891053541064974277813868083959677233126603099132, \
                 "m": "There is no need to be upset", \
                 "boing": "as if like magic"}
    sendstr = json.dumps(jsonbit)
    print "Mangled DUPLICATE IS"
    print sendstr
    print "DUPLICATE ENDS"
    s.send(sendstr)

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.settimeout(10)
s.connect(("52.0.217.48",60231))
state = 1
while (1):
    data = s.recv(4000)
    if not data:
        sys.exit()
    else:
        sys.stdout.write(data)
    if state == 1:
            ProcessA(data,s)
            ProcessB(data,s)
            state = 2
    elif state == 2:
            print data