#include <bits/stdc++.h>
using namespace std;

int N;

int arr[7];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    if (N==1) {
        int hap=0, max_val=0;
        for (int i = 0; i < 6; i++) {
            hap += arr[i];
            max_val = max(max_val, arr[i]);
        }

        cout << hap-max_val;

        return 0;
    }

    
    int d1,d2=100,d3=150;

    d1 = *min_element(arr, arr+6);

    d2 = 100;
    for (int a = 0; a < 6; a++) {
        for (int b = a+1; b < 6; b++) {
            if (a+b==5)
                continue;
            
            d2 = min(d2, arr[a]+arr[b]);
        }
    }
    d3 = 150;
    for (int a = 0; a < 6; a++) {
        for (int b = a+1; b < 6; b++) {
            for (int c = b+1; c < 6; c++) {
                if ( (a+b==5) || (a+c==5) || (b+c==5))
                    continue;

                d3 = min(d3, arr[a]+arr[b]+arr[c]);
            }
        }
    }

    long long ans = 0;

    // 1층
    ans += (4ll*d2) + (4ll*d1*(N-2));

    // 2층 이상
    ans += (4ll*d3) + (8ll*d2*(N-2)) + (5ll*d1*(N-2)*(N-2));

    cout << ans;

    return 0;
}
