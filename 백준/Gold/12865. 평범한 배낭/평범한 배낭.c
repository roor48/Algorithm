#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, K;
int things[101][2] = {0}; //[n][0] 무게 [n][1] 가치
int **dp;

int max(int a, int b)
{
  return a > b ? a : b;
}

int f(int n, int k)
{
  if (n>N || k>K) return 0;
  if (dp[n][k] != -1) return dp[n][k];

  dp[n][k] = -1;
  if (k+things[n][0] <= K) dp[n][k] = max(dp[n][k], f(n+1, k+things[n][0]) + things[n][1]);

  return dp[n][k] = max(dp[n][k], f(n+1, k));
}

int main()
{
  scanf("%d %d\n", &N, &K);

  int len = sizeof(int*) * (N+1) + sizeof(int) * (N+1) * (K+1);
  dp = (int**)malloc(len);
  memset(dp, -1, len);
  int* ptr = (int*)dp + N+1;
  for (int i = 0; i <= N; i++)
    dp[i] = ptr + (K+1) * i;

  for (int i = 1; i <= N; i++)
    scanf("%d %d\n", &things[i][0], &things[i][1]);

  printf("%d", f(1, 0));

  free(dp);
}
