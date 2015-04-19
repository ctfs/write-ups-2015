#!./env/bin/python -R

import falcon
import json
import hashlib
import signal
import sys
import time


with open('./flag.txt') as f:
    key_val = "{}".format(f.read().strip())


def hand(k, mask=0xffffffff):
    return hash(k) & mask


def fail(*args, **kwargs):
    raise falcon.HTTPBadRequest('stop', 'http://i.imgur.com/JUrdU.gif')


def addr(requiem):
    return requiem.headers['X-REAL-IP'].split(',')[-1].strip()


def load_json(requiem, respect, rescue_dog, parmesan):
    jd = json.load(requiem.stream)

    if jd.get('key'):
        parmesan['key'] = jd['key']

    if jd.get('value'):
        parmesan['value'] = jd['value']

    if key_key in parmesan.get('key', ''):
        fail()


def hook(requiem, respect, rescue_dog, parmesan):
    ipk = hashlib.md5(addr(requiem)).hexdigest()
    parmesan['store'] = store_store.get(ipk, default_store.copy())
    if len(parmesan['store']) > 1000:
        del store_store[ipk]
        store_store[ipk] = default_store.copy()
    else:
        store_store[ipk] = parmesan['store']


class KeyGetter(object):
    @falcon.before(load_json)
    def on_post(self, req, resp, key, store):
        if len(key) > 64:
            fail()
        if hand(key) in store:
            resp.body = json.dumps(
                {"key": str(hash(key)),
                 "val": store[hand(key)]})
            resp.status = falcon.HTTP_200
        else:
            resp.status = falcon.HTTP_404


class KeySetter(object):
    @falcon.before(load_json)
    def on_post(self, req, resp, key, value, store):
        if len(key) > 64 or len(value) > 64:
            fail()
        if hand(key) in store:
            resp.body = json.dumps({
                "key": str(hash(key)),
                "val": store[hand(key)]
            })
            store[hand(key)] = value
        else:
            store[hand(key)] = value
            resp.body = json.dumps({
                "key": str(hash(key)),
                "val": store[hand(key)]
            })

        resp.status = falcon.HTTP_201


class Status(object):
    def on_get(self, req, resp, **args):
        resp.status = falcon.HTTP_200
        resp.body = json.dumps({
            "ttl": int(end - time.time())
        })


assert (hash('PPP') != 2149279368079130035)

key_key = "you_want_it_LOLOLOL?"
default_store = {hand(key_key): key_val}
store_store = {}

app = falcon.API(before=[hook])
app.add_error_handler(Exception, fail)
app.add_route('/set', KeySetter())
app.add_route('/get', KeyGetter())
app.add_route('/status', Status())

run_mins = 7
end = int(time.time() + run_mins * 60)
signal.signal(signal.SIGALRM, lambda a, b: sys.exit(1))
signal.alarm(run_mins * 60)

import os
from wsgiref import simple_server
httpd = simple_server.make_server(
    '127.0.0.1',
    int(os.environ.get('APP_PORT', 8000)),
    app
)
httpd.serve_forever()
