#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <stack>

using namespace std;

int n, m, tin = 0, scc = 0; 
const int maxn = 105; 
const int N = 1e4 + 5; 

int dx[2] = {0, 1}, dy[2] = {1, 0}; 
vector<pair<int,int>> g[maxn][maxn]; 
stack<pair<int,int>> st;
int low[maxn][maxn], num[maxn][maxn], val[maxn][maxn], id[maxn][maxn];
bool ins[maxn][maxn];    
char grid[maxn][maxn];

vector<int> topo; 
bool vis[N];
long long valdag[N], dp[N];  
vector<int> dag[N];  

inline bool check(int r, int c) {
    return (r >= 1 && r <= n && c >= 1 && c <= m && grid[r][c] != '#');
}

void input() {
    cin >> n >> m; 
    char x; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> x; 
            grid[i][j] = x; 
            ins[i][j] = 0; 
            low[i][j] = num[i][j] = 0;

            if (x == '#') continue; 
            val[i][j] = isdigit(x) ? (x - '0') : 0; 

            for (int k = 0; k < 2; ++k) {
                int nr = i + dx[k], nc = j + dy[k];
                if (check(nr, nc)) g[i][j].push_back({nr, nc});
            }
            if (x == 'W' && check(i, j - 1)) g[i][j].push_back({i, j - 1});
            if (x == 'N' && check(i - 1, j)) g[i][j].push_back({i - 1, j});
        }
    }
}

void dfs(int r, int c) {
    num[r][c] = low[r][c] = ++tin;
    st.push({r, c});
    ins[r][c] = 1;

    for (auto [nr, nc] : g[r][c]) {
        if (!num[nr][nc]) {
            dfs(nr, nc);
            low[r][c] = min(low[r][c], low[nr][nc]);
        } 
        else if (ins[nr][nc]) 
            low[r][c] = min(low[r][c], num[nr][nc]);
    }

    if (low[r][c] == num[r][c]) {
        ++scc;
        long long sum = 0;
        int x, y;
        do {
            x = st.top().first;
            y = st.top().second;
            st.pop();
            ins[x][y] = 0;
            id[x][y] = scc;
            sum += val[x][y];
        } while (!(x == r && y == c));
        valdag[scc] = sum;
    }
}

void dagr() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '#') continue;
            for (auto [r, c] : g[i][j]) {
                int x = id[i][j], y = id[r][c];
                if (x != y) dag[x].push_back(y); 
            }
        }
    }
}

void dfs2(int u) {
    vis[u] = 1;
    for (auto v : dag[u]) if (!vis[v]) dfs2(v);
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    if (grid[1][1] == '#') {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] != '#' && !num[i][j]) dfs(i, j);
        }
    }

    dagr();

    dfs2(id[1][1]);
    for (int i = 1; i <= scc; ++i) dp[i] = -1e18;
    dp[id[1][1]] = valdag[id[1][1]];

    reverse(topo.begin(), topo.end());
    long long ans = 0;
    for (int u : topo) {
        ans = max(ans, dp[u]);
        for (int v : dag[u]) 
            dp[v] = max(dp[v], dp[u] + valdag[v]);
    }

    cout << ans;
}

//Bài giải : https://www.notion.so/R-b-t-m-gi-tr-l-n-nh-t-t-c-trong-1-ng-i-28a8b4d60bef804f9e7dc23c09284524
// đề : https://oj.vnoi.info/problem/kcollect
