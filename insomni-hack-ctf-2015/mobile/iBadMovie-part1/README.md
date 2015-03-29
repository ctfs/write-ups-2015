# Insomni'hack CTF 2015: iBadMovie Season 1

**Category:** Mobile
**Solves:** 40
**Description:** 

> Hi HackLady,
> 
> Just found this strange app in the AppStore. Maybe, it was created by CIA to hide some important secrets. It says that it is protected by snowden-grade encryption, so I need your help to crack it and find the password.
> 
> I give you the application and a copy of the folders I see on my device.
> 
> IMPORTANT: You can solve this challenge with an iDevice but also WITHOUT. No need to be apple-addictive

## Write-up

We are given a zip file which contains an iOS application and 'a copy of folders on the device' (iExplorer path):

```
39836648  2015-03-07 00:26   iBadMovie.ipa
        0  2015-03-12 15:12   iExplorer/
        0  2015-03-12 15:12   iExplorer/Documents/
        0  2015-03-12 15:12   iExplorer/Library/
        0  2015-03-12 15:12   iExplorer/Library/Caches/
        0  2015-03-12 15:12   iExplorer/Library/Caches/LaunchImages/
        0  2015-03-12 15:07   iExplorer/Library/Caches/LaunchImages/ch.scrt.iBadMovie/
        0  2015-03-12 15:12   iExplorer/Library/Caches/Snapshots/
        0  2015-03-12 15:12   iExplorer/Library/Caches/Snapshots/ch.scrt.iBadMovie/
        0  2015-03-12 15:12   iExplorer/Library/Caches/Snapshots/ch.scrt.iBadMovie/ch.scrt.iBadMovie/
        0  2015-03-12 15:07   iExplorer/Library/Caches/Snapshots/ch.scrt.iBadMovie/ch.scrt.iBadMovie/downscaled/
        0  2015-03-12 15:07   iExplorer/Library/Preferences/
      103  2015-03-06 16:09   iExplorer/Library/Preferences/ch.scrt.iBadMovie.plist
        0  2015-03-12 15:12   iExplorer/tmp/
        0  2015-03-12 15:07   iExplorer/tmp/MediaCache/
```
Basically, there are only two files to inspect: the property list ch.scrt.iBadMovie.plist, or the application itself, iBadMovie.ipa. The property list is a binary property list. With [plutil.pl](http://scw.us/iPhone/plutil/), we convert it to text format:

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>key</key>
	<string>QmxhY2toYXQ=</string>
	<key>password</key>
	<string>SU5Te1RBWUxPUl9TV0lGVH0=</string>
</dict>
</plist>
```

The strings are base64 encoded. We decode:

```
$ echo "SU5Te1RBWUxPUl9TV0lGVH0=" | base64 -d
INS{TAYLOR_SWIFT}
```
This is our first flag.

## Other write-ups and resources

[French](http://snipefoo.blogspot.fr/2015/03/insomnihack-2015.html?m=1)
* iBadMovie_66b262caf64ba8d44d84fea63e750d4f.zip