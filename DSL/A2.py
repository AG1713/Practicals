# Question :-
# Write a Python program to store marks scored in subject “Fundamental of Data
# Structure” by N students in the class. Write functions to compute following:
# a) The average score of class
# b) Highest score and lowest score of class
# c) Count of students who were absent for the test
# d) Display mark with highest frequency



def purify(list1):
    list2 = []
    for i in list1:
        if (i!=-1):
            list2.append(i)
        
    return list2


def avg(list1):
    length = len(list1)
    sum = 0

    for i in range(0, (length)):
        sum = sum+list1[i]

    avg = sum/length
    return avg

def highest(list1):
    max = list1[0]
    for i in list1:
        if(i>max):
            max = i
    return max
    
def lowest(list1):
    min = list1[0]
    for i in list1:
        if(i<min):
            min = i
    return min

def mode(list1):
    mode_eles = []
    unique_vals =  set(list1)

    dict1 = {}
    for i in unique_vals:
        dict1[i] = 0 # Creation of dictionary
    
    for i in list1:
        dict1[i] = dict1[i]+1
    # The dictionary now contains key coressponding to unique elements in list1 and values corressponding
    # to the number of times a value is repeated in list1
    
    h = highest(list(dict1.values())) # Getting the highest frequency
    new = list(dict1.items())
    print(new)

    for i in range(0,len(new)):
        if(new[i][1]==h):
            mode_eles.append(new[i][0])
    return mode_eles
    

# *****************************Function definitions end here******************************


list_total = []
n = int(input("Number of students : "))
temp = 0
print("If any student is absent, enter his/her marks as -1")

# The below for loops take input of marks 
for i in range(0,(n)):
    print("The marks of student",(i+1))
    temp = int(input())
    if ((temp>100)or(temp<-1)):
        print("The marks entered are invalid")
        print("The marks of student",(i+1))
        temp = int(input())
    
    list_total.append(temp)
# Loops end here 


list_present = list_total[:] # We made a copy of original list ()
list_present = purify(list_present)




print("*************************************************************************************")
print("Marklist of students :",list_total)
print("Average = ",avg(list_present))
print("Highest marks :",highest(list_present))
print("Lowest marks :",lowest(list_present))
print("Absent student :",len(list_total)-len(list_present))
print("The most reoccuring marks :",mode(list_present))
