#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n, m;   
    cin >> n >> m; 
    int grid[n][m];

    bool visit[n][m]; 
    int d[n][m]; 
  
    memset(visit, 0, sizeof visit); 
    memset(d, -1, sizeof d);
  
    queue<pair<int,int>> q; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i,j});
                visit[i][j] = true;
                d[i][j] = 0;
            }
        }
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0}; 
  
    while (!q.empty()) {
        auto u = q.front(); 
        int r1 = u.first; 
        int c1 = u.second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int r2 = r1 + dx[k]; 
            int c2 = c1 + dy[k]; 
            if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < m && !visit[r2][c2]) {
                q.push({r2, c2}); 
                visit[r2][c2] = true; 
                d[r2][c2] = d[r1][c1] + 1; 
            }
        }
    }
    int dem = 0; 
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
                dem = max(dem, d[i][j]); 

    cout << dem << endl;
    return 0; 
}

    
