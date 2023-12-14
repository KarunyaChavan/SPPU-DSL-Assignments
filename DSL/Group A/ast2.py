'''Write Python program to store marks scored for first test of subject ‘Data Structures and
Algorithms&#39; for N students. Compute
A. The average score of class
B. Highest score and lowest score of class
C. Marks scored by most of the students
D. list of students who were absent for the test'''

#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ MARKS ANALYSIS_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

def avg(marks, N):
    res = 0 #Initializing sum of all elements of list 
    m = N #Length of List
    for i in range(N):
        if marks[i]==-1: #Ignoring -1 as it indicates absence
            m -= 1 #If -1 occurs then decrementing length by 1
            continue
        else:
            res += marks[i] #Updating the value of res
    return res/m

#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
def maximaMin(marks, N):
    #Initializing the max and min values
    for i in range(N):
        if marks[i]==-1: 
            continue #Ignoring -1 as it indicates absence
        else:
            small = marks[i]
            grt = marks [i]
    for i in range(N):
        if (small>marks[i]) and marks[i]!=-1:
            small = marks[i]
        elif (grt<marks[i]) and marks[i]!=-1:
            grt = marks[i]
    return grt,small

#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
def absenty(marks, N):
    ab = [] #initializing number of absent student to zero
    for i in range(N):
        if marks[i]==-1: #If it ecounters -1 then incrementing it by 1
            ab.append(names[i])
    return ab

#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
def frequency(marks, N):
    fr = [];    
    for i in range(0, N):
        if (marks[i]!=-1): 
            grt = 1;  
            for j in range(0, N):  
                if(marks[i] == marks[j]) and i!=j: 
                    grt += 1;  
                #To avoid counting same element again  
            fr.append(grt);
        else:
            fr.append(1)
    #print(fr)
    a,b = maximaMin(fr,N)
    k = fr.index(a)
    if(a==1):
        print("All have Same Frequency")
    else:
        print(f"{marks[k]} is appearing {a} times")
            
#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-

#Reading values for total number of examiners
N = int(input("Total numbers of students expected to be appearing = "))
marks = []#Creating the list to store marks of each student.
names = []
#Reading values of marks for each student,
for i in range(N):
    names.append(input("Enter name of Student %d = "%(i+1)))
    marks.append(float(input("Enter his score = ")))

#Displaying the marks entered
print("Data of Students = ", names)
print("Data of marks scored = ",marks)

ch = 1 #Choice variable
while(ch==1):

    opt = int(input("1)The average score of class.\n2)Highest score and lowest score of class.\n3)Marks scored by most of the students.\n4)List of Students who were absent for test.\nYour Choice = "))
    
    if (opt==1):
     #Finding Average score of the class
        print("Average Score = ",(avg(marks, N))) 
        
#-------------------------------------------------------------------------------------------------------------------
    elif (opt==2):		
        grt,small = maximaMin(marks, N)
        print("Highest Score of class is %d\nLowest Score of class is %d"%(grt, small))
        
#------------------------------------------------------------------------------------------------------------------	
    elif(opt==3):
        frequency(marks, N)

#------------------------------------------------------------------------------------------------------------------	
    elif (opt==4): #Frequency
        print(absenty(marks, N))

#-------------------------------------------------------------------------------------------------------------------
    else:
        print("Invalid Option. ")

#------------------------------------------------------------------------------------------------------------------			
    ch = int(input("Do you want to continue ?\n1)Yes\n2)No\nYour Response = ")) #Deciding whether to continue or exit from the code