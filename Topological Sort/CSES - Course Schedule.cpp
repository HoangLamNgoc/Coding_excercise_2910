#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5; 
vector<int> g[maxn], tp; 
int a[maxn], vis[maxn]; 
int n, m;
bool ok = true; 

void input() {
    cin >> n >> m; 

    while (m--) {
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
    }

    fill_n(vis, maxn, false); 
    fill_n(a, maxn, 0); 
}

void dfs(int u) {
    vis[u] = 1; 
    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
        else if (vis[v] == 1 ) {
            cout << "IMPOSSIBLE" << endl;
            ok = false;
            exit(0);
        }
    }
    tp.push_back(u);
    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i); 
    }

    if (!ok) return 0; 
    if (tp.size() < n) {
        cout << "IMPOSSIBLE" << endl; 
        return 0; 
    }

    reverse(tp.begin(), tp.end());
    int cnt = 0; 
    for(int x : tp) cout << x << " "; 
}
