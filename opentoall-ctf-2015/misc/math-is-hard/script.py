from socket import create_connection
from time import sleep
import numpy

def calc(s):
    data = s.recv(4096).decode().split()[-3:]
    nb1 = int(data[0])
    nb2 = int(data[2])
    res = str(nb1 + nb2)
    s.send(res.encode())

def equation(s):
    data = s.recv(4096).decode()
    eq1, eq2 = tuple(data.split('\n')[-4:-2])
    eq1, eq2 = eq1.split(), eq2.split()
    eq1x, eq1y, eq1z = int(eq1[0][:-1]), int(eq1[2][:-1]), int(eq1[4])
    eq2x, eq2y, eq2z = int(eq2[0][:-1]), int(eq2[2][:-1]), int(eq2[4])
    a = numpy.array([[eq1x, eq1y], [eq2x, eq2y]])
    b = numpy.array([[eq1z], [eq2z]])
    res = numpy.linalg.solve(a, b)
    x = str(res[0])[1:-2]
    y = str(res[1])[1:-2]
    s.send(x.encode())
    s.send(y.encode())

def derivation(s):
    data = s.recv(4096).decode().split('\n')
    pt = int(data[-4][-2:-1])
    fs = data[-3][7:].split()
    fs = [x for x in fs if 'x' in x]
    a = int(f[0])
    b = int(f[-1])
    res = sum([a * b * pow(pt, b - 1) for f in fs])
    s.send(str(res).encode())

s = create_connection(('104.131.107.153', 12121))
# Calc step
for i in range(8):
    calc(s)
# Equation step
for i in range(8):
    equation(s)
# Derivation step
for i in range(8):
    derivation(s)
# Print the flag
print(s.recv(4096).decode())
