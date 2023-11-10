#include <stdio.h>

int dp[31][31] = {0};

long long f(int n, int r)
{
  if (r>n) return 0;
  if (n==r || r==0) return 1;
  if (dp[n][r]) return dp[n][r];

  dp[n][r] = f(n-1, r) + f(n-1, r-1);
  dp[n][n-r] = dp[n][r];
  return dp[n][r];
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    int n, r;
    scanf("%d %d", &r ,&n);
    printf("%lld\n", f(n, r));
  }
}
