#include <stdio.h>

int arr[50];
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d", arr+i);

    int count = 0;
    for (int cur = 0; cur < M; cur++)
    {
        int move_left = arr[cur]-1;
        int move_right = N-arr[cur]+1;
        count += move_left < move_right ? move_left : move_right;

        for (int i = cur+1; i < M; i++)
        {
            if (move_left < move_right)
            {
                arr[i] -= move_left;
                if (arr[i] <= 0)
                    arr[i] += N;
            }
            else
            {
                arr[i] += move_right;
                if (arr[i] > N)
                    arr[i] -= N;
            }

            arr[i]--;
        }
        N--;
    }
    printf("%d", count);
    return 0;
}
