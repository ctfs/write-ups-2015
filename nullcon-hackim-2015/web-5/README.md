# nullcon HackIM 2015: Web Question 5

**Category:** Web
**Points:** 500
**Author:**
**Description:**

>Break the captcha! 
>
>Flag format: flag{flag}
>
>[captcha.php](http://54.165.191.231/captcha.php)

## Write-up

Notice that captcha uses the fixed font family and characters are upper- and lower-case letters
at fixed location. So the idea is to crop letters and label them for use. Whenever we get a
new captcha, crop out the letters, and compare those letters against our labelled ones.

The script that is used to get and label samples:

~~~python
#!/usr/bin/env python
from PIL import Image
import requests
import string
from StringIO import StringIO

num_requests = 2
img_dim = 11
top = 23
left = 4
gap = 30

for j in range(0, num_requests):
    r = requests.get('http://54.165.191.231/imagedemo.php')
    im = Image.open(StringIO(r.content))
    for i in range(0, 6):
        res = im.crop((left + gap * i, top, left + img_dim + 30 * i, top + img_dim))
        res.show()
        filename = raw_input("Label this image: ")
        if filename in string.lowercase:
            res.save('lower_' + filename + '.png')
        elif filename in string.uppercase:
            res.save('upper_' + filename + '.png')
        else:
            continue
~~~

Run the script and manually label for a couple times until we get 52 images of labelled
letters that is of size 11x11. Then whenever we get a new captcha, we crop out letters
inside, compare the letter against every labelled letter image, and guess the one that
has the minimal score. The score is the sum of pixel-wise difference between two images:

~~~python
import sys
from glob import glob
from PIL import Image
import requests
from cStringIO import StringIO
from io import BytesIO

WIDTH = 11
HEIGHT = 11

def recognize(im, letters):
    # compare im against all letters and find the best score one.
    best_score = sys.maxint
    best_letter = None
    for letter, letter_img in letters.iteritems():
        score = 0
        for x in xrange(WIDTH):
            for y in xrange(HEIGHT):
                score += abs(im.getpixel((x, y)) - letter_img.getpixel((x, y)))
        if score < best_score:
            best_score = score
            best_letter = letter
    return best_letter

def noise_cancel(im):
    return im.convert('L').point(lambda x: 0 if x < 128 else 255, '1')

def load_letters():
    letters = {}
    files = glob('*.png')
    for f in files:
        original = Image.open(f)
        im = noise_cancel(original)
        letter = f[10:11]
        letters[letter] = im
    return letters

IMG_DIM = 11
TOP = 23
LEFT = 4
GAP = 30

def crop_captcha(im):
    return [
        im.crop((LEFT + GAP * i, TOP, LEFT + IMG_DIM + 30 * i, TOP + IMG_DIM))
        for i in xrange(0, 6)
    ]

def solve_captcha(im, letters):
    captcha = map(noise_cancel, crop_captcha(im))
    return ''.join(
        recognize(c, letters)
        for c in captcha
    )

IMG_URL = 'http://54.165.191.231/imagedemo.php'
VERIFY_URL = 'http://54.165.191.231/verify.php'

if __name__ == '__main__':
    letters = load_letters()
    s = requests.Session()
    cookies = None
    while True:
        # pull the image
        r = s.get(IMG_URL, cookies=cookies)
        im = Image.open(StringIO(r.content))
        # made the guess
        guess = solve_captcha(im, letters)
        # verify my guess
        r = s.post(VERIFY_URL, data={'solution': guess})
        # diagnostic info
        print r.content
        print 'my guess was: %s' % guess
~~~

The flag shows up after we solved ~40 captchas in 120 seconds.

`flag{H@CKIM_C@pTcha!09022015}`

## Other write-ups and resources

* <https://ctf-team.vulnhub.com/hackim-2015-web-500/>
* <https://github.com/S42X/CTF/blob/master/HACKIM/captcha.md>
* <http://garage4hackers.com/entry.php?b=3103>
* <http://piggybird.net/2015/01/hackim-2015-web-question-5-500-points/>
* [Spanish](https://blog.ka0labs.net/post/20/)
* <https://gist.github.com/pich4ya/4cbfb645b29d75a81d3f>
* <http://pastebin.com/juq973EU>
