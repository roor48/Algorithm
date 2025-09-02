#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    if (__builtin_popcount(n) <= k) {
        cout << "0";
        return 0;
    }

    int cnt = 0, h;
    for (int i = 31; i >= 0; i--) {
        if (n&(1<<i))
        {
            n &= ~(1<<i);
            cnt++;
        }
        
        if (k <= cnt) {
            cout << (n ^ ((1<<i)-1))+1;
            break;
        }
    }

    return 0;
}