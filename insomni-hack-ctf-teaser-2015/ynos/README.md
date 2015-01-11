# Insomni’hack CTF 2015: YNOS

**Category:** Web
**Points:** 100
**Author:** clZ
**Description:**

> <https://www.youtube.com/watch?v=O2rGTXHvPCQ>
>
> So many hacking scenes, so little sk1llz…
>
> Apparently [this website](http://ynos.teaser.insomnihack.ch/) likes these stupid films. Pwn them and get the flag which is in a pretty obvious file in the webroot.

## Write-up

<http://ynos.teaser.insomnihack.ch/> presents a login screen. Some random guesses reveal we can log in using the username `admin` with password `admin`. Now we can browse artists, films, and directors. Clicking any of those links triggers an Ajax request to `/INSO.RPC` with some JSON-formatted data:

```bash
$ curl -H 'Content-Type: application/json' -H 'Accept: */*' -H 'Cache-Control: no-cache' -H 'X-Requested-With: XMLHttpRequest' -H 'Cookie: AWSELB=CFABFDBD1C5BB6C16340B9340EA064028E4DF570D44D64084C319E70EE8D963FBDB0FBB63151BAE16EB9FFA8E0D4123E34E5D7D9AA1E396E163C4F960FFBFF45E6083CB961; session=fe5e3eddfcad1992c22b98cfd8d3e5b3' --data-binary '{"c":{"name":"page"},"a":{"name":"render","params":{"name":"artists"}}}' 'http://ynos.teaser.insomnihack.ch/INSO.RPC'
<fieldset>

<!-- Form Name -->
<legend>Artists</legend>


<ul class="list-group">
  <li class="list-group-item">Jonny Lee Miller</li>
  <li class="list-group-item">Angelina Jolie</li>
  <li class="list-group-item">Jesse Bradford</li>
  <li class="list-group-item">Matthew Lillard</li>
  <li class="list-group-item">Laurence Mason</li>
  <li class="list-group-item">Fisher Stevens</li>
</ul>

</fieldset>
```

(TODO)

## Other write-ups and resources

* none yet
