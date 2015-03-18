# Ghost in the Shellcode 2015: Knockers

**Category:** Crypto
**Points:** 150
**Description:**

> Dude, here's a knocker token that will let you access my service on port 80. One day I will let you see my cool stuff on port 7175.
> 
> Your token: 6e248dc3dec420c42f48f720475f9cb70f2485d8214715c66106050fd1a7b687326b2c82114419474042bb5df1602d578c059ba5dac260f644b8584dd5a0a38b0050
>
> Server: knockers.2015.ghostintheshellcode.com
>
> Knocker program: [source](knockers-28e0925c5d1a7e50f21a32e5448cf84a4216e46dbedbb2266fd8a)

## Write-up

The service implements a form of [port knocking](http://en.wikipedia.org/wiki/Port_knocking). We are given a token that when provided to the service will allow our IP address to access certain ports on the server. However, it only allows us to access port 80 where there is a web server that taunts us and says the real goods are on port 7175. 

```
$ python knock.py knock knockers.2015.ghostintheshellcode.com 6e248dc3dec420c42f48f720475f9cb70f2485d8214715c66106050fd1a7b687326b2c82114419474042bb5df1602d578c059ba5dac260f644b8584dd5a0a38b0050

$ nc knockers.2015.ghostintheshellcode.com 80
GET / HTTP/1.0

HTTP/1.1 200 OK
Server: nginx/1.4.6 (Ubuntu)
Date: Sun, 18 Jan 2015 22:29:59 GMT
Content-Type: text/html
Content-Length: 329
Last-Modified: Fri, 16 Jan 2015 23:24:24 GMT
Connection: close
ETag: "54b99da8-149"
Accept-Ranges: bytes

<html>
<head><title>port 80 is for noobs</title></head>
<body>

<h1>Hello</h1>

<p>
I have been pwning noobs in a cool game at <a href="http://pwnadventure.com/">http://pwnadventure.com/</a>. When I'm not playing that, I enjoy the stuff on port 7175, but you will never see it!
</p><pre>

--computerality
</pre>

</body>
</html>
```

The source is provided for the port knocking server so:

```python
...
PORT = 8008

g_h = hashlib.sha512
g_key = None

def generate_token(h, k, *pl):
	m = struct.pack('!'+'H'*len(pl), *pl)
	mac = h(k+m).digest()
	return mac + m
...
```

The token consists of a [MAC](http://en.wikipedia.org/wiki/Message_authentication_code) and then some other data. Since [SHA-512](http://en.wikipedia.org/wiki/SHA-2) is 512 bits we know the token provided to us is really:

* MAC: 6e248dc3dec420c42f48f720475f9cb70f2485d8214715c66106050fd1a7b687326b2c82114419474042bb5df1602d578c059ba5dac260f644b8584dd5a0a38b
* data: 0050

Continuing on:

```python
def parse_and_verify(h, k, m):
	ds = h().digest_size
	if len(m) < ds:
		return None
	mac = m[:ds]
	msg = m[ds:]
	if h(k+msg).digest() != mac:
		return None
	port_list = []
	for i in range(0,len(msg),2):
		if i+1 >= len(msg):
			break
		port_list.append(struct.unpack_from('!H', msg, i)[0])
	return port_list
```
	
The data part of the token is just a list of ports with 2 bytes for each port in [big endian](http://en.wikipedia.org/wiki/Endianness). We still don't know where k in the MAC is coming from, but it is basically loaded from secret.txt so one last important bit:
	
```python
	elif sys.argv[1]=='setup':
		f = open('secret.txt','wb')
		f.write(hexlify(os.urandom(16)))
		f.close()
		print 'wrote new secret.txt'
```

So we need a token that is ```SHA-512(<secret><port_list>)<port_list>``` and the port list needs to contain 7175.  There isn't a way for us to leak the secret so we cannot generate a MAC for a different list of ports.

SHA-512 (and several other popular hash functions) are all based on a [Merkle–Damgård construction](http://en.wikipedia.org/wiki/Merkle%E2%80%93Damg%C3%A5rd_construction). Messages are padded to the size of blocks and the hash function has an intial state. A new internal state for the hash function is generated from the current state and a message block. The new state and the next message block are fed to the function again until all message blocks are processed. Once all of the message blocks are processed the state is output as the digest. This leads to a [length extension attack](http://en.wikipedia.org/wiki/Length_extension_attack), given the internal state of a hash we can compute the digest of messages that consist of the original message (plus padding) and any additonal blocks of our choosing.

Since we know that ```SHA-512(<secret><[80,]>)``` is really ```SHA-512(<secret><[80,]>||<padding>)``` and the state after computing it we can compute ```SHA-512(<secret><[80,]>||<padding>||<our_block>)``` without having to know ```<secret>``` provided we know how long ```<secret>``` is so we can generate the correct padding (or just guess the size until it works). We know it is 16 bytes long though so all we need is to do a little math.

Thankfully, [iagox86/hash_extender](https://github.com/iagox86/hash_extender) and [bwall/HashPump](https://github.com/bwall/HashPump) (and others) already do the drudge work for you so:

```
$ ./hash_extender -f sha512 --data-format=hex -d '0050' --append-format=hex -a '1c07' -l 16 -s '6e248dc3dec420c42f48f720475f9cb70f2485d8214715c66106050fd1a7b687326b2c82114419474042bb5df1602d578c059ba5dac260f644b8584dd5a0a38b'
Type: sha512
Secret length: 16
New signature: f11849ac29b10a169b8a378a84695ddf8d80c2e75f6e59e7de5a84a66e5c204efb1d3b2e486498d106b7236b7fbf23fefb7f3ce930c702c25ff5563bd596bea7
New string: 005080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000901c07

$ python knocker.py knock knockers.2015.ghostintheshellcode.com f11849ac29b10a169b8a378a84695ddf8d80c2e75f6e59e7de5a84a66e5c204efb1d3b2e486498d106b7236b7fbf23fefb7f3ce930c702c25ff5563bd596bea7005080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000901c07

$ nc knockers.2015.ghostintheshellcode.com 7175

```

From there just guess it is probably a web server:
```
$ nc knockers.2015.ghostintheshellcode.com 7175
GET / HTTP/1.1
Host: knockers.2015.ghostintheshellcode.com

HTTP/1.1 200 OK
Server: nginx/1.4.6 (Ubuntu)
Date: Sun, 18 Jan 2015 22:32:52 GMT
Content-Type: text/html
Transfer-Encoding: chunked
Connection: keep-alive

35e9
<html>
<head><title>Index of /</title></head>
<body bgcolor="white">
<h1>Index of /</h1><hr><pre><a href="../">../</a>
<a href="01.jpg">01.jpg</a>                                             16-Jan-2015 23:09              463525
<a href="02.jpg">02.jpg</a>                                             16-Jan-2015 23:09              497187
<a href="049057d53e832623ccca379ed973b0a3508b59a6.jpg">049057d53e832623ccca379ed973b0a3508b59a6.jpg</a>       16-Jan-2015 23:09              110853
<a href="0597c6407db43e06edd545ce4f6b6bad8140bdb1.jpg">0597c6407db43e06edd545ce4f6b6bad8140bdb1.jpg</a>       16-Jan-2015 23:09              320875
<a href="06febe0150ba0dd841870dd7be8a760c9ba2246d.jpg">06febe0150ba0dd841870dd7be8a760c9ba2246d.jpg</a>       16-Jan-2015 23:09               65929
<a href="0af086557a767bf077cda3c0d83dcece13681d25.jpg">0af086557a767bf077cda3c0d83dcece13681d25.jpg</a>       16-Jan-2015 23:09              313881
<a href="12c85be9090ff33d17c77031ddc69e4f7a2b5ff3.jpg">12c85be9090ff33d17c77031ddc69e4f7a2b5ff3.jpg</a>       16-Jan-2015 23:09               43869
<a href="14b7pr4.gif">14b7pr4.gif</a>                                        16-Jan-2015 23:09              592135
<a href="153798m.gif">153798m.gif</a>                                        16-Jan-2015 23:09              842651
<a href="15fb89d6d9f5ac1557526f96967af93aa43f7683.jpg">15fb89d6d9f5ac1557526f96967af93aa43f7683.jpg</a>       16-Jan-2015 23:09               29205
<a href="208cp00.jpg">208cp00.jpg</a>                                        16-Jan-2015 23:09              187045
<a href="20fp21j.jpg">20fp21j.jpg</a>                                        16-Jan-2015 23:09               48555
<a href="263tq86.jpg">263tq86.jpg</a>                                        16-Jan-2015 23:09              207498
<a href="2890deeb570020704f3b42eda4c1e27b640d8a94.jpg">2890deeb570020704f3b42eda4c1e27b640d8a94.jpg</a>       16-Jan-2015 23:09              176665
<a href="29669d7668ef4f361318481f66da7688c06cd653.jpg">29669d7668ef4f361318481f66da7688c06cd653.jpg</a>       16-Jan-2015 23:09               43613
<a href="29cd4697b327c7a63157101b90476387e412491e.jpg">29cd4697b327c7a63157101b90476387e412491e.jpg</a>       16-Jan-2015 23:09              379015
<a href="2fa7a64692c30622a75c0f98501ef9eaeab8b556.jpg">2fa7a64692c30622a75c0f98501ef9eaeab8b556.jpg</a>       16-Jan-2015 23:09               72995
<a href="2gybpko.jpg">2gybpko.jpg</a>                                        16-Jan-2015 23:09              492078
<a href="2qbcgb5.jpg">2qbcgb5.jpg</a>                                        16-Jan-2015 23:09              326193
<a href="2z57kt4.jpg">2z57kt4.jpg</a>                                        16-Jan-2015 23:09              585028
<a href="30cvqf8.jpg">30cvqf8.jpg</a>                                        16-Jan-2015 23:09              812538
<a href="34hi3vm.jpg">34hi3vm.jpg</a>                                        16-Jan-2015 23:09              237547
<a href="3ca0b624a4b028519bb7fe24b0f04fa93909112d.jpg">3ca0b624a4b028519bb7fe24b0f04fa93909112d.jpg</a>       16-Jan-2015 23:09               29919
<a href="3e64743aba691b40f39c540ad3426a26c2dbcdb6.jpg">3e64743aba691b40f39c540ad3426a26c2dbcdb6.jpg</a>       16-Jan-2015 23:09              212699
<a href="45fb2068727abd4a6240e5555ce4b7cf16ca1dc1.jpg">45fb2068727abd4a6240e5555ce4b7cf16ca1dc1.jpg</a>       16-Jan-2015 23:09               27940
<a href="474794b35915b0652075384565d89b3fb48d20dd.jpg">474794b35915b0652075384565d89b3fb48d20dd.jpg</a>       16-Jan-2015 23:09              183704
<a href="4eMo8.jpg">4eMo8.jpg</a>                                          16-Jan-2015 23:09               67914
<a href="5260bf1db426ddff1ebc330457c6ee87ccf954fb.jpg">5260bf1db426ddff1ebc330457c6ee87ccf954fb.jpg</a>       16-Jan-2015 23:09               46905
<a href="598c06f636802461702e0ff66cc2310576663691.jpg">598c06f636802461702e0ff66cc2310576663691.jpg</a>       16-Jan-2015 23:09              275011
<a href="5a71daade6e63a60e65b5b006ab2b956c0a0e936.jpg">5a71daade6e63a60e65b5b006ab2b956c0a0e936.jpg</a>       16-Jan-2015 23:09               34699
<a href="5c59cd71092ad4c8ee2c6279b88706698e4dc5f1.jpg">5c59cd71092ad4c8ee2c6279b88706698e4dc5f1.jpg</a>       16-Jan-2015 23:09               46321
<a href="71653dd60579dc0e17a4ebaebdbb989aeb397c1f.jpg">71653dd60579dc0e17a4ebaebdbb989aeb397c1f.jpg</a>       16-Jan-2015 23:09               54048
<a href="736ee9539439f9cdd1d1d53b9802d9b16aba2b22.jpg">736ee9539439f9cdd1d1d53b9802d9b16aba2b22.jpg</a>       16-Jan-2015 23:09               27449
<a href="77f52ba19b3627f1ee2bd329fe1b3203b43f537b.jpg">77f52ba19b3627f1ee2bd329fe1b3203b43f537b.jpg</a>       16-Jan-2015 23:09               44937
<a href="78de0adb46a92e6e639c3064ef01421735c781f0.jpg">78de0adb46a92e6e639c3064ef01421735c781f0.jpg</a>       16-Jan-2015 23:09               62668
<a href="7f2bf18158e5fee67794c8c5c574b23d0e7a111e.jpg">7f2bf18158e5fee67794c8c5c574b23d0e7a111e.jpg</a>       16-Jan-2015 23:09              496880
<a href="86f1ea8bc941a0d7494961c02dcd6e76269ebe09.jpg">86f1ea8bc941a0d7494961c02dcd6e76269ebe09.jpg</a>       16-Jan-2015 23:09               45411
<a href="87176_ChristinaHendricks_EsquireRussia_June2010_2_122_382lo.jpg">87176_ChristinaHendricks_EsquireRussia_June2010..&gt;</a> 16-Jan-2015 23:09              234399
<a href="88391_ChristinaHendricks_EsquireRussia_June2010_13_122_200lo.jpg">88391_ChristinaHendricks_EsquireRussia_June2010..&gt;</a> 16-Jan-2015 23:09               26455
<a href="8dfc04e737cd67bd001e2d9d6b1d8ed3ada98122.jpg">8dfc04e737cd67bd001e2d9d6b1d8ed3ada98122.jpg</a>       16-Jan-2015 23:09              105940
<a href="8ec9519b1ec4f837595c142b7a0a72ea1bf4da14.jpg">8ec9519b1ec4f837595c142b7a0a72ea1bf4da14.jpg</a>       16-Jan-2015 23:09               26692
<a href="96cdc9869ffd7da35db6367201c442afa560f728.jpg">96cdc9869ffd7da35db6367201c442afa560f728.jpg</a>       16-Jan-2015 23:09              210710
<a href="97b93a0bbae6bfdada860257b425a669e4210069.jpg">97b93a0bbae6bfdada860257b425a669e4210069.jpg</a>       16-Jan-2015 23:09               28277
<a href="9d62a3dd63964cc1dd483a9f84b40af103316e79.jpg">9d62a3dd63964cc1dd483a9f84b40af103316e79.jpg</a>       16-Jan-2015 23:09               40957
<a href="Christina-Hendricks-Esquire-Photoshoot-HQ-christina-hendricks-8730769-1085-1526.jpg">Christina-Hendricks-Esquire-Photoshoot-HQ-chris..&gt;</a> 16-Jan-2015 23:09              366473
<a href="ChristinaHendricks2.jpg">ChristinaHendricks2.jpg</a>                            16-Jan-2015 23:09               51203
<a href="ETCvSl.jpg">ETCvSl.jpg</a>                                         16-Jan-2015 23:09               86191
<a href="QroQy.jpg">QroQy.jpg</a>                                          16-Jan-2015 23:09              122664
<a href="Uqp3H.jpg">Uqp3H.jpg</a>                                          16-Jan-2015 23:09               69622
<a href="XKcgt.jpg">XKcgt.jpg</a>                                          16-Jan-2015 23:09               33167
<a href="a099360ff91b72f17d4e12528029c0d4ece2db7e.jpg">a099360ff91b72f17d4e12528029c0d4ece2db7e.jpg</a>       16-Jan-2015 23:09              145341
<a href="a31f08a40290aa75d479685c4d92a7be3dd3af4d.gif">a31f08a40290aa75d479685c4d92a7be3dd3af4d.gif</a>       16-Jan-2015 23:09              606838
<a href="a5ey6r.jpg">a5ey6r.jpg</a>                                         16-Jan-2015 23:09               27299
<a href="a6ce3916e4144924adefb907ea1bf487a4860ba5.jpg">a6ce3916e4144924adefb907ea1bf487a4860ba5.jpg</a>       16-Jan-2015 23:09              105846
<a href="attachment.php%3fattachmentid%3d736537">attachment.php?attachmentid=736537</a>                 16-Jan-2015 23:09              200955
<a href="attachment.php%3fpostid%3d375910557">attachment.php?postid=375910557</a>                    16-Jan-2015 23:09              200955
<a href="attachment.php%3fpostid%3d375924101">attachment.php?postid=375924101</a>                    16-Jan-2015 23:09              155807
<a href="attachment.php%3fpostid%3d375948751">attachment.php?postid=375948751</a>                    16-Jan-2015 23:09              279018
<a href="attachment.php%3fpostid%3d375948771">attachment.php?postid=375948771</a>                    16-Jan-2015 23:09              781178
<a href="attachment.php%3fpostid%3d377569452">attachment.php?postid=377569452</a>                    16-Jan-2015 23:09               25269
<a href="b6be647c5dd5995e56592bbc4be843d58b53009b.jpg">b6be647c5dd5995e56592bbc4be843d58b53009b.jpg</a>       16-Jan-2015 23:09               37789
<a href="b7d50fc6fadab52fbc12c5cc2b8e3b888ddcb8ab.jpg">b7d50fc6fadab52fbc12c5cc2b8e3b888ddcb8ab.jpg</a>       16-Jan-2015 23:09               26818
<a href="b8d9e40937f393c1bdfabed56d3ce33409d9ac4d.jpg">b8d9e40937f393c1bdfabed56d3ce33409d9ac4d.jpg</a>       16-Jan-2015 23:09               85049
<a href="bad33a2c7c952a1e287f5e0c13345f3960358202.jpg">bad33a2c7c952a1e287f5e0c13345f3960358202.jpg</a>       16-Jan-2015 23:09              227207
<a href="be8ccb4dc6a611e8ba944f97d09630dba501f3a1.jpg">be8ccb4dc6a611e8ba944f97d09630dba501f3a1.jpg</a>       16-Jan-2015 23:09              170859
<a href="becb11d47a65a22847fa2716e68170729eac4a49.jpg">becb11d47a65a22847fa2716e68170729eac4a49.jpg</a>       16-Jan-2015 23:09               25019
<a href="c126939f48bb995de9ed67aaec59a067f7b3f618.jpg">c126939f48bb995de9ed67aaec59a067f7b3f618.jpg</a>       16-Jan-2015 23:09               60828
<a href="c1cd1df7feb423b2f950757eb40f3fc2acdf7017.jpg">c1cd1df7feb423b2f950757eb40f3fc2acdf7017.jpg</a>       16-Jan-2015 23:09               58899
<a href="c9495809a73ba5b4e317c27c62e3c9ef0eaf3127.jpg">c9495809a73ba5b4e317c27c62e3c9ef0eaf3127.jpg</a>       16-Jan-2015 23:09               56751
<a href="c9d0f72c423b7b2f3f8291c13f08e7ceddc71ab0.jpg">c9d0f72c423b7b2f3f8291c13f08e7ceddc71ab0.jpg</a>       16-Jan-2015 23:09               87597
<a href="cc1ec381ccb0f12516103b6d5362891767810fff.jpg">cc1ec381ccb0f12516103b6d5362891767810fff.jpg</a>       16-Jan-2015 23:09              223826
<a href="ce35392ddb7f25d6f5c3ffe4d1c8e8905da7cf94.jpg">ce35392ddb7f25d6f5c3ffe4d1c8e8905da7cf94.jpg</a>       16-Jan-2015 23:09              122864
<a href="d474bb9a7e7900eed87718e1d98fa2862ca5b1b3.jpg">d474bb9a7e7900eed87718e1d98fa2862ca5b1b3.jpg</a>       16-Jan-2015 23:09               44671
<a href="d6e41da783fe73ae2e587faf05b9e51908f81a5b.jpg">d6e41da783fe73ae2e587faf05b9e51908f81a5b.jpg</a>       16-Jan-2015 23:09              474253
<a href="d732c58f03480f158930695f9be172d87723c1e1.jpg">d732c58f03480f158930695f9be172d87723c1e1.jpg</a>       16-Jan-2015 23:09               21088
<a href="da5baf89352ce35065131d499ae2c5b174b02f46.jpg">da5baf89352ce35065131d499ae2c5b174b02f46.jpg</a>       16-Jan-2015 23:09              330334
<a href="dm5vm8.jpg">dm5vm8.jpg</a>                                         16-Jan-2015 23:09              515344
<a href="e03c34b9549fec241d8a29c23ee0db470aa1c7b1.jpg">e03c34b9549fec241d8a29c23ee0db470aa1c7b1.jpg</a>       16-Jan-2015 23:09              246346
<a href="e5dd21632e3bb7851e93a0a59bed15a5b379703c.jpg">e5dd21632e3bb7851e93a0a59bed15a5b379703c.jpg</a>       16-Jan-2015 23:09              385784
<a href="eb26054e9f3817b6e2327e8fe881469143aa99b6.jpg">eb26054e9f3817b6e2327e8fe881469143aa99b6.jpg</a>       16-Jan-2015 23:09               73749
<a href="eed53c5a1127b218f9cf424e776137745478ef8d.jpg">eed53c5a1127b218f9cf424e776137745478ef8d.jpg</a>       16-Jan-2015 23:09               32904
<a href="f1c66aabecf538eabc7718e4a19e926b73f3b62a.jpg">f1c66aabecf538eabc7718e4a19e926b73f3b62a.jpg</a>       16-Jan-2015 23:09              273218
<a href="f7fbc15c75829f57fcbfc4c45d76aa53007c8908.jpg">f7fbc15c75829f57fcbfc4c45d76aa53007c8908.jpg</a>       16-Jan-2015 23:09               74894
<a href="f7zR4.jpg">f7zR4.jpg</a>                                          16-Jan-2015 23:09              102468
<a href="f85599cb374f74fc7176005556fe49dc5d08b09c.jpg">f85599cb374f74fc7176005556fe49dc5d08b09c.jpg</a>       16-Jan-2015 23:09               69120
<a href="fa23ec63568d591b1cc08c7e11a073ce83846941.jpg">fa23ec63568d591b1cc08c7e11a073ce83846941.jpg</a>       16-Jan-2015 23:09              342187
<a href="hendricks.jpg">hendricks.jpg</a>                                      16-Jan-2015 23:09               23665
<a href="jz8774.jpg.gif">jz8774.jpg.gif</a>                                     16-Jan-2015 23:09             1351611
<a href="k1ckgm.jpg">k1ckgm.jpg</a>                                         16-Jan-2015 23:09              191441
<a href="key.txt">key.txt</a>                                            16-Jan-2015 23:10                  39
<a href="n1JdM.jpg">n1JdM.jpg</a>                                          16-Jan-2015 23:09               77911
<a href="o9KBX.jpg">o9KBX.jpg</a>                                          16-Jan-2015 23:09              394726
<a href="qHChf.jpg">qHChf.jpg</a>                                          16-Jan-2015 23:09              114109
<a href="redheadboobies.jpg">redheadboobies.jpg</a>                                 16-Jan-2015 23:09               37797
<a href="uyQ1a.jpg">uyQ1a.jpg</a>                                          16-Jan-2015 23:09              128651
<a href="v91PO.jpg">v91PO.jpg</a>                                          16-Jan-2015 23:09               77387
<a href="w1qp84.jpg">w1qp84.jpg</a>                                         16-Jan-2015 23:09              335746
<a href="works7175.txt">works7175.txt</a>                                      16-Jan-2015 21:35                   8
<a href="yDVi0.jpg">yDVi0.jpg</a>                                          16-Jan-2015 23:09              458559
</pre><hr></body>
</html>

0

^C

$ wget -np -r http://knockers.2015.ghostintheshellcode.com:7175
...
Total wall clock time: 8.4s
Downloaded: 100 files, 19M in 6.7s (2.82 MB/s)

$ cat knockers.2015.ghostintheshellcode.com:7175/key.txt
the_snozberries_taste_like_snozberries

```

I actually had a harder time getting IPv6 working than solving the challenge as I was familiar with it, remembered when Flickr and a few other services had similiar vulnerabilities, and solved a [similar challenge in StripeCTF 2.0](https://github.com/stripe-ctf/stripe-ctf-2.0/tree/master/levels/7). 

Somehow I can connect to several IPv6 destinations, but not the knocker box. After spending way longer than I should have trying to fix that I just spun up a new ec2 instance and used [Hurricane Electric's](https://tunnelbroker.net/) [tunnel broker](http://en.wikipedia.org/wiki/IPv6_transition_mechanisms#Tunnel_broker). I saw a few similar complaints on IRC so IPv6 is clearly ready for the mainstream.

## Other write-ups and resources

* <http://blog.tinduong.pw/ghost-in-the-shellcode-2015-write-ups/>
* <https://blog.skullsecurity.org/2015/gits-2015-knockers-py-hash-extension-vulnerability>
* [French](https://t0x0sh.org/ghosts-in-the-shellcodes-2015-knockers-crypto-150.html)
* [German](https://cryto.org/writeup-ghost-in-the-shellcode-2015-crypto-150-knockers/)
