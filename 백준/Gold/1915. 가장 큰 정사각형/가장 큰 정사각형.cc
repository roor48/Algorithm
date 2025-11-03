#include <bits/stdc++.h>
using namespace std;

int N, M;
string arr[1000];
int dp[1000][1000];

int f(int y, int x) {
    if (y<0 || y>=N || x<0 || x>=M || arr[y][x]=='0')
        return 0;

    if (dp[y][x] != -1)
        return dp[y][x];

    int a = f(y, x+1);
    int b = f(y+1, x);
    int c = f(y+1, x+1);

    int minLevel = min(a, min(b, c));

    return dp[y][x] = minLevel+1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, f(i, j));
        }
    }

    cout << ans*ans;

    return 0;
}
