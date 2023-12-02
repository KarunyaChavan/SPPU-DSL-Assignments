m = int(input("Rows = "))
n = int(input("Columns = "))
mat = []
for i in range(m):
    a = []
    for j in range(n):
        a.append(int(input("Enter element mat[%d][%d] = "%(i,j))))
    mat.append(a)
for i in range(m):
    for j in range(n):
        print(mat[i][j],end=" ")
    print()
    
for i in range(m):
    row = mat[i][0]
    c = 0
    for j in range(1,n):
        if (row>mat[i][j]):
            row = mat[i][j]
            c = j
    col = mat[0][c]
    d = 0
    for k in range(1,n):
        if (col < mat[k][c]):
            col = mat[k][c]
            d = k
    if (row==col):
        print(f"{row} Found at {i}{c} ")