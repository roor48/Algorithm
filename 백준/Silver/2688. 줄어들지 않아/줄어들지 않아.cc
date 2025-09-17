#include <bits/stdc++.h>
using namespace std;

long long dp[65][11];
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < 10; i++) 
        dp[1][i] = 10-i;

    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < 10; j++) {
            for (int ii = j; ii < 10; ii++) {
                dp[i][j] += dp[i-1][ii];
            }
        }
    }

    int N;
    while (T--) {
        cin >> N;
        cout << dp[N][0] << '\n';
    }
    
    return 0;
}
