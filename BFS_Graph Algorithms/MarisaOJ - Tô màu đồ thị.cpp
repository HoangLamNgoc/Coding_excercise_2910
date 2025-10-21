#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
 
const int N = 1e5 + 5;
vector<int> g[N];
vector<int> r(N, 0), vis(N), col(N); 
 
struct Query {
    int u, d, c;
};
 
Query qe[N];
 
void bfs(int u, int d, int c, int n) {
    queue<int> q;
    q.push(u);
 
    if(!vis[u]) col[u] = c; 
    vis[u] = 1;
    r[u] = d;
 
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(r[v] == 0) continue; 
 
        for(int i : g[v]) {
            if(!vis[i]) {
                vis[i] = 1;
                r[i] = r[v] - 1;
                col[i] = c;
                q.push(i);
            } else {
                if(r[v] - 1 > r[i]) {
                    r[i] = r[v] - 1;
                    q.push(i);
                }
            }
        }
    }
}
 
int main() {
    int n, m, qn;
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    cin >> qn;
    for(int i = 0; i < qn; i++) {
        cin >> qe[i].u >> qe[i].d >> qe[i].c;
    }
 
    for(int i = qn-1; i >= 0; i--) {
        bfs(qe[i].u, qe[i].d, qe[i].c, n);
    }
 
    for(int i = 1; i <= n; i++) cout << col[i] << '\n';
    return 0;
}
