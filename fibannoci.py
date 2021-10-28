# Program to display the Fibonacci sequence up to n-th term

N = int(input("Number of elements in Fibonacci Series, N, (N>=2) : "))

#initialize the list with starting elements: 0, 1
fibonacciSeries = [0,1]

if N>2:
	for i in range(2, N):
		#next elment in series = sum of its previous two numbers
		nextElement = fibonacciSeries[i-1] + fibonacciSeries[i-2]
		#append the element to the series
		fibonacciSeries.append(nextElement)

print(fibonacciSeries)
