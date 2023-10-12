#include <stdio.h>
#include <string.h>

int N=0;
int dp[10001][4] = {0};
int podo[10001] = {0};

int f(int n, int status)
{
  if (n>N || status >= 3) return 0;
  if (dp[n][status] != -1) return dp[n][status];

  int num = f(n+1, status+1) + podo[n];

  for (int i = n+2; i <= N; i++)
  {
    int t = f(i, 1) + podo[n];
    if (t > num) num = t;
  }

  return dp[n][status] = num;
}

int main()
{
  memset(dp, -1, sizeof(int)*40004);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &podo[i]);
  }

  printf("%d", f(0, 0));
}

