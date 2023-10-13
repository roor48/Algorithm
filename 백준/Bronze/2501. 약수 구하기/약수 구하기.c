#include <stdio.h>

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  int cnt = 0;
  int arr[n];

  for (int i = 1; i*i <= n; i++)
  {
    if (n%i == 0) 
      arr[cnt++] = i;
  }

  int cntF = cnt;
  for (int i = cntF-1; i>=0; i--)
  {
    if (arr[cnt-1] != n/arr[i])
      arr[cnt++] = n/arr[i];
  }

  if (cnt < k) puts("0");
  else printf("%d", arr[k-1]);
}
