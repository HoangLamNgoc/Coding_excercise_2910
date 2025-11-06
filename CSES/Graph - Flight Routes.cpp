#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int N = (int)2e5 + 5;

bool ss(const long long& x, const long long& y) {
    return x > y;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, long long>> g[N];
    while (m--) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
    }

    vector<vector<long long>> d;
    d.resize(n + 1);
    d[1].emplace_back(0);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    q.push({0, 1});

    while (!q.empty()) {
        pair<long long,int> e = q.top();
        q.pop();
        long long c = e.first;
        int u = e.second;

        if ((int)d[u].size() == k && c > d[u].front()) continue;

        for (pair<int,long long> e1 : g[u]) {
            int v = e1.first;
            long long w = e1.second;
            long long new_cost = c + w;

            if ((int)d[v].size() < k) {
                d[v].emplace_back(new_cost);
                sort(d[v].begin(), d[v].end(), ss);
                q.push({new_cost, v});
            } else {
                if (new_cost < d[v][0]) {
                    d[v].emplace_back(new_cost);
                    d[v].erase(d[v].begin());
                    sort(d[v].begin(), d[v].end(), ss);
                    q.push({new_cost, v});
                }
            }
        }
    }

    sort(d[n].begin(), d[n].end());
    for (long long& i : d[n]) cout << i << ' ';
}
