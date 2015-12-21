# School CTF Winter 2015: Voting fraud

**Category:** Web
**Points:** 400
**Solves:** 
**Description:**

> Hey! We heard you are good at hacking. We have a deal for you: we are interested in victory of our candidate in that voting. Lead "Swift" to win, every proof will be awarded!
> 
> <http://sibears.ru:10024/>
> 
> 
> <http://sibears.ru:12024/>
> 
> 
> <http://sibears.ru:13024/>


## Write-up

<div><h3>Voting fraud</h3><p>You need to lead Swift to win, so you need to know in what way service authorizes every vote. Looking to the network requests in developer tools (F12) or in Wireshark we can find out that it uses custom HTTP header <code>X-Vote-Sid</code>. </p>
<p>According to javascript <code>custom.js</code> its value is accured from input <code>$("#vote-ssid")</code> and seems random. So we should try to send a request with a value that looks exactly the same as given but little bit different, e.g. just change the last character.</p>
<p>The vote will be accepted, so now we can forge votes and lead Swift to win.</p>
<p>That task also has more tricky way to solve. Occasionly we can find out that votes are generated only if client is asking for this. So no checks from client = no votes. We just need to start voting, vote once for Swift and wait for its end.</p></div>

## Other write-ups and resources

* none yet
