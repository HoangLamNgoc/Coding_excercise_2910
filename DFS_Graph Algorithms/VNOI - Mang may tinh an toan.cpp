#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, cc, Time;
int was[N], par[N], root[N];
int num[N], low[N], size1[N];
long long ans[N];
vector<int> g[N];

void dfs(int u) {
    was[u] = cc;
    num[u] = ++Time;
    low[u] = N;
    size1[u] = 1;

    for (int v : g[u]) 
        if (v != par[u]) {
            if (was[v]) {
                low[u] = min(low[u], num[v]);
            } else {
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                size1[u] += size1[v];
            }
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        sort(g[u].begin(), g[u].end());
        g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
    }

    for(int i = 1; i <= n; ++i) {
        if (!was[i]) {
            cc++; 
            root[cc] = i; 
            dfs(i); 
        }
    }

    for (int u = 1; u <= n; ++u) {
        vector<int> paths; 

        for (int v : g[u])
            if (low[v] >= num[u] && par[v] == u)  paths.push_back(size1[v]); 

        long long sum = 0; 
        for (int i : paths) sum += i;
        
        int res = size1[root[was[u]]] - 1 - sum; 
        if (res > 0 ) paths.push_back(res), sum += res;
        
        long long sumq = 0; 
        for (int i : paths) sumq += 1LL * i * i; 
        ans[u] = (sum * sum - sumq) / 2;   
    }
   
    long long total = 0;
    for (int u = 1; u <= n; u++) total += ans[u];
    cout << fixed << setprecision(2) << (long double)total / n << "\n";
    return 0;
}
