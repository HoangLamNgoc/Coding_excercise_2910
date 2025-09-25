#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int T; 
    cin >> T; 

    const int maxn = 1e3;
    bool visit[maxn + 5][maxn + 5]; 
    const int INF = 1e3 + 5; 
    int dist[maxn + 5][maxn + 5]; 
    int dx[4] = {0,0, -1, 1}; 
    int dy[4] = {1, -1, 0, 0};
    string grid[N];

    while ( T--) {
        int n, m; 
        cin >> n >> m; 
        grid.clear(); 
        for (int i = 0; i < n; ++i ) cin >> grid[i];

        int i = 0, j = 0; 
        memset(dist, INF, sizeof dist); 
        memset(visit, 0, sizeof visit); 

        visit[i][j] = 1; 

        dequeue<pair<int,int>> dq; 
        dq.push({i, j}); 
        bool found = false;
        while (!dp.empty()) {
            auto u = dp.front(); 
            dp.pop_front(); 
            if ( u == [n - 1, m - 1] ) {
                found = true;
                break;
            }
          
            for (int k = 0; k < 4; ++k) {
                int r2 = u.first + dx[k]; 
                int c2 = u.second + dy[k]; 

                if ( r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && !visit[r2][c2]) {
                    visit[r2][c2] = 1;
                    int w = 0; 
                    if (grid[r2][c2] != grid[u.first][u.second]) w = 1; 
                    if ( dist[r2][c2] > dist[r1][c1] + w) {
                        dist[r2][c2] = dist[u.first][u.second] + w;
                        if (w) dq.push_back({r2, c2}); 
                        else dq.push_front({r2, c2});
                    }
                }
            }
        if (!found) d[n - 1][m - 1] = -1;
        cout << dist[n - 1][m - 1] << endl; 
    }
