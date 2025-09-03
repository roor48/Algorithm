#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    int x, y, cnt;
    long long pos;
    while (T--) {
        cin >> x >> y;

        y -= x;
        pos = 0;
        cnt = 0;
        
        for(int i = 1;;i++) {
            pos += i*2;
            cnt += 2;

            if (pos-i >= y) {
                cout << cnt-1 << '\n';
                break;
            }

            if (pos >= y) {
                cout << cnt << '\n';
                break;
            }
        }
    }
    return 0;
}
