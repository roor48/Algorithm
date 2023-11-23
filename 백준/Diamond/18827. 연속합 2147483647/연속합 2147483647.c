#include <stdio.h>

long long max(long long a, long long b) {return a > b ? a : b;}

int main()
{
  int n;
  scanf("%d", &n);

  long long sum = 0;
  long long best = -1001;
  for (int i = 0; i < n; i++)
  {
    int num;
    scanf("%d", &num);
    sum = max(sum + num, num);
    best = max(best, sum);
  }

  printf("%lld", best);
}
