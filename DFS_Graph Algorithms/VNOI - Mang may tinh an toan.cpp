#include <bits/stdc++.h>
using namespace std;
int n, m; 
const int maxn = 1e6 + 5;
bool visited[maxn]; 
int d[maxn],par[maxn];  
vector<int> g[maxn]; 
long long best; 

void bfs(int s) {
    visited[s] = true; 
    d[s] = 0;
    queue<int> q; 
    par[s] = -1;  
    q.push(s); 

    while (!q.empty()) {
        int u = q.front(); q.pop(); 
        for (int v : g[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1; 
                visited[v] = true;
                q.push(v);  
            }
            else if ( v != par[u])
                    best = max(best, (long long)d[u] + d[v] + 1) ; 
            }
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

    memset(visited, false, sizeof (visited)); 
    memset(d, -1, sizeof (d)); 
    memset(par, 0, sizeof par);
}

int main() {
    input(); 
    for(int i = 1; i <= n; ++i) {
        if (!visited[i]) bfs(i); 
    }

    cout << best << endl; 
    return 0; 
}
