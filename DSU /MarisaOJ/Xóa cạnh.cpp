#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (int)1e5 + 5;
const int MAXM = (int)1e5 + 5;

struct edge {
    int u, v;
    edge() {}
    edge(int uu, int vv) : u(uu), v(vv) {}
};

bool vis[MAXM];      

struct DSU {
    int par[MAXN], sz[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int v) {
        return (v == par[v]) ? v : par[v] = find_root(par[v]);
    }

    void merge(int u, int v) {
        u = find_root(u);
        v = find_root(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
} dsu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    dsu.init(n);

    vector<edge> adj;
    adj.reserve(m);

    for (int i = 0; i < m; ++i) {
        int u, v; 
        cin >> u >> v;
        adj.emplace_back(u, v);
    }

    for (int i = 0; i < m; ++i) vis[i] = false;

    vector<pair<int,int>> queries;
    queries.reserve(q);

    for (int i = 0; i < q; ++i) {
        int e, c;
        cin >> e >> c;
        e--;                    
        queries.emplace_back(e, c);
        vis[e] = true;             
    }

    for (int e = 0; e < m; ++e) {
        if (!vis[e]) {
            dsu.merge(adj[e].u, adj[e].v);
        }
    }
    reverse(queries.begin(), queries.end());

    vector<int> ans;
    ans.reserve(q);

    for (auto &p : queries) {
        int e = p.first;
        int c = p.second;

        ans.push_back(dsu.sz[dsu.find_root(c)]);
        dsu.merge(adj[e].u, adj[e].v);
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << "\n";

    return 0;
}

/*https://marisaoj.com/problem/137*/
