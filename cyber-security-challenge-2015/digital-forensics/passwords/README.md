# Cyber Security Challenge 2015: Passwords

**Category:** Digital Forensics
**Points:** 30
**Description:**

> The forensic department received a memory dump from a computer. The goal is to obtain the passwords for all users. What is the password for the standard user account?
>
> File download link: <http://we.tl/AMKxMDamz3>

## Write-up

Let’s use [Volatility](https://github.com/volatilityfoundation/volatility) and start by identifying the operating system profile:

```bash
$ vol.py -f memdump_password.mem imageinfo
Volatility Foundation Volatility Framework 2.4
Determining profile based on KDBG search...

          Suggested Profile(s) : Win2008R2SP0x64, Win7SP1x64, Win7SP0x64, Win2008R2SP1x64
                     AS Layer1 : AMD64PagedMemory (Kernel AS)
                     AS Layer2 : FileAddressSpace (/tmp/memdump_password.mem)
                      PAE type : No PAE
                           DTB : 0x187000L
                          KDBG : 0xf80002c0c0a0
          Number of Processors : 1
     Image Type (Service Pack) : 1
                KPCR for CPU 0 : 0xfffff80002c0dd00L
             KUSER_SHARED_DATA : 0xfffff78000000000L
           Image date and time : 2015-02-16 08:05:50 UTC+0000
     Image local date and time : 2015-02-16 09:05:50 +0100
```

We should use one of the suggested profiles to analyze the memory dump. Let’s use `--profile=Win7SP1x64` and print the list of registry hives, to figure out the starting location in memory where the registry info resides:.

```bash
$ vol.py -f memdump_password.mem --profile=Win7SP1x64 hivelist
Virtual            Physical           Name
------------------ ------------------ ----
0xfffff8a002692010 0x000000007804e010 \??\C:\Users\user01\ntuser.dat
0xfffff8a003b7c410 0x0000000019b7f410 \??\C:\Windows\System32\config\COMPONENTS
0xfffff8a004211010 0x000000006ff00010 \SystemRoot\System32\Config\DEFAULT
0xfffff8a006780010 0x00000000188aa010 \??\C:\Windows\ServiceProfiles\NetworkService\NTUSER.DAT
0xfffff8a00000f010 0x000000002d547010 [no name]
0xfffff8a00002e010 0x000000002d65c010 \REGISTRY\MACHINE\SYSTEM
0xfffff8a000065010 0x000000002d693010 \REGISTRY\MACHINE\HARDWARE
0xfffff8a000f30010 0x0000000027586010 \SystemRoot\System32\Config\SOFTWARE
0xfffff8a000fe6410 0x0000000027079410 \Device\HarddiskVolume1\Boot\BCD
0xfffff8a001ea5010 0x0000000014b27010 \SystemRoot\System32\Config\SECURITY
0xfffff8a001f16010 0x000000001765d010 \SystemRoot\System32\Config\SAM
0xfffff8a002096010 0x00000000186b7010 \??\C:\Windows\ServiceProfiles\LocalService\NTUSER.DAT
0xfffff8a00246e010 0x0000000005f61010 \??\C:\System Volume Information\Syscache.hve
0xfffff8a002617010 0x00000000065e0010 \??\C:\Users\user01\AppData\Local\Microsoft\Windows\UsrClass.dat
```

The virtual address corresponding to `SYSTEM` is `0xfffff8a00002e010`, and the address corresponding to `SAM` is `0xfffff8a001f16010`. With this information we can dump the LM/NTLM password hashes from memory:

```bash
$ vol.py -f memdump_password.mem --profile=Win7SP1x64 hashdump -y 0xfffff8a00002e010 -s 0xfffff8a001f16010
Administrator:500:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
Guest:501:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
user01:1000:aad3b435b51404eeaad3b435b51404ee:f9e37e83b83c47a93c2f09f66408631b:::
```

A quick Google search reveals that `f9e37e83b83c47a93c2f09f66408631b` is the NTLM hash of `abc123`. That’s the password we were looking for!

## Other write-ups and resources

* [Memory forensics: how to pull passwords from a memory dump](http://articles.forensicfocus.com/2014/04/28/windows-logon-password-get-windows-logon-password-using-wdigest-in-memory-dump/)
