#include <stdio.h>

int N, target, arr[99];
long long dp[99][21] = {0};


long long f(int n, int num)
{
    if (num<0 || num>20) return 0ll;
    if (n==N) return num == target;
    if (dp[n][num]) return dp[n][num];
    
    return dp[n][num] = f(n+1, num+arr[n]) + f(n+1, num-arr[n]);
}

int main()
{
    scanf("%d", &N);
    N--;
    for (int i = 0; i < N; i++)
        scanf("%d", arr+i);
    scanf("%d", &target);

    printf("%lld", f(1, arr[0]));

    
    return 0;
}

