def partition(arr,start,end):
    pivot = arr[end];
    i = start - 1
    for j in range(start,end):
        if(arr[j]>=pivot):
            i += 1
            arr[j],arr[i] = arr[i],arr[j]
    arr[i+1],arr[end] = arr[end],arr[i+1]
    return (i+1)

def quickSort(arr,start,end):
    if(start<end):
        pivot = partition(arr,start,end)
        quickSort(arr,start,pivot-1)
        quickSort(arr,pivot+1,end)
        
n = int(input("Enter Number of Elements = "))
arr = []
for i in range(n):
    arr.append(float(input("Enter Number at index %d = "%(i+1))))
for i in range(n):
    print(arr[i], end = " ")
print()
quickSort(arr,0,n-1)
for i in range(n):
    print(arr[i], end = " ")
print()
print("Top Five Score : ",arr[:5])