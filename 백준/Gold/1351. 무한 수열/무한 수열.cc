#include <iostream>
#include <map>
using namespace std;

// 1000000000000
map<long long, long long> dp;
long long N, P, Q;

long long f(long long n)
{
    if (dp.find(n) != dp.end()) return dp[n];

    return dp[n] = f(n/P) + f(n/Q);
}

int main()
{
    dp[0] = 1;
    cin >> N >> P >> Q;
    
    cout << f(N);

    return 0;
}