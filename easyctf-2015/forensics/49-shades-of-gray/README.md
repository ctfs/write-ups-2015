# EasyCTF 2015: 49 Shades of Gray (125)

**Category:** Forensics
**Points:** 125
**Solves:** 
**Description:**

> We only have 49 shades of gray D:
> 
> 
> \#000000 to \#F5F5F5... there's one shade missing! Find the hex value of the missing shade. Pound sign optional.
> 
> 
> [Image](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/shades.png)
> 
> 
> Hint: How can we tell which color is which?


## Write-up

by [polym](https://github.com/abpolym)

This writeup is based on following writeup links:

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/49_shades_of_gray_125.md>

We are given a picture:

![](https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/files/shades.png)

The description and name of this task suggests that there are only 49 types of rgb values that form a gray shade and that we have to find the missing shade.

We run [this python script](pixels.py) on the image to get all pixel values and sort the unique occurrences of the pixel values numerically to get all used rgb values:

```bash
$ python2.7 ~/scripts/pixels.py shades.png  | sort -nu 
0 0 0
5 5 5
10 10 10
15 15 15
20 20 20
25 25 25
30 30 30
35 35 35
40 40 40
45 45 45
50 50 50
55 55 55
60 60 60
65 65 65
70 70 70
75 75 75
85 85 85
90 90 90
95 95 95
100 100 100
105 105 105
110 110 110
115 115 115
120 120 120
125 125 125
130 130 130
135 135 135
140 140 140
145 145 145
150 150 150
155 155 155
160 160 160
165 165 165
170 170 170
175 175 175
180 180 180
185 185 185
190 190 190
195 195 195
200 200 200
205 205 205
210 210 210
215 215 215
220 220 220
225 225 225
230 230 230
235 235 235
240 240 240
245 245 245
$ python2.7 ~/scripts/pixels.py shades.png  | sort -nu  | wc
      49     147     525
```

Using `wc`, we indeed see only 49 lines, meaning 49 used rgb values that form a specific gray.

We find the missing combination: `80 80 80` or in hex `50 50 50`.

The final flag is `505050`

## Other write-ups and resources

* <https://github.com/EasyCTF/easyctf-2015-writeups/blob/master/49_shades_of_gray_125.md>
