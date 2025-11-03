#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
const long long NEG_INF = -9e18;

struct Edge {
    int u, v;
    long long w;
};

int n, m;
vector<Edge> e;
vector<int> g[N], gr[N];
long long d[N];
bool vis[N], vis2[N];

void dfs1(int u) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v]) dfs1(v);
}

void dfs2(int u) {
    vis2[u] = true;
    for (int v : gr[u])
        if (!vis2[v]) dfs2(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        e.push_back({a, b, x});
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    dfs1(1);
    dfs2(n);

    fill(d, d + N, NEG_INF);
    d[1] = 0;

    for (int i = 1; i < n; ++i) {
        for (auto &E : e) {
            if (d[E.u] == NEG_INF) continue;
            d[E.v] = max(d[E.v], d[E.u] + E.w);
        }
    }

    for (auto &E : e) {
        if (d[E.u] == NEG_INF) continue;
        if (d[E.v] < d[E.u] + E.w) {
            if (vis[E.u] && vis2[E.v]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << d[n];
}
