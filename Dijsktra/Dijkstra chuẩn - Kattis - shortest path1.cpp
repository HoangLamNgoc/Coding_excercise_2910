#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> g[N];
long long dist[N];

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    fill(dist, dist + N, INF);
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        pair<long long,int> r = q.top();
        q.pop();

        long long du = r.first; 
        int u = r.second; 
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0) break;

        for (int i = 0; i < n; i++) g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        dijkstra(s);
        while (q--) {
            int p;
            cin >> p;
            if (dist[p] < INF)
                cout << dist[p] << '\n';
            else
                cout << "Impossible\n";
        }

        cout << '\n'; 
    }
    return 0;
}

