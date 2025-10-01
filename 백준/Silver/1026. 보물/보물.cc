#include <bits/stdc++.h>
using namespace std;

int N;
int A[50], B[50];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    
    sort(A, A+N);
    sort(B, B+N);

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i] * B[N-i-1];
    
    cout << ans;
        


    return 0;
}
