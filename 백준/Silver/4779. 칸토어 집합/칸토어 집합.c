#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, Len;
char* arr;

int pwr(int n)
{
  int num = 1;
  for (int i = 0; i < n; i++)
  {
    num *= 3;
  }
  return num;
}

void f(int l, int r, int num)
{
  int pos1 = l+num, pos2 = r-num;
  for (int i = pos1; i < pos2; i++)
    arr[i] = ' ';

  if (pos2 - pos1 == 1) return;

  f(l, pos1, num/3);
  f(pos2, r, num/3);
}

int main()
{
  while (scanf("%d", &N) != EOF)
  {
    Len = pwr(N);
    arr = (char*)realloc(arr, sizeof(char) * (Len+1));
    memset(arr, '-', sizeof(char) * Len);
    arr[Len] = '\0';
    if (Len != 1)
      f(0, Len, Len/3);
    puts(arr);
  }
  
  free(arr);
  return 0;
}
