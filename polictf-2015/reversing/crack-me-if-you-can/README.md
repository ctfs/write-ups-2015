# PoliCTF 2015: Crack Me If You Can

**Category:** Reversing
**Points:** 100
**Solves:** 196
**Description:**

> John bets nobody can find the passphrase to login!

>> GPG key: viphHowrirOmbugTudIbavMeuhacyet'

> [crack-me-if-you-can](crack-me-if-you-can_d4e396383e3f64ec7698efaf42f7f32b.tar.gz.gpg)

## Write-up

by [polym](https://github.com/abpolym)

Keywords:

* Android Application (`.apk`)

This writeup is based on the following writeups:

* <http://jackson.thuraisamy.me/polictf-2015-android.html> (Use of python script)
* <http://www.bannsecurity.com/index.php/home/10-ctf-writeups/10-polictf-2015-crack-me-if-you-can> (Run application in debugger)

We are given an GPG-encrypted file, which we decrypt using gpg:

```bash
$ gpg --output crack-me-if-you-can_d4e396383e3f64ec7698efaf42f7f32b.tar.gz --decrypt crack-me-if-you-can_d4e396383e3f64ec7698efaf42f7f32b.tar.gz.gpg 
gpg: AES256 encrypted data
Enter passphrase: <viphHowrirOmbugTudIbavMeuhacyet'>
```

We extract the resulting gzipped tar archive using `tar` to get an Android application:

```bash
$ tar xvf crack-me-if-you-can_d4e396383e3f64ec7698efaf42f7f32b.tar.gz 
x crack-me-if-you-can/
x crack-me-if-you-can/crack-me-if-you-can.apk
$ file crack-me-if-you-can/crack-me-if-you-can.apk 
crack-me-if-you-can/crack-me-if-you-can.apk: Zip archive data, at least v2.0 to extract
```

I decompile the APK using a combination of `apktool` (for the resources) and `jadx` (for a better source code):

```bash
$ apktool d crack-me-if-you-can.apk
$ jadx --show-bad-code --deobf crack-me-if-you-can.apk > out.log
```

First, we have a look at the [AndroidManifest.xml](./AndroidManifest.xml), in which we find the EntryPoint for our Android Application: `it.polictf2015.LoginActivity` (Look for the activity with the `android.intent.action.MAIN` action).
Since the Manifest does not reveal any other interesting services or applications, we head right to the [Main Activity](./LoginActivity.java).

We can see some Anti-Virtualization techniques, such as checking for deviceIDs (`000000000000000`) and Phone Numbers (starting with `1555521`).
The `onCreate` method checks if the application is run inside a Virtual Machine and if any of those hit, it prints the String resource `R.string.ù`, which can be found in [res/values/strings.xml](./strings.xml). Note that the resource name consists of some weird UTF-8 letters.
Otherwise, a new instance of the [C0671a](./C0671a.java) class is created, which finally yields the execution of the `m5319a` function, which in turn executes the `m5325a` function.

Having a look at the `m5325a` function, we can see that the String resource `R.string.àè` is passed as a parameter to a cascade of functions calls of the [C0672b](./C0672b.java) and [C0673c](./C0673c.java) classes, which contain several String replace functions. This suggests that the resulting string after the cascade might be our final flag.

We thus re-implement the replace Calls in [python](./decrypt.py), call them in the same order as done in the `m5325a` function and finally get the flag:

```bash
$ python decrypt.py
fla{g}{Maybe_This_Obfuscation_Was_Not_That_Good_As_We_Thought}
```

The flag is `flag{Maybe_This_Obfuscation_Was_Not_That_Good_As_We_Thought}`.





## Other write-ups and resources

* <https://ctf-team.vulnhub.com/polictf-2015-crack-me-if-you-can/>
* <http://www.bannsecurity.com/index.php/home/10-ctf-writeups/10-polictf-2015-crack-me-if-you-can>
* <http://jackson.thuraisamy.me/polictf-2015-android.html>
