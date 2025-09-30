#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> dp[1001];
queue<pair<int, int>> q;

int f() {
    int L, t;
    cin >> L;
    for (int i = 1; i <= L; i++) {
        cin >> t;

        int hap = dp[i-1].second + t;

        if (hap <= t) {
            dp[i] = make_pair(i, t);
        } else {
            dp[i] = make_pair(dp[i-1].first, hap);
        }
    }

    int ans=INT32_MIN;
    pair<int, int> idx;
    for (int i = 1; i <= L; i++) {
        if (ans < dp[i].second) {
            ans = dp[i].second;
            idx = make_pair(dp[i].first, i);
        } else if (ans == dp[i].second) {
            if ((i - dp[i].first) < (idx.second - idx.first)) {
                idx = make_pair(dp[i].first, i);
            }
        }
    }

    q.push(idx);
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    long long ans=0, L;
    for (int i = 0; i < N; i++) {
        ans += f();
    }

    cout << ans << '\n';
    while (!q.empty()) {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
    
    return 0;
}
