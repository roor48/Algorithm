#include <bits/stdc++.h>
using namespace std;

int C, N;
int dp[1100];
int main() {
    fill(dp+1, dp+1100, 1'000'000);

    cin >> C >> N;

    int ans = 1'000'000;
    int cost, client;
    for (int i = 0; i < N; i++) {
        cin >> cost >> client;

        for (int c = client; c <= 1099; c++) {
            dp[c] = min(dp[c], dp[c-client] + cost);
    
            if (c>=C && ans>dp[c]) {
                ans = dp[c];
            }
        }
    }

    cout << ans;

    return 0;
}
