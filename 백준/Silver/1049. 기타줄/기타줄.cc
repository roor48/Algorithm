#include <bits/stdc++.h>
using namespace std;

int N, M;
int price6[50], price1[50];
int dp[101]; // [i]: i개의 줄을 최소치로 살 수 있는 값
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(dp, dp+101, 100001);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> price6[i] >> price1[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            // 줄 1개씩 사는 경우
            dp[i] = min(dp[i], dp[i-1] + price1[j]);
            // 세트로 사는 경우
            dp[i] = min(dp[i], dp[max(0, i-6)] + price6[j]);
        }
    }

    cout << dp[N];

    return 0;
}
