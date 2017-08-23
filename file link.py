import os
from bag_of_words import *
enter=input()
enter.replace("/","\\")
l1=os.listdir(enter)
os.chdir(enter)
l2=[]
for i in l1:
	temp=[]
	for j in l1:
		if i==j:
			pass
		elif i<j:
			temp.append(Bag_of_words(i,j,enter))
		else:
			pass
	l2.append(temp)
print(l2)

