#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[50];

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> S;

    for (int i = 0; i < N; i++) {
        int maxVal = -1;
        int maxIdx = -1;
        for (int j = min(N-1, S+i); j >= i; j--) {
            if (maxVal < arr[j]) {
                maxVal = arr[j];
                maxIdx = j;
            }
        }
        
        S -= (maxIdx-i);
        for (int j = maxIdx; j > i; j--) {
            swap(arr+j, arr+j-1);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}

/*

| 왼쪽은 고정 이후 계산에 포함 안함

5
|3 5 1 2 4
3
maxIdx = 1

5| 3 1 2 4
2
maxIdx = 1

5 3| 1 2 4
2
maxIdx = 4

5 3 4 1 2|
0
*/
