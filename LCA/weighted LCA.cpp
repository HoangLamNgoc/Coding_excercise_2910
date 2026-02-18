#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 
const int MAXN = 1e5 + 5; 
const int LOG = 20; 

struct LCA { 
    vector<vector<pair<int,int>>> adj;
    int up[MAXN][LOG]; 
    long long val[MAXN][LOG]; 
    int depth[MAXN]; 

    void build(int n) {
        adj.resize(n + 1);
        fill(depth, depth + n + 1, -1); 

        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < LOG; ++j) { 
                up[i][j] = 0; 
                val[i][j] = 0LL; 
            }
        }

        for(int i = 1; i < n; ++i) {    
            int u, v, w; 
            cin >> u >> v >> w; 

            adj[u].emplace_back(make_pair(v, w));
            adj[v].emplace_back(make_pair(u, w)); 
        } 

        queue<int> q;
        q.push(1);

        depth[1] = 0;
        up[1][0] = 1; 
        val[1][0] = 0;

        while (!q.empty()) {
            int u = q.front(); 
            q.pop(); 

            for(pair<int,int> v1 : adj[u]) {
                int v = v1.first; 
                int w = v1.second; 

                if (depth[v] != -1) continue; 

                depth[v] = depth[u] + 1; 
                up[v][0] = u; 
                val[v][0] = w; 
                q.push(v); 
            }
        }

        for(int k = 1; k < LOG; ++k) {
            for(int i = 1; i <= n; ++i) {
                int mid = up[i][k - 1]; 
                up[i][k] = up[mid][k - 1];
                val[i][k] = val[mid][k - 1] + val[i][k - 1];  
            }
        }
    }

    long long root(int u, int v) {
        long long res = 0; 

        if (depth[u] != depth[v]) {
            if (depth[u] < depth[v]) swap(u, v);

            int k = depth[u] - depth[v]; 

            for(int i = k; i; i -= (i & (-i))) {
                int x = __builtin_ctz(i); 
                res += val[u][x];
                u = up[u][x]; 
            }
        }

        if (v == u) return res; 

        int k = depth[u]; 
        for(int i = __lg(k); i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                res += val[u][i]; 
                res += val[v][i]; 

                u = up[u][i]; 
                v = up[v][i]; 
            }
        }

        res += val[u][0];
        res += val[v][0];  
        return res; 
    }
} lca; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n, q; cin >> n >> q; 

    lca.build(n); 

    while (q--) {
        int u, v; 
        cin >> u >> v; 
        
        cout << lca.root(u, v) << '\n';  
    }    
}
