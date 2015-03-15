# Cyber Security Challenge 2015: Reverse That App

**Category:** Mobile Application Security
**Points:** 20
**Description:**

> We have intercepted a malicious Android binary, and we need your help analyzing the application! Reports from the wild say that this piece of malware is sending text messages to a premium number, resulting in a huge phone bill for the victims! This needs to stop… Can you identify the mobile number of the attacker so we can track him down? Answer in this format: `+XX XXX XXX XXX`
>
> [`Kbank.apk`](Kbank.apk)

## Write-up

After decompiling [`Kbank.apk`](Kbank.apk) you can find the the answer in the following class: ```src\com\fake\site\sms\sms.java```. The following variable contains the solution:

```java
public static final String NUMBER = "+79163525068";
``` 

## Other write-ups and resources

* none
