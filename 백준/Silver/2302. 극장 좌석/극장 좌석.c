#include <stdio.h>

int N, M;
int vip[41] = {0};
int dp[41] = {1,1,2};

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++)
  {
    int t;
    scanf("%d", &t);
    vip[t] = 1;
  }

  for (int i = 3; i <= N; i++)
    dp[i] = dp[i-1] + dp[i-2];

  int sum = 1;
  int idx = 0;
  for (int i = 1; i <= N; i++)
  {
    if (i==N)
      sum *= dp[idx+(!vip[i])];
    else if (vip[i])
    {
      sum *= dp[idx];
      idx = 0;
    }
    else
      idx++;
  }

  printf("%d", sum);

  return 0;
}
