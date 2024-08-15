#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


int possible[504][3];
int len, cnt = 504;

int *checkVal(int *answer, int *input)
{
	int *val = (int*)malloc(sizeof(int) * 2);
	val[0] = val[1] = 0;

	for (int i = 0; i < 3; i++)
	{
		if (answer[i] == input[i])
		{
			val[0]++;
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				if (answer[i] == input[j])
				{
					val[1]++;
					break;
				}
			}
		}
	}

	return val;
}

void f(int *num)
{
	for (int i = 0; i < 504; i++)
	{
		if (possible[i][0] == -1) continue;

		int *val = checkVal(possible[i], num);

		if (val[0] != num[3] || val[1] != num[4])
		{
			possible[i][0] = -1;
			cnt--;
		}
	}
}

int main()
{
	int N;
	scanf("%d\n", &N);

	// possible 배열 초기화
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			for (int c = 1; c < 10; c++)
			{
				if (a==b || a==c || b==c) continue;

				possible[len][0] = a;
				possible[len][1] = b;
				possible[len][2] = c;
				len++;
			}
		}
	}

	// 입력
	for (int i = 0; i < N; i++)
	{
		int arr[5];
		arr[0] = getchar() - '0';
		arr[1] = getchar() - '0';
		arr[2] = getchar() - '0';
		getchar();
		arr[3] = getchar() - '0';
		getchar();
		arr[4] = getchar() - '0';
		getchar();

		f(arr);
	}

	printf("%d", cnt);

	return 0;
}