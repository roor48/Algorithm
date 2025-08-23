#include <iostream>
using namespace std;

int N;
int dp[5000];
int f(int n) {
    if (n > N) return 5000;
    if (n == N) return 0;
    if (dp[n]) return dp[n];

    int t = min(f(n + 5), f(n + 3)) + 1;

    return dp[n] = t;
}

int main() {
    cin >> N;

    int ans = f(0);
    cout << (ans > 5000 ? -1 : ans);

    return 0;
}
