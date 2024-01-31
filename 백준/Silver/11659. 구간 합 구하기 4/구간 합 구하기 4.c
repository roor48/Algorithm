#include <stdio.h>
#include <malloc.h>

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  int* arr = (int*)calloc(n+1, sizeof(int));
  arr[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    int num;
    scanf("%d", &num);

    arr[i] = num + arr[i-1];
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("%d\n", arr[b] - arr[a-1]);
  }

  return 0;
}