#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
const int N = 1e3 + 5;
char grid[N][N];
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
string ans = "";
string par[N][N];
string path[4] = {"L", "R", "U", "D"};
int d[N][N];
int n, m;
int r, c;
int r_ans, c_ans;
pair<int, int> parent[N][N];
bool found = false;

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    parent[r][c] = {-1,-1};

    while(!q.empty()) {
        auto[r1, c1] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int r2 = r1 + dx[i];
            int c2 = c1 + dy[i];
            if (r2 >= n || c2 >= m || r2 < 0 || c2 < 0) continue;
            if(grid[r2][c2] == '.') {
                grid[r2][c2] = '#';
                d[r2][c2] = d[r1][c1] + 1;
                par[r2][c2] = path[i];
                parent[r2][c2] = {r1, c1};
                q.push({r2,c2});
            }
            else if (grid[r2][c2] == 'B') {
                d[r2][c2] = d[r1][c1] + 1;
                par[r2][c2] = path[i];
                parent[r2][c2] = {r1, c1};
                found = true;
                return;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                r = i;
                c = j;
            }
            else if (grid[i][j] == 'B') {
                r_ans = i;
                c_ans = j;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j){
            parent[i][j] = {-1,-1};
            par[i][j] = "";
            d[i][j] = -1;
        }
    }

    d[r][c] = 0;
    parent[r][c] = {-1,-1};

    bfs(r,c);
    if (!found) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << d[r_ans][c_ans] << endl;

    int x = r_ans;
    int y = c_ans;
    while(parent[x][y].first != -1) {
        ans += par[x][y];
        int px = parent[x][y].first;
        int py = parent[x][y].second;
        x = px;
        y = py;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
