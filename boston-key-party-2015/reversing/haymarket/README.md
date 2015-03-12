# Boston Key Party CTF 2015: Haymarket

**Category:** Reversing
**Points:** 150
**Solves:** 216
**Description:**

> Monty Hall wrote a script of how he was supposed to run one of his game shows for his trusty accounting computer some time ago, but hes not really sure what the punch cards mean any more. I mean, that was a while ago. Only, hes sure his key is hidden somewhere in these punch-cards, if he could figure out how to run them... : 150

## Write-up

To solve this problem you first need to perform some reconaissance on identifying the type and strcuture of the punch cards. 

Some googling revealed this handy tool that was probably used to generate this challenge
http://www.kloth.net/services/cardpunch.php 

First, the above tool was used to generate a legend of characters and determine the ecoding method. ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789 was input into the tool to generate a bit of a legend. 

http://www.kloth.net/services/pcard.php?punch2=ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789&code=DEC-029&unk=ignore&ccolor=yellow&t=png 

A manual decode of the first punch card did reveal some english text so it was concluded that the card was infact a DEC-029 model punch card.

You could certainly decode all 31 cards manually now but that would take you a long time. Looks like its time to write a decoder. 

Some Googling revealed a punch card decoder for another punch card challenge that was modified and calibrated to images provided. (will add url when I find it again) 


```python
from PIL import Image

def decode(code):
    if code == ['0']: return '0'
    elif code == ['1']: return '1'
    elif code == ['2']: return '2'
    elif code == ['3']: return '3'
    elif code == ['4']: return '4'
    elif code == ['5']: return '5'
    elif code == ['6']: return '6'
    elif code == ['7']: return '7'
    elif code == ['8']: return '8'
    elif code == ['9']: return '9'
    elif code == ['12', '1']: return 'A'
    elif code == ['12', '2']: return 'B'
    elif code == ['12', '3']: return 'C'
    elif code == ['12', '4']: return 'D'
    elif code == ['12', '5']: return 'E'
    elif code == ['12', '6']: return 'F'
    elif code == ['12', '7']: return 'G'
    elif code == ['12', '8']: return 'H'
    elif code == ['12', '9']: return 'I'
    elif code == ['11', '1']: return 'J'
    elif code == ['11', '2']: return 'K'
    elif code == ['11', '3']: return 'L'
    elif code == ['11', '4']: return 'M'
    elif code == ['11', '5']: return 'N'
    elif code == ['11', '6']: return 'O'
    elif code == ['11', '7']: return 'P'
    elif code == ['11', '8']: return 'Q'
    elif code == ['11', '9']: return 'R'
    elif code == ['0', '1']: return '/'
    elif code == ['0', '2']: return 'S'
    elif code == ['0', '3']: return 'T'
    elif code == ['0', '4']: return 'U'
    elif code == ['0', '5']: return 'V'
    elif code == ['0', '6']: return 'W'
    elif code == ['0', '7']: return 'X'
    elif code == ['0', '8']: return 'Y'
    elif code == ['0', '9']: return 'Z'
    elif code == ['11', '2', '8']: return '!'
    elif code == ['4', '8']: return '@'
    elif code == ['3', '8']: return '#'
    elif code == ['11', '3', '8']: return '$'
    elif code == ['0', '4', '8']: return '%'
    elif code == ['12', '7', '8']: return '^'
    elif code == ['12']: return '&amp;'
    elif code == ['11', '4', '8']: return '*'
    elif code == ['12', '5', '8']: return '('
    elif code == ['11', '5', '8']: return ')'
    elif code == ['11']: return '-'
    elif code == ['6', '8']: return '='
    elif code == ['0', '5', '8']: return '_'
    elif code == ['0', '3', '8']: return ','
    elif code == ['12', '6', '8']: return '+'
    elif code == ['12', '2', '8']: return '['
    elif code == ['0', '2', '8']: return '['
    elif code == ['11', '6', '8']: return ';'
    elif code == ['0', '6', '8']: return '&gt;'
    elif code == ['5', '8']: return "'"
    elif code == ['2', '8']: return ':'
    elif code == ['7', '8']: return '"'
    elif code == ['11', '7', '8']: return ' '
    elif code == ['12', '3', '8']: return '.'
    elif code == ['12', '4', '8']: return '&lt;'
    else: return '?'

rows = ['12', '11', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
r_h = 20
r_w = 7
r_begin = [16, 21]
nCols = 80
nRows = 12

folder = "/path/to/folder"
for num in range(31):
    path = folder  +"/L"+ str(num+1) + ".png"
    im = Image.open(path)
    pix = im.load()
    code = []
    text = ""
    for c in range (80):
        for r in range (12):
            pos_h = r_begin[1] + r * r_h #+ 3
            pos_w = r_begin[0] + c * r_w # + 3
            if pix[pos_w, pos_h] == (20, 20, 20, 255):
                code.append(rows[r])
        if len(code) > 0:
            text += decode(code)
            code = []
    print text
```

