# Question :-
# In second year computer engineering class, group A student’s play cricket, group B
# students play badminton and group C students play football.
# Write a Python program using functions to compute following: -
# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET
# built-in functions)

# Assumptions :- Students are represented by their roll no. to avoid same names in a list


# Functions :- Union, intersection, difference, symmetric difference
def set_union(list1, list2):
    list3=[] # Output list

    for i in list1:
        list3.append(i)
    
    for j in list2:
        if(j not in list1):
            list3.append(j)

    return list3
    
def set_intersection(list1, list2):
    list3 = [] # Output list

    for i in set_union(list1, list2):
        if((i in list1) and (i in list2)):
            list3.append(i)
    
    return list3

def set_difference(list1, list2):
    list3 = [] # Output list

    for i in list1:
        if (i not in list2):
            list3.append(i)
    return list3

def set_sym_difference(list1, list2):
    list3 = [] # Output list

    for i in set_union(list1, list2):
        if(((i in list1) or (i in list2)) and (i not in set_intersection(list1, list2))):
            list3.append(i)
    return list3

# Members are roll no.s of students to avoid same name problem
cricket = [23, 42, 12, 43, 54, 13, 37, 45, 27,34]
badminton = [52, 18, 43, 27, 34, 64]
football = [32, 12, 26, 43, 67, 53, 13, 18, 35]

# a) List of students who play both cricket and badminton
print("List of students who play both cricket and badminton :", set_union(cricket, badminton))

# b) List of students who play either cricket or badminton but not both
print("List of students who play either cricket or badminton but not both :", set_sym_difference(cricket, badminton))

# c) Number of students who play neither cricket nor badminton
print("Number of students who play neither cricket nor badminton :", set_difference(football, set_union(cricket, badminton)))

# d) Number of students who play cricket and football but not badminton.
print("Number of students who play cricket and football but not badminton :", set_difference(set_union(cricket, football), badminton))
