import math
print("Enter the integers:")
l=list(map(int.input().split())
str1=""
r=0
q=0
count=int(input("Enter the value of n:")
def lex(l1,count,str1):
    r=count%math.factorial(len(l1)-1)
    q=count//math.factorial(len(l1)-1)
    if r!=0:
      str1+=str(l1[q])
      l1.remove(l1[q])
      return(l1,r,str1)
    else:
      while len(l1)>1:
            str1+=str(l1[q-1])
            l1.remove(l1[q-1]) 
      str2=''.join(map(str, l1)) 
      return(l1,r,(str1+str2))
while (count-r)!=0:
    (l,count,str1)=lex(l,count,str1)
print("The permutation lexicographically = ",str1)
