#include <iostream>
#include <memory.h>
using namespace std;

int N;
int dp3D[121] = {0}; // dp3D[121]은 N보다 커짐
int dp[300001] = {0}; // dp[i]: 대포알이 i개 있을때 최소 사면체 dp[n] + dp[i - dp3D[n]] 최소치가 달라질 수 있음

int maxIdx = 1;
int f(int n, int cnt)
{
    if (cnt > N)
        return 300000;
    if (n > maxIdx)
        return 300000;
    if (cnt==N)
        return 0;

    if (dp[cnt] != -1) return dp[cnt];

    int a = f(n+1, cnt); // 안만들기
    int c = f(n, cnt+dp3D[n])+1; // 계속 만들기
    int b = f(n+1, cnt+dp3D[n])+1; // 만들고 넘기기

    return dp[cnt] = min(a, min(b, c));
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> N;
    dp3D[1] = 1;

    int t = 1;
    for (int i = 2; i < 121; i++)
    {
        dp3D[i] = (t+=i) + dp3D[i-1];

        if (N >= dp3D[i])
            maxIdx = i;
    }

    cout << f(1, 0);

    return 0;
}
