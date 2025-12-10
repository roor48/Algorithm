#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n<=2)
    return n==2;
    if ((n&1)==0)
    return false;
    
    for (int i = 3; i*i <= n; i+=2) {
        if (n%i == 0)
        return false;
    }
    return true;
}

int nCrList[19][19];
int nCr(int n, int r) {
    if (n==r || r==0)
        return 1;
    if (n==1)
        return 1;

    if (nCrList[n][r])
        return nCrList[n][r];


    return nCrList[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
}

double dp[19][19][19];

int main() {
    
    double A, B;

    cin >> A >> B;
    
    A/=100.0;
    B/=100.0;

    // double sumA=0, sumB=0;

    // double ans=0;
    // // i: 골 넣은 횟수
    // for (int i = 0; i < 19; i++) {
    //     double tA = nCr(18, i) * pow(A, i) * pow(1.0-A, 18-i);
    //     double tB = nCr(18, i) * pow(B, i) * pow(1.0-B, 18-i);

    //     if (!isPrime(i)) {
    //         sumA += tA;
    //         sumB += tB;
    //     }
    // }

    // // cout << (sumA*sumB) + (sumA*(1.0-sumB)) + ((1.0-sumA)*sumB);
    // cout << 1.0 - sumA*sumB;

    dp[1][0][0] = (1.0 - A) * (1.0 - B);
    dp[1][0][1] = (1.0 - A) * B;
    dp[1][1][0] = A * (1.0 - B);
    dp[1][1][1] = A * B;

    for (int r = 2; r < 19; r++) {
        for (int a = 0; a <= r; a++) {
            for (int b = 0; b <= r; b++) {
                // 현재 라운드에서 아무도 골을 넣지 못한 경우
                dp[r][a][b] += dp[r-1][a][b] * (1.0 - A) * (1.0 - B);
                // a만 골 넣은 경우
                if (a>0) {
                    dp[r][a][b] += dp[r-1][a-1][b] * A * (1.0 - B);
                }
                // b만 골 넣은 경우
                if (b>0) {
                    dp[r][a][b] += dp[r-1][a][b-1] * (1.0 - A) * B;
                }
                // 둘 다 골 넣은 경우
                if (a>0 && b>0) {
                    dp[r][a][b] += dp[r-1][a-1][b-1] * A * B;
                }
            }
        }
    }

    double ans = 0.0;
    for (int a = 0; a < 19; a++) {
        for (int b = 0; b < 19; b++) {
            if (isPrime(a) || isPrime(b)) {
                ans += dp[18][a][b];
            }
        }
    }

    cout << ans;


    return 0;
}


/*
박스에 빨간 공과 파란 공이 있다.
박스에서 공을 꺼낼 때 빨간 공이 나올 확률이 항상 50% 라면
공을 총 18번 꺼냈을 때 나온 빨간 공의 개수가 소수일 확률은?

2, 3, 5, 7, 11, 13, 17



*/
