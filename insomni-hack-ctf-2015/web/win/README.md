# Insomni'hack CTF 2015: n00bs gonna win!

**Category:** Web
**Solves:** 56
**Description:** 

(TODO)

## Write-up

This was a very easy challenge that most participants solved. We were being
asked to vote for the best hacking movie - selecting one movie from a
dropdown list. It seems that all votes end up with the output "Seriously?!
You think that's the best hacking movie?! You definitely missed one!".
However, having a look at the HTML source we notice this:

	 <option value="21">The Italian Job</option>
	 <!-- <option value="42">The Matrix</option> -->
	 <option value="22">The Net</option>

Just guessing ;P, we vote for 42:

     $ curl http://10.13.37.121/?best_hacking_movie=42

and success, that's our first flag:

    <h2>Yay !</h2>
    <p>Congrats! Your taste for hacking movies is as good as your hacking skills</p>
    <p>INS{No one can be told what the Matrix is. You have to see it for yourself.}


## Other write-ups and resources

* none yet