def rotateMatrix90(A):
    # Transpose
    for i in range(len(A)):
        for j in range(i, len(A)):
            A[i][j], A[j][i] = A[j][i], A[i][j]

        # return A
    
    # reverse 
    N= len(A)
    for i in range(N//2):
        for j in range(N):
            A[j][i], A[j][N-1-i] = A[j][N-1-i], A[j][i]

    return A        
A = [[1,2,3], [4,5,6], [7,8,9]]
print(rotateMatrix90(A))            