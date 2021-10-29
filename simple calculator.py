#hacktoberfest-accepted
#Simple Calculator

#define add function
def add(x, y):
    return x + y

#define subtract function
def subtract(x, y):
    return x - y

#define multiply function
def multiply(x, y):
    return x * y

#define divide function
def divide(x, y):
    return x / y


while True:
    #get number 1
    num1 = float(input("Enter first number : "))
    choice = input("Enter the operation (+,-,/,*) : ")
    
    #check wether the operation inputs are valid
    if choice in ('+', '-', '/', '*'):
        #get number 2
        num2 = float(input("Enter second number : "))

        #call the functions
        if choice == '+':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '-':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == '*':
            print(num1, "*", num2, "=", multiply(num1, num2))

        elif choice == '/':
            print(num1, "/", num2, "=", divide(num1, num2))

    else:
        print("Invalid Input")
    
    #continue or break the program
    next_calculation = input("Do you want to continue? (yes/no): ")
    if next_calculation == "no":
        break

    
