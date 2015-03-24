# Insomni'hack CTF 2015 - Network - Time to leak

I have his IP address so I can locate the suspect in a 10cm area... But I'm
sure there's a way of remotely extracting the flag from his computer. Maybe
reverse scripting the packets with the custom Trojan can do the trick. But
he has a 7th generation firewall so I may fail... If only as was half as
31337 as the guy who did this.... Maybe I should try to reproduce it.
Author : SaD - Difficulty : easy

# Files

* timetoleak_6b4a37c1ec58d7d49e5d636b063ad3b6.pcapng

The pcap file contains 22 packets of IP/ICMP traffic in which host
10.13.37.206 is ping'ed. The host selectively replies to echo requests.
The echo requests have varying TTL values in the domain of printable
ASCII characters. The flag is encoded as a sequence of characters in the 
TTL value. The first four characters are guessable: ```INS{```, this
corresponds to four echo requests with according TTL values: 73, 78, 83,
123, each of which are aknowledged by an echo reply. The next characters
must be guessed. The host does not reply to the echo request when using
a wrong character. Therefore, for each guess, the sequence must be sent
again from the beginning. The resulting flag is:

    INS{time_to_leak_is_trendy_this_year}

