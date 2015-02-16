# BreakIn CTF 2015: Serial Killer

**Category:** Forensics
**Points:** 300
**Description:**

> Police has gotten hold of computer of a serial killer. He managed to delete most of his user data, but they were hopeful that they may still be able to track him down and they actually did predict the exact location and time of his next strike and stopped him. Now they use this challenge for recruitment. You are given the exact same data you have to tell what was the planned place and time of the killer's strike.
>
> The answer format : flag{date,lat,log}
>
> date -> dd:mm:yyyy
>
> lat long should be till 6 decimal places.
>
> Example : flag{01:01:0101,01.010101,01.010101}
>
> [Dowload Link (SerialKillerInvestigation.tar.gz)](SerialKillerInvestigation.tar.gz)

## Write-up

First, we extract the gzip-compressed archive using `tar xzvf SerialKillerInvestigation.tar.gz` and see that it contains a home directory of the user `berch`:

```bash
$ ls -al berch
drwx------@ 19 XXX  wheel  646 Feb 14 16:44 ./
drwxr-xr-x   4 XXX  wheel  136 Feb 16 01:55 ../
-rw-------@  1 XXX  wheel  632 Feb 14 14:05 .ICEauthority
drwx------@  3 XXX  wheel  102 Feb 14 14:14 .adobe/
-rw-------@  1 XXX  wheel   61 Feb 14 14:07 .bash_history
-rw-r--r--@  1 XXX  wheel   21 Aug 25  2013 .bash_logout
-rw-r--r--@  1 XXX  wheel   57 Aug 25  2013 .bash_profile
-rw-r--r--@  1 XXX  wheel  141 Aug 25  2013 .bashrc
drwxr-xr-x@  9 XXX  wheel  306 Feb 14 14:08 .config/
drwx------@  3 XXX  wheel  102 Feb 14 13:55 .dbus/
-rw-------@  1 XXX  wheel   16 Feb 14 13:55 .esd_auth
drwx------@  3 XXX  wheel  102 Feb 14 13:55 .local/
drwx------@  3 XXX  wheel  102 Feb 14 14:14 .macromedia/
drwx------@  4 XXX  wheel  136 Feb 14 14:06 .mozilla/
-rw-------@  1 XXX  wheel   34 Feb 14 16:38 .sqlite_history
-rw-r--r--@  1 XXX  wheel  312 Dec  9  2013 .xinitrc
-rw-r--r--@  1 XXX  wheel  100 Dec  9  2013 .xsession
drwxr-xr-x@  2 XXX  wheel   68 Feb 14 14:06 Desktop/
drwx------@  8 XXX  wheel  272 Feb 14 16:17 Downloads/
```

We have a look inside the `.bash_history` as well as the `.sqlite_history`:

```bash
$ cat .bash_history
ls -a
cd .mozilla/
ls
cd firefox/
ls
cd ot9rmdnk.default/
ls
$ cat .sqlite_history
.tables
select * from moz_places;
```

So this hints that we have to look at the mozilla `places.sqlite` SQLite3 Databse, with `moz\_places` being a table in this db. Let's `cd` to it and have a look at the different tables:

```bash
$ cd .mozilla/firefox/ot9rmdnk.default/
$ sqlite3 places.sqlite <<< '.tables'
moz_anno_attributes  moz_favicons         moz_items_annos
moz_annos            moz_historyvisits    moz_keywords
moz_bookmarks        moz_hosts            moz_places
moz_bookmarks_roots  moz_inputhistory
```

Now, let's repeat the sqlite command from the `.sqlite\_history` file and see what we get:

