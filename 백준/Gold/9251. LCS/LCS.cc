#include <iostream>

using namespace std;

int dp[1001][1001];

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  string S1, S2;
  cin >> S1 >> S2;

  S1 = '0'+S1;
  S2 = '0'+S2;

  // printf("%d %d", S1Len, S2Len);
  for (int i = 0; i < S1.size(); i++)
  {
    for (int j = 0; j < S2.size(); j++)
    {
      if (i==0 || j==0) dp[i][j] = 0;
      
      else if (S1[i]==S2[j]) dp[i][j] = dp[i-1][j-1] + 1;

      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  printf("%d", dp[S1.size()-1][S2.size()-1]);
}
