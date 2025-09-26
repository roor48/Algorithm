#include <bits/stdc++.h>
using namespace std;

long long dp[31][31];

long long f(int w, int h) {
    if (w==0 && h==0) {
        return 1;
    }
    if (dp[w][h])
        return dp[w][h];

    long long ans = 0;
    if (w>0)
        ans += f(w-1, h+1);
    if (h>0)
        ans += f(w, h-1);

    return dp[w][h] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f(30, 0);
    
    int N;
    while (1) {
        cin >> N;
        if (!N) break;
        
        cout << dp[N][0] << '\n';
    }

    return 0;
}
