# CONFidence CTF Teaser So Easy

**Category:** Reverse Engineering
**Points:** 100
**Solves:** 144
**Description:**

> [Get the flag](re_100_final) (tested on Ubuntu 14.04.2 LTS).

## Write-up

At a high-level the program executed the following instructions in the main:

	char flag[32];
	char expected[] = "dRGNs{tHISwASsOsIMPLE}";
	char* output = "Nope.\n";

	puts("Please enter secret flag:");
	scanf("%31s", flag);

	// Some logic that switched uppercase character to lowercase character 
	// and lowercase character to uppercase character

	if (strcmp(flag, expected) == 0) {
		output = "Excellent Work!\n";
	}

	printf(output);
	exit(0);
	
This indeed really seemed simple, but when we entered ' DrgnS{ThisWasSoSimple}' , it returned `Nope.`. 

When digging a bit further, we can see that printf is hooked and it actually executes the code at the offset `0x0804873C`. In that function the flag we entered is actually compared to a value located at the offset `0x804B0A4`. Since the value generated at that offset seems to be generated at runtime, it was best just to place a breakpoint at `0x0804873C` and look in memory at the value stored at `0x804B0A4`. The value stored is `dRGNs{nOTeVENwARMEDuP}` and if we reverse the lowercase/uppercase switch process it gives us `DrgnS{NotEvenWarmedUp}`.

## Other write-ups and resources

* <http://capturetheswag.blogspot.com.au/2015/04/confidence-ctf-2015-so-easy-reversing.html>
