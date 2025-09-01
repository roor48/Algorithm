#include <iostream>
#include <algorithm>
using namespace std;

int s[50];
int N, K;
int alpha;


int ans = 0;

void f(int k, int last) {
    if (k >= K || alpha == 0) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if ((s[i] & alpha) == 0)
                cnt++;
        }

        ans = max(ans, cnt);
        return;
    }

    for (int i = last; i < 26; i++) {

        if (alpha & (1 << i)) {
            alpha = alpha ^ (1 << i);
            f(k+1, i+1);
            alpha = alpha | (1 << i);
        }
    }
}

int main() {

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (char c : str) {
            s[i] = s[i] | (1 << (c - 'a'));
            alpha = alpha | (1 << (c - 'a'));
        }
    }

    f(0, 0);
    cout << ans;

    return 0;
}
