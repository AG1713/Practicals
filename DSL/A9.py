# Question :-
# Write a Python program to compute following computation on matrix:
# a) Addition of two matrices B) Subtraction of two matrices
# c) Multiplication of two matrices d) Transpose of a matrix

# Assumptions :- 
# 1) We have to use 2D lists in python (ofc)
# 2) We enter the same no. of rows and columns for both the matrices

# Functions :- making a matrix, displaying a matrix, addition, subtraction, multiplication and transpose of matrix
def make_mtr(mtr,m,n):
    sample = []

    for i in range(m):
        sample = []
        for j in range(n):
            temp = int(input(f"Enter the value of element of row {i+1} and column {j+1}: "))
            sample.append(temp) # Adding every elements
        mtr.append(sample)

def display_mtr(mtr):
    for i in range(0, len(mtr)):
        for j in range(0, len(mtr[i])):
            print(mtr[i][j], end = " ")
        print()
            
            
def add_mtr(mtr1,mtr2,m,n):
    mtr3 = []
    sample = []

    
    for i in range(m):
        sample = [] # This list is the individual row of 'mtr3' and evrytime it gets overwritten
        for j in range(n):
            sample.append(mtr1[i][j]+mtr2[i][j])
        mtr3.append(sample)
    
    return display_mtr(mtr3)
            
def sub_mtr(mtr1,mtr2,m,n):
    mtr3 = []
    sample = []
    
    
    for i in range(m):
        sample = []
        for j in range(n):
            sample.append(mtr1[i][j]-mtr2[i][j])
        mtr3.append(sample)
    
    display_mtr(mtr3)

def multi_mtr(mtr1, mtr2, m, n):
    mtr3_row = []
    mtr3 = []
    temp = 0
    for i in range(m):
        mtr3_row = []
        for j in range(n):
            temp = 0
            for k in range(n):
                temp = temp + mtr1[i][k]*mtr2[k][j]
            mtr3_row.append(temp)
        mtr3.append(mtr3_row)
    return mtr3

def trans(mtr):
    for i in range(0, len(mtr)):
        for j in range(0, len(mtr[i])):
            print(mtr[j][i], end = " ") # Rows and columns interchange, eg. first row second column element
            # becomes second row first column. Hence we swapped the index i and j.
        print()

m = int(input("Enter the number of rows: "))
n = int(input("Enter the number of columns: "))
mtr_1 = []
mtr_2 = []

print("Enter the values for first matrix")
mtr1 = make_mtr(mtr_1,m,n)
print("Enter the values for second matrix")
mtr2 = make_mtr(mtr_2,m,n)

print("Matrix 1")
display_mtr(mtr_1)

print("Matrix 2")
display_mtr(mtr_2)

print("Addtion of both the mattrix is :-")
add_mtr(mtr_1, mtr_2, m, n)

print("Subtraction of both the mattrix is :-")
sub_mtr(mtr_1, mtr_2, m, n)

print("Transpose of matrix is ")
trans(mtr_1)

print("Multiplication :",display_mtr(multi_mtr(mtr_1,mtr_2,m,n)))
