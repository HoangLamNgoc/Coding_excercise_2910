#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int N = 2e5 + 5; 

int dp[N][2]; 
vector<int> g[N]; 
void dfs(int u, int par = -1) {
    for(int v : g[u]) {
        if (v == par) continue; 
        dfs(v, u); 
 
        dp[u][0] += max(dp[v][0], dp[v][1]); 
    }

    for(int v : g[u]) {
        if (v == par) continue;
        dp[u][1] = max(dp[u][1], 
                       dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1])); 
    }
} 

int main() {
    int n; cin >> n; 

    while(--n) {
        int u, v; 
        cin >> u >> v; 
        
        g[u].emplace_back(v); 
        g[v].emplace_back(u); 
    }

    dfs(1); 
    cout << max(dp[1][0], dp[1][1]); 
}
