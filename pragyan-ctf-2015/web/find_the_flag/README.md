# Pragyan CTF 2015: Find the flag

**Category:** Web
**Points:** 20
**Solves** 104
**Description:**

> [ctf.zip](ctf.zip)

## Write-up

Unzipping the archive with `unzip ctf.zip`, we get a bunch of javascript and css files, as well as a PNG.

The first thing we do is trying to find the string `flag` using `grep`:

```bash
$ grep -ri flag ctf
ctf/aes.js:l)}})();$(document).ready(function() { $('#flag').html("904d553eae0a2a5b82d82fd4f0c7ae6f5fe955f5"); });CryptoJS.lib.Cipher||function(u){var p=CryptoJS,d=p.lib,l=d.Base,s=d.WordArray,t=d.BufferedBlockAlgorithm,r=p.enc.Base64,w=p.algo.EvpKDF,v=d.Cipher=t.extend({cfg:l.extend(),createEncryptor:function(e,a){return this.create(this._ENC_XFORM_MODE,e,a)},createDecryptor:function(e,a){return this.create(this._DEC_XFORM_MODE,e,a)},init:function(e,a,b){this.cfg=this.cfg.extend(b);this._xformMode=e;this._key=a;this.reset()},reset:function(){t.reset.call(this);this._doReset()},process:function(e){this._append(e);return this._process()},
ctf/gumby.css:.icon-flag.icon-left a:before, .icon-flag.icon-right a:after, i.icon-flag:before { content: "\\2691"; height: inherit; }
```

We see a SHA1 hash sum, `904d553eae0a2a5b82d82fd4f0c7ae6f5fe955f5`, which is also the flag.

NOTE: `904d553eae0a2a5b82d82fd4f0c7ae6f5fe955f5` is the hashsum of `39giraffes`. [Source](http://www.hashkiller.co.uk/sha1-decrypter.aspx).

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/pragyan-ctf-2015-web-1/>
