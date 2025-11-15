#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
 
using namespace std; 
const int N = 2e5 + 5;
const int oo = 1e9;  
 
vector<int> g[N]; 
bool vis[N]; 
int d[N]; 
 
void bfs(int s) {
    fill_n(d, N, oo);  
    fill_n(vis, N, 0); 
 
    queue<int> q; 
    q.push(s); 
    d[s] = 0; 
    vis[s] = 1; 
 
    while(!q.empty()) {
        int u = q.front(); 
        q.pop(); 
 
        if(d[u] == oo) continue; 
 
        for(int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1; 
                d[v] = d[u] + 1; 
                q.push(v); 
            }
        }
    }
}
 
int main() {
    int n; cin >> n;
     
     if(n == 1) {
        cout << 0 << '\n';
        return 0;
    } 
 
    for(int i = 1; i < n; ++i) {
        int u, v; 
        cin >> u >> v; 
        
        g[u].emplace_back(v); 
        g[v].emplace_back(u); 
    }
 
    bfs(1); 
    int ans, maxval = 0; 
    for(int i = 1; i <= n; ++i) {
        if(maxval < d[i]) {
            maxval = d[i]; 
            ans = i; 
        }
    } 
 
    int a = ans; 
    bfs(ans);
    maxval = 0; 
    for(int i = 1; i <= n; ++i) {
        if (maxval < d[i]) {
            maxval = d[i]; 
            ans = i; 
        } 
    }
    int b = ans; 
 
    queue<int> q; 
    q.push(a); 
    bool visa[n + 1]; 
    fill_n(visa, n + 1, false);
    visa[a] = true;
 
    int da[n + 1]; 
    fill_n(da, n + 1, oo);
    da[a] = 0;
 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if (!visa[v]) {
                visa[v] = true; 
                da[v] = da[u] + 1; 
                q.push(v); 
            }
        }
    }
 
    queue<int> qb; 
    qb.push(b); 
    bool visb[n + 1]; 
    fill_n(visb, n + 1, false);
    visb[b] = true;
 
    int db[n + 1]; 
    fill_n(db, n + 1, oo);
    db[b] = 0;
 
    while(!qb.empty()) {
        int u = qb.front(); qb.pop();
        for(int v : g[u]) {
            if (!visb[v]) {
                visb[v] = true; 
                db[v] = db[u] + 1; 
                qb.push(v); 
            }
        }
    }
 
    for(int i = 1; i <= n; ++i) {
        cout << max(da[i], db[i]) << ' '; 
    }
}
