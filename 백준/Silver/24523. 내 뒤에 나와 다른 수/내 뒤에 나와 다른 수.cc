#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001] = {1'000'000'001};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int ans = -1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == arr[i-1]) {
            cout << ans << ' ';
            continue;
        }

        ans = -1;
        for (int j = i+1; j <= N; j++) {
            if (arr[i] != arr[j]) {
                ans = j;
                break;
            }
        }

        cout << ans << ' ';
    }

    return 0;
}
