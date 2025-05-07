'''
I. Selection Sort 
'''

def selection_sort(arr):
    n = len(arr)

    for i in range(n):
        min_index = i
        for j in range(i+1,n):
            if (arr[min_index] > arr[j]): min_index = j
        arr[min_index], arr[i] = arr[i], arr[min_index]

n = int(input("Enter the length of the array: "))
arr = []

for i in range(n):
    val = int(input("Element " + str(i+1) + ": "))
    arr.append(val)

selection_sort(arr)
print("Sorted array: ", arr)