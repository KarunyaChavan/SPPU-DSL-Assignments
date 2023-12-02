def unique(l,n):
	#Bubble Sort method of sorting list
	for i in range((n-1)):
		for j in range(i+1,n):
			if l[i]>l[j]:
				temp = l[i]
				l[i] = l[j]
				l[j] = temp
	#Removing duplicates from the sorted list
	ul = []
	size = 0
	for i in range(n-1):
		if l[i] != l[i+1]:
			ul.append(l[i])
			size += 1
	ul.append(l[n-1])
	size += 1
	return ul,size

def union(l1,l2,m,n):
	nl = []
	size = 0
	for i in range(m):
		nl.append(l1[i])
		size += 1
	for i in range(n):
		flag = 0
		for j in range(m):
			if l2[i]==nl[j]:
				flag = 1
		if (flag==0):
			nl.append(l2[i])
			size += 1
	return nl,size

def intersection(l1,l2,m,n):
	nl =[]
	for i in range(m):
		for j in range(n):
			if l1[i]==l2[j]:
				nl.append(l1[i])
	return nl

def diff(l1,l2,m,n):
	nl = []
	size = 0
	for i in range(m):
		flag = 0
		for j in range(n):
			if l1[i]==l2[j]: 
				flag = 1
		if (flag==0):
			nl.append(l1[i])
			size += 1
	return nl,size

def Entry(n):
	l = []
	for i in range(n):
		l.append(input("Enter Name of Player %d = "%(i+1)))
	return l
#----------------------------------------------------------------------------------------------------------------------------------------------
M = int(input("Total Number of Students = "))
Students = Entry(M)
Students,M = unique(Students,M)

C = int(input("Number of players playing Cricket = "))
Cricket = Entry(C)
Cricket,C = unique(Cricket,C)

B = int(input("Number of Students playing Badminton = "))
Badminton = Entry(B)
Badminton,B = unique(Badminton,B)

print("Total Students = ", Students)
print("Students playing cricket = ",Cricket)
print("Students playing badminton = ",Badminton)

ch = 1 #Choice variable
while(ch==1): #Decisional loop depending upon value of ch
	opt = int(input("1)Set of students who play either cricket or badminton or both.\n2)Set of students who play both cricket and badminton.\n3)Set of students who play only cricket.\n4)Set of students who play badminton.\n5)Number of Students who play neither cricket nor badminton.\nYour Choice = "))
 
	if (opt==1):
		a,b = union(Cricket,Badminton,C,B)
		print(a)
	
	elif (opt==2):
		print(intersection(Cricket, Badminton,C,B))
   
	elif(opt==3):
		a,b = diff(Cricket, Badminton, C,B)
		print(a)
  
	elif(opt==4):
		a,b = (diff(Badminton,Cricket,B,C))
		print(a)
  
	elif(opt==5):
		a,b = union(Cricket,Badminton,C,B)
		c,d = (diff(Students,a,M,b))
		print(d)
  
	ch = int(input("Do you want to continue?\n1)Yes.\n2)No\nResponse = "))