def ternary_search(arr,l,r,key):
    if(r>=l):
        mid1=l+int((r-1)//3)
        mid2=r-int((r-l)//3)
        if(arr[mid1]==key):
            return mid1
        if(arr[mid2]==key):
            return mid2
        if (key < arr[mid1]):
            return ternary_search(arr,l,mid1-l,key)
        elif(key>arr[mid2]):
            return ternary_search(arr,mid1+l,r,key)
        else:
            return ternary_search(arr,mid1+l,mid2-l,key)
    return -1

arr=[]
l=int(input("Enter the starting index: "))
r=int(input("Enter the last index: "))

print("Enter elements: ")
for i in range (l,r+1):
    arr.append(int(input()))

arr.sort()
key=int(input("Enter the number you want to search: "))

result=ternary_search(arr,l,r,key)

if(result==-1):
    print("Index not found")
else:
    print("Index of", key, "is", result)
