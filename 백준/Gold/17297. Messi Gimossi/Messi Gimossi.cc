#include <bits/stdc++.h>
using namespace std;

int N, M, dp[41];

char messi2[] = "\0Messi Gimossi";

char f(int n, int m) {
    if (n<=2)
        return messi2[m];

    // 글자가 messi(n-1) 쪽에 있는 경우
    if (m <= dp[n-1])
        return f(n-1, m);

    // 글자가 공백인 경우
    int nextM = m-dp[n-1]-1;
    if (nextM == 0)
        return ' ';

    // 글자가 messi(n-2)에 있는 경우
    return f(n-2, m-dp[n-1]-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M;

    dp[1] = 5;
    dp[2] = 13;
    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i-1]+1+dp[i-2];
    }
    for (int i = 1; i < 41; i++) {
        if (M <= dp[i]) {
            N = i;
            break;
        }
    }

    char ans = f(N, M);
    if (ans==' ') {
        cout << "Messi Messi Gimossi";
    } else {
        cout << ans;
    }

    return 0;
}

/*

 5: 5
13: 5 7
19: 13 5
33: 19 13

Messi Gimossi Messi Messi Gimossi Messi Gimossi Messi

*/
