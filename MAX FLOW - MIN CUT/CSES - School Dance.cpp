#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1005; 
const int oo = 1e9;  
int n, m, k; 
int s = 0, t; 
int d[maxn];
long long c[maxn][maxn], f[maxn][maxn];
vector<int> g[maxn]; 
int curvertexid[maxn]; 

void bfs() {
    fill_n(d, maxn, oo); 
    d[s] = 0; 

    queue<int> q; 
    q.push(s); 

    while (!q.empty()) {
        int u = q.front(); q.pop(); 

        for(int v : g[u]) {
            if (d[v] != oo) continue;
            if (c[u][v] == f[u][v]) continue;  

            d[v] = d[u] + 1; 
            q.push(v); 
        }   
    }
}

long long dfs(int u, long long curdel) { 
    if (u == t ) return curdel;          
    if (curdel == 0) return 0; 

    for(; curvertexid[u] < g[u].size(); ++curvertexid[u]) {
        int v = g[u][curvertexid[u]]; 

        if (d[v] != d[u] + 1) continue; 
        if (f[u][v] == c[u][v]) continue; 

        long long del = dfs(v, min((long long)c[u][v] - f[u][v], curdel)); 

        if (del == 0) continue; 

        f[u][v] += del; 
        f[v][u] -= del; 
        return del; 
    }
    return 0; 
}


int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    cin >> n >> m >> k; 
    t = 2 * n + 1; 

    for(int i = 1; i <= k; ++i) {
        int u, v; 
        cin >> u >> v; 

        c[u][v + n] = 1;
        c[s][u] = 1; 
        c[v + n][t] = 1;   

        g[s].push_back(u); 
        g[v + n].push_back(t); 
        g[u].push_back(v + n);  
        g[u].push_back(s); 
        g[t].push_back(v + n); 
        g[v + n].push_back(u);  
    }

    long long maxflow = 0;  
    while(true) {
        bfs();
        if(d[t] == oo) break;
        fill(curvertexid, curvertexid + 2 * n + 1, 0);
        while(long long del = dfs(s, oo)) {
            maxflow += del;
        }
    }

    cout << maxflow << '\n'; 
    for(int i = 1; i <= n; ++i) {
        for(int j = n + 1; j <= m + n; ++j) {
            if (f[i][j] == 1) cout << i << ' ' << j - n << '\n'; 
        }
    }
    return 0; 
}
