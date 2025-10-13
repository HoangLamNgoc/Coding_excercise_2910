#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1005;
vector<int> g[N], tp;
int a[N];
int vis[N];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = n; i > 0; --i) {
        int r = 1, c = i - 1;
        while (r < c) {  
            int s = a[r] + a[c];
            if (s == a[i]) {
                g[r].push_back(i);
                g[c].push_back(i);
                ++r; --c;        
            } else if (s < a[i]) ++r;
            else --c;
        }
    }

    fill_n(vis, N, 0);
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs(v);
    tp.push_back(u); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    reverse(tp.begin(), tp.end());

    for (int i = 1; i <= n; ++i) {
        if (!g[i].empty()) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        }
    }

    long long dp[N];
    for (int i = 1; i <= n; ++i) dp[i] = 0;
    long long ans = 0;

    for (int u : tp) {
        dp[u] = max(dp[u], 1LL);          
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
        ans = max(ans, dp[u]);
    }

    cout << ans << "\n";
    return 0;
}
