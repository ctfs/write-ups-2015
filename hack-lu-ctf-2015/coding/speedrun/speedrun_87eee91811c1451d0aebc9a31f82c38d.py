#!/usr/bin/python2

import time
import os
import sys
import socket
import json

BUFFSIZE = 4096


class _Getch:
    def __init__(self):
        try:
            self.impl = _GetchWindows()
        except ImportError:
            self.impl = _GetchUnix()

    def __call__(self): return self.impl()


class _GetchUnix:
    def __init__(self):
        import tty, sys

    def __call__(self):
        import sys, tty, termios
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch


class _GetchWindows:
    def __init__(self):
        import msvcrt

    def __call__(self):
        import msvcrt
        return msvcrt.getch()


class Client:

    def __init__(self, host, port, layer4="tcp"):
        self.host = host
        self.port = port
        self.layer4 = layer4


    def connect(self, maxRetries=2, pauseAfterFail=0.5):
        # use the right socket configuration
        if self.layer4 == "tcp":
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        elif self.layer4 == "udp":
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        else:
            raise NotImplementedError("Layer 4 protocol not implemented Client class")

        # try to connect for maxRetries time
        retries = 0
        while True:
            try:
                self.socket.connect((self.host, self.port))
                return True
            except:
                retries += 1
                if retries == maxRetries:
                    print "Unable to connect. Giving up after %d retries." % retries
                    return False

                time.sleep(pauseAfterFail)


    def send(self, data):
        try:
            count = self.socket.send(data)
        except:
            print "Unable to send data."
            return False
        if count == len(data):
            return True
        else:
            print "Unable to send all data."
            return False


    def recv(self, buffsize, timeout=10.0):
        data = None
        self.socket.settimeout(timeout)
        try:
            data = self.socket.recv(buffsize)
        except socket.timeout:
            print "Receive timed-out"
        except:
            print "Unexpected exception while receiving"
        self.socket.settimeout(None)
        return data


    def close(self):
        self.socket.close()


class FieldSymbols(object):
    empty = 0
    barrier = 1
    candy = 2
    snake = (3, 5, 7, 9, 11, 13)
    snake_head = (4, 6, 8, 10, 12, 14)


class SnakeMoveDirections(object):
    up = 0
    down = 1
    left = 2
    right = 3



def output_field(field):

    os.system("clear")

    line = ""
    for i in range(len(field[0]) + 2):
        line += "-"
    print(line)

    for y in range(len(field)):

        line = "|"
        for x in range(len(field[0])):

            if field[y][x] == FieldSymbols.empty:
                line += " "
            elif field[y][x] == FieldSymbols.barrier:
                line += "#"
            elif field[y][x] == FieldSymbols.candy:
                line += "$"
            else:
                for i in range(len(FieldSymbols.snake)):
                    if field[y][x] == FieldSymbols.snake[i]:
                        line += "o"
                        break
                    elif field[y][x] == FieldSymbols.snake_head[i]:
                        line += chr(65 + i)
                        break
        line += "|"
        print(line)

    line = ""
    for i in range(len(field[0]) + 2):
        line += "-"
    print(line)


if __name__ == '__main__':

    getch = _Getch()

    conn = Client(sys.argv[1], int(sys.argv[2]))
    if conn.connect():

        data = conn.recv(BUFFSIZE)
        message = json.loads(data)

        print(message["message"])
        time.sleep(5)

        while True:

            recv_data = conn.recv(BUFFSIZE)
            if recv_data == None or recv_data =="\r\n" or recv_data == "":
                break

            # received data can be fragmented
            # => get next fragment
            data = recv_data.strip()
            exit = False
            while data[-1:] != "}":
                recv_data = conn.recv(BUFFSIZE)

                if (recv_data == None
                    or recv_data =="\r\n"
                    or recv_data == ""):
                    exit = True

                data += recv_data.strip()
            if exit:
                break

            message = json.loads(data)
            output_field(message["field"])
            if "message" in message.keys():
                print(message["message"])

            if "quit" in message.keys():
                break

            if "restart" in message.keys():
                continue

            print("Turns remaining: %d" % message["limit"])

            while True:
                try:
                    print("(W, A, S, D ; Q = quit): ")
                    user_input = getch()
                except KeyboardInterrupt:
                    sys.exit(0)
                except:
                    continue
                user_input = user_input.strip()

                if user_input.upper() == "W":
                    move_direction = SnakeMoveDirections.up
                elif user_input.upper() == "A":
                    move_direction = SnakeMoveDirections.left
                elif user_input.upper() == "S":
                    move_direction = SnakeMoveDirections.down
                elif user_input.upper() == "D":
                    move_direction = SnakeMoveDirections.right
                elif user_input.upper() == "Q":
                    sys.exit(0)
                else:
                    print("Illegal input.")
                    continue
                break

            message = dict()
            message["move_direction"] = move_direction
            conn.send(json.dumps(message))

