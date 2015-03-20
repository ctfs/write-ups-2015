# Deceptive Ports 

**Category:** Pwnable
**Points:** 120
**Author:** 
**Description:**

>python.sctf.io:25565

## Writeup
We start this problem by accessing the port. 
Once we jump in, we are asked "Are you ready to rumble?" 
No matter your answer, the battle begins and we face our first enemy, SLUG!
After beating SLUG, we continue to face enemies until we reach SID, who has 5 attack compared to our 2.
Losing to SID is inevitable, and the game over screen gives us our hint. "If only you were invincible like Boss"
Hmmm... There isn't any obvious way to legitimately beat SID, so we have to cheat >:D
(http://en.wikipedia.org/wiki/Glossary_of_video_game_terms)

>"WIKIPEDIA HOW CAN I BE INVINCIBLE"

>"USE GODMODE"

We studiosly type ```godmode``` in our next game, and we get +99999999 health! 
Beating all the bosses is trivial, and after beating the final boss, BOSS HOSS, we get the flag.

## Flag
>godmode_is_best

## Other write-ups and resources
