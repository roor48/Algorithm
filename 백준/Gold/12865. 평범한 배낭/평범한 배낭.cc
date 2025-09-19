#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[100], V[100];
int dp[100001];

int main() {

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= K-W[i]; k++) {
            dp[k] = max(dp[k], dp[k+W[i]] + V[i]);
        }
    }

    cout << dp[0];
   
    return 0;
}
