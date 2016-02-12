# Hack Dat Kiwi CTF 2015: Leet Maze

**Category:** Forensics
**Points:** 250
**Solves:** 39
**Description:**

> We found a malware that communicates with track.dat.kiwi, however, there's nothing on track.dat.kiwi! It appears that they have established a complicated network of DNS records to point to the C&amp;C server.
> 
> 
> It's basically like CNAME, the software follows track.dat.kiwi to find out the target server. However, there are some caveats.
> 
> 
> <strong>Hint:</strong> To send a DNS request to a particular server for a particular record type, you can use the tool <strong>dig</strong> that comes with BIND like this:
> 
> 
> `dig @server track.dat.kiwi TXT`


## Write-up

by [polym](https://github.com/abpolym)

We are given a domain name `track.dat.kiwi`, which DNS TXT record we have to read, according to the description.

This can be done using `dig` as the description suggests or `python` with the `dns` module.

The former can be done as the description suggests and the latter like [this writeup suggests](http://edholabs.ga/ctf_writeups/Leet_Maze.txt).

Each TXT record then gives you another domain name, which you have to query for its TXT record again - rinse and repeat.

In the end, all TXT records form some sort of maze of domain names.

Some domain names look like leet speak, such as `G|2IP5/-C]{.dat.kiwi` and you have to "de-leet" it before querying its TXT record.

Finally, the flag (`8410393`) is hidden in one of these TXT records:

    FLAG:"The key is: 8410393"

## Other write-ups and resources

* <http://edholabs.ga/ctf_writeups/Leet_Maze.txt>
* <http://hack.dat.kiwi/writeup#Leet_Maze>
