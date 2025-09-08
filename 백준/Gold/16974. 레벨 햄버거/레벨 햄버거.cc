#include <bits/stdc++.h>
using namespace std;

int N;
long long X;
long long len[51], Pcnt[51];

long long f(int n, long long left, long long right) {
    if (n==0) return 1LL;
    if (left == X) return 0LL;
    // 중앙 P의 인덱스
    long long mid = (left+right) / 2;
    
    // 반 이상을 먹을 예정이면
    if (mid == X) {
        return Pcnt[n-1]+1;
    }
    if (mid < X) {
        return Pcnt[n-1]+1 + f(n-1, mid+1, right-1);;
    }

    return f(n-1, left+1, mid-1);
}

int main() {
    cin >> N >> X;

    // 버거의 길이 얻기
    len[0] = 1;
    Pcnt[0] = 1;
    for (int i = 1; i <= 50; i++) {
        len[i] = len[i-1]*2 + 3;
        Pcnt[i] = Pcnt[i-1]*2 + 1;
    }

    cout << f(N, 1, len[N]);

    return 0;
}
