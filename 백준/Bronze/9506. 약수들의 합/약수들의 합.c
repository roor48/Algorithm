#include <stdio.h>

int main()
{
  while (1)
  {
    int n;
    scanf("%d", &n);
    if (n==-1) break;
    int arr[n];

    int cnt=0;
    for (int i = 1; i*i <= n; i++)
    {
      if (n%i == 0) 
        arr[cnt++] = i;
    }

    int temp = cnt;
    for (int i = temp-1; i>0; i--)
    {
      if (arr[cnt-1] != n/arr[i])
        arr[cnt++] = n/arr[i];
    }

    int sum = 0;
    for (int i = 0; i < cnt; i++)
    {
      sum+=arr[i];
    }
    if (sum==n)
    {
      printf("%d = %d", n, arr[0]);
      for (int i = 1; i < cnt; i++)
      {
        printf(" + %d", arr[i]);
      }
    }
    else
    {
      printf("%d is NOT perfect.", n);
    }
    puts("");
  }
}
