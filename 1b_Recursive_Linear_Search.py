def R_Linear_Search(arr, i, t):
    if i>=len(arr):
        return False
    if arr[i]==t:
        return True
    else:
        return R_Linear_Search(arr, i+1, t)

arr,target = list(map(int,input('Enter numbers : ').split())),int(input("Enter Target to be searched : "))
Conclusion = R_Linear_Search(arr, 0, target)
print("Element Found") if Conclusion==True else print("Element Not Found")