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
    fibc = fib2+fib1
    
    while(fibc<n):
        fib2 = fib1
        fib1 = fibc
        fibc = fib2 + fib1  
    
    offset = -1
    
    while(fibc>1):
        i = min(offset+fib2, n-1)#required for deciding the index of value to be compared in array.
        if(arr[i]<key):
            #Decrementing fibonacci sequence by step = 1
            #Note that offset is updated
            fibc = fib1
            fib1 = fib2
            fib2 = fibc - fib1
            offset = i
        elif(arr[i]>key):
            #Decrementing fibonacci sequence by step = 2
            #Note that offset isn't updated
            fibc = fib2
            fib1 = fib1 - fib2
            fib2 = fibc - fib1    
        else: #if arr[i] == key
            return i
    if(fibc and arr[n-1] == key):
        return (n-1)
    
    return -1

# def fib(n):
#     if(n==0):
#         return 0
#     if(n==1):
#         return 1
#     return fib(n-1)+fib(n-2)
    
# def fibSearch(arr,mid,p,q,key):
#     if(key==arr[mid-1]):
#         return mid-1
#     if(key>arr[mid-1]):
#         if(p==1):
#             return -1
#         mid += q
#         p -= q
#         q -= p
#         return fibSearch(arr,mid,p,q,key)
#     else:
#         if(q==0):
#             return -1
#         mid -= q
#         temp = p-q
#         p = q
#         q = temp
#         return fibSearch(arr,mid,p,q,key)
    
n = int(input("Number of Elements in Array = "))
l = []
for i in range(n):
    l.append(int(input("Enter Element %d = "%(i+1))))
l = sort(l,n)
print(l)
ch =1
while (ch==1):
    opt = int(input("\t\t\tMENU\n1)Linear Search.\n2)Sentinel Search.\n3)Binary Search.\n4)Fibonacci Search.\nYour Choice = "))
    k = int(input("Key = "))
    if(opt==1):
        result = linearSearch(l,n,k)
  
    elif(opt==2):
        result = sentiSearch(l,n,k)
  
    elif(opt==3):
        result = binarySearch(l,0,n,k)
        
    elif(opt==4):
        # for i in range(n+1):
        #     c = fib(i)
        # p = fib(i-2)
        # q = fib(i-3)
        # mid = n - p + 1
        # result = fibSearch(l,mid,p,q,k)
        result = fibSearch(l,k,n)
    if result != -1:
        print("Element is present at index", result)
    else:
         print("Element is not present in array")
    
    ch = int(input("Press 1 to continue else any other key to exit = "))