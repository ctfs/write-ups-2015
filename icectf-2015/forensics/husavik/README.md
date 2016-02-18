# IceCTF 2015: Husavik

**Category:** Forensics
**Points:** 85
**Description:** 

> This handy [Android App](./husavik.apk) is supposed to display the flag, but it's not working!

**Hint:**

> Only if you could get into the code...

## Write-up

by [polym](https://github.com/abpolym)

We are given an Android Application, which we can decompile using a combination of `apktool` and `jadx`.

After decompilation, we find several files inside the root directory:

```bash
+bash-4.3$ ls
AndroidManifest.xml     android                 husavik.jobf            log                     res                     tf
```

Having a look inside `AndroidManifest.xml`, we see that the MainActivity is `tf.icec.husavik.MainActivity`:

```bash
$ cat AndroidManifest.xml
[...]
        <activity android:label="@string/app_name" android:name="tf.icec.husavik.MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
[...]
```

So we `cd` into the `tf/icec/husavik` directory that contain several other decompiled `.class` Methods in `.java` source code:

```bash
+bash-4.3$ tree tf/
tf/
└── icec
    └── husavik
        ├── BuildConfig.java
        ├── C0150R.java
        ├── C0151b.java
        ├── C0152c.java
        ├── MainActivity.java
        └── RedHerring.java

2 directories, 6 files
```

After looking at each source code file, we finally find a base64 encoded String in `C0151b.java`:

```bash
+bash-4.3$ cat C0151b.java
package tf.icec.husavik;
[...]
            objectOutputStream.writeObject("ZmxhZ193YWl0X3dhc250X2l0X2RhbHZpawo=");
[...]
```

Decoding this base64 encoded string reveals the flag, `flag_wait_wasnt_it_dalvik`:

```bash
+bash-4.3$ echo 'ZmxhZ193YWl0X3dhc250X2l0X2RhbHZpawo=' | base64 --decode
flag_wait_wasnt_it_dalvik
```
## Other write-ups and resources

* <http://blog.oleaass.com/ctf-icectf-husavik-85-forensics/>
* <https://github.com/james9909/PracticeCTF/blob/master/IceCTF-2015/Husavik/Solution.txt>
