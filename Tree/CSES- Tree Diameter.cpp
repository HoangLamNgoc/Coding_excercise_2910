#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

vector<int> g[N];
bool vis[N];
int d[N];

void bfs(int s) {
    fill_n(d, N, oo);
    fill_n(vis, N, 0);

    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(d[u] == oo) continue;

        for(int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n; cin >> n;

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    bfs(1);
    int ans, maxval = 0;
    for(int i = 1; i <= n; ++i) {
        if(maxval < d[i]) {
            maxval = d[i];
            ans = i;
        }
    }

    bfs(ans);
    maxval = 0;
    for(int i = 1; i <= n; ++i) {
        maxval = max(maxval, d[i]);
    }

    cout << maxval;
}

/*
void dfs(int u, int par) {
    d[u] = 0;
    int best1 = 0, best2 = 0;
    for(int v : g[u]) {
        if(v == par) continue;
        dfs(v, u);
        int best = d[v] + 1;
        d[u] = max(d[u], best);

        if(best > best1) {
            best2 = best1;
            best1 = best;
        } else if(best > best2) {
            best2 = best;
        }
    }
    diameter = max(diameter, best1 + best2);
}
*/
