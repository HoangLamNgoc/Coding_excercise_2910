#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;
int n, m; 
const int maxn = 1e6 + 5; 
vector<int> g[maxn]; 
int low[maxn], num[maxn];  
int tin = 0;
int cnt = 1, ans = 0;  
int cnt_node[maxn]; 

void dfs(int u, int pre) {
    cnt_node[u] = 1;
    low[u] = num[u] = ++tin; 
    for (int v : g[u]) {
        if (v == pre ) continue; 
        if (!num[v]) {
            dfs(v, u);
            cnt_node[u] += cnt_node[v]; 
            low[u] = min(low[u], low[v]); 
        }
        else low[u] = min(low[u], num[v]); 
    }
    if ( low[u] == num[u]) {
        ans += cnt_node[u] * (n - cnt_node[u]) ; 
    } 
}
        
void input() {
    cin >> n >> m; 
    while(m--) {
        int u, v; 
        cin >> u >> v; 
        
        g[u].push_back(v); 
        g[v].push_back(u); 
    }
 
    memset(low, 0, sizeof (low));
    memset(num, 0, sizeof (num));  
    memset(cnt_node, 0, sizeof(cnt_node)); 
}

int main() {
    input(); 
    for(int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i, -1); 
        }
    }

    cout << ans << endl; 
    return 0; 
}
