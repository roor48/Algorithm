#include <bits/stdc++.h>
using namespace std;

int N;
int arr[200001];

int gcd(int a, int b) {
    if (a%b==0) return b;
    return gcd(b, a%b);
}
int getGCD(int left, int right) {
    int ans = arr[left];
    for (int i = left+1; i <= right; i++) {
        ans = gcd(ans, arr[i]);
    }

    return ans;
}

int f(int left, int right) {
    if (left > right) return 0;
    if (left==right) return arr[left];

    int len = right-left+1;
    int mid = left + (len/2);

    // 왼쪽 선택
    int val1 = getGCD(left, mid-1) + f(mid, right);
    // 오른쪽 선택
    int val2 = getGCD(mid, right) + f(left, mid-1);
    
    return max(val1, val2);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    

    cout << f(1, N);

    return 0;
}
