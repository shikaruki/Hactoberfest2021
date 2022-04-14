import time

def fibo():
    a=0
    b=1
    n=int(input("Ending Number for Fibanacci Series:"))
    for i in range(1,n):
        sum=a+b
        a=b
        b=sum
        print(sum)
        time.sleep(1)

start=time.time()
fibo()
stop=time.time()
print("Total time taken to print 100 fibonacci series is",stop-start)
