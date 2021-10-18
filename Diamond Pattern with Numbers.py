print(end="Enter Row Size (Total Lines): ")
rowSize = int(input())
if rowSize%2==0:
  halfDiamRow = int(rowSize/2)
else:
  halfDiamRow = int(rowSize/2)+1
space = halfDiamRow-1
for i in range(1, halfDiamRow+1):
  for j in range(1, space+1):
    print(end=" ")
  space = space-1
  for j in range(2*i-1):
    print(end="*")
  print()
space = 1
for i in range(1, halfDiamRow):
  for j in range(1, space+1):
    print(end=" ")
  space = space+1
  for j in range(1, 2*(halfDiamRow-i)):
    print(end="*")
  print()
