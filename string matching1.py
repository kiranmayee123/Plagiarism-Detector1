import re
import os
'''finding the longest substring'''
def matching(f1,f2,path):
	s=open(f1,"r")
	a=s.read().lower()#converting into lower alphabets 
	x=a.replace(" ","")#removing spaces
	s=len(x)
	a=re.sub("[^a-z0-9\_]"," ",a)#removing special characters
	l1=a.split()#converting into list
	s1=open(f2,"r")
	b=s1.read().lower()
	x1=b.replace(" ","")
	s1=len(x1)
	b=re.sub("[^a-z0-9]"," ",b)#removing special characters
	l2=b.split()#converting into list
	lcs=[]
	max1=0
	sum1=0
	i=0
	print(l1)
	print(l2)
	while i<len(l1):
		temp=i
		j=0
		while j<len(l2):
			temp2=j
			while l1[i]==l2[j]:#comparing similar words in two lists
				sum1=sum1+len(l1[i])
				max1=sum1
				i=i+1
				j=j+1
				if i>=len(l1) or j>=len(l2):
					break
			i=temp
			j=temp2
			max1=sum1
			sum1=0
			if len(lcs)==0:
				temp1=0
			else:
				temp1=max(lcs)
			if max1>temp1:
				lcs.append(max1)
			j=j+1
		i=i+1
	print("lcs",max(lcs))
	sum1=s+s1
	print("sum1",sum1)
	return (((max(lcs)*2)/sum1)*100)
# f1=input("enter the file")
# f2=input("enter the file")
# print(matching(f1,f2))
enter=input()
l1=os.listdir(enter)#importing the directory having files
os.chdir(enter)
l2=[]
for i in l1:
	temp=[]
	for j in l1:
		if i==j:
			pass
		elif i<j:
			print("enter in row:",i,"enter in column:",j)
			temp.append(matching(i,j,enter))
		else:
			pass
	l2.append(temp)
print(l2)
