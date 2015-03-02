#!/usr/bin/env ipython
from matplotlib import pyplot as plt
import os

f = open("rel_coord_log","r")

subset_size = 200
point_color = ["red", "blue"]
mkrsz = 20

x = 0
y = 0
x_pos = []
y_pos = []

i = 0
line = f.readline()
print "rendering PNGs..."
while line:
	if "click" not in line:
		str_coords = line.strip().split(" ")
		delta = [int(str_coords[0]), int(str_coords[1])]

		# update the current position based on the relative offset
		x = x + delta[0]
		y = y - delta[1]

		# append the new position to the list to plot
		x_pos.append(x)
		y_pos.append(y)

	else:
		if point_color == "blue":
			point_color = "red"
		elif point_color == "red":
			point_color="green"
		else:
			point_color = "blue"

		print "cur: %s,%s, delta: %s" % (x,y,delta)
		#img = plt.imread("bg.png")
		plt.plot(x,y, 'ro', c=point_color, markersize=mkrsz)
		plt.axis([0,950,0,600])
		#plt.imshow(img,zorder=0)
		plt.savefig("%04d.png" % i)

	i = i +1
	line = f.readline()

print "rendering animation..."
os.system("convert -delay 200 -loop 0 *.png animaion.gif") # requires ImageMagick

f.close()
