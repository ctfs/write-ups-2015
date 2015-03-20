# strpos

**Category:** Web
**Points:** 45
**Author:** 
**Description:**

>[Try this one...](http://compete.sctf.io/problems/2015q1/jz/main.php)

## Writeup

Loading the website the user is greeted by an empty PHP page. Checking the source, one would find the following:

```php

<!--

CODE BACKUP ©SCTF CORPORATION EVEN THO WE AINT A CORPORATION:

$a = $_GET["plang"];
if(isset($a)) {
	if(strpos($a,"answer") !== false && strlen($a) < 2) {
		echo $flag;
	} else {
		echo "Sadly, yee hath given bad input.";
	}
}

-->

```

After analysing the code the user would figure the PHP script utilises a GET tag called ```plang```, and the statement in which the user must break to retrieve the flag is the following:

```php
if(strpos($a,"answer") !== false && strlen($a) < 2)
```

After some Googling it's found what ```strpos``` and ```strlen``` does:

>strpos — Find the position of the first occurrence of a substring in a string.

>strlen — Get string length.

The issue becomes evident. The variable submitted through ```plang``` must contain the string ```answer```, but must also be smaller than length ```2```, which is technically impossible. After some Googling on PHP variables and exploits, it's found that the compare statement ```==``` is (for lack of better terms) broken.

Simply running an array through ```plang``` one would validate both conditions within the if statement.

>http://compete.sctf.io/problems/2015q1/jz/main.php?plang[]

The following is displayed:

> arrays_and_strings

##Flag

>arrays_and_strings

## Other write-ups and resources