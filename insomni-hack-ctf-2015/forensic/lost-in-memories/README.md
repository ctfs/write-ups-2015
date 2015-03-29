# Insomni'hack CTF 2015: Lost In Memories

**Category:** Forensic
**Solves:** 26
**Description:** 

> You can download a memory image from an compromise host.
> In this challenge, you have to find the flag which is composed of 2 parts:
> - One part is available in the memory image.
> - Another part is available in another host (maybe a CnC...).
> 
> Image available from: Download Image
> Author : Benoit - Difficulty : easy

## Write-Up

This one provides a memory image
(WIN-DEA2KM5I93L-20150318-151408_e93e1b0d01e0b5c4d5985254e94b958e.7z, 303MB)
and tells us the flag is composed of 2 parts, one in the memory image, and
another one available on another host "maybe a CnC".

We unzip the file and get a 1.5GB of raw data according to 'file'. However,
the data is full of strings. As CTF flags follow the format INS{xxxxx} and
we know the flag is cut in 2 parts, we grep the data for 'INS{'. We are
unlucky. Then, the text mentions a remote server, so we grep for interesting
URLs on the local network (Insomni'hack is an 'offline' CTF - only those
physically present can play). The local network starts by 10.x.x.x:

	$  strings WIN-DEA2KM5I93L-20150318-151408.raw | grep http://10
           http://10.13.37.117/oyekv5ty9tQj/


When we try to visit this URL, the server complains we haven't provided
username/password credentials. So, this looks like the right URL, but we
need to search a bit better.
We are going to look for potential username or password located close to the
URL string:

    $  strings WIN-DEA2KM5I93L-20150318-151408.raw | grep -C 5 http://10


And this time, we are lucky to spot:

    http://johntheslayer:H!66q5p6F$8z8Z*D8gkB@10.13.37.117/oyekv5ty9tQj711.73.31.01.


This corresponds to the syntax http://username:password@server. There are
some additional garbage characters after oyekv5ty9tQj/ . We won't care for
those.
We cannot directly request such a URL though because characters such as ! or
$ need to be encoded (reciprocally %21 and %24). We visit the URL which
provides a link to a file named flag.txt. Let's open that! It says:

	 # Well done, you find the first part of the flag
	 INS{memory_dump_provided_by


Right, so that's why our first search for INS{ did not succeed: the first
part of the flag was provided on the CnC and the second part of the flag is
in the raw image. So, we should rather search for something that ends with
xxx}. We notice that the first part of the flag has several lowercase words
separated by underscores, so we search for _xxx} where xxx are lowercase
characters or digits.

	   $ strings WIN-DEA2KM5I93L-20150318-151408.raw | grep -E '_[a-z0-9]*}' | more
	   ...
	   The second part of the flag is: _by_CSI_drama_series}


Note we are lucky, because acually the flag contained some uppercase
characters so my reasoning was wrong, but the grep worked nonetheless ;)

Finally, the flag is

       INS{memory_dump_provided_by_by_CSI_drama_series}

Oh no! That doesn't work! So we try

       INS{memory_dump_provided_by_CSI_drama_series}

and that works :)

## Other write-ups and resources

The image is splitted in blocks of 100M because of github limitations.
The resulting image is WIN-DEA2KM5I93L-20150318-151408_e93e1b0d01e0b5c4d5985254e94b958e.7z with sha256

f39aff9d45911160c2ca9b8b2394ac62324b288752de264619cf3c9aeb8516e7

[French](http://snipefoo.blogspot.fr/2015/03/insomnihack-2015.html?m=1)