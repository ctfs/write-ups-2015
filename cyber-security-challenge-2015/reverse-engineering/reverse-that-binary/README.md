# Cyber Security Challenge 2015: Reverse That Binary

**Category:** Reverse Engineering
**Points:** 20
**Description:**

> We received a binary that guards a flag. However, the password has been lost. Can you still retrieve the flag?
>
> [`login`](login)

## Write-up

Let's run the binary:
```
root@jeroen-u64:/media/sf_SHARED/CSC# chmod +x login
root@jeroen-u64:/media/sf_SHARED/CSC# ./login
Please fill in the password:test
Please fill in the password:^C
root@jeroen-u64:/media/sf_SHARED/CSC# 
```
Maybe the password is hardcoded in the binary. 
```
root@jeroen-u64:/media/sf_SHARED/CSC# strings login
<...snip...>
%"	 
impo
ssib
le_t
o_gu
ess_
pass
word
fffff.
l$ L
t$(L
|$0H
Please fill in the password:
Correct password
Flag: You_hacked_it
;*3$"
zPLR
root@jeroen-u64:/media/sf_SHARED/CSC# 
```
Great! We've got the password AND the flag right there!
```
root@jeroen-u64:/media/sf_SHARED/CSC# ./login 
Please fill in the password:impossible_to_guess_password
Correct password
Flag: You_hacked_it
root@jeroen-u64:/media/sf_SHARED/CSC#
```

## Other write-ups and resources

* none yet
