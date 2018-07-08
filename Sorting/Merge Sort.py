def divide(left,right):
    a=[]
    i,j = 0,0
    n=len(left)
    m=len(right)
    while i+j<n+m:
        if i == n:
            a.append(right[j])
            j+=1
        elif j== m or left[i]<=right[j]:
            a.append(left[i])
            i+=1
        elif left[i]>right[j]:
            a.append(right[j])
            j+=1
        elif left[i]<=right[j]:
            a.append(left[i])
            i+=1    
    return a

def merge(arr, l, r):
    if r-l<=1:
        return arr[l:r]
    elif r-l>1:
        m = int((l+r)/2)
        left = merge(arr,l,m)
        right = merge(arr,m,r)
        return divide(left,right)

l=list(map(int, input().split()))
print(merge(l,0,len(l)))