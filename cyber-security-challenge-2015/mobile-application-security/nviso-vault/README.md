# Cyber Security Challenge 2015: Nviso Vault

**Category:** Mobile Application Security
**Points:** 50
**Description:**

> One of our programmers made a Vault that is used to store sensitive information. He says it’s safe, but come on, the application *must* be leaking information somewhere… right?
>
> [`NvisoVault.apk`](NvisoVault.apk)

## Write-up

First, create an emulator (like Google's AVD or Genymotion) and install the application.
```
ComputerJ:NvisoVault jbeckers$ adb install -r NvisoVault.apk 
7869 KB/s (109363 bytes in 0.013s)
	pkg: /data/local/tmp/NvisoVault.apk
Success
ComputerJ:NvisoVault jbeckers$ 
```
When we launch the application, it counts down from 10 and displays a bunch of random symbols.

The easiest way to solve this challenge is to run strace on the application. In order for strace to work, you need to know the PID, so let's get that first:
```
ComputerJ:NvisoVault jbeckers$ adb shell
root@vbox86p:/ # ps | grep vault                                               
u0_a59    2568  1240  579356 39396 ffffffff b76cc07b S be.nviso.nvisovault
```
Next, we have to attach strace. Note that this has to be done within the first 10 seconds of starting up the application, or else you'll be too late.

```
root@vbox86p:/ # ps | grep vault                                               
u0_a59    2605  1240  575216 36544 ffffffff b76cba23 S be.nviso.nvisovault
root@vbox86p:/ # strace -p 2605
Process 2605 attached - interrupt to quit
clock_gettime(CLOCK_MONOTONIC, {1735, 201662416}) = 0
...
access("Decoding data with password ?\200\230I_love_panda_bears?\200\231", F_OK) = -1 ENOENT (No such file or directory)
...
```
Which is the flag: `I_love_panda_bears`

## Other write-ups and resources

* none yet
