#include <stdio.h>

int countBit(int n) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (n&(1<<i))
            ans++;
    }
    return ans;
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    if (countBit(n) <= k) {
        puts("0");
        return 0;
    }

    int cnt = 0, h;
    for (int i = 31; i >= 0; i--) {
        if (n&(1<<i))
        {
            n &= ~(1<<i);
            cnt++;
        }
        
        if (k <= cnt) {
            printf("%d", (n ^ ((1<<i)-1))+1);
            break;
        }
    }

    return 0;
}
