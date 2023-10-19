#include <stdio.h>
#include <stdlib.h>

int* list;
int* temp;

void merge(int left, int mid, int right)
{
  int leftPos = left, midPos = mid+1, tempPos = left;
  while (leftPos <= mid && midPos <= right)
  {
    temp[tempPos++] = list[leftPos] < list[midPos] ? list[leftPos++] : list[midPos++];
  }

  if (leftPos > mid)
    for (int i = midPos; i <= right; i++)
      temp[tempPos++] = list[i];

  else
    for (int i = leftPos; i <= mid; i++)
      temp[tempPos++] = list[i];

  for (int i = left; i <= right; i++)
    list[i] = temp[i];
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

int findNum;
int bs(int left, int right)
{
  while(left<=right)
  {
    int mid = (left+right)/2;
    if (list[mid] == findNum) return findNum;

    if(list[mid] < findNum)
      left = mid+1;
    else
      right = mid-1;
  }

  return -2147483647;
}

int main()
{
  int N;
  scanf("%d", &N);
  list = (int*)malloc(sizeof(int) * N);
  temp = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d", &list[i]);
  sort(0, N-1);

  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; i++)
  {
    scanf("%d", &findNum);
    printf("%d ", bs(0, N-1) == findNum);
  }

  free(list);
  free(temp);
}
