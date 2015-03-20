# Impromptu GET 

**Category:** Web
**Points:** 65
**Author:** 
**Description:**

>Jonathan cloned our router online access page again... Model number BRL-04FXP by bRoad Lanner. Except there's been a slight issue, he didn't copy any of the elements on the page used to login and we lost the username and password, but there's some sensitive data we need to recover.
>
>Luckily it uses GET. So now it looks like we'll have to just pass the ```username```
> and ```password``` parameters manually. But, we just don't know the username and password...
>
>I'll hand you the [link](http://compete.sctf.io/problems/2015q1/impromptuget.php), maybe you can figure it out.

## Writeup

Going to the link the user will be greeted by a simple ```Incorrect.``` message. Following the information given by the problem, the user had to come up with a method to log-in to the page utilising PHP's GET.

>http://compete.sctf.io/problems/2015q1/impromptuget.php?username=&password=

We don't know what the usename or password was though. Looking in the problem again, they give us the router, which could be important. Researching the router given, ```BRL-04FXP by bRoad Lanner default password```, the user would find the default username to be ```blank``` and password ```0000```.

>http://compete.sctf.io/problems/2015q1/impromptuget.php?username=blank&password=0000

The page would now return:

> flag: getting_is_fun

## Flag

>getting_is_fun

## Other write-ups and resources
