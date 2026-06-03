#include <bits/stdc++.h>

using namespace std; 
const int MAXN = 2e5 + 5; 

vector<int> adj[MAXN]; 
int tour[MAXN], st[MAXN], en[MAXN]; 
int par[MAXN]; 
int tin = 0; 

/* 
B1 : Flattening Tree
B2 : BS on Tour (find the kth smallest in which [1, k] on Euler Tour contains a, b -> Log2(n)
B3 : Cout ans 
*/

void dfs(int u, int p) {
    par[u] = p;
    st[u] = ++tin; 
    tour[tin] = u; 

    for(int v : adj[u]) {
        if (v == p) continue; 

        dfs(v, u); 
    }

    en[u] = tin; 
}

int M = 0; 

//lam 1 ham doc cau tra loi 
int que(int k) {
    cout << '?' << ' ' << k << " ";
    for(int i = 1; i <= k; ++i)
        cout << tour[i] << " "; 

    cout << "\n"; 
    cout.flush(); 

    int res; cin >> res; 
    return res; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n;  

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v; 
        
        adj[u].emplace_back(v); 
        adj[v].emplace_back(u); 
    }

    dfs(1, 0); 

    M = que(n); 

    int l = 2, r = n; 
    while (l <= r) {
        int m = (l + r) >> 1;

        if (que(m) == M) 
            r = m - 1; 
        else 
            l = m + 1; 
    }
    cout << '!' << ' ' << tour[l] << ' ' << par[tour[l]] << "\n";   //l la index

}
