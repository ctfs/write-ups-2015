from base64 import b64encode as encode
from base64 import b64decode as decode
import urllib2

def encrypt(key,message):
    result = ""
    for i in range(0,len(message),len(key)):
        message_part = message[i:i+len(key)]
        for pair in zip(message_part,key):
            result += chr(ord(pair[0])^ord(pair[1]))
    return result

def decrypt(key,message):
    return encrypt(key,message)

secret_url = "WxUHCWVfbwQERE8bDSsdbgcYHAVBQGdJchdAUARCGmgTckRCUlcQSG8RJUpAAwQQGGwSbhsHXg0="
key = raw_input("Please enter the key to decrypt necessary data:\n")

try:
    response = urllib2.urlopen(decrypt(key, decode(secret_url)))
    with open('flag','w') as f:
        f.write(response.read())
except:
    print "Something goes wrong, sorry!"


