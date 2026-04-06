#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int n, q;
int arr[MAXN];
int depth[MAXN];
int up[MAXN][LOG];
vector<int> adj[MAXN];

vector<int> basis[MAXN][LOG];

void add(vector<int>& b, int x) {
    for (int y : b) x = min(x, x ^ y);
    if (x) b.push_back(x);
}

vector<int> merge(vector<int> a, const vector<int>& b) {
    for (int x : b) add(a, x);
    return a;
}

void dfs(int u, int p) {
    up[u][0] = p;

    for (int v : adj[u]) {
        if (v == p) continue;

        depth[v] = depth[u] + 1;

        basis[v][0] = basis[u][0];  
        add(basis[v][0], arr[v]);  

        dfs(v, u);
    }
}

void build() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            basis[i][j] = merge(basis[i][j-1], basis[up[i][j-1]][j-1]);
        }
    }
}

vector<int> query(int u, int v) {
    vector<int> res;

    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i)) {
            res = merge(res, basis[u][i]);
            u = up[u][i];
        }
    }

    if (u == v) return res;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            res = merge(res, basis[u][i]);
            res = merge(res, basis[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }

    res = merge(res, basis[u][0]);
    res = merge(res, basis[v][0]);

    return res;
}

bool can(vector<int>& b, int k) {
    for (int x : b) k = min(k, k ^ x);
    return k == 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    add(basis[1][0], arr[1]);

    dfs(1, 0);
    build();

    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;

        vector<int> b = query(u, v);

        if (can(b, k)) cout << "YES\n";
        else cout << "NO\n";
    }
}
