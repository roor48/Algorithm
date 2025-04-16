#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void swap(pair<int, int> *a, pair<int, int> *b)
{
    pair<int, int> t = *a;
    *a = *b;
    *b = t;
}

bool isPriority(pair<int, int> *a, pair<int, int> *b) // a가 b보다 우선순위가 높으면 true
{
    if (a->first > b->first) return false;
    
    if ((a->first == b->first) && (a->second > b->second))
        return false;

    return true;
}

int N;
pair<int, int> arr[100001]; // (우선순위, 값)
int h_size = 0;
void push(int abs_val, int val)
{
    int child = ++h_size;
    int parent = child/2;
    arr[child] = make_pair(abs_val, val);

    while (child>1)
    {
        if (isPriority(&arr[parent], &arr[child])) // 부모가 자식보다 우선순위가 높으면 break
            break;
        
        swap(&arr[parent], &arr[child]);

        child = parent;
        parent = child / 2;
    }
}

int pop()
{
    if (h_size==0)
        return 0;

    int data = arr[1].second;
    
    arr[1] = arr[h_size--];

    int parent = 1, child;

    while (parent*2 <= h_size)
    {
        if (isPriority(&arr[parent*2], &arr[parent*2+1])) // 왼쪽 자식의 우선순위가 더 높으면
        {
            child = parent*2;
        }
        else
        {
            child = parent*2 + 1;
            if (child > h_size) // 우측 노드가 최대치를 초과하면 왼쪽 노드로 변경
                child--;
        }

        if (child > h_size) break; // child가 최대치를 초과하면

        if (isPriority(&arr[parent], &arr[child])) // 부모의 우선순위가 더 높으면
            break;
        

        swap(&arr[parent], &arr[child]);
        parent = child;
        child = parent * 2;
    }

    return data;
}


int main()
{
    cin >> N;
    
    int t;
    int abs_val;
    while(N--)
    {
        cin >> t;
        
        if (t)
        {
            abs_val = abs(t);
            push(abs_val, t);
            continue;
        }
        
        cout << pop() << '\n';
    }

    return 0;
}

