import RPi.GPIO as gpio
import time
import sys
import struct

rfd = open(sys.argv[1], 'rb')
wfd = open(sys.argv[2], 'wb')
len = int(sys.argv[3])

load  = 4
clock = 10
reset = 9

p0=21
p1=20
p2=16
p3=12
p4=25
p5=24
p6=23
p7=18

pns = [p7,p6,p5,p4,p3,p2,p1,p0]

q0=19
q1=13
q2=6
q3=5
q4=22
q5=27
q6=17
q7=26

def pulse(pin):
    gpio.output(pin, gpio.LOW)
    gpio.output(pin, gpio.HIGH)

def init():
    gpio.setwarnings(False)
    gpio.setmode(gpio.BCM)
    gpio.setup([clock,load,reset], gpio.OUT)
    gpio.output([clock,load,reset], gpio.HIGH)
    pulse(reset)
    gpio.setup(pns, gpio.OUT)
    gpio.output(pns, gpio.LOW)
    for q in [q7, q6, q5, q4, q3, q2, q1, q0]:
        gpio.setup(q, gpio.IN)

def setValue(n):
    pulse(reset)
    for i in range(n):
        pulse(clock)

def a2v(a):
    return a[7]+2*a[6]+4*a[5]+8*a[4]+16*a[3]+32*a[2]+64*a[1]+128*a[0]

# main        
init()

for i in range(len):
    value = a2v([gpio.input(q7), gpio.input(q6), gpio.input(q5),
                 gpio.input(q4), gpio.input(q3), gpio.input(q2),
                 gpio.input(q1), gpio.input(q0)])
    # file convert 
    v = rfd.read(1)
    d = ''
    d += struct.pack('B', ord(v) ^ value)
    wfd.write(d)

    setValue(value)
    time.sleep(0.1)
    pulse(clock)
    pulse(clock)
    pulse(clock)

gpio.cleanup()


