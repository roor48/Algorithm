#include <stdio.h>

int isPrime(int n)
{
  if (n==1) return 0;
  for (int i = 2; i*i <= n; i++)
  {
    if (n%i==0) return 0;
  }
  return n;
}

int main()
{
  int M, N;
  scanf("%d\n%d", &M, &N);

  int sum = 0, firstNum = 0;
  for (int i = M; i <= N; i++)
  {
    sum+=isPrime(i);
    if (!firstNum) firstNum = sum;
  }

  if (sum) printf("%d\n%d", sum, firstNum);
  else puts("-1");
}
