#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    int a[n][m];
    int d[n][m];
    bool visit[n][m];
  
    memset(visit, 0, sizeof visit);
    memset(d, -1, sizeof d);

    const int INF = 2147483647;

    queue<pair<int, int>> q;
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) { 
                q.push({i, j});
                visit[i][j] = true;
                d[i][j] = 0;
            }
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // BFS đa nguồn
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int r1 = r + dx[k];
            int c1 = c + dy[k];

            if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m 
                && !visit[r1][c1] && a[r1][c1] == INF) {

                visit[r1][c1] = true;
                d[r1][c1] = d[r][c] + 1;
                q.push({r1, c1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
