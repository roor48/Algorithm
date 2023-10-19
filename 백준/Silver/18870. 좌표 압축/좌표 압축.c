#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int value;
  int idx;
}MyData;

MyData* arr;
MyData* temp;

char t;
void merge(int left, int mid, int right)
{
  int leftPos = left, midPos = mid+1, tempPos = left;

  while(leftPos <= mid && midPos <= right)
  {
    if ((arr[leftPos].value < arr[midPos].value && t=='v') || (arr[leftPos].idx < arr[midPos].idx && t=='i'))
      temp[tempPos++] = arr[leftPos++];
    else
      temp[tempPos++] = arr[midPos++];
  }

  if (leftPos > mid)
  {
    for (int i = midPos; i <= right; i++)
    {
      temp[tempPos++] = arr[i];
    }
  }
  else
  {
    for (int i = leftPos; i <= mid; i++)
    {
      temp[tempPos++] = arr[i];
    }
  }

  for (int i = left; i <= right; i++)
  {
    arr[i] = temp[i];
  }
}

void sort(int left, int right)
{
  if (left < right)
  {
    int mid = (left + right)/2;
    sort(left, mid);
    sort(mid+1, right);

    merge(left, mid, right);
  }
}

int main()
{
  int N;
  scanf("%d", &N);
  arr = (MyData*)malloc(sizeof(MyData) * N);
  temp = (MyData*)malloc(sizeof(MyData) * N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &arr[i].value);
    arr[i].idx = i;
  }

  t = 'v';
  sort(0, N-1);

  int beforNum = arr[0].value;
  int num = 0;
  for (int i = 1; i < N; i++)
  {
    if (beforNum == arr[i].value)
      arr[i].value = num;
    else
    {
      beforNum = arr[i].value;
      arr[i].value = ++num;
    }
  }
  arr[0].value = 0;

  t='i';
  sort(0, N-1);
  for (int i = 0; i < N; i++)
  {
    printf("%d ", arr[i].value);
  }

  free(arr);
  free(temp);
  return 0;
}
