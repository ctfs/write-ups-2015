# Pragyan CTF 2015: Put on your reading glasses

**Category:** Steganography
**Points:** 10
**Solves** 102
**Description:**

> Put on your reading glasses to find the answer
>
> [test.html](test.html)

## Write-up

Opening the `test.html` file with a web-browser of your choice, we see a blank page.

Further inspection yields that there are several blocks with RGB background colors of either `rgb(255, 255, 254)` or `rgb(255, 255, 255)`.

Since we can't differentiate these values with our own eyes, we replace the `255,255,254` values with `0,0,0` - the color black:

```bash
cat test.html | sed 's/rgb(255, 255, 254)/rgb(0,0,0)/g' > test2.html
```

Opening this new HTML page, `test2.html`, we get a QR code:

![](qrcode.png)

Decoding this QR Code with an [online tool](http://zxing.org/w/decode.jspx) yields the flag, `8febb919bc0fc08e3e1108b1b6bfef37`.

## Other write-ups and resources

 none yet
