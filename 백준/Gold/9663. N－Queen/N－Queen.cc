#include <iostream>
using namespace std;

int N;
int arr[15];

bool promise(int y2) {
    for (int y1 = 1; y1 < y2; y1++) {
        if ( (arr[y1] == arr[y2]) || (abs(arr[y1] - arr[y2]) == abs(y2 - y1)) )
            return false;
    }

    return true;
}

int f(int y) {
    if (y>N)
        return 1;

    int ans = 0;
    for (int x = 1; x <= N; x++) {
        arr[y] = x;
        if (promise(y))
            ans += f(y+1);
    }

    return ans;
}

int main() {
    cin >> N;

    cout << f(1);
}
