'''Write Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in descending order using quick sort and display top five
scores.'''

def partition(arr,start,end):
    pivot = arr[end-1]
    i = start - 1
    for j in range(start,end):
        if(arr[j]>=pivot):
            i += 1
            arr[j],arr[i] = arr[i],arr[j]
   # arr[i+1],arr[end] = arr[end],arr[i+1]
    return (i+1)

def quickSort(arr,start,end):
    if(start<end):
        pivot = partition(arr,start,end)
        quickSort(arr,start,pivot-1)
        quickSort(arr,pivot+1,end)
        
n = int(input("Enter Number of Student = "))
arr = []
for i in range(n):
    arr.append(float(input("Enter Percentage of Student %d = "%(i+1))))
    
print("You have Entered List : ", arr )
quickSort(arr,0,n)
print("Sorted List : ",arr)
print("Top Five Score : ",arr[:5])