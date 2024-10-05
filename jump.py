import math

def jump_search(A, item):
    print("Entering Jump Search")
    n = len(A)                          
    m = int(math.sqrt(n))               
    i = 0                              

    while i != len(A)-1 and A[i] < item:
        print("Processing Block - {}".format(A[i: i+m]))
        if A[i+m-1] == item:          
            return i+m-1
            B = A[i: i+m-1]
            return linear_search(B, item, i)
        i += m

    B = A[i:i+m]                        
    print("Processing Block - {}".format(B))
    return linear_search(B, item, i)