When you run this script on the folder of images you get the following ouput. (The script doesn't properly account 
for spaces and a couple of the special characters) You can now pull the flag out of the code without having to run the application (Thanks goodness).

```
IDENTIFICATIONDIVISION.PROGRAM-ID.LETS-MAKE-A-DEAL.AUTHORMONTEHALPARIN.
DATADIVISION.WORKING-STORAGESECTION.01DOORCHOICES.02GOODDOOR
PIC9.02FIRSTCHOICEPIC9.02OPENDOORPIC9.02CH
ANGEDOORPIC9.01CURRENTDATE.02CURRENTYEARPIC9(4).02
CURRENTMONTHPIC99.02CURRENTDAYPIC99.01DAYOFYEAR.02
CURRENTMONTHFILLERPIC9(4).02YEARDAYPIC9(3).01
CURRENTTIME.02CURRENTHOURPIC99.02CURRENTMINUTEPIC99.
02CURRENTTENSPIC9.02CURRENTONESPIC9.02FILLER
PIC99.PROCEDUREDIVISION.DISPLAY'MH:WELCOMETOLETSMAKEADEAL'.DI
SPLAY'MH:THEREARETHREEDOORS.ONLYONEWITHTHEKEY'.ACCEPTCURRENTTIMEF
ROMTIME.IFCURRENTONES&lt;4SETGOODDOORTO1ELSEIFCURRENTONES&lt;7
SETGOODDOORTO2ELSESETGOODDOORTO3END-IFEND-IFDISPLA
Y'MH:YOUMAYONLYOPENONEDOOR.WHICHDOOR?'.IFCURRENTTENS=0ORCURRE
NTTENS=3SETFIRSTCHOICETO1.IFCURRENTTENS=1ORCURRENTTENS=4S
ETFIRSTCHOICETO2.IFCURRENTTENS=2ORCURRENTTENS=5SETFIRSTCHOICE
TO3.DISPLAY'PLAYER:IPICKDOOR'FIRSTCHOICE'.'IFFIRSTCHOICE=GOODDO
ORDISPLAY'MH:THATISANINTERESTINGCHOICEOFDOOR.'IFCURRENTTENS=
OR0ORCURRENTTENS=4SETOPENDOORTO3END-IFIFCURRENTTENS=
1ORCURRENTTENS=5SETOPENDOORTO1END-IFIFCURRENTTENS=2O
1ORCURRENTTENS=3SETOPENDOORTO2END-IFDISPLAY'MH:LETM
EGIVEYOUAHINT.'DISPLAY'MONTYHALLOPENSDOOR'OPENDOORDISPLAY'A
GOATRUSHESOUTWITHNOKEY.'DISPLAY'MH:WOULDYOULIKETOCHANGEYOURD
GOORCHOICE?'DISPLAY'PLAYER:YES!MYLOGICMINORINCOLLEGEHASAUSE!'
GOORIFCURRENTTENS=2ORCURRENTTENS=4SETCHANGEDOORTO1E
ND-IFIFCURRENTTENS=0ORCURRENTTENS=5SETCHANGEDOORTO2EN
D-IFIFCURRENTTENS=1ORCURRENTTENS=3SETCHANGEDOORTO3END
-IFDISPLAY'PLAYER:IWILLCHOOSEDOOR'CHANGEDOOR'INSTEAD!'ELSE
SETCHANGEDOORTOFIRSTCHOICE.IFCHANGEDOOR=GOODDOORDISPLAY'MH:CONGRA
SETULATIONS!YOUFOUNDAKEY.'DISPLAY'MH:THEKEYIS:'DISPLAY'KEY(
SETALEXTREBEKISASOCIALENGINEER)'ELSEDISPLAY'MONTYHALLOPENSTHEDOOR.A
GOATJUMPSOUT.'DISPLAY'MH:THISISTHEINCORRECTDOOR.'DISPLAY'THE
```

FLAG: ALEXTREBEKISASOCIALENGINEER (found in second to last line of output)


## Other write-ups and resources

* <http://hackitguys.com/?p=16>
* <http://u.osu.edu/romig.1/2015/03/02/boston-key-party-haymarket-write-up/>
* <https://0x44696f21.wordpress.com/2015/03/02/haymarket-boston-key-party-2015/>
* [Indonesian](http://blog.rentjong.net/2015/03/boston-key-party-2015-haymarket.html)
* [Resulting Cobold Code](ideone_ylIgJz.cbl) - [Source](http://ideone.com/ylIgJz)
