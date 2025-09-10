#include <bits/stdc++.h>
using namespace std;
const int DIV = 1000000;

// [i][0]: i-1번과 붙어있지 않는 경우의 수
// [i][1]: i번 까지의 모든 경우의 수
int dp[5000][2];
int main() {
    string s;
    cin >> s;

    if (s[0]=='0') {
        cout << "0";
        return 0;
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '0' && (s[i-1] > '2' || s[i-1] == '0')) {
            cout << "0";
            return 0;
        }
    }

    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < s.length(); i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1];

        if (s[i] == '0') {
            continue;
        }
        if (s[i+1] == '0') {
            continue;
        }
        if (s[i-1] == '1') {
            dp[i][1] = (dp[i][1] + dp[i-1][0]) % DIV;
            continue;
        }
        if (s[i-1] == '2') {
            if (s[i] >= '0' && s[i] <= '6') {
                dp[i][1] = (dp[i][1] + dp[i-1][0]) % DIV;
                continue;
            }
        }
    }

    cout << dp[s.length()-1][1];

    return 0;
}
