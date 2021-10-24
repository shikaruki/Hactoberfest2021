def reverserightalgo(arr,i,j):#reverse in right side
    while(i<j):
        temp=arr[i]
        arr[i]=arr[j]
        arr[j]=temp
        i+=1
        j-=1

def reverseleftalgo(arr,i,j):#reverse in left side
    while(i<j):
        temp=arr[i]
        arr[i]=arr[j]
        arr[j]=temp
        i+=1
        j-=1
def printarr(arr,n):#priting the array
    for i in range(n):
        print(arr[i],end=' ')
    print()
def main():
    t=int(input())
    while(t>0):
        n,k=map(int,input().split())
        arr=list(map(int,input().split()))
        reverserightalgo(arr,n-k,n-1)
        reverserightalgo(arr,0,n-k-1)
        reverserightalgo(arr,0,n-1)
        printarr(arr,n)
        reverseleftalgo(arr,0,k-1)
        reverseleftalgo(arr,k,n-1)
        reverseleftalgo(arr,0,n-1)
        printarr(arr,n)
        t=t-1

if __name__=='__main__':
    main()
