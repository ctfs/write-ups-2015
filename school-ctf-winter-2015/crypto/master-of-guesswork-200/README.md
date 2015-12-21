# School CTF Winter 2015: Master of guesswork

**Category:** Crypto
**Points:** 200
**Solves:** 
**Description:**

> Even the best ciphers are weak when you know the plain text.
> 
> 
> [Attachment](./crypto_c94350c7bc3ccac4e6f44f46b4ba69086b73c4d0.py)


## Write-up

<div><h3>Master of guesswork</h3><p>The task states that we know a part of the plaintext. By looking at the script one could realise that it tries to decrypt an encrypted <strong>URL</strong> and download the content. So we need to think of what we already know about the <strong>URL</strong>.</p>
<p>By reading the <a href="https://en.wikipedia.org/wiki/Uniform_Resource_Identifier">wiki page</a> you can make a first guess: It is a scheme; let's try <code>http</code> or <code>https</code>. Using given function to xor stored url with string <code>http://</code> we will get a part of the password <code>3asy_p</code>.</p>
<p>Now we need to do the second guess. Each <strong>URL</strong> can start with <code>www</code>, e.g. <code>www.google.com</code>. Use the function again with string <code>http://www</code> as a key and get <code>3asy_p@ss3a</code>.</p>
<p>So looks like we have the whole key <code>3asy_p@ss</code>, trying to execute the script with that key we will download you the flag.</p></div>

## Other write-ups and resources

* none yet
