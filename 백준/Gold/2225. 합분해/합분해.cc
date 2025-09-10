#include <bits/stdc++.h>
using namespace std;

const int DIV = 1'000'000'000;
int N, K, dp[201][201];
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= K; i++)
        dp[1][i] = i;

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % DIV;
    }



    cout << dp[N][K];
    return 0;
}
