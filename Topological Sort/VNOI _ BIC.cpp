#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
const int MOD = 1e9; 
const int maxn = 1e5 + 5;

vector<int> g[maxn], gr[maxn], tp; 
bool f1[maxn], t2[maxn], ovf[maxn];
int n, m; 
queue<int> q; 
int indeg[maxn]; 

void input() {
    cin >> n >> m; 
    
    fill_n(f1, maxn, 0); 
    fill_n(t2, maxn, 0); 
    fill_n(indeg, maxn, 0); 
    fill_n(ovf, maxn, 0); 

    while(m--) {
        int u, v; 
        cin >> u >> v; 

        g[u].push_back(v); 
        gr[v].push_back(u); 
        ++indeg[v]; 
    } 
}

void bfstp() {
    for(int i = 1; i <= n; ++i) if(!indeg[i] && f1[i] && t2[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop(); 
        tp.push_back(u);
        for(int v : g[u]) {
            if(!f1[v] || !t2[v]) continue; 
            --indeg[v]; 
            if(!indeg[v]) q.push(v); 
        }
    }
}

void dfs(int u, vector<int> grp[maxn], bool vis[]) {
    vis[u] = true; 
    for(int v : grp[u]) if(!vis[v]) dfs(v, grp, vis); 
} 

int main() {
    input(); 
    
    dfs(1, g, f1); 
    dfs(2, gr, t2); 
    bfstp();

    int cnt = 0; 
    for(int i = 1; i <= n; ++i) if(f1[i] && t2[i]) ++cnt;
    if((int)tp.size() < cnt) {
        cout << "inf\n";
        return 0; 
    }

    long long dp[maxn]; 
    fill_n(dp, maxn, 0);
    dp[1] = 1; 
    for(int u : tp) {
        for(int v : g[u]) {
            if(f1[v] && t2[v]) {
                dp[v] += dp[u]; 

                if(dp[v] >= MOD) {
                    dp[v] %= MOD; 
                    ovf[v] = true; 
                }
            }
        }
    }
    if(ovf[2]) cout << setw(9) << setfill('0') << dp[2];
    else cout << dp[2];
}
