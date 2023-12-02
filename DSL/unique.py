def unique(l):
    cl = l.copy()
    nl = []
    size = 0
    for i in range(len(l)-1):
        flag = 0
        for j in range(i+1,len(l)):
            if l[i]==cl[j]:
                flag = 1
        if (flag == 0):
            nl.append(l[i])
            size += 1
    nl.append(l[-1])
    size += 1
    return nl


l = ['s','s','h','s','b','k','b']
print(unique(l))