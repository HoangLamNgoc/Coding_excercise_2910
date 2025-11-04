#include <bits/stdc++.h>
using namespace std;

static int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
static int dy[8] = {-2, -1, -2, -1, 2, 1, 2, 1};

int n = 8;
int a[64];  

bool limit(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool empty_cell(int x, int y) {
    return limit(x, y) && a[y * n + x] == 0;
}

int getdeg(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (empty_cell(nx, ny)) cnt++;
    }
    return cnt;
}

bool nextmove(int &x, int &y) {
    int mindegidx = -1, mindeg = 9;
    int nx, ny, c;

    int start = rand() % 8;  
    for (int k = 0; k < 8; ++k) {
        int i = (start + k) % 8;
        nx = x + dx[i];
        ny = y + dy[i];

        if (empty_cell(nx, ny) && (c = getdeg(nx, ny)) < mindeg) {
            mindegidx = i;
            mindeg = c;
        }
    }

    if (mindegidx == -1) return false;

    nx = x + dx[mindegidx];
    ny = y + dy[mindegidx];

    a[ny * n + nx] = a[y * n + x] + 1;
    x = nx;
    y = ny;
    return true;
}

bool neighbor(int x, int y, int sx, int sy) {
    for (int i = 0; i < 8; ++i)
        if (x + dx[i] == sx && y + dy[i] == sy)
            return true;
    return false;
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(2) << a[i * n + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool find_next_Cycle() {
    memset(a, 0, sizeof(a));

    int x = rand() % n;
    int y = rand() % n;
    int sx = x, sy = y;

    a[y * n + x] = 1;

    for (int i = 1; i < n * n; ++i)
        if (!nextmove(x, y))
            return false;

    if (!neighbor(x, y, sx, sy))
        return false;

    print();
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    srand(time(0));
    while (!find_next_Cycle());
    return 0;
}
