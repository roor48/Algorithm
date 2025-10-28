#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100001], dp[100001][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = arr[0];
    int minVal = 100'000'001;
    dp[0][0] = arr[0];
    dp[0][1] = -100'000'001;
    for (int i = 1; i < N; i++) {
        if (dp[i-1][0] < 0) {
            dp[i][0] = arr[i];
            minVal = 100'000'001;
        } else {
            dp[i][0] = dp[i-1][0] + arr[i];
            minVal = min(minVal, arr[i]);
        }
        dp[i][1] = max(dp[i][0] - minVal, dp[i-1][1] + arr[i]);

        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < N; j++)
    //         cout << dp[j][i] << ' ';
    //     cout << '\n';
    // }

    cout << ans;

    return 0;
}
