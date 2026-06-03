#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5; 

int n; 

int tour[MAXN], st[MAXN], en[MAXN]; 
int val[MAXN];

vector<int> adj[MAXN]; 

int tin = 0; 

map<int,int> occ; 

struct BIT {
    int bit[MAXN] = {}; 

    void upd(int u, int v) {
        for(; u <= n + 1; u += (u & -u)) {
            bit[u] += v; 
        }
    }

    int que(int u) {
        int res = 0;
        for(; u; u -= (u & -u)) 
            res += bit[u]; 
        return res; 
    }
} fen; 

void dfs(int u, int p) {
    st[u] = ++tin; 

    if (!occ.count(val[u])) 
        tour[tin] = 1; //luu y tin kp u 
    else
        tour[tin] = occ[val[u]] + 1; 

    occ[val[u]] = st[u]; 
    for(int v : adj[u]) {
        if (v == p) continue; 

        dfs(v, u);
    }

    en[u] = tin; 
}

struct que {
    int v, t, id; 
}; 

vector<que> evs[MAXN];
int ans[MAXN]; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> n; 

    for(int i = 1; i <= n; ++i) 
        cin >> val[i]; 

    for(int u, v, i = 1; i < n; ++i) {
        cin >> u >> v; 

        adj[u].emplace_back(v); 
        adj[v].emplace_back(u); 
    }   

    dfs(1, 0); 

    for(int i = 1; i <= n; ++i) { 
        int L = st[i]; 
        int R = en[i]; 

        evs[L - 1].push_back({L, -1, i}); 
        evs[R].push_back({L, 1, i}); 
    }

    for(int i = 0; i <= n; ++i) { // n : kich thuoc cua euler tour 
        if(i) fen.upd(tour[i], 1);

        for(que e : evs[i]) 
            ans[e.id] += e.t * fen.que(e.v); 
    }

    for(int i = 1; i <= n; ++i) 
        cout << ans[i] << ' '; 
}
