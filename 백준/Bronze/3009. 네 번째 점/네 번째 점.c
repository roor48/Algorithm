#include <stdio.h>

int main()
{
	int arr[3][2];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d\n", &arr[i][0], &arr[i][1]);
	}

	printf("%d %d", arr[0][0]^arr[1][0]^arr[2][0], arr[0][1]^arr[1][1]^arr[2][1]);

	return 0;
}
