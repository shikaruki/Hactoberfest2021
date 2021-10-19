def sum_fibonacci(n):

    #Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21...
    sum = 0
    a = 0
    b = 1

    if n <= 1:
        return 0
    elif n == 2:
        return 1
    else:
        #added 1 to sum for the second term
        sum = 1 
        for i in range(3, n+1):
            sum_iter = a + b
            sum += sum_iter
            a = b
            b = sum_iter

    return sum

