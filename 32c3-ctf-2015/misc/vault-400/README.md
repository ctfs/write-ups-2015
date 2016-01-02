# 32C3 CTF 2015 : vault

**Category:** Misc
**Points:** 400
**Solves:** 2
**Description:**

> Get the flag ssh://eve@136.243.194.47
> 
> 
> Password: nohaxplz

## System Information

Here are some information that can help to set up the challenge locally.

    eve@vault:/$ uname -a
    Linux vault 3.19.0-25-generic #26~14.04.1-Ubuntu SMP Fri Jul 24 21:16:20 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
    eve@vault:/$ ls -la /home/adam/
    total 28
    dr-xr-xr-x 2 root root     4096 Dec 27 15:42 .
    drwxr-xr-x 4 root root     4096 Dec 27 15:34 ..
    -r-------- 1 adam nogroup    32 Dec 27 15:41 flag
    -r-sr-xr-x 1 adam nogroup 14025 Dec 27 15:34 vault_explorer
    eve@vault:/$ ls -la /vault
    total 4
    drwxrwxrwt  2 root nogroup   40 Jan  2 12:58 .
    drwxr-xr-x 23 root root    4096 Dec 27 15:51 ..
    eve@vault:/$ id
    uid=1338(eve) gid=65534(nogroup) groups=65534(nogroup)
    eve@vault:/$ cat /etc/passwd
    # snip... relevant users:
    adam:x:1337:65534::/home/adam:
    eve:x:1338:65534::/home/eve:

adam owns the flag and `vault_explorer` is a setuid binary that can be used to create and read files in `/vault`.

    eve@vault:/$ /home/adam/vault_explorer
    Welcome to the vault.
    Set up your password and store your data securely with our novel military grade triple-xor encryption.
    [l] list directory
    [s] store data
    [r] retrieve data
    [?] menu
    [q] quit
    > l
    total 0
    > s
    data? asd
    > l
    total 4
    -rw------- 1 adam nogroup 3 Jan  2 13:28 BZo7qh
    > r
    filename? BZo7qh
    content: "asd"
    > q
    Goodbye!
    eve@vault:/$ ls -la /vault
    total 8
    drwxrwxrwt  2 root nogroup   60 Jan  2 13:28 .
    drwxr-xr-x 23 root root    4096 Dec 27 15:51 ..
    -rw-------  1 adam nogroup    3 Jan  2 13:28 BZo7qh

## Write-up

(TODO)

## Other write-ups and resources

* <https://gist.github.com/stephenR/9fc14888ef2cec7c7b99>
