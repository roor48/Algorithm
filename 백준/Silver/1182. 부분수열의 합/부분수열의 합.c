#include <stdio.h>

int arr[21];
int N, S, cnt;

void f(int n, int sum)
{
	if (n > 0 && sum == S)
		cnt++;
		
	if (n==N) return;


	for (int i = n+1; i <= N; i++)
	{
		f(i, sum+arr[i]);
	}
}

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++)
		scanf("%d", arr+i);

	f(0, 0);

	printf("%d", cnt);

	return 0;
}
