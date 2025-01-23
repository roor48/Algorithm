#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[262144];
int sz = 1;


void merge(vector<int> *left, vector<int> *right, vector<int> *origin)
{
    int lIdx = 0, rIdx = 0;
    int lSize = left->size(), rSize = right->size();
    int index = 0;

	origin->resize(lSize+rSize);

    while ((lIdx < lSize) && (rIdx < rSize))
    {
        if ((*left)[lIdx] < (*right)[rIdx])
        {
            (*origin)[index] = (*left)[lIdx];
            lIdx++;
        }
        else
        {
            (*origin)[index] = (*right)[rIdx];
            rIdx++;
        }

        index++;
    }

    for (;lIdx<lSize;lIdx++)
        (*origin)[index++] = (*left)[lIdx];
    for (;rIdx<rSize;rIdx++)
        (*origin)[index++] = (*right)[rIdx];
}

int countBig(int node, int k)
{
    int count = 0;
    int nodeCount = tree[node].size();

    int left = 0, right = nodeCount;
    while (left < right)
    {
        int mid = (left+right) / 2;

        if (tree[node][mid] <= k)
            left = mid+1;
        else
            right = mid;
    }

    return nodeCount-left;
}

int counter(int left, int right, int k)
{
    left += sz;
    right += sz;

    int count = 0;

    while (left <= right)
    {
        if (left%2==1)
        {
            count += countBig(left, k);
            left++;
        }
        left /= 2;

        if (right%2==0)
        {
            count += countBig(right, k);
            right--;
        }
        right /= 2;
    }

    return count;
}

int main()
{
    scanf("%d", &N);
    while(sz<N) sz<<=1;
    sz--;

	for (int i = 1; i <= N; i++)
	{
		int t;
		scanf("%d", &t);
		tree[i+sz].push_back(t);
	}
    for (int i=sz; i; i--)
        merge(&tree[i<<1], &tree[i<<1|1], &tree[i]);

    int M;
    scanf("%d", &M);

    for (int _ = 0; _ < M; _++)
	{
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", counter(i, j, k));
	}

    return 0;
}
/*
											[1 2 3 4 5]
						[1 2 3 5]									[4]
				[1 5]				[2 3]					[4]				[]
        [5]		        [1]	 	[2]		   [3]        [4]        [] 	[]      []
*/

// [1 2 3 4 5 ][1 2 3 5 ][4 ][1 5 ][2 3 ][4 ][][5 ][1 ][2 ][3 ][4 ][][][]
// [1 2 3 4 5 ][1 2 3 5 ][4 ][1 5 ][2 3 ][4 ][][5 ][1 ][2 ][3 ][4 ][][][]
// [][1 2 3 4 5 ][1 2 3 5 ][4 ][1 5 ][2 3 ][4 ][][5 ][1 ][2 ][3 ][4 ][][]