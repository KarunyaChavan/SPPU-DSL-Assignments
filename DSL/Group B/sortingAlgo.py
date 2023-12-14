'''Write Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
A. Selection Sort
B. Bubble sort and display top five scores.'''

def BubSort(l,n):
    for i in range(n-1):
        flag = 0
        for j in range(n-i-1):
            if (l[j]>l[j+1]):
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

l = []
n = int(input("Enter Number of Students : "))
for i in range(n):
    l.append(int(input("Enter Score of Student %d : "%(i+1))))

print("Marks Sorted Using Bubble Sort : ",BubSort(l,n)) #Function Call
print("Marks Sorted Using Selection Sort : ",selSort(l,n))
print("\nTop Five Scores : ", l[-1:-6:-1])