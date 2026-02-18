#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int main() {
    int T, N, M;
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof dp);
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            dp[a]++;
            for (int j = a; j <= 10000; j++) {
                dp[j] += dp[j-a];
            }
        }
        cin >> M;
        cout << dp[M] << '\n';
    }
    
    return 0;
}
