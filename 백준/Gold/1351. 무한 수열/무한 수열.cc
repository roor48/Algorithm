#include <iostream>
using namespace std;

// 1000000000000
long long dp[10000000] = {1};
long long N, P, Q;

long long f(long long n)
{
    if (n >= 10000000)
        return f(n/P) + f(n/Q);

    if (dp[n]) return dp[n];

    return dp[n] = f(n/P) + f(n/Q);
}

int main()
{
    cin >> N >> P >> Q;
    
    cout << f(N);

    return 0;
}