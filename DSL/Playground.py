def minimum_index(l2):
    if (len(l2)==0):
        return None
    min_ind = 0
    for i in range(len(l2)):
        if(l2[min_ind]>l2[i]):
            min_ind = i
    return min_ind

def sel_sort(l1):
    m = len(l1)
    temp = 0

    for i in range(len(l1)):
        min_ind = minimum_index(l1[i:])
        min_ind = min_ind + i
        if(l1[i]>l1[min_ind]):
            temp = l1[i]
            l1[i] = l1[min_ind]
            l1[min_ind] = temp
    
    return l1

l = [1,5,3,5,8,9,8]
print(sel_sort(l))        