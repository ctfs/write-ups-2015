#!/usr/bin/env python2

import argparse
import numpy as np
import re
import struct
import resource
from random import randint
from tornado import gen
from tornado import iostream
from tornado.process import Subprocess
from tornado.ioloop import IOLoop
from tornado.tcpserver import TCPServer


np.warnings.simplefilter("ignore", RuntimeWarning)  # hide integer overflow warning

TIMEOUT = 15
EXPRESSIONS = (
    "$rax + $rbx",
    "$rax + $rbx + 1337",
    "$rax * $rbx",
    "$rax * (31337 + $rbx)",
    "$rcx + 23 * $rax + $rbx - 42 * ($rcx - 5 * $rdx - $rdi * $rsi) - $r8 + 2015",
)
try:
    FLAG = open("flag.txt").read()
except IOError:
    FLAG = "DUMMY_FLAG"


class ScopedProcess(Subprocess):
    def __enter__(self):
        return self

    def __exit__(self, type, value, tb):
        for f in (self.stdin, self.stdout, self.stderr):
            if f is not None:
                f.close()
        try:
            self.proc.kill()
        except OSError:
            pass


class Client(object):
    def __init__(self, cli, loop=None):
        self.cli = cli
        self.regs = Registers.random()
        if loop is None:
            self.loop = IOLoop.instance()
        else:
            self.loop = loop
        self.timeout = None

    def start(self):
        self.timeout = self.loop.call_later(TIMEOUT, lambda: self.error("Too slow!"))
        self.cli.set_close_callback(self.finished)
        self.validate_expressions()

    @gen.coroutine
    def validate_expressions(self, *args):
        for i, expression in enumerate(EXPRESSIONS):
            yield self.cli.write(
                "Level [{}/{}]\n"
                "Create a ROP chain that calculates: {} (store result in rax)\n"
                "Enter your solution as a single hex encoded line: "
                .format(i + 1, len(EXPRESSIONS), expression)
            )
            try:
                line = yield self.cli.read_until("\n", max_bytes=4096)
            except iostream.StreamClosedError:
                break
            try:
                ropchain = line.strip("\n").decode("hex")
            except TypeError:
                yield self.error("Error decoding ROP chain!")
                break
            ok = yield self.execute_ropchain(ropchain, expression)
            if not ok:
                yield self.write("Wrong result. Better luck next time!")
                break
            yield self.write("Correct!\n" + "-" * 80)
        else:
            yield self.write("The flag is: {}".format(FLAG))
        self.finished()

    @gen.coroutine
    def execute_ropchain(self, ropchain, expression):
        args = {
            "close_fds": True,
            "stdin": Subprocess.STREAM,
            "stdout": Subprocess.STREAM,
        }
        with ScopedProcess(["./ropcalc"], **args) as proc:
            yield proc.stdin.write(self.regs.serialize())
            yield proc.stdin.write(struct.pack("<Q", len(ropchain)))
            yield proc.stdin.write(ropchain + "\n")
            try:
                bytes = yield proc.stdout.read_bytes(8)
            except iostream.StreamClosedError:
                self.error("Seems like the process crashed!")
                raise gen.Return(False)
            rop_result = struct.unpack("<Q", bytes)[0]
            real_result = self.regs.eval(expression)
            if rop_result == real_result:
                raise gen.Return(True)
            raise gen.Return(False)

    @gen.coroutine
    def write(self, msg):
        yield self.cli.write(msg + "\n")

    @gen.coroutine
    def error(self, msg):
        try:
            yield self.write(msg)
        except iostream.StreamClosedError:
            pass
        self.finished()

    def finished(self):
        self.loop.remove_timeout(self.timeout)
        self.cli.close()


class Ropcalc(TCPServer):
    def handle_stream(self, stream, address):
        Client(stream).start()


class Registers(object):
    def __init__(self, rax=0, rbx=0, rcx=0, rdx=0, rsi=0, rdi=0, r8=0,
                 r9=0, r10=0, r11=0, r12=0, r13=0, r14=0, r15=0):
        self.rax = np.uint64(rax)
        self.rbx = np.uint64(rbx)
        self.rcx = np.uint64(rcx)
        self.rdx = np.uint64(rdx)
        self.rsi = np.uint64(rsi)
        self.rdi = np.uint64(rdi)
        self.r8  = np.uint64(r8)
        self.r9  = np.uint64(r9)
        self.r10 = np.uint64(r10)
        self.r11 = np.uint64(r11)
        self.r12 = np.uint64(r12)
        self.r13 = np.uint64(r13)
        self.r14 = np.uint64(r14)
        self.r15 = np.uint64(r15)
    
    @classmethod
    def random(cls):
        rand_val = lambda: randint(1, 0xffffffffffffffff)
        num_args = cls.__init__.im_func.func_code.co_argcount - 1
        return cls(*[rand_val() for _ in xrange(num_args)])

    def __repr__(self):
        return ("Registers(rax=0x{s.rax:x}, rbx=0x{s.rbx:x}, rcx=0x{s.rcx:x}, "
                "rdx=0x{s.rdx:x}, rsi=0x{s.rsi:x}, rdi=0x{s.rdi}, "
                "r8=0x{s.r8:x}, r9=0x{s.r9:x}, r10=0x{s.r10:x}, "
                "r11=0x{s.r11:x}, r12=0x{s.r12:x}, r13=0x{s.r13:x}, "
                "r14=0x{s.r14:x}, r15=0x{s.r15:x})".format(s=self))

    def eval(self, term):
        term = term.replace("$", "self.")
        term = re.sub(r"([(+\-*/ ])(\d+)", r"\1np.uint64(\2)", term)
        return eval(term)

    def serialize(self):
        values = [
            self.rax, self.rbx, self.rcx, self.rdx, self.rsi, self.rdi,
            self.r8, self.r9, self.r10, self.r11, self.r12, self.r13,
            self.r14, self.r15
        ]
        return "".join(struct.pack("<Q", value) for value in values)


def increase_fds():
    soft, hard = resource.getrlimit(resource.RLIMIT_NOFILE)
    resource.setrlimit(resource.RLIMIT_NOFILE, (hard, hard))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--port", type=int, default=1024)
    args = parser.parse_args()
    increase_fds()
    server = Ropcalc()
    server.listen(args.port)
    IOLoop.instance().start()
