#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int arr[20], dp[10001];
int main() {
    cin >> T;
    while(T--) {
        memset(dp, 0, sizeof dp);

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> M;
        
        for (int i = 0; i < N; i++) {
            dp[arr[i]] += 1;
            for (int m = arr[i]; m <= M; m++) {
                dp[m] += dp[m-arr[i]];
            }
        }

        cout << dp[M] << '\n';
    }


    return 0;
}
