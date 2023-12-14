'''2.A) Write Python program to store roll numbers of student in array who attended training
program in random order. Write function for searching whether particular student attended
training program or not, using linear search and sentinel search.
B) Write Python program to store roll numbers of student array who attended training program
in sorted order. Write function for searching whether particular student attended training
program or not, using binary search and Fibonacci search.'''
def linearSearch(l,n,k):
    for i in range(n):
        if (l[i]==k):
            return i

def sort(l,n):
    for i in range(n-1):
        for j in range(i+1,n):
            if l[i]>l[j]:
                temp = l[i]
                l[i] = l[j]
                l[j] = temp
    return l

def binarySearch(arr, start, end, x):
    if (end >= start):
        mid = start + (end - start) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, start, mid-1, x)
        else:
            return binarySearch(arr, mid + 1, end, x)
    else:
        return -1
    
def sentiSearch(arr,n,key):
    last = arr[n-1]
    arr[n-1] = key
    i = 0
    while(arr[i]!=key):
        i+=1
    arr[n-1] = last
    if(arr[i]==key):
        return i
    else:
        return -1

def fibSearch(arr,key,n):
    #Phase 1 : Generation of Fibonacci Series.
    fib2 = 0
    fib1 = 1
    fibc = fib2+fib1 #fibc = 1
    
    while(fibc<n): #We are assigning value to fibc such that fibc >= number of elements (n)
        fib2 = fib1
        fib1 = fibc
        fibc = fib2 + fib1  
    #-------------------------------------------------------------------------------#
    offset = -1 #Initailise offset to -1
    
    while(fibc>1):
        i = min( offset+fib2 , n-1 )#required for deciding the index of value to be compared in array.
        if(arr[i]<key):#if key is greater
            #Decrementing fibonacci sequence by step = 1
            #Note that offset is updated
            fibc = fib1
            fib1 = fib2
            fib2 = fibc - fib1
            offset = i #Updating offset
            
        elif(arr[i]>key):
            #Decrementing fibonacci sequence by step = 2
            #Note that offset isn't updated
            fibc = fib2
            fib1 = fib1 - fib2
            fib2 = fibc - fib1    
            
        else: #if arr[i] == key
            return i
    if(arr[n-1] == key):
        return (n-1)
    
    return -1
    
n = int(input("Number of Students = "))
l = []
for i in range(n):
    l.append(int(input("Enter Roll Number of Student %d = "%(i+1))))
l = sort(l,n)
print(l)
ch =1
while (ch==1):
    opt = int(input("\t\t\tMENU\n1)Linear Search.\n2)Sentinel Search.\n3)Binary Search.\n4)Fibonacci Search.\nYour Choice = "))
    k = int(input("Enter Roll Number to be Searched = "))
    if(opt==1):
        result = linearSearch(l,n,k)
  
    elif(opt==2):
        result = sentiSearch(l,n,k)
  
    elif(opt==3):
        result = binarySearch(l,0,n,k)
        
    elif(opt==4):
        result = fibSearch(l,k,n)
        
    if(result != -1):
        print("Element is present at index", result)
    else:
         print("Element is not present in array")
    
    ch = int(input("Press 1 to continue else any other key to exit = "))