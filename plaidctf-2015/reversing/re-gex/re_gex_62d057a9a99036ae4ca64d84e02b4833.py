import SocketServer
import re

FLAG = open('flag.txt', 'r').read().strip()
r = re.compile(open('regex.txt', 'r').read().strip())

class HandleRequest(SocketServer.StreamRequestHandler):
    def handle(self):
        self.request.sendall("Enter your key:\n")
        msg = self.rfile.readline().strip()

        if r.match(msg) == None:
            self.request.sendall("Congrats! You passed the test! Here's your FLAG: %s\n" % FLAG)
        else:
            self.request.sendall("Fail...you did not pass the test.\n")

class ThreadedServer(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
    pass

if __name__ == "__main__":
    SERVER_ADDR = ("", 29285)
    server = ThreadedServer(SERVER_ADDR, HandleRequest)
    server.allow_reuse_address = True
    server.serve_forever()
