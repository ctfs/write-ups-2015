from socket import *

from Lottery import handleClient

import thread
 
def handler(clientsocket, clientaddr):
	print "Accepted connection from: ", clientaddr
     
	try:
		handleClient(clientsocket)
	except:
		pass
	clientsocket.close()
	print "Connection closed for: ", clientaddr
 
if __name__ == "__main__":
 
    host = 'localhost'
    port = 55567
    buf = 1024
 
    addr = (host, port)
 
    serversocket = socket(AF_INET, SOCK_STREAM)
 
    serversocket.bind(addr)
 
    serversocket.listen(2)
 
    while 1:
        print "Server is listening for connections\n"
 
        clientsocket, clientaddr = serversocket.accept()
        thread.start_new_thread(handler, (clientsocket, clientaddr))
    serversocket.close()