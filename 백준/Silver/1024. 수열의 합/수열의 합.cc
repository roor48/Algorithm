#include <bits/stdc++.h>
using namespace std;

int N, L, hap[101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L;

    for (int i = 1; i < 101; i++) {
        hap[i] = hap[i-1] + i;
    }

    for (int l = L; l <= 100; l++) {
        if (N < hap[l-1])
            continue;

        if ((N-hap[l-1])%l == 0) {

            int a = (N-hap[l-1]) / l;

            for (int i = 0; i < l; i++) {
                cout << a+i << ' ';
            }

            return 0;
        }
    }

    cout << "-1";

    return 0;
}
