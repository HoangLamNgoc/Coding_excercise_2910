#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

struct edge {
    int t, id;

    edge(int a, int b) : t(a), id(b) {}
};

const int N = (int)1e5 + 1;
const int M = 4 * N;

bool tplt[M];
vector<edge> adj[N];
bool vis[M];

void dfs(int u, int par = 0) {
    for(auto[v, i] : adj[u]) {
        if (v == par) continue;
        if(!tplt[v]) {
            tplt[v] = 1;
            dfs(v, u);
        }
    }
}

list<int> euler_walk(int u) {
    list<int> ans;
    ans.push_back(u);

    while(!adj[u].empty()) {
        int v = adj[u].back().t;
        int idx = adj[u].back().id;

        adj[u].pop_back();

        if (vis[idx] == 1 ) continue;
        if (idx % 2 == 0) {
            if(vis[idx - 1] == 1 ) continue;
            vis[idx] = vis[idx - 1] = 1;
        }
        else {
            if(vis[idx + 1] == 1 ) continue;
            vis[idx] = vis[idx + 1] = 1;
        }

        u = v;
        ans.push_back(u);
    }

    for(auto it = ++ans.begin() ; it != ans.end(); ++it) {
        list<int> t = euler_walk(*it);
        t.pop_back();
        ans.splice(it, t);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int indeg[n + 1];
    fill_n(indeg, n + 1, 0);

    for(int i = 1; i <= 2 * m; i += 2) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i + 1});
        ++indeg[u];
        ++indeg[v];
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0) continue;
        if(indeg[i] % 2 != 0 || !tplt[i]) {
        cout << "IMPOSSIBLE";
        return 0;
        }
    }

    list<int> ans = euler_walk(1);
    for(auto it = ans.begin(); it != ans.end(); ++it) cout << *it << ' ';
}
