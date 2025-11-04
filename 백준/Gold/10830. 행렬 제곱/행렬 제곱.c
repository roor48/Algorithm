#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

long long** make_2dArray(long long S) {
    long long** arr = (long long**)malloc(sizeof(long long*) * S + sizeof(long long) * S * S);
    long long* ptr = (long long*)(arr+S);
    for (long long i = 0; i < S; i++)
        arr[i] = ptr + i*S;

    return arr;
}

long long S, N;
long long **mat;

long long **multi(long long **a, long long **b) {
    long long **t = make_2dArray(S);

    for (long long i = 0; i < S; i++) {
        for (long long j = 0; j < S; j++) {
            long long _sum = 0;
            for (long long idx = 0; idx < S; idx++) {
                _sum = (_sum + a[i][idx] * b[idx][j]) % 1000;
            }

            t[i][j] = _sum;
        }
    }

    free(a);
    return t;
}


long long **pow(long long n) {
    if (n==1) {
        long long **t = make_2dArray(S);
        for (long long i = 0; i < S; i++)
            memcpy(t[i], mat[i], sizeof(long long)*S);

        return t;
    }

    long long **v = pow(n/2);

    if (n&1)
        return multi(multi(v, v), mat);

    return multi(v, v);
}


int main() {
    scanf("%lld %lld", &S, &N);
    mat = make_2dArray(S);
    for (long long i = 0; i < S; i++)
        for (long long j = 0; j < S; j++)
            scanf("%lld", mat[i]+j);
    long long **answer = pow(N);

    for (long long i = 0; i < S; i++) {
        for (long long j = 0; j < S; j++)
           printf("%lld ", answer[i][j]%1000);
        puts("");
    }

    free(mat);
    free(answer);
    return 0;
}
