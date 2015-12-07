#!/usr/bin/python

import RPi.GPIO as GPIO
import time

CLR = 4
CLK = 5
DA  = 6
DB  = 12

X1  = 13
X2  = 19
X3  = 20
X4  = 21
X5  = 26
X6  = 16

GPIO.setmode(GPIO.BCM)
GPIO.setup(CLR, GPIO.OUT)
GPIO.setup(CLK, GPIO.OUT)
GPIO.setup(DA,  GPIO.OUT)
GPIO.setup(DB,  GPIO.OUT)

GPIO.setup(X1, GPIO.IN)
GPIO.setup(X2, GPIO.IN)
GPIO.setup(X3, GPIO.IN)
GPIO.setup(X4, GPIO.IN)
GPIO.setup(X5, GPIO.IN)
GPIO.setup(X6, GPIO.IN)

GPIO.output(CLK, False)
GPIO.output(DA,  False)
GPIO.output(DB,  False)

GPIO.output(CLR, False)
GPIO.output(CLR, True)

flagString = ""

def encoder(x6,x5,x4,x3,x2,x1):
    v = 0
    v = GPIO.input(x1);
    v = 2*v + GPIO.input(x2)
    v = 2*v + GPIO.input(x3)
    v = 2*v + GPIO.input(x4)
    v = 2*v + GPIO.input(x5)
    v = 2*v + GPIO.input(x6)
    return v

c = '@'
flag = ""

try:
    for i in range(10) :
        if c == 'Y' :
            GPIO.output(DA, False)
            GPIO.output(DB, True)
        else:
            if (i & 1) == 0 :
                GPIO.output(DA, False)
            else :
                GPIO.output(DA, True)
            if (i & 2) == 0 :
                GPIO.output(DB, False)
            else :
                GPIO.output(DB, True)

        time.sleep(0.1)

        c = chr(encoder(X6,X5,X4,X3,X2,X1)+32)
        flag = flag + c

        GPIO.output(CLK, True)
        GPIO.output(CLK, False)

        time.sleep(0.1)
        flag = flag + chr(encoder(X6,X5,X4,X3,X2,X1)+32)

except KeyboardInterrupt:
    print("stop\n")

GPIO.cleanup()

print "The flag is SECCON{"+flag+"}"

