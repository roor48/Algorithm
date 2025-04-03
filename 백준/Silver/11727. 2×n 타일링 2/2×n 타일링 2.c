#include <stdio.h>

int N;
int dp[1001] = {0};

int f(int n)
{
    if (n>N) return 0;
    if (n==N) return 1;
    if (dp[n]) return dp[n];

    return dp[n] = (f(n+1) + f(n+2)*2) % 10007;
}

int main()
{
    scanf("%d", &N);

    printf("%d", f(0));
    return 0;
}
