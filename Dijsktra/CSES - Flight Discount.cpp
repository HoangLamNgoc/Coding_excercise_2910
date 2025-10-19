#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e6 + 5;
const long long INF = 1LL * 2e18;
vector<pair<int,int>> g[N];
long long d[N][2];
int n, m;

void dij(int s) {
    bool p[N][2];

    for(int i = 1; i <= n; ++i) p[n][0] = p[n][1] = false;
    d[s][0] = 0;

    priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long, pair<int,int>>>> q;
    q.push({0,{s, 0}});

    while(!q.empty()) {
        pair<long long,pair<int,int>> r = q.top();
        q.pop();

        int u = r.second.first;
        int used = r.second.second;

        if(p[u][used]) continue;
        p[u][used] = 1;

        for(pair<int,int> c : g[u]) {
            int v = c.first;
            int w = c.second;

            if(!used && d[v][0] > d[u][0] + w) {
                d[v][0] = d[u][0] + w;
                q.push({d[v][0], {v, 0}});
            }

            if(!used && d[v][1] > d[u][0] + w / 2) {
                d[v][1] = d[u][0] + w / 2;
                q.push({d[v][1], {v, 1}});
            }

            if(used && d[v][1] > d[u][1] + w) {
                d[v][1] = d[u][1] + w;
                q.push({d[v][1], {v, 1}});
            }
        }
    }
}

void input() {
    cin >> n >> m;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    for(int i = 1; i <= n; ++i)
        d[i][1] = d[i][0] = INF;
    dij(1);
}

int main() {
    input();
    cout << min(d[n][0], d[n][1]) << '\n';
    return 0;
}
