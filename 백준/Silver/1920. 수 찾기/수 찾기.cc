#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100000];

int bSearch(int target) {
    int left, mid, right;
    left = 0;
    right = N-1;

    while (left<=right) {
        mid = (left+right)/2;

        if (arr[mid]==target) {
            return 1;
        }

        if (left==right) {
            return 0;
        }

        if (target < arr[mid]) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    cin >> M;
    int t;
    for (int i = 0; i < M; i++) {
        cin >> t;

        cout << bSearch(t) << '\n';
    }

    return 0;
}