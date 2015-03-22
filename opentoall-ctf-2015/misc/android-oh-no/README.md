# OpenToAll CTF 2015: Android Oh No!

**Category:** Misc
**Points:** 150
**Solves:** 14
**Author:** Eriner
**Description:**

> It seems someone got a hold of my phone and deleted some important files, and now my phone won't boot! I had an important app on there, maybe you can get it working! Here is an image of my phone...
>
> [http://public.givemesecurity.info/16b11191c1410cb0184a6edd08e9105a.tar.gz](http://public.givemesecurity.info/OTACTF-2015/16b11191c1410cb0184a6edd08e9105a.tar.gz)
>
> Hint: I've encrypted my custom app so no one can find the secretz! Thankfully, I uninstalled it before someone hacked my phone! Trouble is, I can't install it on my new phone! Can you help?

## Write-up

This challenge revolves around finding an encrypted apk, and then decrypting it to get the flag. The first place many people likely checked was in the app folder, located at `mnt/android-4.4-r2/data/app`.
The app found here is titled: `net.opentoall.flag.flag-1.apk`. This app is a red herring, and upon opening the app, it shows a picture of a red fish and says "I'm here to distract you".
This app was to be ignored, and had no useful information. It wasn't the encrypted app the challenge described.
<br>
In the user storage directory, `mnt/android-4.4-r2/data/media/0` the file
 `encrypted.nothingtoseehere.apk` can be found.
<br>

A shortcut, in this case, would be to use `find` to remove the burden of manual search:
> ```
> shell@android ~/ # find mnt/ -type f -iname "*.apk"
> mnt/android-4.4-r2/data/data/com.google.android.gms/app_dg_cache/1B1C47D6957F9C3F15E0130296C46C62216574DA/the.apk
> mnt/android-4.4-r2/data/app/net.opentoall.flag.flag-1.apk
> mnt/android-4.4-r2/data/media/0/encrypted.nothingtoseehere.apk
> mnt/android-4.4-r2/data/media/0/Download/flag.apk
> ```

Or,

```
shell@android ~/mnt/android-4.4-r2/data/media/0 # file encrypted.nothingtoseehere.apk
encrypted.nothingtoseehere.apk: data
```
<br>
It showing 'data' likely means that it is encrypted, as no known headers or magic numbers were found. Doing some searches, you may have found this:
http://nelenkov.blogspot.com/2012/07/using-app-encryption-in-jelly-bean.html
There are a few books about Android JB app encryption (i.e. "Android Security Internals") worth checking out.

<br>
The most important piece of information to glean from this page is:
<br>

> The --algo, --key and --iv parameters obviously have to do with encrypted apps, so before going into details lets first try to install an encrypted APK. Encrypting a file is quite easy to do using the enc OpenSSL commands, usually already installed on most Linux systems. We'll use AES in CBC mode with a 128 bit key (a not very secure one, as you can see below), and specify an initialization vector (IV) which is the same as the key to make things simpler:

> ` $ openssl enc -aes-128-cbc -K 000102030405060708090A0B0C0D0E0F -iv 000102030405060708090A0B0C0D0E0F -in my-app.apk -out my-app-enc.apk `
>

Basically, this particular APK has been encrypted _manually_ and doesn't follow the twofish encryption Google Play uses when it encrypts the dmcrypt app-asec files. But you need a key! In the same blog post,

> Both are unchanged from the original Froyo apps-to-SD implementation: Twofish with a 128-bit key stored in /data/misc/systemkeys:

> ```
> shell@android:/data/misc/systemkeys # ls
> ls
> AppsOnSD.sks
> shell@android:/data/misc/systemkeys # od -t x1 AppsOnSD.sks
> od -t x1 AppsOnSD.sks
> 0000000 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
> 0000020
> ```

As it says, the original android app encryption/decryption process uses twofish, but there is more than one way to encrypt and install apps on android. In this challenge, the encryption is done manually using openssl.

Using the keyfile mentioned above (without spaces), decrypt the `encrypted.nothingtoseehere.apk`:

> ```
> shell@android # openssl aes-128-cbc -d -K aa7db8864627354c7a4b0fbd81f2f399 -iv 000102030405060708090A0B0C0D0E0F -in encrypted.nothingtoseehere.apk -out decrypted.nothingtoseehere.apk
> ```

From here, grep/install to get the flag.
<br>
## Notes from the author:
<br>
This challenge was orignally created out of spite. When I had moved my personal phone from 4.4.4 to 5.0, I decided not to install Gapps, and couldn't get any of my paid applications that I relied upon. I decided to research how Google encrypts the apps so I could decrypt the apps I paid for and continue to use them. After asking people to read my blog post, no one did. So, I decided to make a challenge revolving around the subject.
Blog post can be found here (I hid it during the competition): http://givemesecurity.info/2015/01/05/copying-apps-after-software-upgrade-without-google-play/
<br>
## Hindsight:
<br>
I originally used twofish encryption on the apk and placed it in the app-asec directory, but I was unable to mirror the same implementation Google uses with their encrypted apps, so I decided to change the challenge so something slightly more obscure. In hindsight, the challenge may have been more 'correct' if I had just accepted my imperfection in mirroring Google and just left it as twofish in app-asec, as it may have lead to faster solves.


## Other write-ups and resources

* none yet
