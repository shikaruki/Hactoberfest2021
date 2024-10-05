a=[2,5,5]
s=int(sum(a) / 2)
def eqsumpart(s,a,n):
    dp=[[False for x in range(s+1)] for y in range(n+1)]
    for i in range(n+1):
        for j in range(s+1):
            if i==0:
                dp[i][j] = False
            if j == 0:
                dp[i][j] = True
            elif a[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]]
    print(dp)
    return dp[n][s]
print(eqsumpart(s,a,len(a)))
