#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 

using namespace std;

vector<vector<int>> g;
vector<int> onpath;
vector<int> perm;

void dfs_subtree(int u, int par) {
    for (int v : g[u]) {
        if (v == par) continue;
        if (onpath[v]) continue;
        dfs_subtree(v, u);
    }
    perm.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, st, en;
        cin >> n >> st >> en;
        g.assign(n+1, {});
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n+1, -1);
        queue<int> q;
        q.push(st);
        parent[st] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == en) break;
            for (int v : g[u]) if (parent[v]==-1) {
                parent[v] = u;
                q.push(v);
            }
        }

        if (n == 1) {
            cout << 1 << '\n'; 
            continue; 
        }
        vector<int> path;
        for (int v = en; v != 0; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());

        onpath.assign(n+1, 0);
        for (int x : path) onpath[x] = 1;

        perm.clear();
        for (int u : path) {
            for (int v : g[u]) {
                if (onpath[v]) continue;
                dfs_subtree(v, u);
            }
            perm.push_back(u);
        }

        for (int i = 0; i < n - 1; ++i) {
            cout << perm[i] << ' ';
        }
        cout << en << ' '; 
        cout << '\n';
    }
}
