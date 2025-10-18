#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 200000000000000000LL;

vector<pair<int, long long>> g[N];
long long dist[N];
int trace[N];

void dij(int s, int n) {
    fill_n(dist, N, INF);
    fill_n(trace, N, -1);
    vector<bool> used(N, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();

        if (used[u]) continue;
        used[u] = true;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                trace[v] = u;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dij(1, n);
    for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    return 0;
}
