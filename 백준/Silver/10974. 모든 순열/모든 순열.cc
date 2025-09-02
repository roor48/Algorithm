#include <iostream>
#include <string>
using namespace std;

int N;

bool used[9];

void f(int n, string s) {

    if (n > N) {
        for (char c : s)
            cout << c << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (used[i])
            continue;
        
        used[i] = true;
        f(n+1, s+(to_string(i)));
        used[i] = false;
    }
}

int main() {
    cin >> N;
    f(1, "");

    return 0;
}
