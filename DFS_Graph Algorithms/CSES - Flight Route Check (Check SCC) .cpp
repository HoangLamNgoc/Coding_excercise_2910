#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int N = 2e5 + 5; 

vector<int> g[N];
vector<bool> vis(N, 0); 
void dfs(int s) {
    vis[s] = true; 
    for(int v : g[s]) {
        if(!vis[v]) dfs(v); 
    }
}

vector<int> gr[N]; 
vector<bool> vis2(N, 0); 
void dfsr(int s) {
    vis2[s] = true; 
    for(int v : gr[s]) {
        if(!vis2[v]) dfsr(v); 
    }
}

signed main() {
    int n, m; 
    cin >> n >> m; 

    while(m--) {
        int u, v; 
        cin >> u >> v; 
        g[u].emplace_back(v); 
        gr[v].emplace_back(u); 
    }

    dfs(1); 
    dfsr(1); 

    for(int i = 2; i <= n; ++i) {
        if(!vis[i]) {
            cout << "NO\n"; 
            cout << 1 << ' '; 
            cout << i << '\n';
            return 0; 
        }
        if(!vis2[i]) {
            cout << "NO\n"; 
            cout << i << ' '; 
            cout << 1 << '\n';
            return 0; 
        }  
    }
    cout << "YES" << '\n'; 
}
