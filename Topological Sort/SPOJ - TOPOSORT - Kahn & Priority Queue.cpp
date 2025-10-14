#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
const int N = 1e5 + 5;
const long long MOD = 1e9;

vector<int> g[N], tp;
int n, m;
int indeg[N];
priority_queue<int, vector<int>, greater<int>> q;

void input() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ++indeg[v];
    }
    for (int i = 1; i <= n; ++i)
        if (!indeg[i]) q.push(i);
}

void bfs() {
    while (!q.empty()) {
        int u = q.top(); q.pop();
        tp.push_back(u);
        for (int v : g[u]) {
            --indeg[v];
            if (!indeg[v]) q.push(v);
        }
    }
}

int main() {
    input();
    bfs();

    long long dp[N] = {0};
    dp[1] = 1;

    if ((int)tp.size() < n ) {
        cout << "Sandro fails." << endl;
        return 0;
    }

    for (int u : tp) cout << u << " "; 
    return 0;
}
