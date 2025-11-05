#include <bits/stdc++.h>
using namespace std;

int N, dp[31];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    
    int ans;
    if (N<3) {
        ans = dp[N];
    } else if (N&1) {
        ans = (dp[N] + dp[N/2]) / 2;
    } else {
        ans = (dp[N] + dp[N/2]) / 2 + dp[N/2-1];
    }
    

    cout << ans;

    return 0;
}

/*

||
-
O

|||
|-
|O
-|
O|

||-
-||
||O
O||
-O
O-
||||
|-|
|O|
--
OO

|||||
|||-
|--
||-|
-|-
|||O
|OO
||O|
O|O
|-O
|O-
-|O

*/
