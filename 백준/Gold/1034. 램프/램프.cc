#include <bits/stdc++.h>
using namespace std;

int N, M, K;
long long arr[50];

int countZero(long long n) {
    int cnt = 0;

    while (n) {
        n &= (n-1);
        cnt++;
    }

    return M-cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    map<long long, int> mapp;
    for (int i = 0; i < N; i++) {
        char t;
        for (int j = 0; j < M; j++) {
            cin >> t;
            
            arr[i] <<= 1;
            if (t=='1') {
                arr[i] |= 1;
            }
        }

        mapp[arr[i]]++;
    }
    cin >> K;
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = countZero(arr[i]);

        // i번 행이 절대로 켜질 수 없는 경우
        if (cnt>K || (cnt&1) != (K&1)) {
            continue;
        }

        ans = max(ans, mapp[arr[i]]);
    }

    cout << ans;

    return 0;
}
