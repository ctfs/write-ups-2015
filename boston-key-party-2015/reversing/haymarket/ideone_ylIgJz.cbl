	IDENTIFICATION DIVISION.
	PROGRAM-ID. IDEONE.

	ENVIRONMENT DIVISION.

data division. 
working-storage section.  
01  doorchoices.    
    02  gooddoor        pic 9.    
    02  firstchoice     pic 9.    
    02  opendoor        pic 9.    
    02  changedoor      pic 9.  
01  currentdate.    
   02  currentyear     pic 9(4).      
   02  currentmonth    pic 99.    
   02  currentday      pic 99.  
01  dayofyear.    
   02  currentmonth filler pic 9(4).    
   02  yearday         pic 9(3).  
01  currenttime.    
   02  currenthour     pic 99.        
   02  currentminute   pic 99.  
   02  currenttens     pic 9.      
   02  currentones     pic 9.    
   02  filler          pic 99.  

procedure division. 
display 'mh: welcome to lets make a deal'. 
display 'mh: there are three doors. only one with the key'.
accept currenttime from time. 
if currentones < 4  set   gooddoor to 1 
else    if currentones < 7  set gooddoor to   2    
        else       set gooddoor to 3    
        end-if 
end-if 
display 'mh:   you may only open one door. which door?'. 
if currenttens = 0 or currenttens = 3    set firstchoice to 1. 
if currenttens = 1 or currenttens = 4    set firstchoice to 2. 
if currenttens = 2 or currenttens = 5    set firstchoice to 3. 
display   'player: i pick door ' firstchoice '.' 
if firstchoice = gooddoor    display 'mh: that is an interesting choice of   door.'.  
if currenttens = or 0 or currenttens = 4        set  opendoor to 3    end-if 
if currenttens = 1 or currenttens   = 5         set  opendoor to 1    end-if    
if currenttens = 2 o 1 or   currenttens = 3     set  opendoor to 2    end-if    
display 'mh: let me give you a hint.'.    
display 'monty hall opens  door '. 
opendoor    
display 'a goat rushes out with no key.' .     
display 'mh: would you like to change your d goor choice?' .     
display 'player: yes! my logic minor in college has a use!' .
goor
     
if currenttens = 2 or currenttens = 4  set changedoor to 1    end-if    
if currenttens = 0 or currenttens = 5  set changedoor to 2    end-if    
if currenttens = 1 or currenttens = 3  set changedoor to 3    end-if    
display 'player: i will choose door ' changedoor ' instead!' else  set changedoor to firstchoice. 
if changedoor = gooddoor  display 'mh: congrasetulations! you found a key.'.    
display   'mh: the key is:'.  
display 'key  (alextrebekisasocialengineer)' else  display 'monty hall opens the door. agoat jumps out.'.  
display 'mh: this is   the incorrect door.'.   
display 'the goat eats your punch   cards start over.'. 
stop run.