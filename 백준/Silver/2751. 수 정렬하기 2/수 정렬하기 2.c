#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* arr;

void swap(int a, int b)
{
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

void f(int fr, int ba)
{
  if (fr >= ba) return;

  int pivot = (rand() % (ba-fr+1)) + fr;
  swap(pivot, ba);

  int pos = fr;
  for (int i = fr; i < ba; i++)
    if (arr[i] < arr[ba])
      swap(i, pos++);

  swap(pos, ba);

  f(fr, pos-1);
  f(pos+1, ba);
}

int main()
{
  // srand(time(NULL));
  int n;
  scanf("%d", &n);

  arr = (int*)malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr+i);

  f(0, n-1);

  for (int i = 0; i < n; i++)
    printf("%d\n", arr[i]);

  free(arr);
  return 0;
}
