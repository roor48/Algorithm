#include <stdio.h>

int arr[2187][2187];
int cnt[3] = {0};

int isAllSame(int n, int y, int x)
{
  const int first = arr[y][x];
  for (int i = y; i < y+n; i++)
    for (int j = x; j < x+n; j++)
      if (first!=arr[i][j])
        return -1;

  return first+1;
}

void f(int n, int y, int x)
{
  if (n==0) return;

  int val = isAllSame(n, y, x);
  if (val!=-1)
  {
    cnt[val]++;
    return;
  }

  int half = n/3;

  f(half, y, x);
  f(half, y, x+half);
  f(half, y, x+(half*2));

  f(half, y+half, x);
  f(half, y+half, x+half);
  f(half, y+half, x+(half*2));

  f(half, y+(half*2), x);
  f(half, y+(half*2), x+half);
  f(half, y+(half*2), x+(half*2));
}

int main()
{
  int N;
  scanf("%d", &N);
  // arr = (int**)malloc(sizeof(int*)*N + sizeof(int)*N*N);
  // int* ptr = (int*)arr+N;
  // for (int i = 0; i < N; i++)
  //   arr[i] = ptr+(i*N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &arr[i][j]);

  f(N, 0, 0);

  printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);

  return 0;
}
