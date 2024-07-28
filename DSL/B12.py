# Question :-
# a) Write a Python program to store names and mobile numbers of your friends in sorted
# order on names. Search your friend from list using binary search (recursive and non-
# recursive). Insert friend if not present in phonebook

# b) Write a Python program to store names and mobile numbers of your friends in sorted
# order on names. Search your friend from list using Fibonacci search. Insert friend if not
# present in phonebook.
from math import floor


dict1 = {"ABC":9898989898, "MNO":1234567890, "PQR":8686868686, "XYZ":9191919191}
print(list(dict1.keys()))
print(dict1)

def Binary_Search_iterative(list1, size, key):
    start = 0;
    end = size-1;
    mid = floor(start + (end-start)/2) #

    while(start<=end):
        if(list1[mid] == key):
            return mid
        
        elif(list1[mid] != key):
            if(key < list1[mid]):
                end = mid-1

            elif(list1[mid] < key):
                start = mid+1
        
        mid = floor(start + (end-start)/2)
    return -1

def binary_search_recursive(key,l1, start, end):
    if(start>end):
        return -1
    
    mid = floor((start+end)/2)

    if(l1[mid] == key):
        return mid
    elif(l1[mid]>key):
        return binary_search_recursive(key, l1,start, mid-1)
    elif(l1[mid]<key):
        return binary_search_recursive(key, l1,mid+1, end)

l2 = [10,20,30,40,50,60,70]
# print(binary_search_iterative(10,l1,len(l1)))

def min(a,b):
    if(a>b):
        return b
    return a


def Fibonacci_search(arr, key, n):
    b = 0
    a = 1
    f = b + a

    while(f<n):
        b = a
        a = f
        f = b + a

    offset = -1

    while(f>1):
        i = min(offset+b, n-1)
        print("f =",f,",","a =",a,",","b =",b,",","offset =",offset,",","i =",i)

        if(arr[i]<key):
            f = a
            a = b
            b = f-a
            offset = i

        elif(arr[i]>key):
            f = b
            a = a-b
            b = f-a

        else:
            return i
        
print(Fibonacci_search(l2, 50, len(l2)))


l1 = [1,3,4,6,8,9,10]
print(binary_search_recursive('MNO',list(dict1.keys()),0,len(dict1)-1))
l1.insert(2,8)
print(l1)

d1 = {"ABC":1234, "PQR":8765, "LMN":6543}
sortedkeys = sorted(d1)
d2 = {}

for i in sortedkeys:
    d2[i] = d1[i]
print(d2)



print(Binary_Search_iterative(list(dict1.keys()), len(dict1), 'XYZ'))
    

