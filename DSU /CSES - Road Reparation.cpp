#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int u, v, w;
    edge() {};
    edge(int a, int b, int c) : u(a), v(b), w(c) {};
};
vector<edge> g;

bool cmp (const edge& a, const edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> par, sz;
    vector<bool> vis;

    void init(int n) {
        par.resize(n + 5);
        sz.resize(n + 5);
        vis.resize(n + 5);

        fill(vis.begin(), vis.end(), 0);

        for(int i = 1; i <= n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root (int v) {
        return (v == par[v]) ? v : par[v] = find_root(par[v]);
    }

    bool merge(int u, int v) {
        u = find_root(u);
        v = find_root(v);

        if ( v == u ) return 0;

        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        vis[u] = vis[v] = 1;
        return 1;
    }

} dsu;

void dfs(int s, int par = 0) {
    visited[s] = 1; 
    for(int v : g1[s]) {
        if ( v == par ) continue; 
        if (!visited[v]) dfs(v, u); 
    }
}
vector<int> g1[(int)1e5 + 5]; 
int main() {
    int n, m;
    cin >> n >> m;

    dsu.init(n);
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g.emplace_back(edge(u,v,w));
        g1[u].emplace_back(v); 
        g1[v].emplace_back(u); 
    }

    sort(g.begin(), g.end(), cmp);
    long long total = 0;
    for(edge e : g)
        if(dsu.merge(e.u, e.v)) total += e.w;
    
    dfs(1); 
    for(int i = 1; i <= n; ++i)
        if(!dsu.vis[dsu.par[i]] || visited[i] == 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    cout << total << '\n';
}
