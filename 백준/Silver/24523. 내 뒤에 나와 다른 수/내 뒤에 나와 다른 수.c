#include <stdio.h>

int arr[1000001] = {-1000000001};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", arr+i);


    int ans;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i-1] == arr[i])
        {
            printf("%d ", ans);
            continue;
        }
        ans = -1;
        for (int j = i+1; j <= N; j++)
        {
            if (arr[i] == arr[j])
                continue;
            
            ans = j;
            break;
        }
            
        printf("%d ", ans);
    }
}

// 1000000000
// 2147483647
