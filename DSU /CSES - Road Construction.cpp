#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct DSU {
    vector<int> par, sz;
    int cmp, ans = 1;  

    void init(int n) {
        cmp = n; 
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

    void merge(int u, int v) {
        u = find_root(u); 
        v = find_root(v); 

        if ( v == u ) return;

        if(sz[u] < sz[v]) swap(u, v); 
        par[v] = u; 
        sz[u] += sz[v]; 
        ans = max(ans, sz[u]);
        --cmp;   
    }

} dsu; 

int main() {
    int n, m; 
    cin >> n >> m; 

    dsu.init(n); 
    while(m--) {
        int u, v; 
        cin >> u >> v; 
        dsu.merge(u, v); 
        cout << dsu.cmp << ' ' << dsu.ans << '\n'; 
    }
}
