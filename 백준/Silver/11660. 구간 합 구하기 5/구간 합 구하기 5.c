#include <stdio.h>

int arr[1025][1025] ={0};

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &arr[j][i]);
      arr[j][i] += arr[j][i-1];
    }
  }

  while(m-->0)
  {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int sum = 0;
    for (int i = y1; i <= y2; i++)
    {
      sum += arr[i][x2] - arr[i][x1-1];
    }

    printf("%d\n", sum);
  }

  return 0;
}
