# Cyber Security Challenge 2015: Wardriving

**Category:** Digital Forensics
**Points:** 15
**Description:**

> You managed to perform a MiTM (Man-in-The-Middle) attack on a wifi network while wardriving. You know that one of the residents here uses one password for all his/her accounts, including online games. Find the password that he/she used on Tribal Wars.
>
> [`online_game.pcap`](online_game.pcap)

## Write-up

Let’s open [`online_game.pcap`](online_game.pcap) in Wireshark, and look for Tribal Wars traffic by entering the filter `http.host contains tribalwars`. This reveals a `POST` request (frame 6641) containing the login credentials. The username is `Falken` and the password is `Joshua` — another [WarGames](https://en.wikipedia.org/wiki/WarGames) reference!

## Other write-ups and resources

* none yet
