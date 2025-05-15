#include <iostream>
using namespace std;

int N, M, K, bottom=1; // 트리 바닥에 있는 요소 인덱스
long long tree[2097152]; // tree[1] = 최상단 노드

void update(long long node, const long long diff)
{
    node += bottom;
    while (node)
    {
        tree[node] += diff;
        node/=2;
    }
}

long long sum(int left, int right)
{
    left += bottom;
    right += bottom;

    long long ans = 0;
    while (left <= right)
    {
        if (left&1) // 왼쪽 노드가 부모기준 오른쪽이면
        {
            ans += tree[left];
            left = left/2+1;
        }
        else
        {
            left/=2;
        }

        if (right&1) // 오른쪽 노드가 부모기준 오른쪽이면
        {
            right /= 2;
        }
        else
        {
            ans += tree[right];
            right = right/2-1;
        }

    }

    return ans;
}


int main()
{
    cin >> N >> M >> K;
    while(bottom<N)
        bottom<<=1;
    bottom--;

    long long a, b, c;
    for (int i = 1; i <= N; i++)
    {
        cin >> c;
        update(i, c);
    }

    for (int i = K+M; i>0; i--)
    {
        cin >> a >> b >> c;

        if (a==1)
        {
            update(b, c-tree[bottom+b]);
        }
        else
        {
            cout << sum(b, c) << '\n';
        }
    }

    return 0;
}
