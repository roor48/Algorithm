#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dp[100001];
queue<pair<int, int>> q;
int main()
{
    cin >> N >> K;

    q.push(make_pair(K, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos > 100000 || pos < 0 || dp[pos])
            continue;

        dp[pos] = cnt;
        if (pos==N)
            break;

        if (!(pos&1))
            q.push(make_pair(pos/2, cnt+1));
        q.push(make_pair(pos+1, cnt+1));
        q.push(make_pair(pos-1, cnt+1));
    }


    cout << dp[N];

    return 0;
}
