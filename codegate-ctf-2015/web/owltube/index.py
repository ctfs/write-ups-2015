#!/usr/bin/python

from flask import *
import json
import pymongo
from Crypto.Cipher import AES
from Crypto import Random
from secret import SECRET_KEY

NAME = "Owltube"

app = Flask(NAME)
app.debug = False
#app.debug = True

app.secret_key = SECRET_KEY

defaultvids = []

defaultvids.append({"title": "Barn owl vs cat", "vid": "pZ4ffqXg6RA"})
defaultvids.append({"title": "Owl vs dog", "vid": "NJlyMFCX9CA"})
defaultvids.append({"title": "Singing owl", "vid": "fppKGJD3Y6c"})

@app.before_request
def before_request():
	g.db = pymongo.Connection("mongodb://127.0.0.1").owltube
	g.user = None

@app.teardown_request
def teardown_request(exception):
    if hasattr(g, 'db'):
	g.db.connection.close()

BS = AES.block_size
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS) 
unpad = lambda s : s[0:-ord(s[-1])]

def get_cookie():
	cookie = request.cookies.get("auth")
	if not cookie: return None

	cookie = cookie.decode("base64")

	iv = cookie[:BS]
	cookie = cookie[BS:]
	aes = AES.new(SECRET_KEY, AES.MODE_CBC, iv)
	cookie = aes.decrypt(cookie)
	cookie = unpad(cookie)

	cookie = json.loads(cookie)

	return cookie

def set_cookie(resp, cookie):
	cookie = json.dumps(cookie)

	iv = Random.new().read(BS)
	aes = AES.new(SECRET_KEY, AES.MODE_CBC, iv)
	cookie = pad(cookie)
	cookie = iv + aes.encrypt(cookie)
	cookie = cookie.encode("base64")
	cookie = cookie.replace("\n", "")

	resp.set_cookie("auth", cookie)

def is_logged_in():
	cookie = get_cookie()

	if not cookie: return False

	user = g.db.users.find_one(get_cookie())

	if not user: return False
	g.user = cookie

	return True


@app.route("/")
def index():
	if is_logged_in():
		videos = []
		for i, vid in enumerate(g.db.videos.find({"user": g.user["u"]})):
			vid["num"] = "%u" % (i+1)
			videos.append(vid)

		resp = render_template("main.html", videos=videos)
	else:
		resp = render_template("landing.html")
	return resp

@app.route("/login", methods=['POST'])
def login():
	u = {}
	u["u"] = request.form.get("user")
	u["pw"] = request.form.get("pw")

	user = g.db.users.find_one(u)

	resp = make_response(redirect(url_for('index')))

	if user:
		set_cookie(resp, u)
	else:
		flash("Login failed")

	
	return resp

@app.route("/register", methods=['POST'])
def register():
	u = {}
	u["u"] = request.form.get("user")
	u["pw"] = request.form.get("pw")
	u["email"] = request.form.get("email")

	if g.db.users.find_one({"u":u["u"]}):
		flash("Username taken")
	else:
		g.db.users.insert(u)

		for vid in defaultvids:
			vid["user"] = u["u"]
			g.db.videos.insert(vid)

		flash("Registered")

	return make_response(redirect(url_for('index')))


@app.route("/logout")
def logout():
	resp = make_response(redirect(url_for('index')))
	resp.set_cookie("auth", "")
	return resp

@app.route("/addvid", methods=['POST'])
def addvid():
	if not is_logged_in():
		return make_response(redirect(url_for('index')))

	vid = {}
	vid["title"] = request.form.get("title")
	vid["vid"] = request.form.get("vid")
	vid["user"] = g.user["u"]

	g.db.videos.insert(vid)

	return make_response(redirect(url_for('index')))

if __name__ == "__main__":
	if app.debug:
		app.run()
	else:
		from tornado.wsgi import WSGIContainer
		from tornado.httpserver import HTTPServer
		from tornado.ioloop import IOLoop

		http_server = HTTPServer(WSGIContainer(app))
		http_server.listen(5555)
		IOLoop.instance().start()

