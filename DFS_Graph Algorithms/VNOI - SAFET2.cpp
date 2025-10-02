#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std; 
const int maxn = 1e5 + 6; 
int low[maxn], num[maxn], par[maxn]; 
vector<int> g[maxn]; 
int tin = 0, best = 1; 
int bcc = 0;
int c[maxn]; 
stack <pair<int, int>> st;

void dfs(int u) { 
    low[u] = num[u] = ++tin; 
    for (int v : g[u]) {
        if ( v == par[u]) continue;
        if (!num[v]) {
            par[v] = u;
            st.push({u, v});  
            dfs(v); 
            low[u] = min(low[v], low[u]); 
            if (low[v] >= num[u]) {
                int dem = 0, v1, v2; 
                ++bcc;
                do {
                    v1 = st.top().first;
                    v2 = st.top().second;  
                    st.pop();

                    if(c[v1] != bcc) dem++;
                    if (c[v2] != bcc) dem++; 

                    c[v1] = bcc; 
                    c[v2] = bcc; 
                } while (make_pair(v1, v2) != make_pair(v, u) && make_pair(v1, v2) != make_pair(u, v)); 
                best = max(dem, best); 
            }
        }
        else {
            low[u] = min(low[u], num[v]);
            st.push({u, v}); 
        } 
    } 
}

int main() {
    int n, m; 
    cin >> n >> m; 

    while(m--) {
        int u, v; 
        cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }

    memset(low, 0, sizeof(low)); 
    memset(num, 0, sizeof(num));
    memset(par, -1, sizeof(par));  
    memset(c, -1, sizeof(c));

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            st.push({i, -1});   
            dfs(i);
        } 
    }
    cout << best << endl; 
    return 0; 
}
