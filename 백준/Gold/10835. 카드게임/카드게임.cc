#include <bits/stdc++.h>
using namespace std;

int N;
int A[2000], B[2000];
int dp[2000][2000]; // A번 index, B번 index일때 가질 수 있는 최대 점수
int ans;

int f(int a, int b) {
    if (a==N || b==N)
        return 0;

    if (dp[a][b])
        return dp[a][b];

    dp[a][b] = max(f(a+1, b), f(a+1, b+1));
    if (A[a] > B[b])
        dp[a][b] = max(dp[a][b], f(a, b+1) + B[b]);

    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << f(0, 0);

    return 0;
}
