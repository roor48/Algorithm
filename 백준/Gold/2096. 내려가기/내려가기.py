N = int(input())

arr = [[0,0,0]]
for _ in range(N):
    arr.append(list(map(int, input().split())))


dp = [[0, 0, 0] for _ in range(N+1)]

def f(comp):
    for i in range(1, N+1):
        for j in range(0, 3):
            if j==0:
                dp[i][j] = comp(dp[i-1][j], dp[i-1][j+1])
            elif j==1:
                dp[i][j] = comp(dp[i-1][j-1], comp(dp[i-1][j], dp[i-1][j+1]))
            elif j==2:
                dp[i][j] = comp(dp[i-1][j-1], dp[i-1][j])
        
            dp[i][j] += arr[i][j]


    return comp(dp[N][0], comp(dp[N][1], dp[N][2]))

print(f(max), f(min))