def partition(arr,low,high):
    i = ( low-1 )
    pivot = arr[high]
    for j in range(low , high):
        if   arr[j] <= pivot:
            i = i+1
            arr[i],arr[j] = arr[j],arr[i]
 
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return i+1

def qSort(arr,low,high):
    if low < high:
        pi = partition(arr,low,high)
        qSort(arr, low, pi-1)
        qSort(arr, pi+1, high)
 
l=list(map(int, input().split()))
qSort(l,0,len(l)-1)
print ("Sorted array is:",l)