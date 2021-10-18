#pattern printing
#input = int n
#Boolean True or False

# True
# *
# **
# ***
# ****

#False
# ****
# ***
# **
# *
from builtins import print
try:
    digit = int(input("Enter The No:"))
    boolean = int(input("Enter condition for printing pattern(0 or 1):"))
    if boolean == 1:
        for i in range(1, digit + 1):
            for j in range(i):
                print("*", end="")
            print(end="\n")#is default
    elif boolean == 0:
        for i in range(digit):
            for j in range(digit):
                print("*", end=" ")
            print()
            digit -= 1
    else:
        print("Enter Correct Details...")

except Exception as e:
    print(e)