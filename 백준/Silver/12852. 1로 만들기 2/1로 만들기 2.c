#include <stdio.h>
#include <memory.h>

int dp[1000001] = {0};
int answer[1000001];
int N, idx=0;

int MIN(int a, int b){return a < b ? a : b;}

int f(int n)
{
  if (dp[n]!=-1) return dp[n];

  int num = f(n-1)+1;
  if (n%2==0)
    num = MIN(num, f(n/2)+1);
  if (n%3==0)
    num = MIN(num, f(n/3)+1);

  return dp[n] = num;
}

void getNum(int n, int nextNum)
{
  if (n==1) return;
  if (n%3==0 && dp[n/3] == nextNum)
  {
    answer[idx++] = n;
    getNum(n/3, nextNum-1);
    return;
  }

  if (n%2==0 && dp[n/2] == nextNum)
  {
    answer[idx++] = n;
    getNum(n/2, nextNum-1);
    return;
  }

  answer[idx++] = n;
  getNum(n-1, nextNum-1);
}

int main()
{
  memset(dp, -1, sizeof(dp));
  scanf("%d", &N);

  dp[0] = dp[1] = 0;
  dp[2] = dp[3] = 1;

  printf("%d\n", f(N));
  getNum(N, dp[N]-1);

  answer[idx++] = 1;
  for (int i = 0; i < idx; i++)
    printf("%d ", answer[i]);
}
/*
10

0
0
1
1
2
3
2
3
3
2
3



15

0
0
1
1
2
3
2
3
3
2
3
4
3
4
4
4
*/
