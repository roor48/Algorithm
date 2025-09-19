#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main() {
    string a, b;
    cin >> a >> b;

    int a_len = a.size();
    int b_len = b.size();

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a_len][b_len];

    return 0;
}
