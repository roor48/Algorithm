#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, dp[2001];

int mex(const vector<int> g)
{
    int ans = 0;
    while (1)
    {
        if (find(g.begin(), g.end(), ans) == g.end())
            return ans;
        ans++;
    }
}

int main()
{
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; i++)
    {
        vector<int> t;
        for (int j = 1; j <= (i+(i&1))/2; j++) // x를 그리는 위치, 대칭은 제외
        {
            int t2 = 0;
            if (j >= 4)
                t2 = dp[j-3];
            t2 ^= dp[i-j-2];

            t.push_back(t2);
        }
        dp[i] = mex(t);
    }

    cout << (dp[N] != 0 ? '1' : '2');

    return 0;
}
