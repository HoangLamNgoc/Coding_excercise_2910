#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 5; 
vector<int> g[N], tp;
int n, m; 
int indeg[N]; 
queue<int> q; 

void input() {
    cin >> n >> m; 

    while(m--) {
        int u, v; 
        cin >> u >> v; 

        g[u].push_back(v); 
        ++indeg[v];
    }

    for(int i = 1; i <= n; ++i) 
        if(!indeg[i]) q.push(i);
}

void bfs() {  
    while(!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        tp.push_back(u); 

        for(int v : g[u]) {
            --indeg[v]; 
            if(!indeg[v]) q.push(v); 
        }
    } 
}

int main() {
    input(); 
    bfs(); 
    long long dp[N];
    for(int u : tp) {
        for(int v : g[u]) {
            dp[v] += 1; 
        }
    }

    cout << dp[n]; 
    return 0; 
}
