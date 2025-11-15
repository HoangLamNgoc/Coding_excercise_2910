#include <iostream>
#include <vector>

using namespace std; 
const int N = 2e5 + 5;
vector<int> g[N]; 
long long dp[N]; 
long long subsz[N]; 

void dfs(int u, int par = 0) {
    for(int v : g[u]) {
        if(v == par) continue;
        dfs(v, u); 
        dp[u] += dp[v] + subsz[v];
        subsz[u] += subsz[v];  
    }
}
long long n;
void redfs(int u, int par = 0) {
    for(int v : g[u]) {
        if(v == par) continue;
        dp[v] = dp[u] - subsz[v] + (n - subsz[v]);
        redfs(v, u);
    }
}

int main() {
    cin >> n; 

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v; 

        g[u].push_back(v);
        g[v].push_back(u); 
    }

    fill_n(dp, N, 0); 
    fill_n(subsz, N, 1);
    dfs(1); 
    redfs(1);
    for(int i = 1; i <= n; ++i) cout << dp[i] << ' '; 
}
