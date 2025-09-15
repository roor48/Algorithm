#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100], dp[10001];
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    queue<pair<int, int>> q; // {cnt, k}
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int cnt = q.front().first;
        int k = q.front().second;
        q.pop();

        if (k>10000)
            continue;
        if (dp[k] != -1)
            continue;

        dp[k] = cnt;
        for (int i = 0; i < N; i++) {
            q.push(make_pair(cnt+1, k+arr[i]));
        }
    }

    cout << dp[K];

    return 0;
}
