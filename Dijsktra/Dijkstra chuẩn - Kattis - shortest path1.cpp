#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int,int>> g[N];
long long dist[N];

void dijkstra(int s) {
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    fill(dist, dist + N, INF);
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [du, u] = q.top(); q.pop();
        if (du != dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w1;
        cin >> u >> v >> w1;
        g[u].push_back({v, w1});
    }

    dijkstra(k);

    while (t--) {
        int p;
        cin >> p;
        cout << dist[p] << '\n';
    }
}
