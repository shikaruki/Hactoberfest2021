for i  in range(1,6):
	for space in range(5,i,-1):
		print(end=" ")
	for j in range(1,i+1):
		print(j ,end="")
		if(j>=i):
			for j in range(i-1,0,-1):
					print(j ,end="")
	print()
for k in range(4,0,-1):
	for spacee in range(6,k+1,-1):
		print(end=" ")
	for m in range(1,k+1):
		print(m ,end="")
		if(m>=k):
			for m in range(k-1,0,-1):
				print(m ,end="")
	print()
