#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ MATRIX MANIPULATION _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ 

#Defining a funtion to print the given matrix in a specified manner,
def show(mat, m, n):
	for i in range(m):#Accessing inner list(ith row) list
		for j in range(n):#Accessing each element (jth column) of the above list
			print("\t", mat[i][j],end="")
		print()
		
#-----------------------------------------------------------------------------------------------------------------------------------------------
#Defining a function to add given two matrices,	
def addMat(mat1,rows1, cols1, rows2, cols2, mat2):
	if (rows1!=rows2 or cols1!=cols2): #Checking condition for Addtion of Matrices 
		print("For Addition of Matrices rows should be same") 
		
	else:#If specified condition is true
		res = []#Creating the list to store the resultant matrix (NOTE:- This will same order as of both input matrices)S
		for i in range(rows1):
			s = []#Creating the rows in resultant matrix to accomodate the result of addtion of elements at each specific position
			for j in range(cols2):
				s.append(mat1[i][j]+mat2[i][j]) #Entering the value to the ith row and jth column
			res.append(s)#Appeding the list of resultant values as the ith row to matrix
		show(res, rows1, cols1)#Calling show function to display the given matrix
		return res
		
#-----------------------------------------------------------------------------------------------------------------------------------------------
#Defining a function to subtract the given matrices,		
def subMat(mat1,rows1, cols1, rows2, cols2, mat2):
	if (rows1!=rows2 or cols1!=cols2):#Checking validation for subtraction
		print("For Subtraction of Matrices rows should be same") 
	else:
		diff = []#Creating the list to store the results (NOTE:- This will same order as of both input matrices)
		for i in range(rows1):
			s = []#Creating the rows in resultant matrix to accomodate the result of subtraction of elements at each specific positon 
			for j in range(cols2):
				s.append(mat1[i][j]-mat2[i][j])#Entering the value to the ith row and jth column of the resultant matrix
			diff.append(s)#Appending the list of resultant values as ith row to matrix 
		show(diff, rows1, cols1)#Calling the function to display the resultant matrix
		return diff
	
#-----------------------------------------------------------------------------------------------------------------------------------------------
#Defining a function to muliply the given matrices,
def mulMat(mat1,rows1, cols1, rows2, cols2, mat2):
	if(cols1!=rows2):#Checking the validation for multiplication of matrices
		print("Not eligible for multiplication ")
	else:
		pro = []#Creating the resultant matrix (NOTE:- Order of this resultant matrix will be ROWS1 x COLS2)
		for i in range(rows1):
			mul = []
			for j in range(cols2):
				res = 0#Creating a variable to store the multiplication product for element at each specific position
				for k in range(cols2):
					res += mat1[i][k] * mat2[k][j] #Adding product of respective elements having transposed positions
				mul.append(res)#Append a value for element at index i,j
			pro.append(mul)
		show(pro, rows1, cols2)#Calling the function to display the resultant matrix
		return pro

#-----------------------------------------------------------------------------------------------------------------------------------------------
def transpose(mat1, rows1, cols1):
	transposed = []#Creating the trasnposed matrix
	temp = rows1
	rows1 = cols1
	cols1 = temp
	for i in range(rows1):
		t = []#Creating the ith row of above matrix
		for j in range(cols1):
			t.append(mat1[j][i]) #Swtiching the elements at index i,j with j,i 
		transposed.append(t)#Adding the elements to the ith row
	show(transposed, rows1, cols1)#Calling the function to display the transposed matrix
	return transposed
	
	
#-----------------------------------------------------------------------------------------------------------------------------------------------
#Reading values of matrix 1,
rows1 = int(input("Enter Rows for Matrix 1 = "))
cols1 = int(input("Enter Columns for Matrix 1 = "))

mat1 = []
for i in range(rows1):
	l1 = []
	for j in range(cols1):
		l1.append(int(input("Enter Element mat1[%d][%d] = "%(i,j))))
	mat1.append(l1)

#Reading values for matrix 2,
rows2 = int(input("Enter Rows for Matrix 2 = "))
cols2 = int(input("Enter Columns for Matrix 2 = "))
mat2 = []
for i in range(rows2):
	l2 = []
	for j in range(cols2):
		l2.append(int(input("Enter Element mat2[%d][%d] = "%(i,j))))
	mat2.append(l2)
	
#Displaying above created matrices,	
print("You have created following matrixes,")
print("Matrix 1 = ")
show(mat1, rows1, cols1)
print("Matrix 2 = ")
show(mat2, rows2, cols2)


ch = 1 #Initializing choice variable.
while(ch==1):
	opt = int(input("\nChoose Operation to be performed,\n1)Transpose of a matrix.\n2)Addtion of Matrices.\n3)Subtraction of Matrices.\n4)Multiplication of Matrices\nYour Choice = "))
	if (opt==1):
		opt2 = int(input("1)Matrix 1\n2)Matrix 2\nYour Choice = "))
		if (opt2==1):
			T = transpose(mat1, rows1, cols1) #Calling the transpose function
			
		else:
			T = transpose(mat2, rows2, cols2)
			
	elif (opt==2):
		A = addMat(mat1, rows1, cols1, rows2, cols2, mat2) #Calling the function to add matrices
		#show(A, rows1, cols1)
	elif(opt==3):
		S = subMat(mat1, rows1, cols1, rows2, cols2, mat2) #Calling the function to subtract matrices
		
	elif (opt==4):
		P = mulMat(mat1, rows1, cols1, rows2, cols2, mat2) #Calling the function to multiply matrices
		
	else:
		print("Kindly choose among the given option. ") #If by mistake user selects unspecified option
	
	ch = int(input("Do you want to continue ?\n1)Yes\n2)No\nYour Response = ")) #Updating value of choice variable to decide whether to continue or exit operations
			
