#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, K;
int dp[100001];
queue<pair<int, int>> q;
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> N >> K;

    q.push(make_pair(K, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos > 100000 || pos < 0 || dp[pos] != -1)
            continue;

        dp[pos] = cnt;
        if (pos==N)
            break;
            
            if (!(pos&1))
            q.push(make_pair(pos/2, cnt+1));
        q.push(make_pair(pos-1, cnt+1));
        q.push(make_pair(pos+1, cnt+1));
    }

    cout << dp[N] << '\n';

    int pos = N;
    for (int _ = 0; _ < dp[N]; _++)
    {
        for (int i = 0; i < 3; i++)
        {
            int n_pos = -1;
            if (i==0)
                n_pos = pos*2;
            else if (i==1)
                n_pos = pos+1;
            else if (i==2)
                n_pos = pos-1;
            
            if (n_pos > 100000 || n_pos < 0 || dp[pos] == -1)
                continue;

            if (dp[pos] - dp[n_pos] == 1)
            {
                cout << pos << ' ';
                pos = n_pos;
                break;
            }
            
        }
    }
    cout << K << ' ';

    return 0;
}
