#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,long long>> g[n + 1];
    while(m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        g[u].emplace_back(make_pair(v, w));
    }

    const long long oo = 1e18;
    long long d[n + 1];
    fill_n(d, n + 1, oo);
    d[1] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});
    vector<int> order;
    bool vis[n + 1];
    fill_n(vis, n + 1, false);

    while(!pq.empty()) {
        pair<long long,int> e = pq.top(); pq.pop();

        int c = e.first;
        int u = e.second;

        if ( c > d[u]) continue;
        if(!vis[u]) order.emplace_back(u);
        vis[u] = 1;
        for(pair<int,long long> v1 : g[u]) {
            long long w = v1.second;
            int v = v1. first;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    cout << d[n] << ' ';
    const long long mod = 1e9 + 7;
    long long ways[n + 1], minval[n + 1], maxval[n + 1];
    fill_n(ways, n + 1, 0);
    fill_n(minval, n + 1, oo);
    fill_n(maxval, n + 1, 0);
    ways[1] = 1; minval[1] = 0;

    for(int u : order) {
        for(pair<int,long long> v1 : g[u]) {
            int v = v1.first;
            long long w = v1.second;

            if (d[u] + w == d[v]) {
                ways[v] = (ways[v] + ways[u]) % mod;
                minval[v] = min(minval[v], minval[u] + 1);
                maxval[v] = max(maxval[v], maxval[u] + 1);
            }
        }
    }
    cout << ways[n] % mod << ' ' << minval[n] <<' ' << maxval[n];
}
