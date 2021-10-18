def fact(n):#recursion function for factorial
  if(n==1 or n==0):
    return 1
  else:
    n=n*fact(n-1)
    
