#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000], hap[1000][1000];
int N, arr[1000];

int f(int l, int r) {
    if (l>=N || r>=N) {
        return 0;
    }
    if (dp[l][r] != -1) return dp[l][r];

    int ans = 0;
    for (int i = r+1; i < N; i++) {
        ans = max(ans, f(l, i));
    }
    ans = max(ans, f(r+1, r+2) + hap[l][r]);

    return dp[l][r] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    int s_min, s_max;
    for (int i = 0; i < N; i++) {
        s_max = s_min = arr[i];
        for (int j = i+1; j < N; j++) {
            s_max = max(s_max, arr[j]);
            s_min = min(s_min, arr[j]);
            
            hap[i][j] = s_max - s_min;
        }
    }
    
    cout << f(0, 1);
    return 0;
}
