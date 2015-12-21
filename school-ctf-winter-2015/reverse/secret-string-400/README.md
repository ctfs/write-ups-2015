# School CTF Winter 2015: Secret string

**Category:** Reverse
**Points:** 400
**Solves:** 
**Description:**

> Enter valid string and you will know the flag!
> 
> 
> [Source](./Task_5add03f1c70426f94c4f6f8c8d72cf04fee3eb98.tar.gz)


## Write-up

<div><h3>Secret string</h3><p>Here is a simple virtual machine. We should understand all opcodes meaning and somehow translate bytecode into human-readable code or just replace "run" function and get trace of our program:</p>
<pre><code>function run(){
    while(this.PC &lt; this.code.length){
        var command = parseCommand.call(this)
        console.log(command.args);
        command.execute(this);
    }
}
</code></pre>
<p>After that we can find actual check function:</p>
<pre><code>var f = window.machine.registers[1].userinput
var i = f.length
var nonce = 'groke';
var j = 0;
var out = [];
var eq = true;
while (j &lt; i) {
    out.push(f.charCodeAt(j) ^ nonce.charCodeAt(j % 5))
    j++;
}
var ex = [1, 30, 14, 12, 69, 14, 1, 85, 75, 50, 40, 37, 48, 24, 10, 56, 55, 46, 56, 60];
if (ex.length == out.length) {
    j = 0;
    while (j &lt; ex.length) {
        if (ex[j] != out[j])
            eq = false;
        j += 1;
    }
    if (eq) {
        alert('YOU WIN!');
    } else {
        alert('NOPE!');
    }
} else {
    alert('NOPE!');
}
</code></pre></div>

## Other write-ups and resources

* none yet
