#!/usr/bin/env ruby

require 'sinatra/base'
require 'sinatra/cookies'
require 'openssl'
require 'json'

KEY = IO.binread('super-secret-key')
FLAG = IO.read('/home/simple/flag').strip

class SimpleApp < Sinatra::Base
  helpers Sinatra::Cookies

  get '/' do
    auth = cookies[:auth]
    if auth
      begin
        auth = auth.b
        c = OpenSSL::Cipher.new('AES-128-CFB')
        c.decrypt
        c.key = KEY
        c.iv = auth[0...16]
        json = c.update(auth[16..-1]) + c.final
        r = JSON.parse(json)
        if r['admin'] == true
          "You're admin! The flag is #{FLAG}"
        else
          "Hi #{r['username']}, try to get admin?"
        end
      rescue StandardError
        'Something wrong QQ'
      end
    else
      <<-EOS
<html><body><form action='/' method='POST'>
<input type='text' name='username'/>
<input type='password' name='password'/>
<button type='submit'>register!</button>
</form></body></html>
      EOS
    end
  end

  post '/' do
    username = params['username']
    password = params['password']
    if username && password
      data = {
        username: username,
        password: password,
        db: 'hitcon-ctf'
      }
      c = OpenSSL::Cipher.new('AES-128-CFB')
      c.encrypt
      c.key = KEY
      iv = c.random_iv
      json = JSON.dump(data)
      enc = c.update(json) + c.final
      cookies[:auth] = iv + enc
      redirect to('/')
    else
      'Invalid input!'
    end
  end
end
