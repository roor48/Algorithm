#include <bits/stdc++.h>
using namespace std;

template<typename T>
T** make_2dArray(long long S)
{
    T** arr = (T**)malloc(sizeof(T*) * S + sizeof(T) * S * S);
    T* ptr = (T*)(arr+S);
    for (long long i = 0; i < S; i++)
        arr[i] = ptr + i*S;

    return arr;
}

long long S, N;
long long **mat;

long long **multi(long long **a, long long **b)
{
    long long **t = make_2dArray<long long>(S);

    for (long long i = 0; i < S; i++)
    {
        for (long long j = 0; j < S; j++)
        {
            long long _sum = 0;
            for (long long idx = 0; idx < S; idx++)
            {
                _sum = (_sum + a[i][idx] * b[idx][j]) % 1000;
            }

            t[i][j] = _sum;
        }
    }

    free(a);
    return t;
}


long long **pow(long long n)
{
    if (n==1)
    {
        long long **t = make_2dArray<long long>(S);
        for (long long i = 0; i < S; i++)
            memcpy(t[i], mat[i], sizeof(long long)*S);

        return t;
    }

    long long **v = pow(n/2);

    if (n&1)
        return multi(multi(v, v), mat);

    return multi(v, v);
}


int main()
{
    cin >> S >> N;
    mat = make_2dArray<long long>(S);
    for (long long i = 0; i < S; i++)
        for (long long j = 0; j < S; j++)
            cin >> mat[i][j];
    long long **answer = pow(N);

    for (long long i = 0; i < S; i++)
    {
        for (long long j = 0; j < S; j++)
           cout << (answer[i][j]%1000) << ' ';
        cout << '\n';
    }

    free(mat);
    free(answer);
    return 0;
}
