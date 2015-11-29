import os, random, struct
from Crypto.Cipher import AES
import secrets 

def encrypt_file(key, in_filename, iv, out_filename=None, chunksize=16):
    if not out_filename:
        out_filename = in_filename + '.enc'

    encryptor = AES.new(key, AES.MODE_CBC, iv)
    filesize = os.path.getsize(in_filename)

    with open(in_filename, 'rb') as infile:
        with open(out_filename, 'wb') as outfile:
            while True:
                chunk = infile.read(chunksize)
                if len(chunk) == 0:
                    break
                elif len(chunk) % 16 != 0:
                    chunk += ' ' * (16 - len(chunk) % 16)

                outfile.write(encryptor.encrypt(chunk))

def decrypt_file(key, in_filename, iv, out_filename="cashcat_dec.png", chunksize=16):
    if not out_filename:
        out_filename = os.path.splitext(in_filename)[0]

    with open(in_filename, 'rb') as infile:
        decryptor = AES.new(key, AES.MODE_CBC, iv)

        with open(out_filename, 'wb') as outfile:
            while True:
                chunk = infile.read(chunksize)
                if len(chunk) != 16:
                    break
                outfile.write(decryptor.decrypt(chunk))


KEY = secrets.ptxt
if len(KEY) == 24:
    print 'all is good'

master_key = ""
m = map(ord, ptxt)
for i in m:
	master_key += str(m)

n = 20313365319875646582924758840260496108941009525871463319046021451803402705157052789599990588403L
e = 1404119484958500351776

# hey guys i did this in sage to double check, and the ctxt does equal 4104314974842034312729644734009867622818315323910143873563666990448837112322264379294617825939
# so math works!
ctxt = power_mod(master_key, e, n);

file = "sales_img"
seed = open(file, 'r+').read(6).encode('hex') + '00' + '00'
if len(seed) == 16:
    print 'all is good'

# if we encrypt the key using RSA we can make a super secure IV
IV0 == int(ctxt[78:94]) 
IV == IV0 ^^ seed 

print 'Encrypting sales img for 10k slabs of platinum'
encrypt_file(KEY, file, IV)
print '[+] encryption complete'
