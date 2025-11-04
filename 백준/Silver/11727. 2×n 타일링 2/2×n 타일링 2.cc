#include <bits/stdc++.h>
using namespace std;

int N;
int dp[3];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    dp[0] = 1;
    dp[1] = 3;
    if (N < 3) {
        cout << dp[N-1];
        return 0;
    }

    for (int i = 3; i <= N; i++) {
        dp[2] = (dp[1] + dp[0]*2) % 10007;
        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    cout << dp[2];

    return 0;
}
