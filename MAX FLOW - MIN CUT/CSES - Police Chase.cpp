#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, s = 1, t;
const int maxn = 501;
const long long inf_flow = 1e18;
const int inf_d = 1e9;

long long c[maxn][maxn], f[maxn][maxn];
int d[maxn];
int curvertexid[maxn];
vector<int> g[maxn];
long long maxflow = 0;

void bfs() {
    fill(d, d + n + 1, inf_d);
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(f[u][v] == c[u][v]) continue;
            if(d[v] != inf_d) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

long long dfs(int u, long long curdel) {
    if(curdel == 0) return 0;
    if(u == t) return curdel;

    for(; curvertexid[u] < g[u].size(); ++curvertexid[u]) {
        int v = g[u][curvertexid[u]];
        if(f[u][v] == c[u][v]) continue;
        if(d[v] != d[u] + 1) continue;

        long long del = dfs(v, min(curdel, c[u][v] - f[u][v]));
        if(del == 0) continue;

        f[u][v] += del;
        f[v][u] -= del;
        return del;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    t = n;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        c[u][v] = 1; 
        c[v][u] = 1; 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while(true) {
        bfs();
        if(d[t] == inf_d) break;
        fill(curvertexid, curvertexid + n + 1, 0);
        while(long long del = dfs(s, inf_flow)) {
            maxflow += del;
        }
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(!visited[v] && f[u][v] < c[u][v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<pair<int,int>> cut_edges;
    for(int u = 1; u <= n; u++) {
        if(!visited[u]) continue;
        for(int v : g[u]) {
            if(!visited[v] && c[u][v] > 0) {
                cut_edges.push_back({u, v});
            }
        }
    }

    cout << cut_edges.size() << "\n";
    for(auto &e : cut_edges) {
        cout << e.first << " " << e.second << "\n";
    }
}
