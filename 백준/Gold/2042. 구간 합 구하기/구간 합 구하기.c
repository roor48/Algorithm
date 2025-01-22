#include <stdio.h>

int N, size=1;
long long tree[2097152];

void update(int node, long long diff)
{
    node += size;
    while (node)
    {
        tree[node] += diff;
        node /= 2;
    }
}

long long sum(int left, int right)
{
    left += size;
    right += size;

    long long val = 0;

    while (left<=right)
    {
        if (left%2==1)
        {
            val += tree[left];
            left++;
        }
        left /= 2;

        if (right%2==0)
        {
            val += tree[right];
            right--;
        }
        right /= 2;
    }

    return val;
}

int main()
{
    int M, K;
    int a,b;
    long long c;
    scanf("%d %d %d", &N, &M, &K);
    while(size<N)size<<=1;
    size--;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &c);
        update(i, c);
    }

    for (int i = 0; i < M+K; i++)
    {
        scanf("%d %d %lld", &a, &b, &c);

        if (a==1)
            update(b, c-tree[b+size]);
        else
            printf("%lld\n", sum(b, c));
    }
    return 0;
}
