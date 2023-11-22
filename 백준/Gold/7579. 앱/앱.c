#include <stdio.h>

int N, M;
int A[101], C[101];
int dp[10001] = {0};

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < N; i++)
    scanf("%d", &C[i]);

  int size = 0; // size = 15
  for (int i = 0; i < N; i++)
    size+=C[i];

  for (int i = 0 ; i < N; i++)
  {
    for (int j = size; j >= C[i]; j--)
    {
      dp[j] = max(dp[j], dp[j-C[i]] + A[i]);
    }
  }

  for (int i = 0; i <= size; i++)
  {
    if (dp[i] >= M)
    {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}
