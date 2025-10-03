#include <iostream> 
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
int tin = 0 , scc = 0;
const int maxn = 1e6 + 5; 
const int INT_MAX = 2e9; 
int low[maxn], num[maxn]; 
stack<int> st;
int n, m; 
vector<int> g[maxn]; 
bool deleted[maxn], scc_id[maxn]; 
int root[maxn]; 

void input() {
    cin >> n >> m; 

    while (m--) {
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
    }
    fill_n(low, maxn, 0);
    fill_n(num, maxn, 0);
    fill_n(par, maxn, -1);
    fill_n(deleted, maxn, false);
    fill_n(scc_id, maxn, false);
    fill_n(root, maxn, 0);

}

void dfs(int u) {
    low[u] = num[u] = ++tin;
    st.push(u); 
    for(int v : g[u]) { 
        if (deleted[v]) continue; 
        if(!num[v]) {
            dfs(v); 
            low[u] = min(low[v], low[u]); 
        }
        else if (num[v] < num[u]) 
            low[u] = min(low[u], num[v]); 
    }   
    
    if (low[u] == num[u]) {
        int v; 
        scc++;
        do {
            v = st.top(); 
            st.pop(); 
            low[v] = num[v] = INT_MAX;
            deleted[v] = true; 
            root[v] = scc; 
        } while ( v != u); 
    }
}

int main() {
    input(); 
    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i);
        } 
    }
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            if (root[u] != root[v]) scc_id[root[v]] = true;
        }
    }

    int dem = 0; 
    for (int i = 1; i <= scc; ++i) {
        if (!scc_id[i]) dem++; 
    }
    cout << dem << endl; 
    return 0; 
}
