import math
l=[0,1,2,3,4,5,6,7,8,9]
str1=""
r=0
q=0
count=1000000
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
print("The millionth permutation lexicographically = ",str1)
