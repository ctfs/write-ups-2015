# backdoor CTF 2015: [QR](https://backdoor.sdslabs.co/challenges/QR)

**Category:** Misc
**Points:** 70
**Author:** [Abhay Bir Singh Rana](https://backdoor.sdslabs.co/users/nemo)
**Difficulty:** Easy
**Solves:** 84
**Description:** 

* <https://backdoor.sdslabs.co/challenges/QR>

> Decode some QR codes at `nc hack.bckdr.in 8010`

## Write-up

##Overview
When you run
~ nc hack.bckdr.in 8010
You will get back what looks to be a version 10 QR code

At this point there are a couple options to solve this.
I chose a very inefficient route, but it ended up working in the end.

##Netcat
The connection can be opened by using pwn tools tubes.
There are a lot of great methods in the module, we will be using can_recv, recv, and send.

##Qr code:
This is where I went the long way around.
I split the qr code up to an array based on newlines, 
then created a picture 800x800 using PIL, 
then print the text into the image.
You have to use a mono, unicode font in order to represent the qr code correctly.
I selected DejaVuSansMono since it was the first Google result.
Now we have an image of the qr code, we can use qrtools to read it in, and give us text.
Again, complicated, but it worked. most of the time.
Then send the code back to the server which would then give us the next qr code.

##Code Overview (python 2.x):
Use pwntools remote to connect to the server
	
	self.r = remote(hostname, port)
Then we can grab the qr code:

	#get qr-text from server
	data=''
	while self.r.can_recv(timeout = 0.35):
		try:
			data += self.r.recv(timeout=0.01)
		except:
			pass
Now we have the data (unicode text), we need to make it an image.\n
For this, we use PIL to write text to an image.

	im  =  Image.new ( "RGB", (width,height), back_ground_color )	#width,height=800, back_ground_colot = (255,255,255)
	draw  =  ImageDraw.Draw ( im )
	unicode_font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", font_size)	#font_size=10
	vPos=0
	for unicode_text in data:
		draw.text ( (10,vPos), unicode_text.decode('utf-8'), fill=font_color, font=unicode_font )	#font_color=(0,0,0)
		vPos+=10	#font size of 10, so 10 between characters vertically
	im.save("test.png")
This code takes every line from data and prints it as a new line in the image.

Now we have the image saved as test.png, we can use qrtools to read it.

	qr = qrtools.QR()
	qr.decode("test.png")
	print qr.data
This will print the data for the QR code. Now we just need to send it back to the server.

	self.r.send(qr.data)
The server will then give back another qr code to decode

after 100 successful answers, you will not get a qr code,
instead you get back

	Congratulations. Flag is [Redacted]

## Other write-ups and resources

* <http://kbhat95.github.io/backdoor-ctf/>
* <https://ctf-team.vulnhub.com/backdoor-ctf-2015-qr/>
* <https://babyphd.net/2015/04/backdoorctf-writeup/>
* <http://capturetheswag.blogspot.com.au/2015/04/backdoor-ctf-2015-qr-challenge-response.html>
* <https://gist.github.com/Bono-iPad/e908ddc67b3994069950>
* [Indonesian](https://docs.google.com/document/d/12EM1YFzBoGp5jIDtryIof4Jv_p1S1Fvw-6rP8hm9ZlM/edit)
