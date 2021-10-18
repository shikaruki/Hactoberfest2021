#! /usr/bin/python3

import math

#Function that returns true if x is perfect square
def isPerfectSquare(x):
    s = int(math.sqrt(x))
    return s*s == x

#Function that returns true if n in in Fibonacci series
def isFibonacci(n):
    return isPerfectSquare(5*n*n + 4) or isPerfectSquare(5*n*n - 4)

#Test above functions through 1-10
for i in range(1,11):
     if (isFibonacci(i) == True):
         print (i,"is in Fibonacci")
     else:
         print (i,"is not in Fibonacci")
