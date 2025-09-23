#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int cost;
    int client;
}city;

int C, N;
city arr[1001];
int dp[1100];
int main() {
    fill(dp, dp+1100, 1'000'000);

    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].cost >> arr[i].client;
    }

    int ans = 1'000'000;
    dp[0] = 0;
    for (int i = 0; i < N; i ++) {
        for (int c = arr[i].client; c <= 1099; c++) {
            dp[c] = min(dp[c], dp[c-arr[i].client] + arr[i].cost);

            if (c>=C) {
                ans = min(ans, dp[c]);
            }
        }
    }

    cout << ans;

    return 0;
}
