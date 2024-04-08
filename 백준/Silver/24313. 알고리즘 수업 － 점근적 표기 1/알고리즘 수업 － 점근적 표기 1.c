#include <stdio.h>

int main()
{
  int a1, a0, c, n0;
  scanf("%d %d %d %d", &a1, &a0, &c, &n0);

  printf("%d", a1*n0+a0 <= c*n0 && c>=a1);
}