#include <bits/stdc++.h>
using namespace std;

int D, K;
int main() {
    cin >> D >> K;

    int a, b, c;
    for (int k = 1; k <= K; k++) {
        int a, b, c;
        b = K;
        a = K-k;
        for (int i = D; i > 2; i--) {
            if (a<=0)
                break;
            
            c = b;
            b = a;
            a = c-b;
            
        }

        if (a>0 && a<=b) {
            cout << a << '\n' << b;
            break;
        }
    }
    return 0;
}