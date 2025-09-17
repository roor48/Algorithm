#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int N, K;
int arr[1000];
int dp[1'000'001]; // dp[n]: n까지 오는데 필요한 숫자 최소 개수
int main() {
    fill(dp, dp+1'000'001, MAX);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> K;

    dp[0] = 0;
    int num=0;
    while(++num) {
        for (int i = 0; i < N; i++) {
            int beforeNum = num-arr[i];

            if (beforeNum < 0)
                continue;
            if (dp[beforeNum] == MAX)
                continue;

            dp[num] = min(dp[num], dp[beforeNum]+1);

            if (dp[num] > K)
                dp[num] = MAX;
        }

        if (dp[num] == MAX) {
            cout << (num&1 ? "jjaksoon" : "holsoon") << " win at " << num;
            break;
        }
    }
    
    return 0;
}
