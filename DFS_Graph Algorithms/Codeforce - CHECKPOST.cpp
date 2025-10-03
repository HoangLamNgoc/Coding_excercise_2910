#include <iostream> 
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

int tin = 0, scc = 0;
const int maxn = 1e6 + 5; 
const int INF = 2e9; 

int low[maxn], num[maxn]; 
int minval[maxn]; 
int root[maxn];   
stack<pair<int,int>> st;
int n, m; 
vector<pair<int,int>> g[maxn]; 
bool deleted[maxn]; 
map<int,bool> scc_id; 
map<int,int> mp; 

void input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) { 
        int j; 
        cin >> j; 
        mp[i] = j; 
    }
    cin >> m; 
    while (m--) {
        int u, v; 
        cin >> u >> v;
        g[u].push_back({v, mp[v]}); 
    }
    fill_n(low, maxn, 0);
    fill_n(num, maxn, 0);
    fill_n(deleted, maxn, false);
    fill_n(minval, maxn, INF); 
}

void dfs(int u) {
    low[u] = num[u] = ++tin;
    st.push({u, mp[u]}); 

    for(pair<int,int> v : g[u]) { 
        if (deleted[v.first]) continue;
        int v1 = v.first; 
        if(!num[v1]) {
            dfs(v1); 
            low[u] = min(low[u], low[v1]); 
        }
        else if (num[v1] < num[u]) {
            low[u] = min(low[u], num[v1]); 
        }
    }   

    if (low[u] == num[u]) {
        pair<int,int> v; 
        scc++;
        do {
            v = st.top(); 
            st.pop(); 
            minval[scc] = min(minval[scc], v.second);
            deleted[v.first] = true; 
            root[v.first] = scc;
        } while (v.first != u); 
    }
}

int main() {
    input(); 

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i);
        } 
    }

    int maxv = 0; 
    for (int i = 1; i <= scc; ++i) {
        maxv += minval[i]; 
    }

    for (int u = 1; u <= n; ++u) {
        for (auto &p : g[u]) {
            int v = p.first;
            if (root[u] != root[v]) {
                if(scc_id.count(root[u])) {
                    scc--; 
                    maxv -= max(minval[root[u]], minval[root[v]]); 
                } else {
                    scc_id[root[u]] = false; 
                }
            }
        }
    }

    cout << maxv << " " << scc << endl; 
    return 0; 
}
