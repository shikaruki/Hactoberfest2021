
#program to fibobacci series
#concept of the program:
""" first two values are taken from the user and they are added in a new variable
and the values of value a and value b are swapped to produce the number.."""

def fibo(num1,num2):
    #printing the first and second value..
    print(num1,end=" ")
    print(num2,end=" ")

    for i in range(1,10):
        num3=int(num1+num2)#new variable
        #swapping the values
        num1=num2
        num2=num3

        #printting the result :)
        print(num3,end=" ")

        #inputs and calling the function
num1=int(input("enter the number: "))
num2=int(input("enter the second value: "))
fibo(num1,num2)
