#include <bits/stdc++.h>
using namespace std;

int N, S, K;
int V[51];

bool dp[51][1001];

int main() {
    cin >> N >> S >> K;
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    dp[0][S] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            int minus = j-V[i];
            int plus = j+V[i];

            if (minus>=0 && minus<=K) {
                if (dp[i-1][minus]) {
                    dp[i][j] = true;
                }
            }
            if (plus>=0 && plus<=K) {
                if (dp[i-1][plus]) {
                    dp[i][j] = true;
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i <= K; i++) {
        if (dp[N][i])
            ans = i;
    }

    cout << ans;

    return 0;
}
