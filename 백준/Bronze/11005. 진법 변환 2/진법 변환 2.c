#include <stdio.h>

int main()
{
  char answer[24] = {0};
  int N, B;
  scanf("%d %d", &N, &B);

  int idx = 0;

  while(N)
  {
    char num = N % B;
    N/=B;
    if (num>9)
      num += 7;
    answer[idx++] = num + '0';
  }
  for (int i = idx-1; i >= 0; i--)
    printf("%c", answer[i]);
  
  return 0;
}
