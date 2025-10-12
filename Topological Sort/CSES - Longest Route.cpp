#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5; 
vector<int> g[maxn];
int vis[maxn]; 
vector<int> topo;
int n, m; 

void input() {
    cin >> n >> m; 
    
    while(m--) {
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
    }
    fill_n(vis, maxn, 0); 
}

void dfs(int u) {
    vis[u] = 1; 

    for(int v : g[u]) {
        if (!vis[v]) dfs(v); 
    }

    topo.push_back(u); 
    vis[u] = 2; 
}

int main() {
    input(); 

    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i); 
    }

    int dp[maxn], trace[maxn];
    fill_n(trace, maxn, -1);  
    int ans = 0, id = 0; 
    reverse(topo.begin(), topo.end()); 

    for(int u : topo) {
        for(int v : g[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                trace[v] = u; 
            }
        }
        if(dp[u] > ans) {
            ans = dp[u];
            id = u; 
        }
    }

    if (ans == 0 || id == 0) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> path; 
        for(int v = id; v != -1; v = trace[v]) {
            path.push_back(v); 
        } 
        cout << path.size() << endl; 
        reverse(path.begin(), path.end()); 
        for(const int& i : path) cout << i << " "; 
    }  
    return 0; 
}
