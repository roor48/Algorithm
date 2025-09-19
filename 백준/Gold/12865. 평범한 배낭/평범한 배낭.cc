#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[100], V[100];
int dp[100][100001];

int f(int n, int k) {
    if (k>K)
        return -1000000;
    if (n==N)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] =  max(f(n+1, k+W[n])+V[n], f(n+1, k));

}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }

    cout << f(0, 0);
    
    return 0;
}
