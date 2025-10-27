#include <bits/stdc++.h>
using namespace std;

struct edge {
    int id, u, v, w;
    edge() {}
    edge(int a, int b, int c, int d) : id(a), u(b), v(c), w(d) {}
};

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

    int find_set(int v) {
        if(par[v] == v) return v;
        return par[v] = find_set(par[v]);
    }

    bool merge(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    long long s;
    cin >> n >> m >> s;

    dsu.init(n);
    vector<edge> g(m + 1);
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = edge(i, u, v, w);
    }

    sort(g.begin() + 1, g.end(), [](const edge &a, const edge &b){
        return a.w < b.w;
    });

    vector<bool> used_id(m + 1, false);
    for(int i = m; i >= 1; --i) {
        if(dsu.merge(g[i].u, g[i].v)) used_id[g[i].id] = true;
    }

    vector<int> remove;
    long long sum = 0;
    for(int i = 1; i <= m; ++i) {
        if(!used_id[g[i].id] && sum + g[i].w <= s) {
            remove.push_back(g[i].id);
            sum += g[i].w;
        }
    }

    sort(remove.begin(), remove.end());
    cout << remove.size() << '\n';
    for(int x : remove) cout << x << ' ';
}
