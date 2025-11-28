#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 3005; 

bool vis[MAXN][MAXN]; 
char grid[MAXN][MAXN]; 
int num; 
static int dx[2] = {0, 1}; 
static int dy[2] = {1, 0}; 

inline bool ins(int r, int c) {
    return r >= 0 && r < num && c >= 0 && c < num && !vis[r][c]; 
}
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    cin >> num; 

    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < num; ++j) {
            cin >> grid[i][j]; 
            vis[i][j] = 0; 
        }
    }

    vector<pair<int,int>> cur;
    cur.push_back({0, 0}); 
    string res = ""; 
    res.push_back(grid[0][0]); 
    vis[0][0] = true; 

    for(int i = 1; i <= 2 * num - 2; ++i) {
        vector<pair<int, int>> next; 
        char minc = char('Z' + 4); 

        for(pair<int,int> p : cur) {
            int r = p.first; 
            int c = p.second; 
            for(int k = 0; k < 2; ++k) {
                int nr = r + dx[k]; 
                int nc = c + dy[k]; 

                if (ins(nr,nc)) {
                    vis[nr][nc] = 1; 
                    next.push_back({nr, nc});
                    if (grid[nr][nc] < minc) 
                        minc = grid[nr][nc];
                }
            }
        }
        res.push_back(minc); 
        vector<pair<int,int>> nactive; 
        for (pair<int,int> p : cur) {
            int r = p.first; 
            int c = p.second;
            if (grid[r][c] == minc) 
                nactive.push_back({r, c}); 
        }
        cur = nactive; 
    }
    cout << res << endl;
}

/* Ý tưởng : 
- Chọn các ô có thể đi đến và chọn giá trị nhỏ nhất 
- Lọc lại các ô bước hiện tại để không phải đi vào ô lớn hơn 
*/
