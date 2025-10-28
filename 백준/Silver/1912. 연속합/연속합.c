#include <stdio.h>

int max(int a, int b) {return a > b ? a : b;}

int main()
{
  int n;
  scanf("%d", &n);

  int sum = 0;
  int best = -1001;
  for (int i = 0; i < n; i++)
  {
    int num;
    scanf("%d", &num);
    sum = max(sum + num, num);
    best = max(best, sum);
  }

  printf("%d", best);
}
