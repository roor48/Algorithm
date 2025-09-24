#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[4001];
int main() {
    cin >> a >> b;

    int ans = 0;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = b.length(); j > 0; j--) {
            dp[j] = a[i-1] == b[j-1] ? dp[j-1]+1 : 0;
            ans = max(ans, dp[j]);
        }
    }

    cout << ans;

    return 0;
}
