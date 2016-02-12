# FAUST CTF 2015: sell-your-soul

**Category:** Sell-Your-Soul
**Points:** 
**Solves:** 
**Description:**



## Write-up

by [fluxchief](https://github.com/fluxchief)

The first step was obviously figuring out, what was going on, so we had two POIs, the jobserver and the buildroot.tar.

### Jobserver
The jobserver is some self-decrypting python file, it basically executes an embedded .pyc file. The 'hard' part here was to decompile the pyc file as it was written in python3 and the header was unknown to the py3 decompilers. After some patching and modifying the decompiler, we got most of the original python file.
The script received incoming connections, generates a deterministic hash (the one shown in the webinterface) and added the jobs to a queue. Each job had a 120s delay before starting.

Upon running the job, the jobserver will unpack buildroot.tar to a temporary directory, drop *all* flags + the hash and run make in the directory.


### Buildroot.tar
There is a Makefile, one 64bit c++-ELF (transform) and a pdf directory with a lot of .tex and one avr .hex program. After having a brief look at the ELF we simply skipped it as it seems that it just appends some information to the pdf, so we digged deeper in the tex-files.

The pdf folder contains a couple of `avr.*.tex` files, one `main.tex` and a `checker.c.hex` - It emulates a avr-binary using [avremu](https://gitlab.brokenpipe.de/stettberger/avremu/tree/master) in order to generate the pdf.
The binary loaded one flag via UDR (Serial communication), calculated a hash and then wrote the output to UDR again - looks familar. If we have a look at the `pdf/main.tex`, the remaining part becomes obvious:

	Your Hash:
	\makeatletter
	\newread\myread
	\def\readchallenge#1{%
	    \endlinechar=-1
	    \openin\myread=#1
	    \readline\myread to \challenge%
	    \closein\myread
	}
	\def\process#1{%
	    \endlinechar=-1
	    \openin\myread=#1
	    \@whilesw\unless\ifeof\myread\fi{%
	        \readline\myread to \dataline%
		    \ifdefempty{\dataline}{}{
	            \xdef\avrUDRin{\dataline}
	            \avrloadihex{checker.c.hex}
	            \avrrun
	        	\typeout{Challenge: '\challenge' Hash: '\avrUDR' Flag: \dataline'}
	        	\csxdef{flag@\avrUDR}{\dataline}
	        	\avrreset
		   }
	    }%
	    \closein\myread
	}%
	\makeatother

	\readchallenge{challenge}
	\process{flags}
	\csuse{flag@\challenge}

It reads the challenge + all flags and runs the emulator for each flag.
The application then generates a hash and stores it in `\avrUDR` and defines `flag@\avrUDR` = `\flag`. At the end, it prints the variable `flag@\challenge`, which contains the hash calculated by the buildserver. So the theory is it only prints the flag where the hash matches, so where is the bug?

### The "bug"
In `avr.instr.txt` are a couple of instructions defined, one of them is `\avrreset`:

	\newcommand{\avrreset}{%
	  \avr@keyboard@plugoff
	  \pdfannot
	  {
	    /Subtype /Text
	    /Contents (Resetted)
	    /MyVar AVR-Reset-done\avr@keyboard@plugin
	    }%
	 }

This code does not only plug the keyboard off and on again (;)), but it also annotates some PDF comments. Why would it do this? So let's have a look at `\avr@keyboard@plugin`:

	\def\avr@keyboard@plugoff{
		\edef\@tmp{\avrUDR}
		\edef\avr@keyboard@plugin{\expandafter\avr@keyboard@reset\@tmp\@nnil}
	}
	\def\avr@keyboard@plugin{eDRnil}
	\def\avr@keyboard@reset#1#2#3#4#5#6#7#8\@nnil{:#1:#2:#3:#4:#5:#6:#7:#8}

It looks like some override-thingy is going on, doing something with the `UDR` register - wait, that's the hash, right?

So the code generates for each flag a `AVR-Reset-done` tag with 8 nibbels appended - 4 bytes - the hash for each flag. These tags are stored in *EVERY* pdf.

### Exploiting
Straight forward:
 - Offer Satan your soul
 - Obtain your pdf
 - Get the 4 bytes hash for each flag
 - Download all the pdf's
 - ...
 - Profit
 - Repeat each round

## Other write-ups and resources

* none yet
