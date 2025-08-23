#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    string name, status;
    map<string, bool, greater<string>> attendance;
    for (int i = 0; i < N; i++) {
        cin >> name >> status;
        if (status == "enter") {
            attendance[name] = true;
        } else if (status == "leave") {
            attendance[name] = false;
        }
    }

    for (auto p : attendance) {
        if (p.second)
            cout << p.first << '\n';
    }

    return 0;
}
