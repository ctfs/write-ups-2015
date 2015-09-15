# IceCTF 2015: Statistics

**Category:** Programming
**Points:** 50
**Description:** 

> Daniel is strangely good at computing statistics in his head, so instead of a password, a program asks him a series of statistics questions for authentication. Let's show him how insecure that is. You can access the server with <code>nc vuln2015.icec.tf 9000</code>.

**Hint:**

> Do you really need to do all these statistics?

## Write-up

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket

# some settings
TCP_IP = 'vuln2015.icec.tf'
TCP_PORT = 9000
BUFFER_SIZE = 1024


def parse(data):
    """Parse the numbers and the operation to perform from the raw data received"""
    numbers = [int(n) for n in data[0].split()]
    op = data[1].split()[2]
    return numbers, op


def get_data(s):
    """Get all the raw data (it can be longer than BUFFER_SIZE, so we need to loop)"""
    data = ''
    try:
        while 'numbers' not in data:  # guess the end of the data
            tmp = s.recv(BUFFER_SIZE)

            if tmp == '':  # we got it \o/
                print data
                exit(0)

            data += tmp
    except socket.timeout:
        print 'You have a shitty connection.'
        exit(1)
    return data.split('\n')


def main():
    # connect
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))
    s.settimeout(1)

    count = 1
    while True:
        data = get_data(s)
        numbers, action = parse(data)

        print '%d - %s of %d numbers' % (count, action, len(numbers))

        if action == 'minimum':
            ret = min(numbers)
        elif action == 'maximum':
            ret = max(numbers)
        elif action == 'sum':
            ret = sum(numbers)
        elif action == 'average':
            ret = 1.0 * sum(numbers) / len(numbers)
        else:
            print 'No operation found.'
            exit(1)

        s.send(str(ret)+'\n')
        count += 1


if __name__ == '__main__':
    main()
```

## Other write-ups and resources

