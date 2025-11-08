#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 8;
int a[8][8];

inline bool insight(int x, int y) {
    return (x < n && x >= 0 && y < n && y >= 0);
}

inline bool emp(int x, int y) {
    return insight(x, y) && a[x][y] == -1;
}

static int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
static int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int getdeg(int x, int y) {
    int nx, ny;
    int count = 0;
    for(int i = 0; i < 8; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];

        if(emp(nx, ny)) ++count;
    }
    return count;
}

bool sol(int x, int y, int st) {
    a[x][y] = st;
    if (st == n * n - 1) return true;

    vector<pair<int,pair<int,int>>> moves;
    for(int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (emp(nx, ny))
            moves.push_back({getdeg(nx, ny), {nx, ny}});
    }

    sort(moves.begin(), moves.end());

    for(pair<int,pair<int,int>> v : moves) {
        int nx = v.second.first;
        int ny = v.second.second;

        if(sol(nx, ny, st + 1)) return true;
    }

    a[x][y] = -1;
    return false;
}

int main() {
    int sx, sy;
    cin >> sx >> sy;

    --sx, --sy;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            a[i][j] = -1;

    if (sol(sy, sx, 0)) {
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                cout << a[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}
