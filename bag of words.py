import math
import os
def duplicate(x):
	z=[]
	for i in x:
		if i not in z:
			z.append(i)
	return z
def square(p):
	l=[]
	sum1=0
	l=list(p.values())
	n=len(l)
	for i in l:
		sum1=sum1+int(i**2)
	return sum1
def vector(p,q):
	sum1=0
	l=list(p.values())
	l1=list(q.values())
	n=len(l)
	n1=len(l1)
	i=0
	while i<n:
		sum1=sum1+int(l[i])*int(l1[i])
		i=i+1
	print(sum1)
	return sum1
def frequency(y,x):
	l=[]
	l2=[]
	d={}
	for i in y:
		c=0
		for j in x:
			if i==j:
				c=c+1
		l.append(c)
	d=dict(zip(y,l))
	return d
def Bag_of_words(f1,f2,path):
	path.replace("/","\\")
	os.chdir(path)
	s=open(f1,"r")
	x=s.read().split();
	s1=open(f2,"r")
	x1=s1.read().split()
	z=x+x1
	y=duplicate(z)
	p=frequency(y,x)
	q=frequency(y,x1)
	print(p)
	print(q)
	w=vector(p,q)
	m=square(p)
	n=square(q)
	a=math.sqrt(m)
	b=math.sqrt(n)
	d=a*b
	c=w/d
	print(c) 
f1=input("enter the file")
f2=input("enter the file")
path=input("enter the path")
Bag_of_words(f1,f2,path)