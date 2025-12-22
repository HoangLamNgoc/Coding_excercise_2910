#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 505;
const long long INF = 2e18;

int n, m;
int time_open[MAXN];
long long dp[MAXN][MAXN], weight[MAXN][MAXN];
bool vis[MAXN];

struct state {
    bool ok;
    int u, v, t, idx;
};

bool cmp(const state &a, const state &b) {
    return a.t < b.t || (a.t == b.t && a.ok < b.ok);
}

void opening_day(int u) {
    vis[u] = 1;

    for(int i = 1; i <= n; ++i) {
        if(vis[i] && weight[u][i] != INF) {
            dp[u][i] = weight[u][i];
            dp[i][u] = dp[u][i];
        }
    }

    for(int i = 1; i <= n; ++i) {
		if (!vis[i]) continue; 
        for(int j = 1; j <= n; ++j) {
            if(vis[j]) {
                if(dp[j][i] < INF && dp[i][u] < INF)
                    dp[j][u] = min({dp[j][u], dp[j][i] + dp[i][u], dp[j][u] + dp[i][j]});
                dp[u][j] = dp[j][u];
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
		if (!vis[i]) continue; 
        for(int j = 1; j <= n; ++j) {
            if(vis[j]) {
                if(dp[i][u] < INF && dp[u][j] < INF)
                    dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][j]);
                dp[j][i] = dp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i <= n; ++i) {
        vis[i] = false;
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = (i == j ? 0 : INF);
            weight[i][j] = (i == j ? 0 : INF);
        }
    }

    vector<state> events;

    for(int i = 1; i <= n; ++i) {
        cin >> time_open[i];
        events.push_back({0, 0, 0, time_open[i], i});
    }

    for(int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        weight[u][v] = min(weight[u][v], w);
        weight[v][u] = weight[u][v];
    }

    int q;
    cin >> q;
    vector<long long> ans(q+1);
    for(int i = 1; i <= q; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        events.push_back({1, u, v, t, i});
    }

    sort(events.begin(), events.end(), cmp);

    for(auto [ok, u, v, t, idx] : events) {
        if(!ok)
            opening_day(idx);
        else
            ans[idx] = (dp[u][v] < INF ? dp[u][v] : -1);
    }

    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';

    return 0;
}
