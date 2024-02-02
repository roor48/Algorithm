#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
  int n, m, *arr, *hop;
  scanf("%d %d", &n, &m);

  arr = (int*)calloc(n+1, sizeof(int));
  hop = (int*)calloc(m, sizeof(int));
  arr[0] = 0;
  memset(hop, 0, sizeof(int) * (n+1));

  for (int i = 0; i < n; i++)
  {
    int t;
    scanf("%d", &t);
    arr[i+1] = (arr[i] + t) % m;
  }
 
  for (int i = 0; i <= n; i++)
  {
    hop[arr[i]]++;
  }

  long long answer = 0;
  for (int i = 0; i < m; i++)
  {
    if (hop[i]>1)
      answer += ((long long)hop[i] * (hop[i]-1)) / 2;
  }

  printf("%lld", answer);

  free(arr); free(hop);
  return 0;
}
