#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
long long a[1005][1005];
int n;
bool b[1005][1005];

void moves(int x, int y ) {
    fill_n(&a[0][0], n * n, 0);
    fill_n(&b[0][0], n * n, true);

    queue<pair<int,int>> q;
    q.push({x, y});
    b[x][y] = false;

    while (!q.empty()) {
        pair <int,int> v = q.front();
        q.pop();
        int i = v.first;
        int j = v.second;

        int dx[8] = {-2, -1,  1,  2,  2,  1, -1, -2};
        int dy[8] = { 1,  2,  2,  1, -1, -2, -2, -1};

        for ( int k = 0; k < n; ++k ) {
            int ni = dx[k] + i;
            int nj = dy[k] + j;

            if (ni >= 0 && ni < n && nj >= 0 && nj < n && b[ni][nj]) {
                a[ni][nj] = a[i][j] + 1;
                b[ni][nj] = false;
                q.push({ni, nj});

            }
        }
    }
}

int main() {
    cin >> n;
    moves(0,0);

    for ( int i = 0; i < n; ++i ) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
