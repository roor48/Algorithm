#include <iostream>
using namespace std;

int N;
int dp[1000001]; // dp[n]: n을 마지막으로 하는 1씩 증가하는 최장길이 수열의 길이

int main()
{
    cin >> N;
    int conn_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        dp[t] += dp[t-1] + 1;

        conn_cnt = max(conn_cnt, dp[t]);
    }

    cout << N - conn_cnt;

    return 0;
}
