#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int N = (int)1e5 + 5;

vector<int> g[N];
int vis[N];
int pre[N];
int n, m;
int start, end1;
bool found = false;

void input() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    fill_n(vis, N, 0);
    fill_n(pre, N, -1);
}

void dfs(int u, int par = 0) {
    vis[u] = 1;
    pre[u] = par;
    if(found) return;

    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v, u);
        } else if(vis[v] == 1) {
            start = v;
            end1 = u;
            found = true;
            return;
        }
    }
    vis[u] = 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }

    if(!found) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> path;
    path.emplace_back(start); 
    for(int v = end1;; v = pre[v]) {
        path.emplace_back(v);
        if(v == start ) break; 
    }

    for(const int &i : path) {
        cout << i << ' ';
    }
}
