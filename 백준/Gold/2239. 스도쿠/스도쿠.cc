#include <iostream>
using namespace std;

int sdoku[9][9];
bool verti[9][10];
bool hori[9][10];
bool box[9][10];

bool f(int p) {
    if (p>=81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sdoku[i][j];
            cout << '\n';
        }
        return true;
    }

    int y = p / 9;
    int x = p % 9;
    int bp = y/3*3 + x/3;

    if (sdoku[y][x]) {
        return f(p+1);
    }

    for (int i = 1; i <= 9; i++) {
        sdoku[y][x] = i;

        if (!(verti[x][sdoku[y][x]] ||
              hori[y][sdoku[y][x]] ||
              box[bp][sdoku[y][x]])
            ) {
            
            verti[x][sdoku[y][x]] = true;
            hori[y][sdoku[y][x]] = true;
            box[bp][sdoku[y][x]] = true;

            if (f(p+1))
                return true;

            verti[x][sdoku[y][x]] = false;
            hori[y][sdoku[y][x]] = false;
            box[bp][sdoku[y][x]] = false;
        }
        
        
        sdoku[y][x] = 0;
    }

    return false;
}

int main() {
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            sdoku[i][j] = s[j]-'0';

            if (sdoku[i][j]) {
                verti[j][sdoku[i][j]] = true;
                hori[i][sdoku[i][j]] = true;
                box[i/3*3 + j/3][sdoku[i][j]] = true;
            }
        }
    }

    f(0);

    return 0;
}
