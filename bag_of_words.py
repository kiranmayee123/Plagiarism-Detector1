import math
import re
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
	l=[]
	l1=[]
	sum1=0
	l=list(p.values())
	l1=list(q.values())
	n=len(l)
	n1=len(l1)
	i=1
	j=1
	while i<=n-1:
		while j<=n1-1:
			sum1=sum1+int(l[i])*int(l1[j])
			break
			j=j+1
		i=i+1
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
	# f1=input("enter the file")
	# f2=input("enter the file")
	s=open(f1,"r")
	x=s.read()
	# a1=re.sub("[^a-z0-9\_]"," ",x)
	a1=x.split()
	print(a1)
	s1=open(f2,"r")
	x1=s1.read()
	# b1=re.sub("[^a-z0-9\_]"," ",x1)
	b1=x1.split()
	print(b1)
	z=a1+b1
	y=duplicate(z)
	p=frequency(y,a1)
	q=frequency(y,b1)
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
	return c