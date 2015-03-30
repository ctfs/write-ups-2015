#!/usr/bin/python -u

import signal
from flag import FLAG
from helper import gen_param

def input_int(prompt=''):
    try:
        n = int(raw_input(prompt))
        return n
    except ValueError:
        print 'Invalid number!'
        exit()

def rsaquine():
    total = 30
    print '0CTF RSA Quine'
    print '%d Rounds in total to capture the flag.' % total
    bits = 16
    for i in xrange(total):
        print 'Round %d' % (i+1)
        N,e,qn = gen_param(bits)
        bits += 7
        print 'N = %d' % N
        print 'e = %d' % e
        print 'Total %d quine numbers' % qn
        if (qn <= 200):
            print 'Can you find them?'
        else:
            qn = 200
            print 'Just Give me %d of them.' % qn
        quine = set()
        for j in xrange(qn):
            m = input_int('%d: ' % (j+1))
            if m in quine:
                print 'Do not cheat!'
                exit()
            c = pow(m, e, N)
            if m == c:
                print 'Good Quine!'
                quine.add(m)
            else:
                print 'Bad Number!'
                exit()
    N,e,qn = gen_param(256)
    print 'You are a quine expert!'
    print 'N = %d' % N
    print 'e = %d' % e
    f = pow(int(FLAG.encode('hex'),16), e, N)
    print 'Flag = %d' % f
    print 'Good Luck & Have Fun!'

if __name__ == "__main__":
    signal.alarm(3600)
    rsaquine()
