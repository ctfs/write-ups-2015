# Th3Jackers CTF 2015: Introduction to Keylogging

**Category:** Misc
**Points:** 50
**Solves** 14
**Description:**

> Description: WTF ?: ^[[1;3Aload+^[[1;3Bload+^[[1;3C+here+^[[1;3D4dead
>
> Attachment:

## Write-up

We have to decode the message `^[[1;3Aload+^[[1;3Bload+^[[1;3C+here+^[[1;3D4dead`.

First, we have to know that these weird-looking character sequences `^[[1;3A` are keycodes:

| Keycode  |      Meaning  |
|----------|:-------------:|
| [[1;3A | M-Up  |
| [[1;3B | M-Down  |
| [[1;3C | M-Right  |
| [[1;3D | M-Left  |

If we substitute the meaning of each keycode with the keycode in the message and leave out the preceding `M-`, we are getting this cleartext:

`upload+download+right+here+left4dead`

This results in the correct flag: `flag{upload+download+right+here+left4dead}`

## Other write-ups and resources

* <http://0xa.li/th3jackers-2015-ctf-misc50-writeup/>
