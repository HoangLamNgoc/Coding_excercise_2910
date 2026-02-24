#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
int h[N], up[N][20];
vector<int> adj[N];

void dfs(int u, int p)
{
    up[u][0] = p;
    for (int v : adj[u])
    {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);

    int d = h[u] - h[v];
    for (int i = 0; i < 20; i++)
        if (d >> i & 1)
            u = up[u][i];

    if (u == v) return u;

    for (int i = 19; i >= 0; i--)
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }

    return up[u][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("LCA.INP", "r", stdin);
    freopen("LCA.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    h[1] = 0;
    dfs(1, 0);

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
