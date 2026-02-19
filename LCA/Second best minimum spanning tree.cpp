#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 3e5 + 5; 
const int LOG = 20; 

struct edge {
    int u, v, w, id ;
    edge() {};
    edge(int a, int b, int c, int d) : u(a), v(b), w(c), id(d) {};
};

vector<edge> g;
bool vis[MAXN]; 

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> par, sz;

    void init(int n) {
        par.resize(n + 5);
        sz.resize(n + 5);

        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int v) {
        return (v == par[v]) ? v : par[v] = find_root(par[v]);
    }

    bool merge(int u, int v) {
        u = find_root(u);
        v = find_root(v);
        if (u == v) return 0;

        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return 1;
    }

} dsu;

long long total = 0;

inline void upd(long long x, long long &mx1, long long &mx2) {
    if (x > mx1) {
        mx2 = mx1;
        mx1 = x;
    }
    else if (x > mx2 && x != mx1) {
        mx2 = x;
    }
}

struct LCA { 
    vector<vector<pair<int,int>>> adj;
    int up[MAXN][LOG]; 
    long long val[MAXN][LOG][2]; 
    int depth[MAXN]; 

    pair<long long,long long> combine(long long a1, long long a2,
                                      long long b1, long long b2) {

        long long mx1 = -1, mx2 = -1;

        upd(a1, mx1, mx2);
        upd(a2, mx1, mx2);
        upd(b1, mx1, mx2);
        upd(b2, mx1, mx2);

        return {mx1, mx2};
    }

    void build(int n) {
        fill(depth, depth + n + 1, -1); 

        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < LOG; ++j) { 
                up[i][j] = 0; 
                val[i][j][0] = val[i][j][1] = -1; 
            }
        }

        queue<int> q;
        q.push(1);
 
        depth[1] = 0;
        up[1][0] = 1; 
 
        while (!q.empty()) {
            int u = q.front(); 
            q.pop(); 
 
            for(auto v1 : adj[u]) {
                int v = v1.first; 
                int w = v1.second;

                if (depth[v] != -1) continue; 
                depth[v] = depth[u] + 1; 
                up[v][0] = u; 

                val[v][0][0] = w; 
                val[v][0][1] = -1;

                q.push(v); 
            }
        }
 
        for(int k = 1; k < LOG; ++k) {
            for(int i = 1; i <= n; ++i) {
                int mid = up[i][k - 1]; 

                up[i][k] = up[mid][k - 1];

                auto [mx1, mx2] = combine(
                    val[i][k - 1][0], val[i][k - 1][1],
                    val[mid][k - 1][0], val[mid][k - 1][1]
                );

                val[i][k][0] = mx1;
                val[i][k][1] = mx2;
           }
        }
    }
 
    pair<long long,long long> root(int u, int v) {
        long long r1 = -1, r2 = -1;
 
        if (depth[u] != depth[v]) {
            if (depth[u] < depth[v]) swap(u, v);
 
            int k = depth[u] - depth[v];  
            for(int i = 0; i < LOG; ++i) {
                if (k & (1 << i)) {
                    upd(val[u][i][0], r1, r2);
                    upd(val[u][i][1], r1, r2);
                    u = up[u][i];
                }
            }
        }
 
        if (v == u) return {r1, r2}; 
 
        for(int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {

                upd(val[u][i][0], r1, r2);
                upd(val[u][i][1], r1, r2);

                upd(val[v][i][0], r1, r2);
                upd(val[v][i][1], r1, r2);

                u = up[u][i]; 
                v = up[v][i]; 
            }
        }

        upd(val[u][0][0], r1, r2);
        upd(val[v][0][0], r1, r2);

        return {r1, r2}; 
    }
} lca; 

long long ans = 1e18; 

void sol(edge e) {
    int u = e.u; 
    int v = e.v; 
    int w = e.w; 

    auto [mx1, mx2] = lca.root(u, v);

    if (w > mx1) {
        ans = min(ans, total - mx1 + w);
    }
    else if (w > mx2) {
        ans = min(ans, total - mx2 + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    lca.adj.resize(n + 1);
    fill_n(vis, MAXN, 0);

    dsu.init(n);
    g.reserve(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.emplace_back(edge(u, v, w, i));
    }

    sort(g.begin(), g.end(), cmp);

    for (auto e : g) {
        if (dsu.merge(e.u, e.v)) {
            total += e.w;
            vis[e.id] = 1; 

            lca.adj[e.u].push_back({e.v, e.w}); 
            lca.adj[e.v].push_back({e.u, e.w}); 
        }
    }

    lca.build(n);

    for(auto e : g) {
        if (!vis[e.id]) sol(e); 
    }

    cout << ans << '\n';
    return 0;
}
