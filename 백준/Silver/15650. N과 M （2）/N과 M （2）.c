#include <stdio.h>
#include <stdlib.h>

int N, M;
int* arr;

int promissing(int n)
{
  if (n > 0 && arr[n-1] >= arr[n])
    return 0;
  for (int i = 0; i < n; i++)
    if (arr[i] == arr[n]) return 0;

  return 1;
}

void f(int n)
{
  if (n==M)
  {
    for (int i = 0; i < M; i++)
      printf("%d ", arr[i]);
    puts("");

    return;
  }

  for (int i = 1; i <= N; i++)
  {
    arr[n] = i;
    if(promissing(n))
    {
      f(n+1);
    }
  }
}

int main()
{
  scanf("%d %d", &N, &M);
  arr = (int*)calloc(M, sizeof(int));

  f(0);

  free(arr);
  return 0;
}