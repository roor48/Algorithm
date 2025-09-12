#include<bits/stdc++.h>
using namespace std;

int N, dp[100001];
const int DIV = 9901;
int main() {
    cin >> N;

    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i-1]*2 + dp[i-2]) % DIV;
    }

    cout << dp[N];

    return 0;
}
