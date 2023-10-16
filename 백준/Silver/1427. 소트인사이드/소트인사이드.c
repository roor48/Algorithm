#include <stdio.h>
#include <stdlib.h>

char* arr;

void swap(int a, int b)
{
  char t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

void f(int fr, int ba)
{
  if (fr>=ba) return;

  int pos = 0;
  for (int i = 0; i < ba; i++)
  {
    if (arr[ba] <= arr[i])
    {
      swap(pos++, i);
    }
  }
  swap(pos, ba);

  f(fr, pos-1);
  f(pos+1, ba);
}

int main()
{
  int N;
  scanf("%d", &N);

  int t = N;
  int len = 0;
  while(t)
  {
    len++;
    t/=10;
  }

  t = N;
  arr = (char*)malloc(sizeof(char)*(len+1));
  arr[len] = '\0';
  for (int i = 0; i < len; i++)
  {
    arr[i] = t%10 + '0';
    t/=10;
  }

  f(0, len-1);
  printf("%s", arr);

}
