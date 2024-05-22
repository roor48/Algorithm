#include <stdio.h>

int max(int a, int b){ return a>b?a:b; }

int N;
int arr[1000];
int dp[1000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
	}

	int answer = 1;
	for(int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[j] = max(dp[j], dp[i]+1);
				answer = max(answer, dp[j]);
			}
		}
	}

	printf("%d", answer);

	return 0;
}
