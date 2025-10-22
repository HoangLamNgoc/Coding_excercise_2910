#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N], sz[N];

void make_set(int u) {
    parent[u] = u;
    sz[u] = 1;
}

int find_set(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void merge(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; ++i) make_set(i);

    vector<pair<int,pair<int,int>>> g;

    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
    }

    for(int i = 0; i < q; ++i) {
        string s;
        int u,v;
        cin >> s;
        if(s == "cut") {
            cin >> u >> v;
            g.push_back({1,{u,v}});
        } else if(s == "ask") {
            cin >> u >> v;
            g.push_back({2,{u,v}});
        }
    }

    reverse(g.begin(), g.end());

    vector<string> ans;
    for(auto [i, uv] : g) {
        int u = uv.first, v = uv.second;
        if(i == 1) merge(u,v);
        else ans.push_back(find_set(u) == find_set(v) ? "YES" : "NO");
    }

    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << '\n';
}
