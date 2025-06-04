#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;


int dp[10000];
char cmd[5] = "DSLR";

void solve()
{
    int a, b;
    cin >> a >> b;

    int val, cnt, i;
    int D1, D2, S, L, R;
    int tmp, div, d[4];
    queue<pair<int, int>> q;

    q.push(make_pair(b, 0));
    while(!q.empty())
    {
        val = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (dp[val] != -1)
            continue;

        dp[val] = cnt;

        if (val == a)
            break;

        tmp = val, div=1000;
        for (i = 0; i < 4; i++)
        {
            d[i] = tmp/div;
            tmp %= div;
            div/=10;
        }

        if (val%2==0)
        {
            D1 = val/2;
            D2 = (val+10000) / 2;

            q.push(make_pair(D1, cnt+1));
            q.push(make_pair(D2, cnt+1));
        }

        S = val==9999 ? 0 : val+1;
        L = d[3]*1000 + d[0]*100 + d[1]*10 + d[2];
        R = d[1]*1000 + d[2]*100 + d[3]*10 + d[0];

        q.push(make_pair(S, cnt+1));
        q.push(make_pair(L, cnt+1));
        q.push(make_pair(R, cnt+1));
    }

    int cur = a;
    int next[4];

    while (cur != b)
    {
        tmp = cur, div=1000;
        for (i = 0; i < 4; i++)
        {
            d[i] = tmp/div;
            tmp %= div;
            div/=10;
        }

        next[0] = (cur*2) % 10000;
        next[1] = cur==0 ? 9999 : cur-1;
        next[2] = d[1]*1000 + d[2]*100 + d[3]*10 + d[0];
        next[3] = d[3]*1000 + d[0]*100 + d[1]*10 + d[2];

        for (i = 0; i < 4; i++)
        {
            if (dp[cur]-1 == dp[next[i]])
            {
                cout << cmd[i];
                cur = next[i];
                break;
            }
        }
    }

    cout << '\n';
}

int main()
{
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, -1, sizeof dp);
        solve();
    }

    return 0;
}
