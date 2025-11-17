#include <iostream>
#include <vector>
#include <queue>
 
using namespace std; 
const int LOG = 20; 
const int MAX_NODES = 2e5 + 5;
const int oo = 1e9 + 5; 
 
int up[MAX_NODES][LOG];
vector<int> adj[MAX_NODES];
int hei[MAX_NODES];
bool vis[MAX_NODES]; 
 
void bfs(int src) {
    fill_n(vis, MAX_NODES, 0); 
    fill_n(hei, MAX_NODES, oo); 
 
    queue<int> q;    
    vis[src] = 1; 
    hei[src] = 0;
    q.push(src);
 
    while(!q.empty()) {
        int u = q.front(); 
        q.pop(); 
 
        for(int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1; 
                hei[v] = hei[u] + 1; 
                up[v][0] = u; 
                q.push(v); 
            }
        }
    } 
}
int cnt[MAX_NODES];
void dfs(int u, int par = 0) {
    for(int v : adj[u]) {
        if (v == par) continue; 
        dfs(v, u); 
        cnt[u] += cnt[v]; 
    }
}
 
int lca(int u, int v) {
    if (hei[u] != hei[v]) {
        if (hei[u] < hei[v]) swap(u, v); 
        int dist = hei[u] - hei[v];
        for(int i = 0; (1 << i) <= dist; ++i) {
            if (dist & (1 << i)) {
                u = up[u][i];
                if (u == 0) return -1;
            }
        }  
    }
    if (u == v) return u;
 
    int k = (int)__lg(hei[u]); 
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) 
            u = up[u][j], v = up[v][j];
    return up[u][0]; 
}
 
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    int nodes, quer; cin >> nodes >> quer; 
 
    for(int i = 2; i <= nodes; ++i) {
        int u, v; 
        cin >> u >> v;
 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    bfs(1); 
    for(int j = 1; j < LOG; ++j) 
        for(int u = 1; u <= nodes; ++u) 
            up[u][j] = up[up[u][j - 1]][j - 1];
 
    int visited[nodes + 1]; 
    fill_n(cnt, MAX_NODES, 0); 
    fill_n(visited, nodes + 1, 0); 
    while(quer--) {
        int u, v; 
        cin >> u >> v; 
 
        int c = lca(u, v); 
        visited[c]++;
        cnt[u]++; 
        cnt[v]++; 
        cnt[c] -= 2; 
    }

    dfs(1); 
    for(int i = 1; i <= nodes; ++i) { 
        cout << cnt[i] + visited[i]<< ' '; 
    }
}
//4 1 3 4 1 8 9 7 7 7
