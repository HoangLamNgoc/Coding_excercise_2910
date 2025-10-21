#include <iostream>
#include <queue>

using namespace std; 
const int N = (int)5e3 + 5;   

char grid[N][N];
int n, m; 
bool vis[N][N]; 
long long tong = 0; 

int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0}; 

void input() {
    cin >> n >> m; 

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }
}

inline bool check(int r, int c) {
    return r > n || c > m || r < 1 || c < 1;  
}

void bfs(int i, int j) {
    vis[i][j] = true; 
    bool ok = false; 

    queue<pair<int,int>> q; 
    q.push({i, j});
    int cnt = 0;  

    while(!q.empty()) {
        cnt++; 
        pair<int,int> u = q.front(); q.pop(); 
        int r = u.first, c = u.second; 

        for(int k = 0; k < 4; ++k) {
            int nx = r + dx[k]; 
            int ny = c + dy[k];

            if(check(nx,ny)) continue; 
            if(vis[nx][ny] || grid[nx][ny] == 'B') continue; 
            if(grid[nx][ny] == 'W') {
                q.push({nx,ny}); 
                vis[nx][ny] = true; 
            }
            if(grid[nx][ny] == '.') {
                ok = true;  
            }  
        } 
    }

    if (!ok) tong += (long long)cnt; 
}

int main() {
    input(); 

    for(int i = 1; i <= n ; ++i) {
        for(int j = 1; j <= m; ++j) {
            if (!vis[i][j] && grid[i][j] == 'W') bfs(i, j); 
        }
    }
    cout << tong << '\n';
    return 0; 
}
