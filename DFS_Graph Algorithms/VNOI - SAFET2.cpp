#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std; 
const int maxn = 1e5 + 6; 
int low[maxn], num[maxn]; 
vector<int> g[maxn]; 
int tin = 0, best = 1; 
int bcc = 0;
int ncp[maxn]; 
stack <pair<int, int>> st;

void dfs(int u, int par) { 
    low[u] = num[u] = ++tin; 
    for (int v : g[u]) {
        if ( v == par) continue;
        if (!num[v]) {
            st.push({u, v});  
            dfs(v, u); 
            low[u] = min(low[v], low[u]); 
            if (low[v] >= num[u]) {
                int v1, v2, dem = 0; 
                ++bcc;
                do {
                    v1 = st.top().first;
                    v2 = st.top().second;  
                    st.pop();
                            
                    if(ncp[v1] != bcc) ++dem; 
                    if(ncp[v2] != bcc) ++dem;
            
                    ncp[v1] = bcc; 
                    ncp[v2] = bcc; 
                    
                } while (make_pair(v1, v2) != make_pair(v, u) && make_pair(v1, v2) != make_pair(u, v)); 
                best = max(best, dem); 
            }
        }
        else if (num[v] < num[u]) {
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
    memset(ncp, -1, sizeof(ncp));

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i, -1);
        } 
    }
     if (!st.empty()) {
        int dem = 0,  v1, v2;
        bcc++; 
        while (!st.empty()) {
            v1 = st.top().first;
            v2 = st.top().second; 
            
            if(ncp[v1] != bcc) ++dem; 
            if(ncp[v2] != bcc) ++dem;
            
            ncp[v1] = bcc; 
            ncp[v2] = bcc; 
        }
        best = max(best, dem); 
    }
    
    cout << best << endl; 
    return 0; 
}
