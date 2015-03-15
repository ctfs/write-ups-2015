# Boston Key Party CTF 2015: Mattapan

**Category:** Pwning
**Points:** 150
**Solves`:** 33
**Description:**

> (UPDATED!) We have come across an OpenFlow switch. Maybe you could pwn the traffic for us? nc 54.88.69.118 8888 or nc mattapan.bostonkey.party 8888 : 150

## Write-up

Mattapan Writeup
By: Dogshep - #jmp-esp

Summary:

This challenge required a basic use of SDN (Software Defined Networking). Basically you told the server to set up a switch and connect to your controller at a set IP address at port 3366.

Walkthrough:

1. Netcat to 54.88.69.118 8888 or mattapan.bostonkey.party 8888 (Furst created a mirror since things were going rather slowly for the first one.
2. Enter in the answer to the Park Street Challenge (easy enough to Google the other challenge)
3. Enter the IP address for the BKP switch to connect to for it's controller (don't use 8.8.8.8. you don't own 8.8.8.8)
4. You'll notice that the challenge says it's booting up a switch and connecting, and that you'll have seconds to program the switch before it starts sending data then kills itself.
5. If you have your controller set up correctly it will accept the switch, set it up simply, and accept all traffic to the controller (see instructions on setting up controller below)
6. Once the controller is accepting traffic, you can sniff it with tcpdump/wireshark/etc
7. Grabbing the data and following the basic tcp stream, you can see the flag in the garbled mess

Setting up NOX (Openflow controller):

<http://archive.openflow.org/wp/deploy-labsetup/#OpenFlow_Controller_NOX_0_6>

1. Follow the above to set up a normal controller and get it running so you can launch it.
2. Run `./nox_core -i ptcp:6633 switch`
   * This will set up an openflow controller on 6633 and the switch syntax runs a basic switch module so the switch can actually send data when it connects
   
If you have any questions/concerns please contact me on freenode as dogshep, or dogshep {at} gmail { dot } com.

## Other write-ups and resources

* <https://github.com/pwning/public-writeup/blob/master/bkp2015/pwn150-mattapan/writeup.md>
