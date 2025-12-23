#include <bits/stdc++.h>
using namespace std;

int arr[1000], lis[1000];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    int ans_cnt = -1;
    for (int i = 0; i < N; i++) {
        ans_cnt = max(ans_cnt, lis[i]);
    }
    cout << ans_cnt+1 << '\n';

    vector<int> ans;
    for (int i = N-1; i >= 0; i--) {
        if (ans_cnt==lis[i]) {
            ans.push_back(arr[i]);
            ans_cnt--;
        }
    }

    vector<int>::iterator iter = ans.end();
    while (iter != ans.begin()) {
        iter--;
        cout << *iter << ' ';
    }
    
    
    return 0;
}
