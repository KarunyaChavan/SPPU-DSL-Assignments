import time

def BubSort(l,n):
    for i in range(n-1):
        flag = 0
        for j in range(n-i-1):
            if l[j]>l[j+1]:
                l[j],l[j+1] = l[j+1],l[j]
                flag = 1
        if (flag==0):
            break
    return l

def selSort(l,n):
    for i in range(n-1):
        min_index = i
        for j in range(i+1,n):
            if (l[j]<l[min_index]):
                min_index = j
        if (min_index != i):
            l[i],l[min_index] = l[min_index],l[i]
    return l

l = [3,5,1,2,4]

start = time.time() #Sets starting time
print(BubSort(l,5)) #Function Call
end = time.time() #Gets the end time
print("%.20f"%(end-start)) # Calculates difference between them.

print(selSort(l,5))