#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000000], m[1000000];
int m_size = 0;

int lower_bound(const int left, const int right, const int find) {
    if (left==right)
        return right;
    
    int mid = (left+right) / 2;

    if (m[mid] < find) {
        return lower_bound(mid+1, right, find);
    }
    return lower_bound(left, mid, find);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(0, m_size, arr[i]);
        m_size += pos==m_size;

        m[pos] = arr[i];
    }

    cout << m_size;

    return 0;
}
