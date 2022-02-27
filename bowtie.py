/*
BowTie Pattern:
Complete the given method solve that takes as parameter an integer n and prints a formation like the examples below.

Hint: Is there a relation between row number and the number of *? What about row number and number of .?

Example Input: 1
Example Output:

*.*
***
*.*

Example Input: 5
Example Output:

*.........*
**.......**
***.....***
****...****
*****.*****
***********
*****.*****
****...****
***.....***
**.......**
*.........*


*/

def solve(n):
    # write your code here
    col=2*n+1
    #for i in range(1,n+1):
    for r in range(1,n+1):
        for c in range(1,col+1):
            if(r>=c or c>=(col-r+1)):
                print("*",end="")
        
            else:
                print(".",end="")
        print()
        #print()
    for i in range(col):
        print("*",end="")
    print()
    for r in range(n,0,-1):
        for c in range(1,col+1):
            if(r>=c or c>=(col-r+1)):
                print("*",end="")
            else:
                print(".",end="")
        print()
    print()