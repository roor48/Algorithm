#include <stdio.h>

int arr[3][2];

int directions[4] = {-9999, -9999, 9999, 9999}; // top, right, bottom, left
int directionsCnt[4] = {0};

int main()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d\n", &arr[i][0], &arr[i][1]);

		for (int j = 0; j < 4; j++)
		{
			if (j < 2)
			{
				if (directions[j] < arr[i][j&1])
					directions[j] = arr[i][j&1];
			}
			else if (directions[j] > arr[i][j&1])
			{
				directions[j] = arr[i][j&1];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (directions[0] == arr[i][0])
			directionsCnt[0]++;
		else if (directions[2] == arr[i][0])
			directionsCnt[2]++;

		if (directions[1] == arr[i][1])
			directionsCnt[1]++;
		else if (directions[3] == arr[i][1])
			directionsCnt[3]++;
	}

	int y, x;
	for (int i = 0; i < 4; i++)
	{
		if (i&1)
		{
			if (directionsCnt[i] == 1)
				x = i;
		}
		else
		{
			if (directionsCnt[i] == 1)
				y = i;
		}
	}

	printf("%d %d", directions[y], directions[x]);

	return 0;
}
