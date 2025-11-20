#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string grid[n]; 
    for (int i = 0; i < n; i++) cin >> grid[i];

    long long dp[n][n];
    bool vis[n][n]; 

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            vis[i][j] = 0; 
            dp[i][j] = 0; 
        }
    } 


    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = true;

    while (!q.empty()) {
        auto [r,c] = q.front();
        q.pop();

        for (int t = 0; t < 2; t++) {
            int nr = r + dr[t];
            int nc = c + dc[t];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (grid[nr][nc] == '*') continue;

            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }

            dp[nr][nc] = (dp[nr][nc] + dp[r][c]) % MOD;
        }
    }

    cout << dp[n - 1][n - 1];
}
