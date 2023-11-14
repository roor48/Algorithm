#include <stdio.h>
#include <string.h>
#include <memory.h>

int dp[1001][1001];
int S1len, S2len;
char S1[1001], S2[1001];
char answer[1001];
int idx = 0;

int MAX(int a,int b){ return a>b?a:b; }

int f(int s1, int s2)
{
  if (s1>=S1len || s2>=S2len) return 0;
  if (dp[s1][s2] != -1) return dp[s1][s2];

  return dp[s1][s2] = MAX(f(s1+1, s2+1) + (S1[s1] == S2[s2]), MAX(f(s1+1, s2), f(s1, s2+1)));
}

void getLCS(int s1, int s2)
{
  if (s1 >= S1len || s2>=S2len)
    return;

  if (dp[s1][s2] == dp[s1][s2+1])
  {
    getLCS(s1, s2+1);
    return;
  }

  if (dp[s1][s2] == dp[s1+1][s2])
  {
    getLCS(s1+1, s2);
    return;
  }

  if (S1[s1] == S2[s2])
  {
    answer[idx++] = S1[s1];
    getLCS(s1+1, s2+1);
    return;
  }
}

int main()
{
  memset(dp, -1, sizeof(dp));
  scanf("%s %s", S1, S2);
  S1len = strlen(S1); S2len = strlen(S2);

  printf("%d\n", f(0, 0));
  getLCS(0, 0);
  printf("%s", answer);
  return 0;
}
/*
123456
ACAYKP
CAPCAK

재귀, for 역순
4
4 4 3 3 2 1
3 3 3 3 2 1
2 2 2 2 2 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 0 0 0

for 순
4
0 1 1 1 1 1
1 1 1 2 2 2
1 2 2 2 3 3
1 2 2 2 3 3
1 2 2 2 3 4
1 2 3 3 3 4
*/
