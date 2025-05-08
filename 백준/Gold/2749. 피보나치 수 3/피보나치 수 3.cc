#include <iostream>
#include <map>
#define MOD 1000000
using namespace std;

map<long long, long long> memo;
long long f(long long n)
{
    if (memo.find(n) != memo.end())
        return memo[n];

    if (n&1)
    {
        long long a = f(n/2);
        long long b = f(n/2+1);
        memo[n] = a*a + b*b;
    }
    else
    {
        memo[n] = f(n+1) - f(n-1);
        if (memo[n]<0)
            memo[n] += MOD;
    }

    return memo[n] %= MOD;
}

int main()
{
    memo[1] = 1;
    memo[2] = 1;
    long long N;
    cin >> N;

    cout << f(N);
    return 0;
}
