# Pragyan CTF 2015: Weak RSA

**Category:** Cryptography
**Points:** 100
**Solves** 28
**Description:**

> Sam wants to make his site secure using ssl. So he created his own RSA key pair and submitted a csr.
>
> Over time Sam feels that the traffic from his site is not secure and people tapping the network are reading his messages. He wants someone to verify the integrity of his encryption.
>
> The csr and a cipher are provided to you. Only you can help him ;)
>
> [foo](foo)

## Write-up

Download the file and inspect it.

```bash
$ file foo
foo: xz compressed data
```
Its an xz compressed file. Extract using the built-in unxz utility.

```bash 
unxz < foo > foo2
```

Inspecting foo2 reveals its a tar file.

```bash
$ file foo2
rsa-unzipped: POSIX tar archive

$ tar vxf foo2
./rsa/
./rsa/cipher.enc
./rsa/domain.csr

```
We have the certificate signing request and the cipher text. We need to find some way to decode the cipher.
The public key can be obtained using openssl.

```bash
$ openssl req -in domain.csr -text -modulus -noout
Certificate Request:
    Data:
        Version: 0 (0x0)
        Subject: C=IN, ST=NITT, L=-, O=-, OU=-, CN=weakrsa.com
        Subject Public Key Info:
            Public Key Algorithm: rsaEncryption
                Public-Key: (1024 bit)
                Modulus:
                    00:e8:95:38:49:f1:1e:93:2e:91:27:af:35:e1:00:
                    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
                    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
                    00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:
                    00:00:00:00:51:f8:eb:7d:05:56:e0:9f:ff:ff:ff:
                    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
                    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
                    ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:ff:
                    ff:ff:ff:ff:ff:ff:fb:ad:55
                Exponent: 65537 (0x10001)
        Attributes:
            a0:00
    Signature Algorithm: sha256WithRSAEncryption
         7e:d8:a8:25:51:a1:9e:7b:b1:cc:05:87:18:fc:65:59:ba:db:
         07:d7:cd:95:00:6e:ae:d9:4b:ad:ab:f5:b5:7c:92:e8:c0:59:
         2d:11:df:61:c8:db:e4:f8:f7:e0:d2:7c:94:9a:80:49:20:ee:
         2f:3b:96:f0:4e:5f:ab:12:6d:6d:10:7e:39:e9:c8:35:33:71:
         86:d6:0e:30:6b:46:e6:d1:95:42:94:d9:75:6b:cf:10:b2:62:
         fa:56:4c:f9:60:07:84:cf:73:46:85:24:e1:37:9b:aa:84:70:
         b0:3c:4d:09:45:cb:b7:52:28:db:ca:35:6a:9b:22:d6:fc:89:
         25:0a
Modulus=E8953849F11E932E9127AF35E1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000051F8EB7D0556E09FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAD55
```

The title of the problem suggests the rsa is breakable. 

The modulus is a 1024 bit number and clearly does not factorise easily implying both the primes are large.
The public key exponent is also large. Another possibility is fermat's factorisation.

Fermat's factorisation using [`fermats_factorize.py`](https://github.com/juanjohn/rsa_tool/blob/master/fermats_factorizer.py) immediately spits out the two primes.

The private key is found using [`rsatool.py`](https://github.com/ius/rsatool/blob/master/rsatool.py) 

```bash
$python rsatool.py -p 12779877140635552275193974526927174906313992988726945426212616053383820179306398832891367199026816638983953765799977121840616466620283861630627224899027521 -q 12779877140635552275193974526927174906313992988726945426212616053383820179306398832891367199026816638983953765799977121840616466620283861630627224899026453 
Using (p, q) to initialise RSA instance

n =
e8953849f11e932e9127af35e1000000000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000051f8eb7d0556e09fffffffffffffffffff
ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
fffffffffffbad55

e = 65537 (0x10001)

d =
dbbb7e7e7d0a81cad0e0492c01f25a0da5f25a0da5f25a0da5f25a0da5f25a0da5f25a0da5f25a0d
a5f25a0da5f25a0da5f25a0da5f25a0da5f25a0da5f25a594a5dc42a5d15c1d73e28c1d73e28c1d7
3e28c1d73e28c1d73e28c1d73e28c1d73e28c1d73e28c1d73e28c1d73e28c1d73e28c1d73e28c1d7
3e28c1d73e24ac01

p =
f402bcfd15d8f0000000000000000000000000000000000000000000000000000000000000000000
000000000000000000000000000000000000000000000241

q =
f402bcfd15d8efffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
fffffffffffffffffffffffffffffffffffffffffffffe15
```

We can now decrypt the base64 encoded cipher to read the message : 

"Congrats! The flag is too_close_primes"

## Other write-ups and resources

* [b01lers](https://b01lers.net/challenges/Pragyan%202015/Weak%20RSA/36/)
