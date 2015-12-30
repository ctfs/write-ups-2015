import io
import os
import tempfile
import subprocess
import flask
from flask import Flask, request, redirect, url_for

import traceback

FFMPEG = "ffmpeg-2.8.2-64bit-static/ffmpeg"

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 1 * 1024 * 1024

VIDEO_HTML_HEAD='''<!doctype html>
<title>Super Turbo Atomic GIF Converter</title>
<body style="background-image: url(https://i.imgur.com/nouzgH4.gif)">
<center>
<video src="data:video/webm;base64,'''
VIDEO_HTML_TAIL='''" controls width=640 height=480></video>
</center>
</body>'''

def convert_gif(temp_filename):
    p = subprocess.Popen((
            ("(echo -n '%s' &&" % (VIDEO_HTML_HEAD))
            +("(%s -i '%s' -f webm -codec:v vp8 -cpu-used 4 - | base64) &&" % (FFMPEG, temp_filename))
            +("echo -n '%s');" % (VIDEO_HTML_TAIL))
            +("rm '%s';" % temp_filename)),
        shell=True,
        stdout=subprocess.PIPE)
    stdout2 = open("/dev/fd/%d" % p.stdout.fileno(), "rb")
    return flask.send_file(stdout2, mimetype="text/html")

@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        file_ = request.files['file']
        if not file_.filename.lower().endswith(".gif"):
            return "I don't think this is a GIF file! BORING", 415
        tf = tempfile.mktemp()
        file_.save(tf)
        return convert_gif(tf)
    else:
        return '''<!doctype html>
<title>Super Turbo Atomic GIF Converter</title>
<body style="background-image: url(https://i.imgur.com/nouzgH4.gif)">
<center>
<img src="https://i.imgur.com/UhHmhYR.gif" alt="Super Turbo Atomic GIF Converter">
<form action="" method=post enctype=multipart/form-data>
  <p style="color:white;"><input type=file name=file><input type=submit value=Upload></p>
</form>
</center>
</body>
'''

if __name__ == '__main__':
    # app.debug = True
    app.run(host='0.0.0.0', port=9447, threaded=True)
