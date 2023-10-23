#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int* arr;
int N, cnt=0;

int abs(int a)
{
  return a < 0 ? -a : a;
}

int promissing(int i)
{
  for (int k = 0; k < i; k++)
    if (arr[i]==arr[k] || abs(arr[i]-arr[k]) == abs(i-k))
      return 0;
  return 1;
}

void f(int i)
{
  if (i==N)
  {
    cnt++;
    return;
  }

  for (int k = 0; k < N; k++)
  {
    arr[i] = k;
    if (promissing(i))
      f(i+1);
  }
}

int main()
{
  scanf("%d", &N);
  arr = (int*)calloc(N, sizeof(int));
  memset(arr, 0, sizeof(int) * N);

  f(0);
  printf("%d", cnt);
  
  free(arr);
}