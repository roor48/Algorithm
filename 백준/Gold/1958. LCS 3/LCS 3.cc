#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int dp[101][101][101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            for (int ci = 1; ci <= c.size(); ci++) {
                if (a[ai-1] == b[bi-1] && a[ai-1] == c[ci-1] && b[bi-1] == c[ci-1]) {
                    dp[ai][bi][ci] = dp[ai-1][bi-1][ci-1] + 1;
                } else {
                    dp[ai][bi][ci] = max(dp[ai-1][bi][ci], max(dp[ai][bi-1][ci], dp[ai][bi][ci-1]));
                }
            }
        }
    }

    cout << dp[a.size()][b.size()][c.size()];

    return 0;
}
