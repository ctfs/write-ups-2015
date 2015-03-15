# Boston Key Party CTF 2015: Wellington

**Category:** Reversing
**Points:** 250
**Solves:** 57
**Description:**

> If you had the code, you'd see that the program is calling `decrypt("[QeZag^VQZShWQgeWVQSe]ZW^^Q[`efWSV", X). Unfortunately, you don't have it, HAHAHAHAHAHA. Ho, and by the way, the flag ends with a dot. : 250

## Write-up

This writeup is similar and somewhat based on [this remote writeup](https://github.com/noobdoesre/write-ups/tree/master/boston-key-party-2015/wellington).

After finding out that we are given an ELF file, We first use `strings` and `grep` to find suspicious strings:

```bash
$ strings -a troll_log.4643d195d55746aa180abf7144909677 | igrep flag
flag_value
prolog_flag
$use_flag
/home/diaz/GP/src/src/BipsPl/flag.pl
current_prolog_flag
set_prolog_flag
flag_c.c
```

We see that there are Prolog files, probably from a Gnu Prolog variant [implementation](http://code.metager.de/source/xref/gnu/gprolog/1.4.2/src/BipsPl/).
This is also consistent with the hint that the flag ends with a dot `.`, since prolog statements end with a dot.

So we run the program:

```bash
$ chmod u+x troll_log.4643d195d55746aa180abf7144909677
$ ./troll_log.4643d195d55746aa180abf7144909677
BKP 2015 - Troll_log
Password:
```

We have to insert a password. After some testing, we see that some input (e.g. `X.`), does result in a `WiN` text and others do result in `LOSE`.

However, if you type in a multiline input, the program breaks and you are greeted with a prolog interpreter message:

```bash
$ ./troll_log.4643d195d55746aa180abf7144909677
BKP 2015 - Troll_log
Password: No
Pe
.

system_error(cannot_catch_throw(error(syntax_error('user_input:2 (char:1) expression expected'),read/1)))
warning: /home/jvoisin/prez/BKP2015/main.pl:19: user directive failed
GNU Prolog 1.3.0
By Daniel Diaz
Copyright (C) 1999-2007 Daniel Diaz
| ?- 
```

Pressing <kbd>Tab</kbd> twice, we see several procedures and terms, e.g. `flag`, `decrypt`, `LOSE` etc.

Though several procedures won't run with or without arguments, we can run the decrypt function:

```bash
[...]
| ?- decrypt("[QeZag^VQZShWQgeWVQSe]ZW^^Q[`efWSV", X).

X = [105,95,115,104,111,117,108,100,95,104,97,118,101,95,117,115,101,100,95,97,115,107,104,101,108,108,95,105,110,115,116,101,97,100]
```

This looks like decimal ASCII values, so let's print them as characters:

```bash
$ python
[...]
>>> X = [105,95,115,104,111,117,108,100,95,104,97,118,101,95,117,115,101,100,95,97,115,107,104,101,108,108,95,105,110,115,116,101,97,100]     
>>> print ''.join([chr(x) for x in X])
i_should_have_used_askhell_instead
>>> 
```

The flag is `i_should_have_used_askhell_instead`.

## Other write-ups and resources

* <https://github.com/noobdoesre/write-ups/tree/master/boston-key-party-2015/wellington>
* <http://wiremask.eu/boston-key-party-2015-wellington/>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-wellington.html)
