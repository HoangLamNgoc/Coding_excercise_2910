#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
const int N = 1e6 + 5;
vector<int> g[N], tp;
int n, m;
int indeg[N];
queue<int> q;
string a;

void input() {
    cin >> n >> m;
    cin >> a;
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
        int u = q.front(); q.pop();
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

    vector<vector<long long>> dp(n + 1, vector<long long>(26, 0));

    if ((int)tp.size() < n ) {
        cout << -1 << endl;
        return 0;
    }

    long long ans = 0;
    for(int u : tp) {
        int idx = a[u - 1]-'a';
        dp[u][idx]++;
        ans = max(ans, dp[u][idx]);
        for(int v : g[u]) {
            for(int c = 0; c < 26; ++c) {
                dp[v][c] = max(dp[v][c], dp[u][c]);
                ans = max(ans, dp[v][c]);
            }
        }
    }

    cout << ans << endl;
}
