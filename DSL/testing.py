def fibonacciSearch(arr,key,n):
    fib2 = 0
    fib1 = 1
    fibc = fib2+fib1
    
    while(fibc<n):
        fib2 = fib1
        fib1 = fibc
        fibc = fib2 + fib1
    
    print("fibc = %d, fib1 = %d, fib2 = %d"%(fibc,fib1,fib2))    
    offset = -1
    
    while(fibc>1):
        i = min(offset+fib2, n-1)
        if(arr[i]<key):
            fibc = fib1
            fib1 = fib2
            fib2 = fibc - fib1
            offset = i
            print("fibc = %d, fib1 = %d, fib2 = %d"%(fibc,fib1,fib2))    
        elif(arr[i]>key):
            fibc = fib2
            fib1 = fib1 - fib2
            fib2 = fibc - fib1
            print("fibc = %d, fib1 = %d, fib2 = %d"%(fibc,fib1,fib2))    
        else:
            return i
    if(fibc and arr[n-1] == key):
        return (n-1)
    
    return -1

arr = [2,3,4,10,40]
print(fibonacciSearch(arr,10,5))