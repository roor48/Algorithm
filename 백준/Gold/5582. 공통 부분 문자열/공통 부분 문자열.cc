#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[4001][4001];
int main() {
    cin >> a >> b;

    int ans = 0;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i-1] != b[j-1])
                continue;
            
            dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans;

    return 0;
}
