import random
from cPickle import *
from random import WichmannHill

buffer = 1024

def handleClient(client):
	
	money = 100
	target = 1000;
	bet = 10;
	get = 75
	prize = "I'm_going_to_be_a_professional_gambler!"

	prng = WichmannHill()
	prng.seed()
	
	answer = 0
	
	
	
	intro = ["Welcome to the NVISO lottery!",
	"You start out with $" + str(money) + ".",
	"Each bet will cost you $"+str(bet) + ".",
	"Guess the correct number, and you'll win $"+str(get)+"!",
	"Each number is chosen at random from the range [0, 1000].",
	"If you feel you've been cheated, you can use the ticket ID to get feedback",
	"",
	"Earn more than $1337 and get a special prize!"];

	lineWidth = 80

	output(client, "#" * lineWidth)
	
	for line in intro:
		output(client, line)
	output(client, "#" * lineWidth)
	
	while True:
		output(client, "")
		output(client, "Want to play another round?")
		output(client, "Current money: $"+str(money))
		output(client, "1. Yes")
		output(client, "2. No")
		output(client, "")
		
		input = getInput(client)
		
		if input == '1':
			money -= bet;
			
			if money < 0:
				output(client, "Too bad! You're out of money. Better luck next time.")
				return
			
			prng.seed()
			output(client, "Good luck! (id #" + getID(prng)+")")
			answer = prng.randrange(0, 1000)
			
			output(client, "Please enter a number between 0 and 1000:")
			
			input = getInput(client)
			while not validNumber(input):
				output(client, "That's not a valid number. Try again")
				input = getInput(client)
				
			
			if int(input) == answer:
				output(client, "Congratulations! That was correct!")
				money += get
				
				if money > target:
					output(client, "You're really good at this!")
					output(client, "Here's your prize: ")
					output(client, prize)
			else:
				output(client, "Too bad, the answer was " + str(answer))
		elif input == '2':
			output(client, "Oh.. okay then. Bye!")
			return
		else:
			output(client, "That's not an option")
				

def getInput(conn):
	global buffer
	
	return conn.recv(buffer).strip()
	#return raw_input()
	
def output(conn, str):
	conn.send(str + "\n")
	#print str
	
	
def validNumber(nr):
	try:
		nrc = int(nr)
		if nrc >= 0 and nrc <= 1000:
			return True
		else:
			return False
	except ValueError:
		return False

def getID(prng):
	return dumps(prng.getstate()).encode("base64").strip()
			