#include <stdio.h>

int arr[128][128] = {0};
int answer[2] = {0};

int CheckColor(int n, int y, int x)
{
  const int firstColor = arr[y][x];

  for (int i = y; i < y+n; i++)
  {
    for (int j = x; j < x+n; j++)
    {
      if (arr[i][j] != firstColor)
        return -1;
    }
  }
  
  return firstColor;
}

void f(int n, int y, int x)
{
  if (n==0) return;
  int val = CheckColor(n, y, x);
  if(val!=-1)
  {
    answer[val]++;
    return;
  }

  int half = n/2;

  f(half, y, x);
  f(half, y, x+half);
  f(half, y+half, x);
  f(half, y+half, x+half);
}

int main()
{
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &arr[i][j]);

  f(N, 0, 0);

  printf("%d\n%d", answer[0], answer[1]);


  return 0;
}