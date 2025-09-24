#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, N, a;
    
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof dp);
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a;
            
            dp[a] += 1;
            for (int m = a; m <= 10000; m++) {
                dp[m] += dp[m-a];
            }
        }
        
        cin >> a;
        cout << dp[a] << '\n';
    }

    return 0;
}
