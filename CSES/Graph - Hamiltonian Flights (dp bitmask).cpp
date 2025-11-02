#include <iostream>
#include <algorithm>
#include <vector> 
#include <cstring> 

using namespace std; 
const int mod = 1e9 + 7; 
signed main() {
    int n, m; cin >> n >> m; 

    vector<int> g[n + 1]; 
    while(m--) {
        int u, v; 
        cin >> u >> v;
        --u, --v;  
        g[u].emplace_back(v); 
    }
    
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    dp[1][0] = 1;

    for(int mask = 1; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) continue; // chưa thăm đỉnh i 
            long long w = dp[mask][i]; 
            if (!w) continue; 

            for(int v : g[i]) {
                if (mask & (1 << v)) continue; // đã thăm v 

                int p = mask | (1 << v); 
                dp[p][v] += w;
                dp[p][v] %= mod; 
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] % mod; 
}
