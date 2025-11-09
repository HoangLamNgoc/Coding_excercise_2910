#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>

using namespace std; 
int n, m, s = 1, t; 
const int maxn = 501;
const int inf = 1e9 + 7;  

int c[maxn][maxn], f[maxn][maxn], d[maxn];

int curvertexid[maxn];
vector<int> g[maxn];  

int maxflow = 0; 

void bfs() {
    fill(d, d + n + 1, inf); 

    queue<int> q; 
    q.push(s); 
    d[s] = 0; 

    while(!q.empty()) {
        int u = q.front(); q.pop(); 

        for(int v : g[u]) {
            if (f[u][v] == c[u][v]) continue; 
            if (d[v] != inf) continue; 

            d[v] = d[u] + 1; 
            q.push(v); 
        }
    }
}

int dfs(int u, int curdel) {
    if (curdel == 0) return 0; 

    if (u == t) return curdel; 

    for(; curvertexid[u] < g[u].size(); ++curvertexid[u]) {
        int v = g[u][curvertexid[u]]; 

        if (f[u][v] == c[u][v]) continue; 
        if (d[v] != d[u] + 1) continue; 

        int del = dfs(v, min(curdel, c[u][v] - f[u][v]));

        if (del == 0) continue; 

        f[u][v] += del; 
        f[v][u] -= del; 
        return del;  
    }
    return 0; 
}

signed main() {
    cin >> n >> m; 
    t = n; 

    int u, v; 
    while(m--) {
        cin >> u >> v; 
        cin >> c[u][v]; 
        g[u].emplace_back(v); 
        g[v].emplace_back(u); 
    }

    while(true) {
        bfs(); 
        fill(curvertexid, curvertexid + n + 1, 0);
        if (d[t] == inf) break; 
        while (int del = dfs(s, inf)) {
            maxflow += del; 
        }
    }
    cout << maxflow; 
    return 0; 
}
