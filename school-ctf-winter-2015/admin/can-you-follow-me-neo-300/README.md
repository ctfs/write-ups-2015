# School CTF Winter 2015: Can you follow me, Neo?

**Category:** Admin
**Points:** 300
**Solves:** 
**Description:**

> Who needs Matrix when there is BASH?
> 
> 
> [Some bunch of commands](./commands_d036c00bcca4d54ebe0dcde4e3312d680a6b9c2c.txt)


## Write-up

<div><h3>Can you follow me, Neo?</h3><p>In task description we can see the chain of bash commands connected with a pipe, so the output of every command is the input of the next one. That way the only thing we need to do - inverse all the commands from the chain.</p>
<p>To inverse <code>hd</code> we just need to transform hex representations to bytes. Then we could see ruby sript that xor every byte with 0x42, inverse for xor is xor, so just xor our bytes with 0x42 too. The only thing that can went wrong is newlines - output of the <code>base64</code> command can be multiline so before xoring we should remove excess newline symbols. </p>
<p>Next part of commands is pretty easy to inverse, just decode, unzip and decrypt: `base64 -d | unzip -d | openssl enc -rc4 -d -pass pass:hetto'</p>
<p>Command <code>tr</code> replaces the characters from its first argument to the characters in the second argument, so the only thing we need to do - call it with reverse arguments order: <code>tr 'n-za-mN-ZA-M*' 'a-zA-Z '</code></p>
<p>Then just reoderd words according to awk's <code>print</code> order and replace spaces with '_'.</p></div>

## Other write-ups and resources

* none yet
