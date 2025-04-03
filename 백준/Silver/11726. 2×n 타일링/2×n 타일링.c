#include <stdio.h>

int dp[1001] = {0, 1, 2};

int f(int n)
{
  if (dp[n]) return dp[n];
  return dp[n] = (f(n-1) + f(n-2)) % 10007;
}

int main()
{
  int n;
  scanf("%d", &n);

  printf("%d", f(n));
}