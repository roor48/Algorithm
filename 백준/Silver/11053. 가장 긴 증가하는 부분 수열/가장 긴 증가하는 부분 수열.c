#include <stdio.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int dp[n];
  for (int i = 0; i < n; i++)
    dp[i] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }

  int maxNum = 0;
  for (int i = 0; i < n; i++)
    maxNum = max(maxNum, dp[i]);

  printf("%d", maxNum);

  return 0;
}
