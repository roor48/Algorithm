#include <iostream>
#include <string>
using namespace std;

int N, M, bottom=1; // 트리 바닥에 있는 요소 인덱스
int tree[2097152]; // tree[1] = 최상단 노드

void update(int node, int val)
{
    node += bottom;
    while (node)
    {
        tree[node] = min(tree[node], val);
        node/=2;
    }
}

int f(int left, int right)
{
    left += bottom;
    right += bottom;

    int ans = 2147483647;
    while (left <= right)
    {
        if (left&1) // 왼쪽 노드가 부모기준 오른쪽이면
        {
            ans = min(ans, tree[left]);
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
            ans = min(ans, tree[right]);
            right = right/2-1;
        }

    }

    return ans;
}


int main()
{
    cin.tie(0); cout.tie(0);
    fill(tree, tree+2097152, 2147483647);

    cin >> N >> M;
    while(bottom<N)
        bottom<<=1;
    bottom--;

    int a, b;
    for (int i = 1; i <= N; i++)
    {
        cin >> a;
        update(i, a);
    }

    while (M--)
    {
        cin >> a >> b;
        cout << f(a, b) << '\n';
    }

    return 0;
}
