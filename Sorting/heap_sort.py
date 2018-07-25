import math

def heapify(a,rootIndex,l):
    #Checking if there is no child then return a
    largest = leftIndex = rightIndex = leftasRoot = rightasRoot = 0
    if rootIndex*2 +1 <l+1:
        leftIndex = rootIndex*2 +1
        leftasRoot = leftIndex
    if rootIndex*2 +2 <l+1:    
        rightIndex = rootIndex*2 + 2
        rightasRoot = rightIndex 
    if a[leftIndex]<a[rightIndex]:
        largest = rightIndex
    else:
        largest = leftIndex
    if a[rootIndex]<a[largest] and largest !=0:
        a[rootIndex],a[largest] = a[largest],a[rootIndex]
        
    #checking whether leftRoot has a single child or not, so checking for the existence of the left child of the right and left
    if(leftasRoot*2 + 1<l and leftasRoot !=0):
        a = heapify(a,leftasRoot,l)
    if(rightasRoot*2 +1<l and rightasRoot !=0):
        a = heapify(a,rightasRoot,l)
    return a

def sorting(a,l):
    while(l>0):
        #swaping
        a[l],a[0]=a[0],a[l]
        l-=1
        a = minHeap(a,l)
    return a

def minHeap(a,l):
    #calculating number of the root in the tree/array
    numberOfRoot = math.ceil(l/2)
    for i in range(1,numberOfRoot+1):
        findRoot = numberOfRoot -i
        a = heapify(a,findRoot,l)
        print(a)
    #from here, the array, a, is the now in the form of the maxHeap
    return a

a = list(map(int, input().split()))
print("MaxHeap is achieved-",minHeap(a,len(a)-1))
print("Sorted List is-",sorting(a,len(a)-1))