#include <stdio.h>
#include <memory.h>
int MAX(int a,int b){return a>b?a:b;}

int arr[1000] = {10, 20, 10, 30, 20, 50}, dp[1000] = {0};
int answer[1000] = {0}, back[1000] = {0};
int N = 6;

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", arr+i);
    dp[i] = 1;
  }

  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        if (dp[j]+1 > dp[i])
        {
          dp[i] = dp[j]+1;
          answer[i] = j;
        }
      }
    }
  }

  int maxNum = 0;
  int maxIdx = 0;
  for(int i = 0; i < N; i++)
  {
    if (maxNum < dp[i])
    {
      maxIdx = i;
      maxNum = dp[i];
    }
  }
  // printf("%d %d\n", maxIdx, maxNum);
  // for (int i = 0; i < N; i++)
  //   printf("%d ", answer[i]);
  // puts("");

  int temp[1000] = {arr[maxIdx]}, idx = 1;

  while(idx<maxNum)
  {
    // printf("%d ", maxIdx);
    temp[idx++] = arr[answer[maxIdx]];
    maxIdx = answer[maxIdx];
  }
  puts("\n");
  printf("%d\n", maxNum);
  for (int i = idx-1; i >= 0; i--)
    printf("%d ", temp[i]);

  return 0;
}
/*
6
10 20 10 30 20 50
 0  1  0  2  1  3
answer : 0 0 0 1 0 3


5
1 6 7 1 4
0 1 2 0 1
*/
