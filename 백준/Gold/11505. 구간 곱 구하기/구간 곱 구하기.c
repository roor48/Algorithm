#include <stdio.h>

int arr[1000001];
int tree[2097152];

int makeTree(int start, int end, int node)
{
    if (start==end)
        return tree[node] = arr[end];
    
    int mid = (start+end) / 2;
    return tree[node] = (long long)makeTree(start, mid, node*2) * makeTree(mid+1, end, node*2 + 1) % 1000000007;
}

int multi(const int left, const int right, int start, int end, int node)
{
    if (end<left || start>right)
        return 1;
    if (start>=left && end<=right)
        return tree[node];

    int mid = (start+end) / 2;
    return (long long)multi(left, right, start, mid, node*2) * multi(left, right, mid+1, end, node*2 + 1) % 1000000007;
}

int update(const int index, const int after, int start, int end, int node)
{
    if (index < start || index > end)
        return tree[node];
    if (start==end)
        return tree[node] = after;
    int mid = (start+end) / 2;
    int left = update(index, after, start, mid, node*2);
    int right = update(index, after, mid+1, end, node*2+1);

    return tree[node] = (long long)left * right % 1000000007;
}

int main()
{
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", arr+i);
    makeTree(1, N, 1);
   
    int a,b,c;
    for (int _=K+M;_>0;_--)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a==1)
        {
            update(b, c, 1, N, 1);
            arr[b] = c;
        }
        else
        {
            printf("%d\n", multi(b, c, 1, N, 1));
        }
    }    
    return 0;
}

/*

4142 * 7120 * 922 * 10097 * 132
36,239,925,542,219,520 % 3189
900

4142 % 3189 * 7120 % 3189 * 922 % 3189 * 10097 % 3189 * 132 % 3189


1 2 3 4 5

            120
        6            20
    2       3     4      5
1      2


120 6 20 2 3 4 5 1 2 0 0 0 0 0 0 0

1 2 6 4 2
            96
        12            8
    2       6     4      2
1      2


*/
