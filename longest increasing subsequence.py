def lis(s1,s2,m, n):
    x=0
    k=0
    dp=[[-1 for x in range(n+1)] for x in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif s1[i-1] > x and i < j:
                dp[i][j] = 1 + dp[i-1][j-1]
                x=s1[i-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]
s=[5,8,3,7,9,1]
print(lis(s,s,6,6))