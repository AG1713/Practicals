# Question :-
# Write a Python program to store first year percentage of students in array. Write
# function for sorting array of floating point numbers in ascending order using
# a) Selection Sort
# b) Bubble sort and display top five scores.



# Functions
def minimum_index(l2):
    if (len(l2)==0):
        return None
    min_ind = 0
    for i in range(len(l2)):
        if(l2[min_ind]>l2[i]):
            min_ind = i
    return min_ind

def sel_sort(l2):
    temp = 0
    for i in range(len(l2)):
        if(minimum_index(l2[i:]) == None):
            return l2
        
        a = i + minimum_index(l2[(i):])

        temp = l2[a]
        l2[a] = l2[i]
        l2[i] = temp

        # l2[a] = l2[a]+l2[i]
        # l2[i] = l2[a]-l2[i]
        # l2[a] = l2[a]-l2[i]
        # for some reason, this is not working
    return l2

def bub_sort(l1):
    length = len(l1)
    for i in range(length-1): # Number of times 
        for j in range(length-i-1):
            if(l1[j]>l1[j+1]):
                # Swapping
                temp = l1[j]
                l1[j] = l1[j+1]
                l1[j+1] = temp
    print(l1)
    return l1

# DO NOT READ THE BELOW FUNCTION FOR PRACTICALS, DO NOT EVEN READ, ITS JUST MY NO TE
# def bub_sort(l1): # This is not bubble sort,!
#     i = 0
#     temp = 0
#     while(i<len(l1)):
#         if(i == (len(l1)-1)):
#             break
#         elif (l1[i]>l1[i+1]):
#             temp = l1[i]
#             l1[i] = l1[i+1]
#             l1[i+1] = temp
#             i = 0
#         else:
#             i = i+1
#     return l1


# You can read after this line


# Taking input
percentages = []
m = int(input("Enter the number of students :"))

for i in range(0,m):
    percentages.append(int(input(f"Percentage of student {i+1} :")))



# Applying functions to the input list
print("\n\n*****************************************************************************")
print("Unsorted list of percentages :",percentages)
percentages_edited = percentages
print("Sorted list via bubble sort :", bub_sort(percentages_edited))
percentages_edited = percentages # We do this to revert the list to original unrdered form to make sure sel_sort is working
print("Sorted list via Selection sort :", sel_sort(percentages_edited))


length = len(percentages_edited)
print("First 5 percentages are :",end=' ')
for i in range(length-5,length):
    if(i<0):
        continue
    print(percentages_edited[i], end=' ')

