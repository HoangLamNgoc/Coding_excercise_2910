#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOGN = 20;

int n, q;
vector<int> adj[MAXN];

int dep[MAXN];
int par[LOGN][MAXN];

int dwn[MAXN];
int mx1[MAXN], mx2[MAXN];
int bst[MAXN];

int upv[MAXN];

void dfs1(int u, int p) {
    par[0][u] = p;

    mx1[u] = mx2[u] = 0;
    bst[u] = -1;

    for (int v : adj[u]) {
        if (v == p) continue;

        dep[v] = dep[u] + 1;
        dfs1(v, u);

        int val = dwn[v] + 1;

        if (val > mx1[u]) {
            mx2[u] = mx1[u];
            mx1[u] = val;
            bst[u] = v;
        }
        else if (val > mx2[u]) {
            mx2[u] = val;
        }
    }

    dwn[u] = mx1[u];
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;

        int use = mx1[u];
        if (bst[u] == v) use = mx2[u];

        use = max(use, upv[u]);

        upv[v] = use + 1;

        if (upv[v] > mx1[v]) {
            mx2[v] = mx1[v];
            mx1[v] = upv[v];
            bst[v] = u;
        }
        else if (upv[v] > mx2[v]) {
            mx2[v] = upv[v];
        }

        dfs2(v, u);
    }
}

int jump(int u, int k) {
    for (int i = 0; i < LOGN; i++)
        if (k & (1 << i))
            u = par[i][u];
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    u = jump(u, dep[u] - dep[v]);

    if (u == v) return u;

    for (int i = LOGN - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int dista(int u, int v) {
    int w = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);

    for (int i = 1; i < LOGN; i++)
        for (int j = 1; j <= n; j++)
            par[i][j] = par[i - 1][par[i - 1][j]];

    upv[1] = 0;
    dfs2(1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            cout << 0 << '\n';
            continue;
        }

        int d = dista(u, v);
        int root = lca(u, v);

        int t = (d - 1) / 2;

        int du = dista(u, root);
        int dv = dista(v, root);

        int mid;
        bool block = 0;

        if (dv >= t) 
            mid = jump(v, t);
        else 
            mid = jump(u, d - t);

        int distum = d - t;
        int ans = mx1[mid]; 
        
        if (dv > t) {
            if (bst[mid] == par[0][mid]) {
                ans = mx2[mid]; 
            }
        }

        else {
            int cv = jump(u, d - t - 1); 

            if (bst[mid] == cv) {
                ans = mx2[mid]; 
            }
        }

        cout << ans + distum << "\n";
    }
}
