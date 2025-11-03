#include <bits/stdc++.h>
#define DIV 1'000'000
using namespace std;

int N;
int dp[1001][2][3];

int f(int n, int lCnt, int aStreak) {
    if (lCnt >= 2 || aStreak >= 3)
        return 0;
    if (n==N)
        return 1;
    if (dp[n][lCnt][aStreak] != -1)
        return dp[n][lCnt][aStreak];

    return dp[n][lCnt][aStreak] =
                (f(n+1, lCnt, 0) + f(n+1, lCnt+1, 0) + f(n+1, lCnt, aStreak+1)) % DIV;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);

    cin >> N;
    
    cout << f(0, 0, 0);

    return 0;
}

/*

현재 일 수
총 지각 횟수
현재 결석 스택

dp[1001][2][3]

*/
