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

    void init(int n) {
        par.resize(n + 1); 
        sz.resize(n + 1); 

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
        return 1; 
    }

} dsu; 

int main() {
    int n, m; 
    cin >> n >> m; 

    dsu.init(n); 
    while(m--) {
        int u, v, w; 
        cin >> u >> v >> w; 
        g.emplace_back(edge(u,v,w)); 
    }

    sort(g.begin(), g.end(), cmp);
    int total = 0;  
    for(edge e : g) 
        if(dsu.merge(e.u, e.v)) total += e.w;

    cout << total << '\n';  
}
