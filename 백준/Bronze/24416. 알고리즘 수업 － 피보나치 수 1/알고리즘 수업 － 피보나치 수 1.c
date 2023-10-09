#include <stdio.h>

int f1(int n)
{
    if (n==1 || n==2) return 1;
    return f1(n-1) + f1(n-2);
}

// int dp[41] = {0,1,1};
// int cnt = 0;
// int f2(int n)
// {
//     if (dp[n]) return dp[n];
//     cnt++;
//     return dp[n] = f2(n-1) + f2(n-2);
// }

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d", f1(n), n-2);
}
