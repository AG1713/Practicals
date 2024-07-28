# Question :-
# Write a Python program to store 12th class percentage of students in array. Write
# function for sorting array of floating point numbers in ascending order using bucket sort
# and display top five scores.


def insertion_sort(x):
    for i in range(1,len(x)):
        up = x[i]
        j= i-1 # Therefore, j+1 = i
        while ((j>=0) and (x[j]>up)):
            x[j+1] = x[j]
            j = j-1
        x[j+1] = up
    return x

def Bucket_Sort(x):
    arr = []
    num_buckets = 10

    for i in range(num_buckets): # Created buckets
        arr.append([])
    
    for j in x: # Inserted elements
        bucket_num = int(j//10)
        arr[bucket_num].append(j)
    
    for k in arr: # Sorted buckets
        insertion_sort(k)
    
    m = 0

    for i in range(num_buckets):
        for j in range(len(arr[i])):
            x[m] = arr[i][j]
            m = m+1

    return x

l1 = [90.67, 54.34, 67.86, 54.87, 86.45]
print(Bucket_Sort(l1))

        
