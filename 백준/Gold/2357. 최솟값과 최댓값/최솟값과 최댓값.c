#include <stdio.h>

int arr[100001];
int treeMin[262144];
int treeMax[262144];
int min(int a, int b)
{
    return a > b ? b : a;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int makeTree(int *tree, int start, int end, int node, int(*judg)(int a, int b))
{
    if (start==end)
        return tree[node] = arr[end];

    int mid = (start+end) / 2;
    return tree[node] = judg(makeTree(tree, start, mid, node*2, judg), makeTree(tree, mid+1, end, node*2 +1, judg));
}

int find(int* tree, int left, int right, int start, int end, int node, int(*judg)(int a, int b))
{
    if (left > end || right < start)
        return judg == &min ? 1000000001 : 0;

    if (start >= left && end <= right)
        return tree[node];

    int mid = (start+end) / 2;
    return judg(find(tree, left, right, start, mid, node*2, judg), find(tree, left, right, mid+1, end, node*2 + 1, judg));
}


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", arr+i);
    makeTree(treeMin, 1, N, 1, min);
    makeTree(treeMax, 1, N, 1, max);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d %d\n", find(treeMin, a, b, 1, N, 1, min), find(treeMax, a, b, 1, N, 1, max));
    }

    return 0;
}