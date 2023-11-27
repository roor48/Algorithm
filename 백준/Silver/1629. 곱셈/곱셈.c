#include <stdio.h>

int A, B, C;

long long f(int b)
{
  if (b==1) return A%C;

  long long num = f(b/2);
  if (b&1) return (num * f(b/2+1)) % C;
  return (num * num) % C;
}

int main()
{
  scanf("%d %d %d", &A, &B, &C);
  printf("%lld", f(B));
 
  return 0;
}
