#include <stdio.h>

int N;
int nums[11] = {0};
int plus, minus, multi, divide;

int min = 2147483647, max = -2147483647;

int f(int n, int sum)
{
  if (n == N)
  {
    if (min > sum) min = sum;
    if (max < sum) max = sum;

    return 1;
  }

  if (plus > 0)
  {
    plus--;
    f(n+1, sum+nums[n]);
    plus++;
  }
  if (minus > 0)
  {
    minus--;
    f(n+1, sum-nums[n]);
    minus++;
  }
  if (multi > 0)
  {
    multi--;
    f(n+1, sum*nums[n]);
    multi++;
  }
  if (divide > 0)
  {
    divide--;
    f(n+1, sum/nums[n]);
    divide++;
  }

  return 0;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &nums[i]);
  scanf("%d %d %d %d", &plus, &minus, &multi, &divide);

  f(1, nums[0]);

  printf("%d\n%d", max, min);
}