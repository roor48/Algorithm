#include <bits/stdc++.h>
using namespace std;

int N, R, C, cnt;
// r행 c열
void f(int n, int r, int c) {

    if (n<1) {
        if (r==R && c==C)
            cout << cnt;
        return;
    }
    n--;

    int nextR = r+(1<<n);
    int nextC = c+(1<<n);
    
    if (R>=r && R<nextR && C>=c && C<nextC) {
        f(n, r, c);
    } else if (R>=r && R<nextR && C>=nextC) {
        cnt += (1<<n * 1<<n);
        f(n, r, nextC);
    } else if (R>=nextR && C>=c && C<nextC) {
        cnt += (1<<n * 1<<n) * 2;
        f(n, nextR, c);
    } else {
        cnt += (1<<n * 1<<n) * 3;
        f(n, nextR, nextC);
    }
}

int main() {
    cin >> N >> R >> C;

    f(N, 0, 0);

    return 0;
}