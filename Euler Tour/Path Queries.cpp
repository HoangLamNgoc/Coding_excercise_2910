#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5; 

int n, q; 
struct BIT {
    long long bit[MAXN << 1] = {}; 

    void upd(int u, long long x) {
        for(; u <= 2 * n; u += (u & -u)) 
            bit[u] += x * 1ll;  
    } 

    long long que(int u) {
        long long ans = 0; 
        for(; u; u -= (u & -u)) 
            ans += bit[u];
        return ans; 
    }
} fen; 

int st[MAXN], en[MAXN];
long long val[MAXN]; 
int tin = 0; 

vector<int> adj[MAXN]; 

void dfs(int u, int p) {
    st[u] = ++tin; 
    fen.upd(tin, val[u]); 

    for(int v : adj[u]) {
        if (v == p) continue; 

        dfs(v, u); 
    }

    en[u] = ++tin; 
    fen.upd(tin, -val[u]); 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> n >> q; 

    for(int i = 1; i <= n; ++i) 
        cin >> val[i];

    for(int u, v, i = 1; i < n; ++i) {
        cin >> u >> v; 

        adj[u].emplace_back(v); 
        adj[v].emplace_back(u); 
    }

    dfs(1, 0); 

    while (q--) {
        int t, s, x; 
        cin >> t; 

        if (t == 1) {
            cin >> s >> x; 

            int diff = val[s] - x;

            fen.upd(st[s], -diff); 
            fen.upd(en[s], diff);  
            val[s] = x; //ngu hoc chua :) 
        }

        else {
            cin >> s; 
            cout << fen.que(st[s]) << "\n"; 
        }
    }
}
