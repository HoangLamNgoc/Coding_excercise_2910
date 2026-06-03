#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5;
 
int n;
int m; 
struct BIT {
    vector<int> bit = vector<int>(MAXN, 0); 

    void upd(int u, int v) {
        for(; u <= n + 1; u += (u & -u)) 
            bit[u] += v; 
    }

    int que(int v) {
        int ans = 0; 
        for(; v; v -= (v & -v)) 
            ans += bit[v];
        return ans;  
    }
} fen; 

vector<int> adj[MAXN]; 
int col[MAXN]; 

int tour[MAXN];
int st[MAXN], en[MAXN];     
int tin = 0;  

map<int, int> occ; 

void dfs(int u, int p) {
    st[u] = ++tin; 
    
    if (occ.count(col[u])) 
        tour[tin] = occ[col[u]] + 1; 
    else
        tour[tin] = 1; 
    
    int a = occ[col[u]]; 
    occ[col[u]] = st[u]; 

    for(int v : adj[u]) {
        if (v == p) continue; 

        dfs(v, u); 
    }  

    en[u] = tin; 
}

struct ev {
    int val; 
    int t;  
    int id; 
}; 

int ans[MAXN]; 
vector<ev> evs[MAXN]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n;

    // unordered_map<int, int> occ; 
    for(int i = 1; i <= n; ++i) 
        cin >> col[i]; 
        
    //     if (!occ.count(x)) last[i] = 0;
    //     else last[i] = occ[x]; 
        
    //     occ[x] = i; 
    // }
    //sai : mang tinh va thu tu duyet DFS la khac nhau -> Neu last co ban ton tai nhung gia tri DFS chua toi -> st[last[u]] = 0 -> sai 
    //can duyet last dong theo Euler Tour 

    for(int u, v, i = 1; i < n; ++i) {
        cin >> u >> v; 

        adj[u].emplace_back(v); 
        adj[v].emplace_back(u); 
    }

    dfs(1, 0); 

    for(int u = 1; u <= n; ++u) {
        int L = st[u];
        int R = en[u]; 

        evs[R].push_back({L, 1, u}); //do +1 trong st[u], moi gia tri trong BIT duoc shift len 1 don vi do 0 la infinite loop
        evs[L - 1].push_back({L, -1, u});  
    }

    for(int i = 0; i <= n; ++i) {
        if (i) fen.upd(tour[i], 1); 

        for(ev e : evs[i]) 
            ans[e.id] += e.t * fen.que(e.val); 
    }



    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';  
}
