#include <stdio.h>
const int DIV = 1000000000;

int N, dp[1000001], squares[20];
int main() {
    
    scanf("%d", &N);

    squares[0] = 1;
    for (int i = 1; i < 20; i++) {
        squares[i] = squares[i-1]<<1;
    }

    dp[0] = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = squares[i]; j <= N; j++) {
            dp[j] = (dp[j] + dp[j-squares[i]]) % DIV;
        }
    }

    printf("%d", dp[N]);

    return 0;
}
