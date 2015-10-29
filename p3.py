#!/usr/bin/python
import math
import sys
l=[[70,0],[40,10],[50,-2],[2,10],[20,7],[1,2]]
speed = input('Enter Speed')
path = input("Enter path")
xf=0
yf=0
t = 0
while t<=5:
	xb=l[t][0]
	yb=l[t][1]
	dist=math.sqrt(((yb-yf)**2) +((xb-xf)**2))
	sin=(yb-yf)/dist
	cos=(xb-xf)/dist
	xf=xf+speed*cos
	yf=yf+speed*sin
	if(dist<10):
		print "success"
		sys.exit(0)
	t=t+1
if(t==6):
	print "fail"
	sys.exit(0)

