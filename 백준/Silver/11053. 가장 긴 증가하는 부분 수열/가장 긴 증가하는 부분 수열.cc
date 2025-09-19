#include <bits/stdc++.h>
using namespace std;

int arr[1000], dp[1000];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans+1;
    
    return 0;
}
