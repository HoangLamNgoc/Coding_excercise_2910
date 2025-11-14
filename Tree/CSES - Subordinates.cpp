#include <iostream>
#include <vector>

using namespace std;
const int N = 2e5 + 5;
vector<int> g[N + 1];
bool vis[N];
int sub[N];

void dfs(int u) {
    vis[u] = 1;

    for(int v : g[u]) {
        if (!vis[v]) {
            sub[u]++;
            dfs(v);
            sub[u] += sub[v];
        }
    }
}

int main() {
    int n; cin >> n;
    fill_n(sub, N, 0);
    for(int i = 2; i <= n; ++i) {
        int u; cin >> u;   
        g[u].push_back(i);
    }

    for(int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; ++i) cout << sub[i] << ' ';
}
