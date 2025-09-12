#include<bits/stdc++.h>
using namespace std;

int main() {
    int K, a, b;
    cin >> K;
    int t;
    while(K--) {
        cin >> a >> b;
        t = 1;

        while(b--) {
            t = (t * a) % 10;
        }

        if (!t)
            t = 10;
        cout << t << '\n';
    }
    
    return 0;
}
