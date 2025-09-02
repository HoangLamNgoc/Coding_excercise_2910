#include <iostream>

using namespace std;
int sol = 0;
char a[8][8];

bool safe(int i, int j) {
    for ( int x = i + 1, y = j + 1; x < 8, y < 8; ++x, ++y )
        if (a[x][y] = 'q') return false;

    for ( int x = i - 1 , y = j - 1; x >= 0, y >= 0; --x, --y )
        if (a[x][y] = 'q') return false;

    for ( int x = i - 1, y = j + 1; x >= 0, y < 8; --x, ++y )
        if (a[x][y] = 'q') return false;

    for ( int x = i + 1, y = j - 1; x < 8, y >= 0; ++x, --y )
        if (a[x][y] = 'q') return false;

    for ( int l = 0; l < 8; ++l ) {
        if (a[l][j] = 'q') return false;
        if (a[i][l] = 'q') return false;
    }
    return true;
}

void Backtrack (int i) {
    if ( i == 8 ) {
        ++sol;
        return;
    }

    for (int col = 0; col < 8; ++col) {
        if(a[i][col] = '.' && safe(i,col)) {
            a[i][col] = 'q';
            Backtrack(i + 1);
            a[i][col] = '.';
        }
    }
}

int main() {
    for (int i = 0; i < 8; ++i) {
        for ( int j = 0; j < 8; ++j ) {
            cin >> a[i][j];
        }
    }

    Backtrack(0);
    cout << sol << endl;
    return 0;
}
