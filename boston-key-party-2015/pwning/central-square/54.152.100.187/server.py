#!/usr/bin/python

# Server for Central Square vulnerable service.
# Copyright (C) 2015 Robbie Harwood <rharwood@club.cc.cmu.edu>
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.

from gevent.wsgi import WSGIServer

from subprocess import *
from threading import *

from tempfile import mkdtemp
from urllib2 import unquote

import os
import shutil
import socket
import pipes

large = 5000000

class RunCmd(Thread):
  def __init__(self, cmd, timeout):
    Thread.__init__(self)

    self.cmd = cmd
    self.timeout = timeout

    return

  def run(self):
    self.p = Popen(args=self.cmd,
                   stdin=None,
                   stdout=PIPE,
                   stderr=STDOUT,
                   shell=True,
                   env=None,
    )
    return

  def Run(self):
    self.start()
    self.join(self.timeout)

    if self.is_alive():
      self.p.kill() # 9
      self.join()
      pass

    return self.p.stdout.read(large)
  pass

def application(env, start_response):
  tmpdir = None # on exception, we wipe state
  method = env["REQUEST_METHOD"].upper()
  if method == "POST":
    try:
      dat = env["wsgi.input"].read(max(env["CONTENT_LENGTH"], 400))
      dat = dat.split("location=", 1)[1]
      dat = dat.split("&", 1)[0]
      dat = unquote(dat)
      name = dat.split("/")[-1]
      [nonext, ext] = name.split(".", 1)

      tmpdir = mkdtemp(prefix="/tmp/585-")
      shutil.copytree("/home/frozencemetery/CTF2015/cs585hw1.hpp",
                      tmpdir+'/dat')
      os.chdir(tmpdir+'/dat')

      cmd = "curl -O --max-filesize 5000000 -k %s" % pipes.quote(dat)
      a = RunCmd(cmd, 2)
      a.Run()

      if name != "image.xpm":
        if ext != "xpm":
          a = RunCmd("convert %s image.xpm" % pipes.quote(name), 2)
          a.Run()
          os.remove(name)
          name = "image.xpm"
          pass
        else:
          d = open(name, 'r').read()
          d = d.replace(nonext, "image")
          os.remove(name)
          name = "image.xpm"
          with open(name, "wb") as f:
            f.write(d)
            pass
          pass
        pass

      os.chown(tmpdir+'/dat/image.xpm', 0, 1001)
      os.chmod(tmpdir+'/dat/image.xpm', 0o770)
      os.chown(tmpdir+'/dat/template.c', 0, 1001)
      os.chmod(tmpdir+'/dat/template.c', 0o770)
      os.chown(tmpdir+'/dat', 0, 1001)
      os.chmod(tmpdir+'/dat', 0o770)
      os.chown(tmpdir, 0, 1001)
      os.chmod(tmpdir, 0o770)
      os.chown(tmpdir+'/dat/key', 0, 1001)
      os.chmod(tmpdir+'/dat/key', 0o770)

      # from remote_pdb import set_trace
      # set_trace()

      a = RunCmd("su frozencemetery -c 'gcc template.c; ./a.out'", 2)
      a = a.Run()

      shutil.rmtree(tmpdir, ignore_errors=True)
      start_response("200 OK", [("Content-type", "text/xpm")])
      return [a]
    except:
      if tmpdir is not None:
        shutil.rmtree(tmpdir, ignore_errors=True)
        pass
      pass
  elif method == "GET":
    start_response("200 OK", [("Content-type", "text/html")])
    return ["""
<html><head>
  <title>Acme scrambling service</title>
</head><body>
  <form method="post" name="form">
    Where? <input name="location" type="text">
   <input name="Submit" type="submit" value="Submit">
  </form>
</body></html>
    """]

  start_response("402 pay me", [("Content-type", "text/plain")])
  return ["I wasn't paid enough to implement that method."]

http_server = WSGIServer(('', 80), application)
http_server.serve_forever()
