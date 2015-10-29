import random
from matplotlib import pyplot as plt
observed =[1.88,0.54,1.9,0.15,0.02,2.81,1.50,1.53,2.62,2.67, 3.53,0.53,1.80,1.80,0.79,0.21,0.8,0.26,0.63,0.36,2.03,1.42,1.28,0.82,2.16,0.05,0.04,1.49,0.66,0.2,0.3,1,0.34,0.34,0.01,0.10,1.10,0.24,0.26,0.45,0.17,4.29,0.80,5.50,4.91,0.35,0.36,0.90,1.03,1.73,0.38,0.48]
expected = []
for i in range(len(observed)):
	observed[i] = int(observed[i]/10)
alpha = 0.05
df = 9
#print("How many random numbers you want to generate?")
num = len(expected) #int(input())
#print("How many intervals?")
interval = 10#int(input())
for i in range(0,interval):
	#observed.append(0)
	expected.append(int(sum(observed)/(interval+1)))
total = 0
for i in range(0,10):
	diff = observed[i] - expected[i]
	diff = diff * diff
	total = total + (diff/(expected[i]+1))
print("chi square sum: ",total)
print("alpha: ",alpha)
print("Degree of freedom: ",df)
print("Chi square at (",alpha,",",df,"): 16.9")
if total < 16.9:
	print("Accepted")
else:
	print("Rejected")
x = []
for i in range(10):
	x.append(0)
for i in observed:
	if i <0.1:
		x[0]+=1
	elif i<0.2:
		x[1]+=1
	elif i<0.3:
		x[2]+=1
	elif i<0.4:
		x[3]+=1
	elif i<0.5:
		x[4]+=1
	elif i<0.6:
		x[5]+=1
	elif i<0.7:
		x[6]+=1
	elif i<0.8:
		x[7]+=1
	elif i<0.9:
		x[8]+=1
	else:
		x[9]+=1
plt.plot(x,[i for i in range(10)])
plt.show()
