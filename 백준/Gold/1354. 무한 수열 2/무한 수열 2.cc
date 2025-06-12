#include <iostream>
#include <map>
using namespace std;

// 1000000000000
map<long long, long long> dp;
long long N, P, Q, X, Y;

long long f(long long n)
{
    if (n<=0) return 1;
    if (dp.find(n) != dp.end()) return dp[n];

    return dp[n] = f(n/P - X) + f(n/Q - Y);
}

int main()
{
    cin >> N >> P >> Q >> X >> Y;
    
    cout << f(N);

    return 0;
}