```bash
$ sqlite3 -cmd '.headers ON' places.sqlite <<< 'select * from moz_places;'
id|url|title|rev_host|visit_count|hidden|typed|favicon_id|frecency|last_visit_date|guid
1|https://www.mozilla.org/en-US/firefox/central/||gro.allizom.www.|0|0|0||137||QO-VikH8PZr4
2|https://www.mozilla.org/en-US/firefox/help/||gro.allizom.www.|0|0|0|1|137||23iTj4UgMd3y
3|https://www.mozilla.org/en-US/firefox/customize/||gro.allizom.www.|0|0|0|2|137||EVOErRlfgYg4
[...]
612|https://www.google.co.in/search?q=goa&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb&gfe_rd=cr&ei=mmvfVJTjNcqW8Qf8sYD4BA|goa - Google Search|ni.oc.elgoog.www.|1|0|0|5|100|1423928169572529|9WDI9q2mHAdt
613|https://www.google.com/search?q=police+nehind+where+to+hide+hyderabad&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb||moc.elgoog.www.|1|1|0||100|1423928194103894|gWWrougtKwcc
614|https://www.google.co.in/search?q=police+nehind+where+to+hide+hyderabad&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb&gfe_rd=cr&ei=s2vfVP-6H8qW8Qf8sYD4BA|police nehind where to hide hyderabad - Google Search|ni.oc.elgoog.www.|1|0|0|5|100|1423928194227435|yz-yHoVFmY8u
615|https://www.google.co.in/search?q=police+nehind+where+to+hide+hyderabad&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb&gfe_rd=cr&ei=s2vfVP-6H8qW8Qf8sYD4BA#rls=org.mozilla:en-US:official&channel=sb&q=hiding+place+hyderbad|hiding place hyderbad - Google Search|ni.oc.elgoog.www.|1|0|0|5|100|1423928217992935|5Ha-sjjfh6Ey
```

Well, these google search entries look promising, let's select all titles that indicate what the user searched for:

```bash
$ sqlite3 -cmd '.headers ON' places.sqlite <<< 'select id,title from moz_places;'
id|title
1|
2|
[...]
604|security conferences india - Google Search
605|
606|Asian Security Conference 2015
607|Asian Security Conference 2015
608|cyber security conferences in india - Google Search
609|cyber security conferences in india 2015 - Google Search
610|
611|
612|goa - Google Search
613|
614|police nehind where to hide hyderabad - Google Search
615|hiding place hyderbad - Google Search
```

So his last searches were where to hide in hyderabad, india and some security conferences. Besides that, he downloaded and searched for visa application forms, which are located at `berch/Downloads`.

At this stage, we might think that he wants to assassinate someone at a conference, e.g. the nullcon/goa conference in India, which the last searches suggest.

If we `grep` the db entries for nullcon or goa, we get
```bash
$ sqlite3 places.sqlite <<< 'select * from moz_places;' | grep -iE '(nullcon|goa)'
81|https://www.google.co.in/maps/@52.5574402,31.4575282,7z|nullcon - Google Maps|ni.oc.elgoog.www.|1|0|0|15|100|1423920465333719|YSh-eoywAoBV
82|https://www.google.co.in/maps/search/nullcon/@52.5574402,31.4575282,7z|defcon - Google Maps|ni.oc.elgoog.www.|1|0|0|15|100|1423920466511530|surdFuuZ90Ac
590|https://www.google.com/search?q=nullcon&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb||moc.elgoog.www.|1|1|0||100|1423928033306733|sL2qujRDPqLX
594|http://nullcon.net/||ten.nocllun.|1|1|0||100|1423928045857218|NV1E1o5TCVrB
595|http://nullcon.net/website||ten.nocllun.|1|1|0||100|1423928046127594|B-ETEgLc1tzl
611|https://www.google.com/search?q=goa&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb||moc.elgoog.www.|1|1|0||100|1423928169451852|Z7zFZBZie6SM
612|https://www.google.co.in/search?q=goa&ie=utf-8&oe=utf-8&aq=t&rls=org.mozilla:en-US:official&client=firefox-a&channel=sb&gfe_rd=cr&ei=mmvfVJTjNcqW8Qf8sYD4BA|goa - Google Search|ni.oc.elgoog.www.|1|0|0|5|100|1423928169572529|9WDI9q2mHAdt
```

We see some google map searches with their respective latitude/longitude coordinates (right after the `@` symbol), but these do not point anywhere near India.

So we manually search for the location of the nullcon conference, which happens to be the location of last years nullcon conference - [The Bogmallo Beach Resort](https://www.google.de/maps/place/Bogmallo+Beach+Resort/@15.368603,73.835396,15z).

Having in mind (by visiting the [nullcon website](http://nullcon.net/website/)) that the conference is scheduled for 4 days...

![](dates.png)

...we try every date combination and finally get the flag `flag{05:02:2015,15.368603,73.835396}`.

## Other write-ups and resources

* none yet
