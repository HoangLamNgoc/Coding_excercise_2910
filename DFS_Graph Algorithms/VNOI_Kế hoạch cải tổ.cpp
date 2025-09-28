#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5; 
vector<int> g[maxn];
int n, m; 
long long low[maxn], num[maxn], cnt_bridge[maxn], f[maxn], cnt_node[maxn]; 
long long tin = 0, cc = 0, kq = 0;

void dfs(int u, int pre) {
    low[u] = num[u] = ++tin; 
    cnt_node[cc]++;
    f[u] = 1; 
    for (int v : g[u]) {
        if (v == pre) continue; 
        if (!num[v]) {
            dfs(v, u); 
            f[u] += f[v]; 
            low[u] = min(low[u], low[v]); 
            if (low[v] == num[v]) {
                cnt_bridge[cc]++;
                kq += 1LL * f[v] * (n - f[v]) - 1;
            }   
        }
        else low[u] = min(num[v], low[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m; 
    
    for(int i = 1; i <= m; ++i) {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    
    fill_n(low, maxn, 0);
    fill_n(num, maxn, 0); 
    fill_n(f, maxn, 0);
    fill_n(cnt_node, maxn, 0);
    fill_n(cnt_bridge, maxn, 0); 
    
    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            cc++;
            dfs(i, -1); 
        }
    }
    
    if (cc > 2) 
        cout << 0 << endl; 
    else if (cc == 2) {
        long long dem = 1LL * cnt_node[1] * cnt_node[2] * (m - cnt_bridge[1] - cnt_bridge[2]); 
        cout << dem << endl;
    }
    else {
        kq += 1LL * (m - cnt_bridge[1]) * ((1LL * n * (n - 1) / 2) - m);
        cout << kq << endl;
    }
    
    return 0;
}
