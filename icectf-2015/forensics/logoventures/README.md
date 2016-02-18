# IceCTF 2015: Logoventures

**Category:** Forensics
**Points:** 35
**Description:** 

> I believe I misplaced something in this [image](./logo.gif), could you see if you can find it for me?

**Hint:**

> Only if you could slow down time itself

## Write-up

by [polym](https://github.com/abpolym)

We are given a gif:

![](./logo.gif)

If you look long enough at this gif, you'll notice the text switching at a certain frame.

We can use ImageMagick's `convert` tool to split the gif into its individual frames and look for unique frames:

```bash
$ +bash-4.3$ convert logo.gif logo.png
+bash-4.3$ md5 -r *.png | column -t | sort -k1
63356d1c04b210c9f7388e953cf7c7f7  logo-0.png
8f943d4a902e7c18bb5e4833b49292d3  logo-1.png
8f943d4a902e7c18bb5e4833b49292d3  logo-10.png
[...]
8f943d4a902e7c18bb5e4833b49292d3  logo-7.png
8f943d4a902e7c18bb5e4833b49292d3  logo-8.png
8f943d4a902e7c18bb5e4833b49292d3  logo-9.png
```

`logo-1.png` to `logo-66.png` are the same frame, which is the frame you see the longest.

`logo-0.png` contains our flag:

![](./logo-0.png)

The flag is `boy_this_goes_by_so_fast`.

## Other write-ups and resources

* <http://blog.oleaass.com/ctf-icectf-logoventures-35-forensics/>
* <https://github.com/james9909/PracticeCTF/blob/master/IceCTF-2015/Logoventures/Solution.txt>
