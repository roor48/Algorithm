#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);

  int dp[41][2] = {0};
  for (int _ = 0; _ < T; _++)
  {
    int n;
    scanf("%d", &n);

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
      dp[i][0] = dp[i-1][0] + dp[i-2][0];
      dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    printf("%d %d\n", dp[n][0], dp[n][1]);
  }
}
