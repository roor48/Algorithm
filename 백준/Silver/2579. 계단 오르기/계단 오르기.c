#include <stdio.h>

int arr[301] = {0};
int dp[301][3] = {0};

int max(int a, int b)
{
  return a > b ? a : b;
}

int f(int n, int status)
{
  if (n<=0) return 0;
  if (dp[n][status]) return dp[n][status];

  int num = f(n-2, 1);
  if (status == 1)
    num = max(num, f(n-1, status+1));

  return dp[n][status] = num + arr[n];
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);
    
  printf("%d", f(n, 1));

  return 0;
}
