#include <stdio.h>

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", arr+i);

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[i])
      {
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
      }
    }
  }

  printf("%d", arr[n-k]);

  return 0;
}